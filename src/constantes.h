#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "change_log.h"
#include "menu_items.h"

#define TIEMPO_PARPADEA_EDICION 500

#define TAM_VAR_TXT 22

#define CAPACIDAD_CISTERNA   30000
#define CAPACIDAD_CISTERNA_DEFAULT  5000

#define LIMITE_MIN 0                //indican la posicion en la matriz de minimos y maximos
#define LIMITE_MAX 1
#define VALOR_DEFAULT 2

#define LIMITE_MIN 0 // indican la posicion en la matriz de minimos y maximos
#define LIMITE_MAX 1
#define LIMITE_DEFAULT 2
#define MAX_SIGNED_SHORT 32767
#define MIN_SIGNED_SHORT -32767
const char PASSWORD_FIX[]="20972098";

const float variables_float_limites[MNU_TAM_VAR_FLOAT][3]=
{
	// MIN,   MAX,           DEFAULT,
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, CAPACIDAD_CISTERNA_DEFAULT,     //disponibles 1
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, CAPACIDAD_CISTERNA_DEFAULT,     //disponibles 2
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, CAPACIDAD_CISTERNA_DEFAULT,     //disponibles 3
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, CAPACIDAD_CISTERNA_DEFAULT,     //disponibles 4
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, CAPACIDAD_CISTERNA_DEFAULT,     //disponibles 5
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, 0,                      //Utilizados  1
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, 0,                      //Utilizados  2
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, 0,                      //Utilizados  3
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, 0,                      //Utilizados  4
    -CAPACIDAD_CISTERNA,CAPACIDAD_CISTERNA, 0,                      //Utilizados  5
    0,    30000,              1500,        //litros a cargar
    -10,  100,            0,        //temperatura de leche
    -10,  100,            0,        //temperatura de aceite
    0,    30000,              0,        //cantidad A
    0,    30000,              0,        //cantidad B
    0,    30000,              0,        //cantidad C
    0,    200000,           0,        //cantidad total de litros del recorrido
    0,    100,               8,        //temperatura maxima que puede tener la leche
    -10,  100,           0,        //temperatura maxima alcanzada en la carga
    -10,  100,           0,        //temperatura minima alcanzada en la carga
    -10,  100,           60,       //temperatura maxima alcanzada en la carga de aceite
    -10,  100,           0,        //temperatura promedio leche alcanzada en la carga de aceite
    -50000,50000,            0,        //caudal maximo y minimo
    0.1,    3000, 19.2992,      //FLOAT_SENSORCONSTANT parametro del caudalimetro
    -999999.00000,999999.00000, 0,      //FLOAT_ZEROELECTRODES parametro del caudalimetro
    -99999.0,99999.0,              0,      //volumen del caudalimetro
	0,900,                 300,			//FLOAT_Q_MIN
    -10,100,                0,      //FLOAT_TEMP_LECHE_PROMEDIO
    -10,100,         0,      //FLOAT_CORRIENTE_BOBINA
    0.1,900,                 1.0,      //FLOAT_K_CABEZAL
    -5000,5000,1000,       //V_REF_CAUDALIMETRO
    0,2500,1500,    //FLOAT_CAUDALIM_UMBRAL_AIRE
    0.1,100.0,39.0, //FLOAT_IBOBINA_MAX: default = 30 * 1.3
    0.1,100.0,21.0, //FLOAT_IBOBINA_MIN  default = 30 * 0.7
    0,50,0,//Litros Desaireador Inicio Carga
    0,50,0,//Litros Desaireador Fin Carga
    0,50,4.5, //FLOAT_LTS_OFFSET_DESAIREADOR
    -500000,500000,0, //FLOAT_VOLUMEN_TOTAL
};

const int variables_short_limites[MNU_TAM_VAR_SHORT][3]=
{
	//MIN,  MAX,    DEFAULT,
	1,     5,        1,        //cisterna de destino
	1,     5,        1,        //cisterna de origen
	0,     10000,    0,        //kilometros recorridos
	0,     1000,      40,       //litros desaireador
	0,     1000,     250,      //Nivel B
	0,     1000,     200,      //Nivel A
	0,     4096,     1,        //factor division del codigo de ad del desaireador
	0,     5,        0,       //compartimento A
	0,     5,        0,       //compartimento B
	0,     5,        0,       //compartimento C
	0,     9999,     20,      //tiempo cip de corte de valvula desaireador (en segundos)
	0,     30000,    3000,      //idem para tomamuestra (en ,milisegundos)
	0,     9999,     60,      //tiempo total del ciclo cip (en segundos)
	0,     4096,     0,        //offset de desaireador
	1,     5,        5,        //cantidad de cisternas disponibles
	1,     30000,    150,        //diametro de la rueda en cm
	0,     200,      150,        //cantidad de litros minimos necesarios para empezar a tomar como valida la temperatura medida
	0,     3600,     0,        //SHORT_SEGUNDOS_BOMBA
	0,     4096,     4096,      //(seg) tiempo despues del cual se considera finalizada la recepcion por mas que no se salga del menu
	1,     180,      60,        //(min) tiempo despues del cual se considera finalizado el CIP
	0,     999,      5,        //(mseg) logitud del pulso del tomamuestra
	0,     30000,     30000,        //cantidad de pulsos del tomamuestra
	0,     1000,     290,        //(l)umbral superior del desaireador      //NIVEL B1?//
	0,     CAPACIDAD_CISTERNA,   CAPACIDAD_CISTERNA_DEFAULT,        //tamaño de las 5 diferentes cisternas
	0,     CAPACIDAD_CISTERNA,   CAPACIDAD_CISTERNA_DEFAULT,
	0,     CAPACIDAD_CISTERNA,   CAPACIDAD_CISTERNA_DEFAULT,
	0,     CAPACIDAD_CISTERNA,   CAPACIDAD_CISTERNA_DEFAULT,
	0,     CAPACIDAD_CISTERNA,   CAPACIDAD_CISTERNA_DEFAULT,
	0,     MAX_SIGNED_SHORT,      0,        //SHORT_PROM_TEMP_CUENTA
	0,     MAX_SIGNED_SHORT,       0,       //SHORT_HORAS_USO_BOMBA
	30 ,    200,      90,      //velocidad maxima
	1,     600,      30,      //Q=0 al final
	5,     600,      30,      //Q=0 al principio
	0,     50,       3,       //lineas en blanco despues de una impresion
	0,     999,      30,        //l para comienzo de tomamuestra
	0,     9999,     1000,      //(l) cantidad de litros que se toman como estimados cuando no se tiene informacion del tambo en cuestion
	0,     4096,     0,         //canales AD del 0 al 3
	0,     4096,     0,          //canales AD del 0 al 3
	0,     4096,     0,          //canales AD del 0 al 3
	0,     4096,     0,          //canales AD del 0 al 3
	MIN_SIGNED_SHORT,     MAX_SIGNED_SHORT,   0,           //short de status
	1,     100,      30,            //caudal maximo /1000 este parametro se manda al caudalimetro
	0,     1000,     510,         //capacidad maxima del desaireador
	0,     60,       10,          //(s) cantidad de segundos en los que esta prendido el desaireador estado B         //TB abierta//
	0,     60,       10,          //(s) cantidad de segundos en los que esta apagado el desaireador estado B          //TB cerrada//
	0,     60,       5,           //(s) cantidad de segundos en los que esta prendido el desaireador estado C         //TC abierta//
	0,     60,       7,          //(s) cantidad de segundos en los que esta apagado el desaireador estado C          //TC cerrada//
	0,     60,       10,          //(s) cantidad de segundos que tarda en apagar la bomba en el estado D              //TD bomba//
	0,     60,       10,          //(s) cantidad de segundos que tarda en apagar la el desaireador en el estado D     //TD desaireador//
	0,     MAX_SIGNED_SHORT,     0,        //(#) codigo del ADC que de el nivel maximo de desaireador
	0,     1000,     0,           //SHORT_RESIST_IMPRESORA
	1,     20,       4,           //contraste de la impresora
	0,     5,        1,           //nivel de seguridad
	-1000,     1000,      0,           //porcentaje de ADC utilizado por el caudalimetro
	0,     32000,    0,           //aca guardo la cantidad de muestras tomadas por el tomamuestras (este dato lo transmite el caudalimetro)
	0,2000,    1000,       //offset de la pt100 leche
	-9000,12000,    100,       //offset de la pt100 aceite
	3,     9,        0  ,            //contraste del display
	0,     32000,    0,            //SHORT_HORAS_USO
	0,   32000,    2000,         //SHORT_T_TOMAMUESTRA_ATRAS
	0,     99,       0,            //SHORT_DB_CONTADOR_RUTA
	0,     32000,      VERSION_FIRMWARE,            //Version Firmware
	MIN_SIGNED_SHORT,MAX_SIGNED_SHORT,0,                     //temperatura interna del texas
	0,MAX_SIGNED_SHORT,5000,         //SHORT_CAUDAL_MINIMO_TOMAMUESTRA
	0,MAX_SIGNED_SHORT,5000,         //SHORT_CAUDAL_CERO_UMBRAL
	0,16,0,         //SHORT_CANT_DIG_REMITO //Si esta en 0 se habilita cualquier cantidad
	0,     999,      1,        //(mseg) logitud del pulso (ON) del tomamuestra
	0,     999,      1,        //(mseg) logitud del pulso (OFF) del tomamuestra
	0,16,0, //SHORT_CANT_DIG_TAMBO
	1,2,1,  //Vector_Nivel del Desaireador 
	0,5,0    //SHORT_OBS_TAMBO
        //0,0,0   //No usar 
};

//variables tipo texto ----------------------------------

const char variables_txt_default[][TAM_VAR_TXT]={
	"0110658000207125",   //TXT_REMITO          0
	"00000",              //TXT_ACOPLADO        1
	"0315102748024238",   //TXT_TAMBERO         2
	"7000",              //TXT_UNIDAD          3
	"54321",              //TXT_CUENTA          4
	"------",             //TXT_RECORRIDO       5
	"",                   //TXT_VERSION_DISPLAY   6
	"",                   //TXT_SERIE_DISPLAY     7
	"",                   //TXT_FECHA_DISPLAY     8
	"",                   //TXT_VERSION_CAUDALIM  9
	"",                   //TXT_SERIE_CAUDALIM    10
	"",                //TXT_FECHA_CAUDALIM    11
	"3",                  //TXT_PASSWORD_NIVEL_1 12 
	"2",                  //TXT_PASSWORD_NIVEL_2  13
	"3",                  //TXT_PASSWORD_NIVEL_3  14
        "000000000000",       //TXT_SERIE_CABEZAL     15
        "CARGAR        ",    //TXT_NOMBRE_RENGLON_1  16
        "NOMBRE      ",     //TXT_NOMBRE_RENGLON_2  17
		"000000000000",        //TXT_BT_ADDRESS 18  Direccion del dispositivo BLuetoooth para transferir archivo
        "000000000000", //Nro Serie Equipo 19
        "00",                   //TXT_NUM_LINEA 20
        "0000000000000000",//TXT_MUESTRA 21
        "0000000000",//TXT_NRO_REC 22
        "0000000000000000",//TXT_CHOFER 23        
        "0000000000",//TXT_REMITO_TRASBORDO 27
        "0000000000",//TXT_NRO_TRASBORDO 28
        "",//TXT_IOT_MODEM 0
        "",//TXT_IOT_MAC
        "",//TXT_IOT_GPRS_POW 
        "",//GPS
        "",//STATUS
		"16:21:04",
		"24-05-24"
};

const long variables_bits_default=0;


struct Var{
int vshort[MNU_TAM_VAR_SHORT];
signed short viot[MNU_TAM_VAR_SHORT_IOT];
char vtxt[MNU_TAM_VAR_TXT][TAM_VAR_TXT];
float vfloat[MNU_TAM_VAR_FLOAT];

long vbit=0x00;
};


#define FECHA_ACTUAL              0   //fecha y hora actual
#define FECHA_ARRANQUE            1   //hora de arranque
#define FECHA_FIN                 2   //hora de finalizacion
#define FECHA_ARRANQUE_RECEP      3   //fecha de arranque de la recepcion
#define FECHA_FIN_RECEP           4   //idem fin

#endif