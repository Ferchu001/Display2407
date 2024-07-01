#include <FS.h>
#include <SPIFFS.h>
#include "constantes.h"
#include "struct_defines.h"

/*****************Externas ***********************************/
extern struct Var variables;

/************************************************************/

void db_genera_touridx(char *touridx);


struct reg_cip cip;
struct reg_tour tour;
struct reg_tambo tambo;
struct reg_info info;
struct reg_trasvase trasvase;

struct Date date_now;

void save_variables(const char* path) {
    File file = SPIFFS.open(path, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.write((const uint8_t*)&variables, sizeof(variables));
    file.close();
    Serial.println("Variables saved");
}

// Función para cargar la estructura desde un archivo
void load_variables(const char* path) {
    File file = SPIFFS.open(path, FILE_READ);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }
    file.read((uint8_t*)&variables, sizeof(variables));
    file.close();
    Serial.println("Variables loaded");
}

void save_ini_recorrido(void)
{
// Guarda info de inicio de recorrido
// Guarda Tour
char touridx[20];
db_genera_touridx(touridx);
Serial.println(touridx);

}
void db_genera_touridx(char *touridx)       //genera un nuevo numero de touridx
{
char i;
// Touridx = TTTTTDDMMYYYYnn
// TTTTT: Truck Number (5 DIGITS)
// DD: day (2 DIGITS)
// MM: Month (2 DIGITS)
// YYYY: Year(4 DIGITS)
// nn : number of route during the same day. (Incremental number)
    //variables.vtxt[TXT_UNIDAD] 5 digitos
    //date_now //DDMMYYYY
    //nn
    char unidad[6] = "00000"; // Inicializa con ceros
    int len = strlen(variables.vtxt[TXT_UNIDAD]);
    if (len > 5) len = 5; // Asegura que no se sobrescriba el buffer
    memcpy(&unidad[5 - len], variables.vtxt[TXT_UNIDAD], len); // Copia los últimos dígitos

Serial.println("--1");
    // Formatear la fecha como DDMMYYYY
    char fecha[9];
    sprintf(fecha, "%02d%02d%04d", date_now.day, date_now.month, date_now.year);
Serial.println("--2");
    // Formatear el contador con 2 dígitos
    char contador[3];
    sprintf(contador, "%02d", variables.vshort[SHORT_DB_CONTADOR_RUTA]);
Serial.println("--3");
Serial.printf("%s%s%s", unidad, fecha, contador);
    // Concatenar todo en la cadena resultante
    sprintf(touridx, "%s%s%s", unidad, fecha, contador);
    Serial.print("touridx:");
    Serial.println(touridx);
}
/*
extern char var_ticket;
union registro registros;
#define DB_MAX_WR_RETRY 5     //cantidad maxima de reintentos de escritura de los registros
void db_generar_nuevo_tour()
{
    unsigned short direccion;
    char i;

    for(i=0;i<DB_MAX_WR_RETRY;i++)
      {
      registro_actual=DB_TIPO_TOUR;
      db_genera_touridx((char*)registros.tour_temp.touridx);
      string_to_long(variables_txt[TXT_UNIDAD],&registros.tour_temp.truckno );
      string_to_long(variables_txt[TXT_CUENTA],&registros.tour_temp.driverno );
      strcpy(registros.tour_temp.remitono,variables_txt[TXT_REMITO]);        //guarda que tiene que ocupar 6 caracteres
      strcpy(registros.tour_temp.noguiatrns,"                ");        //guarda que tiene que ocupar 6 caracteres
      string_to_long(variables_txt[TXT_ACOPLADO],&registros.tour_temp.trailerno );
      registros.tour_temp.tourno=0;
      strcpy(registros.tour_temp.driverNro, variables_txt[TXT_CHOFER]);
      strcpy(registros.tour_temp.tourNro, variables_txt[TXT_NRO_REC]);
      registros.tour_temp.timestart=variables_fecha[FECHA_ARRANQUE][FECHA_HORA]*100+variables_fecha[FECHA_ARRANQUE][FECHA_MINUTO];
      registros.tour_temp.timeend=variables_fecha[FECHA_FIN][FECHA_HORA]*100+variables_fecha[FECHA_FIN][FECHA_MINUTO];
      registros.tour_temp.datestart=(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_ANO];
      if( var_ticket==MNUF_TICKET_INICIO )
        registros.tour_temp.dateend=0;
      else
        registros.tour_temp.dateend=(unsigned long)variables_fecha[FECHA_FIN][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_FIN][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_FIN][FECHA_ANO];

      registros.tour_temp.kmstart=TOUR_KM_START;                                     //kilometros al principio de la ruta.
      registros.tour_temp.kmend=(float)variables_short[SHORT_KILOMETROS_RECORRIDOS]; //kilometros al fin de la ruta.
      registros.tour_temp.tourquant=Obtener_litros_tour();          //cantidad de leche total de la ruta
      registros.tour_temp.samplcount=variables_short[SHORT_MUESTRAS_TOMADAS];
      registros.tour_temp.checksum=calcula_checksum((char*)&registros.tour_temp, sizeof(struct reg_tour)-2);


  //    if(db_cant_reg[DB_TIPO_TOUR]>=DB_MAX_REG_TOUR) db_cant_reg[DB_TIPO_TOUR]=0;
      if(db_cant_reg[DB_TIPO_TOUR]<DB_MAX_REG_TOUR)// db_cant_reg[DB_TIPO_TOUR]=0;
        {
        direccion=DB_ADD_TOUR+sizeof(struct reg_tour)*db_cant_reg[DB_TIPO_TOUR];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
        db_cant_reg[DB_TIPO_TOUR]++;
        db_procesa_errores(i2c_mem_write((char*)&registros.tour_temp, sizeof(struct reg_tour),direccion));      //escribe los datos y procesa si existe algun error
       if(db_leer_dato(db_cant_reg[DB_TIPO_TOUR]-1,DB_TIPO_TOUR)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
          break;
       else
          db_cant_reg[DB_TIPO_TOUR]--;        //esto es por compatibilidad con la version anterior
        }
      else
        {
        db_generar_nuevo_info(INFOCODE_MEMORIA_TOUR_LLENA);
        break;     //salgo del for porque no hay lugar en memoria
        }

}   //fin for

if(i>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_TOUR]++;
  registro_actual=DB_TIPO_TOUR;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }

db_guardar_fat();
}

void db_generar_nuevo_intake(char estado)
{
    unsigned short direccion;
    char n;

    for(n=0;n<DB_MAX_WR_RETRY;n++)
       {         
       registro_actual=DB_TIPO_INTAKE;
       db_genera_touridx((char*)registros.intake_temp.touridx);
       string_to_short(variables_txt[TXT_NUM_LINEA],&registros.intake_temp.nro_linea);
       strcpy(registros.intake_temp.codigo_tambero,variables_txt[TXT_TAMBERO]);
       registros.intake_temp.quantity=variables_float[FLOAT_CANTIDAD_A]+variables_float[FLOAT_CANTIDAD_B]+variables_float[FLOAT_CANTIDAD_C];
       strcpy(registros.intake_temp.remitono,variables_txt[TXT_REMITO]);//guarda que tiene que ocupar 6 caracteres
       registros.intake_temp.timestart=variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_HORA]*100+variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_MINUTO];
       registros.intake_temp.timeend=variables_fecha[FECHA_FIN_RECEP][FECHA_HORA]*100+variables_fecha[FECHA_FIN_RECEP][FECHA_MINUTO];
       registros.intake_temp.datestart=(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_ANO];
       registros.intake_temp.dateend=(unsigned long)variables_fecha[FECHA_FIN_RECEP][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_FIN_RECEP][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_FIN_RECEP][FECHA_ANO];
       registros.intake_temp.tempaver=variables_float[FLOAT_TEMP_LECHE_PROMEDIO];
       registros.intake_temp.tempmin=variables_float[FLOAT_TEMP_MIN_ALCANZADA];
       registros.intake_temp.tempmax=variables_float[FLOAT_TEMP_MAX_ALCANZADA];
       registros.intake_temp.observacion=variables_short[SHORT_OBS_TAMBO];
       if(estado==1){
       registros.intake_temp.compa=variables_short[SHORT_COMPARTIMENTO_A];
       registros.intake_temp.quantitya=variables_float[FLOAT_CANTIDAD_A];
       }
       registros.intake_temp.compb=variables_short[SHORT_COMPARTIMENTO_B];
       registros.intake_temp.quantityb=variables_float[FLOAT_CANTIDAD_B];
       registros.intake_temp.compc=variables_short[SHORT_COMPARTIMENTO_C];
       registros.intake_temp.quantityc=variables_float[FLOAT_CANTIDAD_C];
       registros.intake_temp.status=variables_short[SHORT_STATUS];
       registros.intake_temp.LitrosRegla=variables_float[FLOAT_LITROS_A_CARGAR];
       registros.intake_temp.Desaireador_Inicial=variables_float[VOLUMEN_DESAIREADOR_INICIO];
       registros.intake_temp.Desaireador_Final=variables_float[VOLUMEN_DESAIREADOR_FIN];
       registros.intake_temp.ConstanteKE=variables_float[FLOAT_SENSORCONSTANT];
       registros.intake_temp.ConstanteKC=variables_float[FLOAT_K_CABEZAL];
       registros.intake_temp.MuestraNro[0] = '\0';
       strcpy(registros.intake_temp.MuestraNro,variables_txt[TXT_MUESTRA]);
       registros.intake_temp.remitoTrasbordo[0]='\0';
       if(isTrasbordo)
       {
         strcpy(registros.intake_temp.remitoTrasbordo,variables_txt[TXT_REMITO_TRASBORDO]);        //guarda que tiene que ocupar 6 caracteres 
         strcpy(registros.intake_temp.codigo_tambero,variables_txt[TXT_NRO_TRASBORDO]);
       }
       else
       {       
         strcpy(registros.intake_temp.codigo_tambero,variables_txt[TXT_TAMBERO]);         
       }
       registros.intake_temp.checksum=calcula_checksum((char*)&registros.intake_temp, sizeof(struct reg_intake)-2);

       if(db_cant_reg[DB_TIPO_INTAKE]<DB_MAX_REG_INTAKE)   //si tengo espacio en memoria
          {
          direccion=DB_ADD_INTAKE+sizeof(struct reg_intake)*db_cant_reg[DB_TIPO_INTAKE];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
          db_cant_reg[DB_TIPO_INTAKE]++;
          db_procesa_errores(i2c_mem_write((char*)&registros.intake_temp, sizeof(struct reg_intake),direccion));
       if(db_leer_dato(db_cant_reg[DB_TIPO_INTAKE]-1,DB_TIPO_INTAKE)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
          break;
       else
          db_cant_reg[DB_TIPO_INTAKE]--;        //esto es por compatibilidad con la version anterior
          }
        else
          {
          db_generar_nuevo_info(INFOCODE_MEMORIA_INTAKE_LLENA);
          break;
          }
    } //fin for

if(n>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_INTAKE]++;
  registro_actual=DB_TIPO_INTAKE;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }

//solo si la leche no es decomizada, y se cargaron al menos 100 litros, genero un nuevo registro de litros para ese tambo
//if(!(variables_short[SHORT_STATUS]&INFCO_INTAKE_DECOMISADA) && (variables_float[FLOAT_CANTIDAD_A]+variables_float[FLOAT_CANTIDAD_B]+variables_float[FLOAT_CANTIDAD_C]>100))
//  db_generar_litros_tambo();      //actualiza la base de datos de litros recolectado

db_guardar_fat();
}



void db_generar_nuevo_info(unsigned short error_code)
{
   unsigned short direccion;
   char n;


    for(n=0;n<DB_MAX_WR_RETRY;n++)
      {
       registro_actual=DB_TIPO_INFO;
       db_genera_touridx((char*)registros.error_temp.touridx);
       registros.error_temp.infono=error_code;
       registros.error_temp.time=variables_fecha[FECHA_ACTUAL][FECHA_HORA]*100+variables_fecha[FECHA_ACTUAL][FECHA_MINUTO];
       registros.error_temp.date=(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_ANO];
       registros.error_temp.checksum=calcula_checksum((char*)&registros.error_temp, sizeof(struct reg_error)-2);

    if(db_cant_reg[DB_TIPO_INFO]<DB_MAX_REG_ERROR-1)   //si tengo espacio en memoria
       {
       direccion=DB_ADD_ERROR+sizeof(struct reg_error)*db_cant_reg[DB_TIPO_INFO];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
       db_cant_reg[DB_TIPO_INFO]++;
       if(db_cant_reg[DB_TIPO_INFO]<=1)
                db_cant_reg[DB_TIPO_INFO]=1;
       db_procesa_errores(i2c_mem_write((char*)&registros.error_temp, sizeof(struct reg_error),direccion));       
       if(db_leer_dato(db_cant_reg[DB_TIPO_INFO]-1,DB_TIPO_INFO)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
          break;
       else
          {             
          db_cant_reg[DB_TIPO_INFO]--;        //esto es por compatibilidad con la version anterior
          }
       }
    else
      {
      direccion=DB_ADD_ERROR+sizeof(struct reg_error)*(DB_MAX_REG_ERROR-1);    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
      db_procesa_errores(i2c_mem_write((char*)&registros.error_temp, sizeof(struct reg_error),direccion));
      db_cant_reg[DB_TIPO_INFO]=DB_MAX_REG_ERROR;
      break;
      }
    }//fin for

if(n>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_INFO]++;
  registro_actual=DB_TIPO_INFO;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }


if(((error_code/1000)==7) && mnu_chekear_bit(BIT_IMPRIMIR_INFOS_7XXX))
  mnuf_ticket(MNUF_TICKET_OBSERVACION,0);         //imprime el ticket pedido, con_base=1 indica qeu tiene que guardar en la base de datos la info
else if(error_code==INFOCODE_POWERFAIL)
  mnuf_ticket(MNUF_TICKET_OBSERVACION,0);         //imprime el ticket pedido, con_base=1 indica qeu tiene que guardar en la base de datos la info


db_guardar_fat();

}




void db_generar_nuevo_cip()
{
   unsigned short direccion;
   char n;


    for(n=0;n<DB_MAX_WR_RETRY;n++)
      {
       registro_actual=DB_TIPO_CIP;
       db_genera_touridx((char*)registros.cip_temp.touridx);
       string_to_long(variables_txt[TXT_UNIDAD],&registros.cip_temp.truckno);     //si el contenido de TXT_UNIDAD no representa un numero, cargo 0 en la variable
       registros.cip_temp.timestart=variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_HORA]*100+variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_MINUTO];
       registros.cip_temp.timeend=variables_fecha[FECHA_FIN_RECEP][FECHA_HORA]*100+variables_fecha[FECHA_FIN_RECEP][FECHA_MINUTO];

        registros.cip_temp.date=(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ACTUAL][FECHA_ANO];

	registros.cip_temp.TempAver=(variables_float[FLOAT_TEMP_MIN_ALCANZADA]+variables_float[FLOAT_TEMP_MAX_ALCANZADA])/2;
	registros.cip_temp.TempMin=variables_float[FLOAT_TEMP_MIN_ALCANZADA];
	registros.cip_temp.TempMax=variables_float[FLOAT_TEMP_MAX_ALCANZADA];
        registros.cip_temp.TotalLitros=variables_float[FLOAT_VOLUMEN_TOTAL];
	
	
        registros.cip_temp.checksum=calcula_checksum((char*)&registros.cip_temp, sizeof(struct reg_cip)-2);

       if(db_cant_reg[DB_TIPO_CIP]<DB_MAX_REG_CIP)   //si tengo espacio en memoria
          {
          direccion=DB_ADD_CIP+sizeof(struct reg_cip)*db_cant_reg[DB_TIPO_CIP];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
          db_cant_reg[DB_TIPO_CIP]++;

          db_procesa_errores(i2c_mem_write((char*)&registros.cip_temp, sizeof(struct reg_cip),direccion));

         if(db_leer_dato(db_cant_reg[DB_TIPO_CIP]-1,DB_TIPO_CIP)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
            break;
         else
            db_cant_reg[DB_TIPO_CIP]--;        //esto es por compatibilidad con la version anterior
          }
          else
            {
            db_generar_nuevo_info(INFOCODE_MEMORIA_CIP_LLENA);
            break;
            }
        }// fin for


if(n>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_CIP]++;
  registro_actual=DB_TIPO_CIP;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }

db_guardar_fat();
}


void db_generar_nuevo_trasvase()
{

   unsigned short direccion;
   char n;
    for(n=0;n<DB_MAX_WR_RETRY;n++)
      {
       registro_actual=DB_TIPO_TRASVASE;
       db_genera_touridx((char*)registros.trasvase_temp.touridx);
       registros.trasvase_temp.sourcecomp=variables_short[SHORT_COMPARTIMENTO_A];
       registros.trasvase_temp.destcomp=variables_short[SHORT_COMPARTIMENTO_B];
       string_to_long(variables_txt[TXT_ACOPLADO],&registros.trasvase_temp.trailerno );
       registros.trasvase_temp.timestart=variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_HORA]*100+variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_MINUTO];
       registros.trasvase_temp.datestart=(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ARRANQUE_RECEP][FECHA_ANO];
       registros.trasvase_temp.quantity=variables_float[FLOAT_CANTIDAD_B];         //cantidad total del trasvase

       registros.trasvase_temp.checksum=calcula_checksum((char*)&registros.trasvase_temp, sizeof(struct reg_trasvase)-2);

        if(db_cant_reg[DB_TIPO_TRASVASE]<DB_MAX_REG_TRASVASE)   //si tengo espacio en memoria
          {
          direccion=DB_ADD_TRASVASE+sizeof(struct reg_trasvase)*db_cant_reg[DB_TIPO_TRASVASE];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
          db_cant_reg[DB_TIPO_TRASVASE]++;

          db_procesa_errores(i2c_mem_write((char*)&registros.trasvase_temp, sizeof(struct reg_trasvase),direccion));
           if(db_leer_dato(db_cant_reg[DB_TIPO_TRASVASE]-1,DB_TIPO_TRASVASE)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
              break;
           else
              db_cant_reg[DB_TIPO_TRASVASE]--;        //esto es por compatibilidad con la version anterior
          }
          else
            {
            db_generar_nuevo_info(INFOCODE_MEMORIA_TRASVASE_LLENA);
            break;
            }
        }//fin for

if(n>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_TRASVASE]++;
  registro_actual=DB_TIPO_TRASVASE;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }

db_guardar_fat();
}


{
    unsigned short direccion;
    char i;

    for(i=0;i<DB_MAX_WR_RETRY;i++)
      {
      registro_actual=DB_TIPO_TOUR;
      db_genera_touridx((char*)registros.tour_temp.touridx);
      string_to_long(variables_txt[TXT_UNIDAD],&registros.tour_temp.truckno );
      string_to_long(variables_txt[TXT_CUENTA],&registros.tour_temp.driverno );
      strcpy(registros.tour_temp.remitono,variables_txt[TXT_REMITO]);        //guarda que tiene que ocupar 6 caracteres
      strcpy(registros.tour_temp.noguiatrns,"                ");        //guarda que tiene que ocupar 6 caracteres
      string_to_long(variables_txt[TXT_ACOPLADO],&registros.tour_temp.trailerno );
      registros.tour_temp.tourno=0;
      strcpy(registros.tour_temp.driverNro, variables_txt[TXT_CHOFER]);
      strcpy(registros.tour_temp.tourNro, variables_txt[TXT_NRO_REC]);
      registros.tour_temp.timestart=variables_fecha[FECHA_ARRANQUE][FECHA_HORA]*100+variables_fecha[FECHA_ARRANQUE][FECHA_MINUTO];
      registros.tour_temp.timeend=variables_fecha[FECHA_FIN][FECHA_HORA]*100+variables_fecha[FECHA_FIN][FECHA_MINUTO];
      registros.tour_temp.datestart=(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_ARRANQUE][FECHA_ANO];
      if( var_ticket==MNUF_TICKET_INICIO )
        registros.tour_temp.dateend=0;
      else
        registros.tour_temp.dateend=(unsigned long)variables_fecha[FECHA_FIN][FECHA_DIA]*10000+(unsigned long)variables_fecha[FECHA_FIN][FECHA_MES]*100+(unsigned long)variables_fecha[FECHA_FIN][FECHA_ANO];

      registros.tour_temp.kmstart=TOUR_KM_START;                                     //kilometros al principio de la ruta.
      registros.tour_temp.kmend=(float)variables_short[SHORT_KILOMETROS_RECORRIDOS]; //kilometros al fin de la ruta.
      registros.tour_temp.tourquant=Obtener_litros_tour();          //cantidad de leche total de la ruta
      registros.tour_temp.samplcount=variables_short[SHORT_MUESTRAS_TOMADAS];
      registros.tour_temp.checksum=calcula_checksum((char*)&registros.tour_temp, sizeof(struct reg_tour)-2);


  //    if(db_cant_reg[DB_TIPO_TOUR]>=DB_MAX_REG_TOUR) db_cant_reg[DB_TIPO_TOUR]=0;
      if(db_cant_reg[DB_TIPO_TOUR]<DB_MAX_REG_TOUR)// db_cant_reg[DB_TIPO_TOUR]=0;
        {
        direccion=DB_ADD_TOUR+sizeof(struct reg_tour)*db_cant_reg[DB_TIPO_TOUR];    //aca tengo a partir de que direccion escribo en memoria, esto es la direccion base de los registros de este tipo mas la cantidad de registros por su tamaño
        db_cant_reg[DB_TIPO_TOUR]++;
        db_procesa_errores(i2c_mem_write((char*)&registros.tour_temp, sizeof(struct reg_tour),direccion));      //escribe los datos y procesa si existe algun error
       if(db_leer_dato(db_cant_reg[DB_TIPO_TOUR]-1,DB_TIPO_TOUR)==0)     //intento leer el registro recien escrito, si el checksum es correcto, esta funcion retorna cero, entonces doy por entendido qeu el registro se escribio correctamente
          break;
       else
          db_cant_reg[DB_TIPO_TOUR]--;        //esto es por compatibilidad con la version anterior
        }
      else
        {
        db_generar_nuevo_info(INFOCODE_MEMORIA_TOUR_LLENA);
        break;     //salgo del for porque no hay lugar en memoria
        }

}   //fin for

if(i>=DB_MAX_WR_RETRY)    //se sobrepasaron los reintentos de escribir
  {
  db_cant_reg[DB_TIPO_TOUR]++;
  registro_actual=DB_TIPO_TOUR;
  db_procesa_errores(DB_ERROR_ESCRITURA);
  }

db_guardar_fat();
}
*/