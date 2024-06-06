#ifndef MENU_H
#define MENU_H
#include <menu_tabla.h>
#include <menu_items.h>
#include <constantes.h>
#include <Arduino.h>
typedef struct
{
    char Etiqueta[20];
    int Nivel;
    char Tipo;
    int Nivel_Next;
    int Nivel_Back;    
    char Tecla_Rapida;
    char Pre_proceso;
    char Post_Proceso;
    char Variable_Asoc;
    char Cant_digitos;
} MenuItem;
#define PRE_VOID 0
#define POST_VOID 0
#define POST_SAVE_PARAM 1

#define VAR_VOID 0
#define TEC_VOID 255



const MenuItem menu[] = {
//    Etiqueta,    		Nivel,          tipo de item,   	Nivel_Next,     	Nivel_Back,    Tecla_Rapida,PreProceso,PostProceso,Variable, CantDigitos,
	{ET_RECORRIDO, 		ID_PRINCIPAL,	TIPO_ETIQ,      	ID_RECORRIDO_D, 	ID_VOID,       '1',       PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_CIP,       		ID_PRINCIPAL,	TIPO_ETIQ,      	ID_CIP,         	ID_VOID,       '2',       PRE_VOID,POST_VOID,VAR_VOID, 0},
	{ET_CIP_HORA,  		ID_CIP,         TIPO_HORA_NM_SL, 	ID_VOID,       		ID_PRINCIPAL,  TEC_VOID,PRE_VOID,POST_VOID, SHORT_TIEMPO_USO_CIP, 0},
    {ET_CIP_TEMP,  		ID_CIP,         TIPO_FLOAT_NM_SL,	ID_VOID,       		ID_PRINCIPAL,  TEC_VOID,PRE_VOID,POST_VOID, FLOAT_TEMP_LECHE, 0},

    {ET_REMITO,    		ID_RECORRIDO_D, TIPO_TXT_SM_SL, 	ID_NXT_ITEM,    	ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_REMITO, 16},
    {ET_NRO_LINEA, 		ID_RECORRIDO_D, TIPO_TXT_SM_SL, 	ID_NXT_ITEM,    	ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_NUM_LINEA, 2},
    {ET_ACOPLADO,  		ID_RECORRIDO_D, TIPO_TXT_SM_SL, 	ID_NXT_ITEM,    	ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_ACOPLADO, 5},
    {ET_NRO_REC,   		ID_RECORRIDO_D, TIPO_TXT_SM_SL, 	ID_NXT_ITEM,    	ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_NRO_REC, 16},
    {ET_CHOFER,    		ID_RECORRIDO_D, TIPO_TXT_SM_SL, 	ID_RECORRIDO_I, 	ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_CHOFER,  16},    
    
	{ET_1_RECEPCION, 	ID_RECORRIDO_I,	TIPO_TXT_SM_SL, 	ID_TAMBO,       	ID_VOID,        '1',	PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_2_TRASVASE, 	ID_RECORRIDO_I,	TIPO_TXT_SM_SL, 	ID_TAMBO,       	ID_VOID,        '2',    PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_4_FIN_RECORR, 	ID_RECORRIDO_I,	TIPO_TXT_SM_SL, 	ID_TAMBO,       	ID_VOID,        '4',    PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_5_TRASBORDO, 	ID_RECORRIDO_I,	TIPO_TXT_SM_SL, 	ID_TAMBO,       	ID_VOID,        '5',    PRE_VOID,POST_VOID, VAR_VOID, 0},

	{ET_0_VACIA_DESAI,	ID_FUNCIONES,	TIPO_ETIQ		,	ID_VOID,			ID_MEMORIA	,	'0',	PRE_VOID,POST_VOID, VAR_VOID, 0},
	{ET_1_REIMPRIMIR,	ID_FUNCIONES,	TIPO_ETIQ		,	ID_VOID,			ID_MEMORIA	,	'1',	PRE_VOID,POST_VOID, VAR_VOID, 0},
	{ET_2_OBSERVACION,	ID_FUNCIONES,	TIPO_ETIQ		,	ID_VOID,			ID_MEMORIA	,	'2'	,	PRE_VOID,POST_VOID, VAR_VOID, 0},
	{"3-ULT CARGA"	,	ID_FUNCIONES,	TIPO_ETIQ	    ,	ID_TAG_ULT_CARGA,	ID_MEMORIA	,	'3',	PRE_VOID, POST_VOID,VAR_VOID, 0	},
	{"4-PARAMETROS"	,	ID_FUNCIONES,	TIPO_ETIQ	    ,	ID_PASSWORD,		ID_MEMORIA	,	'4',	PRE_VOID, POST_VOID,VAR_VOID, 0},
	{ET_PASSWORD	,	ID_PASSWORD	,	TIPO_PASSWORD_SL,   ID_PARAMETROS	,   ID_FUNCIONES,TEC_VOID,PRE_VOID,POST_VOID, TXT_PASSWORD_INGRESADO,16},

	{"INSOLTECH"	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_INSOLTECH,       ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_VEHICULO	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_VEHICULO	,	ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_FECHA_HORA	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_TIEMPOS	,	ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_BLUETOOTH_CF,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_BLUETOOTH,	ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_I_O,	        ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_IO	    ,	ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},	
    {ET_CAUDALIMETRO,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_CAUDALIMETRO,ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_IMPRESORA	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_IMPRESORA,   ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_TOMAMUESTRAS,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_TOMAMUESTRAS,ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_DESAIREADOR	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_DESAIREADOR, ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	{ET_PROCESOS	,	ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_PROCESOS	,   ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
    {ET_BASE_DATOS,		ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_BASE_DATOS,  ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
    {ET_SIM_7000,	    ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_SIM7000	,   ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
    {ET_GPRS,	        ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_GPRS	,       ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},	
    {ET_PASSWORD,	    ID_PARAMETROS,	TIPO_ETIQ		,	ID_PAR_PASSWORD,    ID_FUNCIONES,TEC_VOID, PRE_VOID,POST_SAVE_PARAM, VAR_VOID, 0},
	

	{ET_UNIDAD	,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID, TXT_UNIDAD, 5},
	{ET_ACOPLADO,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,TXT_ACOPLADO,	16},
	{ET_CUENTA	,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,TXT_CUENTA		,	5},
	{ET_CISTERNAS,	ID_PAR_VEHICULO	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_CANTIDAD_CISTERNAS,	1},
	{ET_CAPA_1	,	ID_PAR_VEHICULO	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_TAMANO_CIST_1	,	5},
	{ET_CAPA_2	,	ID_PAR_VEHICULO,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_TAMANO_CIST_2	,	5},
	{ET_CAPA_3	,	ID_PAR_VEHICULO,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_TAMANO_CIST_3	,	5},
	{ET_CAPA_4	,	ID_PAR_VEHICULO,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_TAMANO_CIST_4	,	5},
	{ET_CAPA_5	,	ID_PAR_VEHICULO,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,SHORT_TAMANO_CIST_5	,	5},

	{ET_VOLUMEN	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_VOLUMEN_CAUDALIM	,	10},
	{ET_CAUDAL	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_CAUDAL		,	5	},	
	{ET_Q_MINIMO,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_Q_MIN		,	5	},
    {ET_CORR_BOBINA,ID_PAR_CAUDALIMETRO	,   TIPO_SINGLE_NM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_CORRIENTE_BOBINA	,	12},
    {ET_CERO	,	ID_PAR_CAUDALIMETRO	,	TIPO_ETIQ		    ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID			,0},
    {ET_C_ELEC	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_ZEROELECTRODES	,	5 },
    {ET_K_ELECTRO,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_SENSORCONSTANT	,	10	},
	{ET_K_CABEZAL,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_K_CABEZAL		,	10},	
	{ET_PORC_AD	,	ID_PAR_CAUDALIMETRO	,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_PORCENTAJE_AD	,	3	},
	{ET_Q_MAXIMO,	ID_PAR_CAUDALIMETRO	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CAUDAL_MAXIMO	,	3},	
	{ET_DECIMAL	,	ID_PAR_CAUDALIMETRO	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_DECIMAL_EN_CARGA	,	0},
    {ET_SERIE_CABEZAL,	ID_PAR_CAUDALIMETRO	,TIPO_TXT_SM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_CABEZAL	,	12},
    {ET_V_REF	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_NM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	V_REF_CAUDALIMETRO	,	12},
    {ET_UMBRAL_AIRE,ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_CAUDALIM_UMBRAL_AIRE,	5},
    {ET_IBOB_MAX,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_IBOBINA_MAX	,	5},
    {ET_IBOB_MIN,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_IBOBINA_MIN	,	5},
	{ET_INVERTIR,	ID_PAR_CAUDALIMETRO	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_INVERSION_CAUDALIMETRO,	2},
	
	{ET_LEC_BARRAS   ,	ID_INSOLTECH	,	TIPO_BIT_SM_ML	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_LECTOR_BARRAS_ON	,	5},	
	{ET_EMPRESA_RN1  ,	ID_INSOLTECH	,	TIPO_TXT_SM_SL_ALFA	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_NOMBRE_RENGLON_1	,	15},	
	{ET_EMPRESA_RN2  ,	ID_INSOLTECH	,	TIPO_TXT_SM_SL_ALFA	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_NOMBRE_RENGLON_2	,	15},
	{ET_SERIE_DISP	,	ID_INSOLTECH	,	TIPO_TXT_SM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_DISPLAY	,	11},
	{ET_FECHA_DISP	,	ID_INSOLTECH	,	TIPO_TXT_NM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_FECHA_DISPLAY	,	8},
	{ET_VER_DISP	,	ID_INSOLTECH	,	TIPO_TXT_NM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_VERSION_DISPLAY	,	5},
	{ET_SERIE_CAUD	,	ID_INSOLTECH	,	TIPO_TXT_SM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_CAUDALIM	,	11},
	{ET_FECHA_CAUD	,	ID_INSOLTECH	,	TIPO_TXT_NM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_FECHA_CAUDALIM	,	8},
	{ET_VER_CAUD	,	ID_INSOLTECH	,	TIPO_TXT_NM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_VERSION_CAUDALIM	,	5},
    {ET_SERIE_IMP	,	ID_INSOLTECH	,	TIPO_SHORT_SM_SL,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_SERIAL_IMPRESORA	,	5	},
	{ET_SERIE_EQUIPO,	ID_INSOLTECH	,	TIPO_TXT_SM_SL	,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_EQUIPO	,	11	},
	{ET_HORAS_ELECTRO,	ID_INSOLTECH	,	TIPO_SHORT_SM_SL,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_HORAS_USO_ELECTRO	,	5},	   
    {ET_T_MICRO	   ,	ID_INSOLTECH	,	TIPO_SHORT_NM_ML,		ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TEMP_TEXAS	,	4},

	{ET_HORA_ACTUAL	,	ID_PAR_TIEMPOS		,	TIPO_HORA_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_HORA		,12},
	{ET_FECHA_ACTUAL,	ID_PAR_TIEMPOS		,	TIPO_FECHA_SM_SL,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_FECHA	,	12},

	// {ET_CONFIRMAR,		ID_DUMMY		,	TIPO_ETIQ		,	0			,	ID_LITROS_CARGAR,0,	ID_TAG_LITROS_MUESTRA},
	{ET_LITROS_TAMBO,	ID_LITROS_CARGAR,	TIPO_FLOAT_SM_SL	,	ID_NXT_ITEM,		ID_RECORRIDO_I,	TEC_VOID, PRE_VOID,POST_VOID,FLOAT_LITROS_A_CARGAR,	5},
    {ET_MUESTRA,    	ID_LITROS_CARGAR,	TIPO_TXT_SM_SL  	,	ID_TAMBO_OBS,		ID_BACK_ITEM,	TEC_VOID, PRE_VOID,POST_VOID,TXT_MUESTRA       		,16},
    {ET_NADA,			ID_TAMBO_OBS    ,	TIPO_ETIQ       	,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'0', PRE_VOID,POST_VOID,VAR_VOID,	0},
    {ET_ACIDEZ,			ID_TAMBO_OBS    ,	TIPO_ETIQ       	,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'1', PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_TEMPERATURA,	ID_TAMBO_OBS	,	TIPO_ETIQ       	,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'2', PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_ANTIBIOTICOS,	ID_TAMBO_OBS    ,	TIPO_ETIQ	        ,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'3', PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_AGUADO,			ID_TAMBO_OBS    ,	TIPO_ETIQ	        ,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'4', PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_OTROS,			ID_TAMBO_OBS    ,	TIPO_ETIQ       	,	ID_CAPA_CISTERNA,	ID_LITROS_CARGAR,	'5', PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_1_LITROS,		ID_CAPA_CISTERNA,	TIPO_SINGLEZ_NM_ML	,	ID_TAMBO_OBS    ,	ID_PANTALLA_CARGA,	'1', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_1	,	4},
	{ET_2_LITROS,		ID_CAPA_CISTERNA,	TIPO_SINGLEZ_NM_ML	,	ID_TAMBO_OBS    ,	ID_PANTALLA_CARGA,	'2', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_2	,	4},
	{ET_3_LITROS,		ID_CAPA_CISTERNA,	TIPO_SINGLEZ_NM_ML	,	ID_TAMBO_OBS    ,	ID_PANTALLA_CARGA,	'3', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_3	,	4},
	{ET_4_LITROS,		ID_CAPA_CISTERNA,	TIPO_SINGLEZ_NM_ML	,	ID_TAMBO_OBS    ,	ID_PANTALLA_CARGA,	'4', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_4	,	4},
	{ET_5_LITROS,		ID_CAPA_CISTERNA,	TIPO_SINGLEZ_NM_ML	,	ID_TAMBO_OBS    ,	ID_PANTALLA_CARGA,	'5', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_5	,	4},
	//{'',			ID_DUMMY		,	TIPO_ETIQ		,	0			,	ID_NADA		,0,	ID_TAG_SE_ELIGIO_SIST},
	{ET_1_LITROS,		ID_TRANS_ORIGEN	,	TIPO_SINGLEZ_NM_ML	,	ID_TRANS_DESTINO,	ID_RECORRIDO_I,'1', PRE_VOID,POST_VOID,FLOAT_UTILIZADOS_SIST_1	,	4},
	{ET_2_LITROS,		ID_TRANS_ORIGEN	,	TIPO_SINGLEZ_NM_ML	,	ID_TRANS_DESTINO,	ID_RECORRIDO_I,'2', PRE_VOID,POST_VOID,FLOAT_UTILIZADOS_SIST_2	,	4},
	{ET_3_LITROS,		ID_TRANS_DESTINO,	TIPO_SINGLEZ_NM_ML	,	ID_PANTALLA_CARGA,	ID_TRANS_ORIGEN,'3', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_3	,	4},
	{ET_4_LITROS,		ID_TRANS_DESTINO,	TIPO_SINGLEZ_NM_ML	,	ID_PANTALLA_CARGA,	ID_TRANS_ORIGEN,'4', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_4	,	4},
	{ET_5_LITROS,		ID_TRANS_DESTINO,	TIPO_SINGLEZ_NM_ML	,	ID_PANTALLA_CARGA,	ID_TRANS_ORIGEN,'5', PRE_VOID,POST_VOID,FLOAT_DISPONIBLE_SIST_5	,	4},
	//{'',			ID_NADA			,	0			,	0			,	ID_VOID		,0,	ID_TAG_PANTALLA_DATOS},
	//{'',			ID_DUMMY		,	TIPO_ETIQ		,	0			,	ID_ELIGE_FIN_CARGA,0,	ID_TAG_OPCIONES_POST_CARGA},
	{ET_1_ELEGIR_CIST,	ID_ELIGE_FIN_CARGA	,	TIPO_ETIQ		,	ID_CAPA_CISTERNA,	ID_VOID,'1'			, PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_2_CONT_CARGA,	ID_ELIGE_FIN_CARGA	,	TIPO_ETIQ		,	ID_PANTALLA_CARGA,	ID_VOID,'2'			, PRE_VOID,POST_VOID,VAR_VOID,	0},
	{ET_3_FIN_CARGA	,	ID_ELIGE_FIN_CARGA	,	TIPO_ETIQ		,	ID_RECORRIDO_I,	    ID_VOID,'3'			, PRE_VOID,POST_VOID,VAR_VOID,	0},


    {ET_IO_TEST	,		ID_PAR_IO		,	TIPO_ETIQ			,	ID_PAN_IO,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,VAR_VOID,0	},	
	{ET_TEMP_LECHE	,	ID_PAR_IO		,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_TEMP_LECHE	,	2},
	{ET_OFFSET_LECHE,	ID_PAR_IO		,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_OFFSET_PT100	,	5},
	{ET_TEMP_ACEITE	,	ID_PAR_IO		,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_TEMP_ACEITE	,	2},	
    //{"OFFSET ACEITE",	ID_PAR_IO		,	TIPO_SHORT_SM_SL	,	SHORT_OFFSET_PT100_ACEITE,	5		,0,			},
	{ET_AD_LECH	,		ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_ADC_0		,	4	},
	{ET_AD_IMPR	,		ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_ADC_1		,	4	},
	{ET_AD_ACEI	,		ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_ADC_2		,	4	},
	{ET_AD_DESA	,		ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_ADC_3		,	4	},
    {ET_APAGAR	,		ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_IMP_DESCONECTAR	,	0},	
    {ET_TICKET_CIP,		ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_IMPRIMIR_CIP	,	0},
	{ET_LINEAS_VACIAS,	ID_PAR_IMPRESORA	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_IMP_LINEAS_VACIAS	,	2},
	{ET_CONTRASTE	,	ID_PAR_IMPRESORA	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CONTRASTE_IMPRESORA,	2},
	{ET_IMPRIMIR_PARAM,	ID_PAR_IMPRESORA	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,TEC_VOID,0},
    {ET_IMPR_7XXX	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_IMPRIMIR_INFOS_7XXX	,	0	},
	{ET_DES_PUERTA	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_PUERTA_DESHAB	,	0},
	{ET_DES_PAPEL	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_PAPEL_DESHAB	,	0},
	{ET_DES_TEMP	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_TEMP_DESHAB		,	0},
    {ET_ELIGE_IMP	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_ELIGE_IMP		,	0},
	{ET_PROBAR	,		ID_PAR_TOMAMUESTRAS	,	TIPO_ETIQ			,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	0			,	0	},
    {ET_CANT_PASOS	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_LONGITUD_PULSO_TOMAM,	3		},
    {ET_TIEMPO_ON	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_LONGITUD_PULSO_TOMAM_ATRAS_ON, 3		},	
    {ET_TIEMPO_OFF	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_LONGITUD_PULSO_TOMAM_ATRAS_OFF, 3		},
    {ET_LT_P_COMIENZO,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_L_PARA_TOMAMUESTRA,	3			},
	{ET_CANT_PULSOS	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CANT_PULSOS_TOMAM	,	5			},
	{ET_TIEMPO_CIP	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TMP_CIP_MUESTR	,	5			},
	{ET_CANT_ESTIMADA,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TOMAM_CANTIDAD_ESTIMADA,	4		},
    {ET_TIEMPO_ATRAS,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_T_TOMAMUESTRA_ATRAS,	5			},
    {ET_CAUDAL_MINIMO,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CAUDAL_MINIMO_TOMAMUESTRA,5		},
	{ET_TB_ABIERTA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TB_ON		,	2				},
	{ET_TB_CERRADA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TB_OFF		,	2			},
	{ET_TC_ABIERTA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TC_ON		,	2				},
	{ET_TC_CERRADA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TC_OFF		,	2			},
	{ET_TD_BOMBA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TD_BOMBA		,	2			},
	{ET_TD_DESAI	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TD_DESAIREADOR	,	2		},
	{ET_NIVEL_A	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_UMBRAL_DESAIR_A	,	3			},
	{ET_NIVEL_B	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_UMBRAL_DESAIR_B	,	3			},
	{ET_NIVEL_B1	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_UMBRAL_DESAIR_B1	,	3		},
	{ET_VOL_MAX	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_MAX_L_DESAIR	,	3				},
	{ET_NIVEL_DESAI	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_LITROS_DESAIREADOR,	4		},
	{ET_CALIB_MIN	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_DESAI_CALIB_MIN	,	1		},
	{ET_CALIB_MAX	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_DESAI_CALIB_MAX	,	1		},
	{ET_MIN_MANUAL	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_DESAI_CALIB_MIN	,	4		},
	{ET_MAX_MANUAL	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_DESAI_CALIB_MAX	,	4		},
	{ET_CALIB_RESET	,	ID_PAR_DESAIREADOR	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID			,	0		},
	{ET_TIEMPO_CIP	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TMP_CIP_DESAIREA	,	2		},
	{ET_LTS_OFFSET	,	ID_PAR_DESAIREADOR	,	TIPO_SINGLE_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_LTS_OFFSET_DESAIREADOR,	4	},
    {ET_ELIGE_DESAIREADOR ,	ID_PAR_DESAIREADOR,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_ELIGE_DESAIREADOR	,	1		},
	{ET_TEMP_MAX	,	ID_PAR_PROCESOS		,	TIPO_FLOAT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_TEMP_MAX		,	2			},
	{ET_MIN_L_TEMP	,	ID_PAR_PROCESOS		,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_MIN_L_TEMP_MEDICION,	3		},
	{ET_T_ACEITE_MAX,	ID_PAR_PROCESOS		,	TIPO_FLOAT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_TEMP_ACEITE_MAX	,	2		},
	{ET_Q_0_PRINC,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_Q0_PRINCIPIO	,	3			},
	{ET_Q_0_FINAL,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_Q0_FINAL		,	3			},	
    {ET_Q_0_UMBRAL,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CAUDAL_CERO_UMBRAL,	5		},	
    {ET_T_CIP	,	ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_TIEMPO_MAX_CIP	,	3			},
	{ET_RST_DATOS	,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID,0},
	{ET_RST_LITROS_TM,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID,0},
	{ET_RST_PARAM	,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID,0},
	{ET_CONFIG_PEN1,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID,0},
	{ET_CONFIG_PEN2,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	VAR_VOID,0},
	{ET_BORR_RECOR	,	ID_PAR_BASE_DATOS	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_BORRAR_BASE_RECORRIDO,	3},
	{ET_BORR_TRANS	,	ID_PAR_BASE_DATOS	,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_BORRAR_BASE_TRANS	,	3},
	{ET_HORAS_ELECTRO,	ID_PAR_SIM7000		,	TIPO_SHORT_NM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_HORAS_USO_ELECTRO	,	5},
    {ET_HORAS_BOMBA	,	ID_PAR_SIM7000		,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_HORAS_USO_BOMBA	,	5},
	{ET_SERIE_DISP	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_DISPLAY	,	11	},
	{ET_SERIE_CAUD	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_SERIE_CAUDALIM	,	11	},
    {ET_SERIE_IMP	,	ID_PAR_SIM7000		,	TIPO_SHORT_NM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_SERIAL_IMPRESORA	,5},
    {ET_VER_DISP	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_VERSION_DISPLAY	,	5	},
    {ET_VER_CAUD	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_VERSION_CAUDALIM	,	5},
	//{ET_PASSWORD	,	ID_PASSWORD_PARAM	,	TIPO_PASSWORD_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_PASSWORD_NIVEL_1	,	10},
	{ET_PASSWORD_1	,	ID_PAR_PASSWORD		,	TIPO_TXT_SM_SL		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	TXT_PASSWORD_NIVEL_1	,	10},
	{ET_TEMP	,	ID_CIP			,	TIPO_SINGLE_NM_ML	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	FLOAT_TEMP_LECHE	,	2			},
    {ET_GPRS   	,	ID_PAR_GPRS		,	TIPO_BIT_SM_ML		,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	BIT_GPRS_ON		,	5		},	
    {ET_MODEM   ,   ID_PAR_GPRS     ,   TIPO_TXT_NM_SL      ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,    TXT_IOT_MODEM   ,       10  },
    {ET_MAC     ,   ID_PAR_GPRS     ,   TIPO_TXT_NM_SL      ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,    TXT_IOT_MAC     ,       20  },
    {ET_GPRSPOW ,   ID_PAR_GPRS     ,   TIPO_TXT_NM_SL      ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,    TXT_IOT_GPRS_POW,       20   },
    {ET_GPS     ,   ID_PAR_GPRS     ,   TIPO_TXT_NM_SL      ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,    TXT_IOT_GPS     ,       20   },
    {ET_STATUS 	,   ID_PAR_GPRS     ,   TIPO_TXT_NM_SL      ,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,    TXT_IOT_STATUS  ,       20   },

    {ET_CANT_DIG_REMITO,ID_PAR_BASE_DATOS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CANT_DIG_REMITO	,	2	},
    {ET_CANT_DIG_TAMBO,	ID_PAR_BASE_DATOS	,	TIPO_SHORT_SM_SL	,	ID_NXT_ITEM,	ID_PARAMETROS, TEC_VOID, PRE_VOID,POST_VOID,	SHORT_CANT_DIG_TAMBO	,	2	},
};
struct edicion
{
    bool item_ON=false;
    char pos_digito;
    char val_digito;
    char str_dato[TAM_VAR_TXT];
    ulong ms_parpadea;
    bool digito_ON;
};
#endif