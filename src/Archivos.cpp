#include <FS.h>
#include <SPIFFS.h>
#include "constantes.h"
/*****************Externas ***********************************/
extern struct Var variables;

/************************************************************/

extern union registros registro;


struct reg_tour               //Tamaño: 96 bytes
   {
   char     touridx[18];     //numero de guia FFFFFTTMMJJJJnn (F:numero de camion, J:ano, M:mes, T:dia, n va de 1 en adelante por cada nueva ruta)
   long     truckno;         //TXT_UNIDAD
   long     driverno;        //TXT_CUENTA
   char     remitono[18];    //TXT_REMITO
   char     noguiatrns[18];  //numero de guia transporte
   long     trailerno;       //TXT_ACOPLADO
   char     driverNro[18];   //TXT_CHOFER
   char     tourNro[18];     //TXT_NRO_REC
   unsigned short    tourno; //RECORRIDO
   unsigned short timestart; //FECHA_ARRANQUE (la hora nomas) hhmm
   unsigned short timeend;   //FECHA_FIN      (la hora nomas) hhmm
   unsigned long datestart;  //FECHA_ARRANQUE (la fecha) ddmmaa
   unsigned long dateend;    //FECHA_FIN (la fecha) ddmmaa
   float kmstart;            //kilometros al principio de la ruta (0?????)
   float kmend;              //kilometros al fin de la ruta (0?????)
   float tourquant;          //cantidad de leche total de la ruta
   short samplcount;         //numero de muestras tomadas durante la ruta
   unsigned short checksum;  //checksum de los datos anteriores
   };

struct reg_tambo             //Tamaño: 159 bytes
   {
   char     touridx[18];      //numero de guia FFFFFTTMMJJJJnn (F:numero de camion, J:ano, M:mes, T:dia, n va de 1 en adelante por cada nueva ruta)
   short     nro_linea;
   float    quantity;         //cantidad total de la recepcion (FLOAT_CANTIDAD_A+FLOAT_CANTIDAD_B+FLOAT_CANTIDAD_C)
   char     remitono[18];     //TXT_REMITO
   unsigned short timestart;  //FECHA_ARRANQUE_RECEP (la hora nomas) hhmm
   char     observacion;
   unsigned short timeend;    //FECHA_FIN_RECEP      (la hora nomas) hhmm
   unsigned long datestart;  //FECHA_ARRANQUE (la fecha) ddmmaa
   unsigned long dateend;    //FECHA_FIN (la fecha) ddmmaa
   float  tempaver;            //temperatura promedio FLOAT_TEMP_LECHE_SUMA
   float  tempmin;             //temperatura promedio FLOAT_TEMP_MIN_ALCANZADA
   float  tempmax;             //temperatura promedio FLOAT_TEMP_MAX_ALCANZADA
   char   compa;                //compartimeto a de carga SHORT_COMPARTIMENTO_A
   char   tanque_a;
   float  quantitya;            //cantidad a de carga     FLOAT_CANTIDAD_A
   char   compb;                //compartimeto b de carga SHORT_COMPARTIMENTO_B
   char   tanque_b;
   float  quantityb;            //cantidad b de carga     FLOAT_CANTIDAD_B
   char   compc;                //compartimeto c de carga SHORT_COMPARTIMENTO_C
   char   tanque_c;
   float  quantityc;            //cantidad c de carga     FLOAT_CANTIDAD_C
   unsigned short  status;      //SHORT DE STATUS SHORT_STATUS
   char     codigo_tambero[18]; //TXT_TAMBERO
   long LitrosRegla;        // Litros Medidos por la regla se toma del valor de los litros tomamuestras
   float Desaireador_Inicial;
   float Desaireador_Final;
   char   MuestraNro[18];     //NRO de Muestra para identificar el tarrito de la muestra
   char   remitoTrasbordo[18];     //NRO de remito de trasbordo
   float ConstanteKE;
   float ConstanteKC;
   unsigned short checksum;     //cheksum de los datos anteriores
   };

struct reg_error               //Tamaño: 28 bytes
  {
  char     touridx[18];      //numero de guia FFFFFTTMMJJJJnn (F:numero de camion, J:ano, M:mes, T:dia, n va de 1 en adelante por cada nueva ruta)
  unsigned short infono;     //numero de error/nota
  unsigned short time;       //FECHA_ACTUAL (la hora nomas) hhmm
  unsigned long date;        //FECHA_ACTUAL (la fecha) ddmmaa

  unsigned short checksum;   //checksum de los datos anteriores
  };

struct reg_cip                //Tamaño: 48 bytes
  {
  char     touridx[18];      //numero de guia FFFFFTTMMJJJJnn (F:numero de camion, J:ano, M:mes, T:dia, n va de 1 en adelante por cada nueva ruta)
  long     truckno;          //TXT_UNIDAD
  unsigned short timestart;  //FECHA_ARRANQUE (la hora nomas) hhmm   del cip
  unsigned short timeend;    //FECHA_FIN      (la hora nomas) hhmm   del cip
  unsigned long date;        //FECHA_ACTUAL (la fecha) ddmmaa
  float TempAver;
  float TempMin;
  float TempMax;
  float TotalLitros;

  unsigned short checksum;   //checksum de los datos anteriores
  };

struct reg_trasvase           //Tamaño: 38 bytes
  {
  char     touridx[18];      //numero de guia FFFFFTTMMJJJJnn (F:numero de camion, J:ano, M:mes, T:dia, n va de 1 en adelante por cada nueva ruta)
  short     sourcecomp;       //SHORT_ELECCION_ORIGEN  cisterna de origen
  short     destcomp;         //SHORT_ELEC_MEMORIA_CIST
  long     trailerno;        //TXT_ACOPLADO
  unsigned short timestart;  //FECHA_ARRANQUE (la hora nomas) hhmm  del trasvase
  unsigned long datestart;   //FECHA_ARRANQUE (la fecha) ddmmaa  del trasvase
  float    quantity;         //cantidad total del trasvase
  unsigned short checksum;   //checksum de los datos anteriores
  };

union registros
{
struct reg_cip cip;
struct reg_tour tour;
struct reg_tambo tambo;
struct reg_error error;
struct reg_trasvase trasvase;
};


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

