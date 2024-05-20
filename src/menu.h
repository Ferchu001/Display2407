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
#define VAR_VOID 0
#define ID_NXT_ITEM 1
#define ID_BACK_ITEM 2
#define TEC_VOID 255



const MenuItem menu[] = {
//    Etiqueta,    Menu,            tipo de item,   Nivel_Next,     Nivel_Back,    Tecla_Rapida,PreProceso,PostProceso,Variable, CantDigitos,
    {ET_RECORRIDO, ID_PRINCIPAL,    TIPO_ETIQ,      ID_RECORRIDO_D, ID_VOID,       '1',       PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_CIP,       ID_PRINCIPAL,    TIPO_ETIQ,      ID_CIP,         ID_VOID,       '2',       PRE_VOID,POST_VOID,VAR_VOID, 0},
    {ET_REMITO,    ID_RECORRIDO_D,  TIPO_TXT_SM_SL, ID_NXT_ITEM,    ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_REMITO, 16},
    {ET_NRO_LINEA, ID_RECORRIDO_D,  TIPO_TXT_SM_SL, ID_NXT_ITEM,    ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_NUM_LINEA, 2},
    {ET_ACOPLADO,  ID_RECORRIDO_D,  TIPO_TXT_SM_SL, ID_NXT_ITEM,    ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_ACOPLADO, 5},
    {ET_NRO_REC,   ID_RECORRIDO_D,  TIPO_TXT_SM_SL, ID_NXT_ITEM,    ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_NRO_REC, 16},
    {ET_CHOFER,    ID_RECORRIDO_D,  TIPO_TXT_SM_SL, ID_RECORRIDO_I, ID_PRINCIPAL,  TEC_VOID, PRE_VOID,POST_VOID,TXT_CHOFER,  16},    
    {ET_CIP_HORA,  ID_CIP,          TIPO_HORA_NM_SL, ID_VOID,       ID_PRINCIPAL,  TEC_VOID,PRE_VOID,POST_VOID, SHORT_TIEMPO_USO_CIP, 0},
    {ET_CIP_TEMP,  ID_CIP,          TIPO_FLOAT_NM_SL,ID_VOID,       ID_PRINCIPAL,  TEC_VOID,PRE_VOID,POST_VOID, FLOAT_TEMP_LECHE, 0},
    {ET_1_RECEPCION, ID_RECORRIDO_I,TIPO_TXT_SM_SL, ID_TAMBO,       ID_VOID,        '1',      PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_2_TRASVASE, ID_RECORRIDO_I,TIPO_TXT_SM_SL, ID_TAMBO,       ID_VOID,        '2',      PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_4_FIN_RECORR, ID_RECORRIDO_I,TIPO_TXT_SM_SL, ID_TAMBO,       ID_VOID,        '4',      PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_5_TRASBORDO, ID_RECORRIDO_I,TIPO_TXT_SM_SL, ID_TAMBO,       ID_VOID,        '5',      PRE_VOID,POST_VOID, VAR_VOID, 0},
    {ET_UNIDAD	,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_ML		,	TXT_UNIDAD		,	TEC_VOID		,0,			5},
//	{ET_EMPRESA_RN1  ,	ID_INSOLTECH		,	TIPO_TXT_SM_SL_ALFA	,	TXT_NOMBRE_RENGLON_1	,	15		,0,		},	
//	{ET_EMPRESA_RN2  ,	ID_INSOLTECH		,	TIPO_TXT_SM_SL_ALFA	,	TXT_NOMBRE_RENGLON_2	,	15		,0,		},	

	/*{ET_ACOPLADO,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_SL		,	TXT_ACOPLADO		,	5		,0,			},
	{ET_CUENTA	,	ID_PAR_VEHICULO	,	TIPO_TXT_SM_ML		,	TXT_CUENTA		,	5		,0,			},
	{ET_CISTERNAS,	ID_PAR_VEHICULO	,	TIPO_SHORT_SM_ML	,	SHORT_CANTIDAD_CISTERNAS,	1		,0,			},
	{ET_CAPA_1	,	ID_PAR_VEHICULO	,	TIPO_SHORT_SM_ML	,	SHORT_TAMANO_CIST_1	,	5		,0,			},
	{ET_CAPA_2	,	ID_PAR_VEHICULO_2,	TIPO_SHORT_SM_ML	,	SHORT_TAMANO_CIST_2	,	5		,0,			},
	{ET_CAPA_3	,	ID_PAR_VEHICULO_3,	TIPO_SHORT_SM_ML	,	SHORT_TAMANO_CIST_3	,	5		,0,			},
	{ET_CAPA_4	,	ID_PAR_VEHICULO_4,	TIPO_SHORT_SM_ML	,	SHORT_TAMANO_CIST_4	,	5		,0,			},
	{ET_CAPA_5	,	ID_PAR_VEHICULO_5,	TIPO_SHORT_SM_ML	,	SHORT_TAMANO_CIST_5	,	5		,0,			},
	{ET_HORA_ACTUAL	,	ID_PAR_TIEMPOS,	TIPO_HORA_SM_SL		,	FECHA_ACTUAL		,	3		,0,			},
	{ET_FECHA_ACTUAL,	ID_PAR_TIEMPOS,	TIPO_FECHA2_SM_SL	,	FECHA_ACTUAL		,	3		,0,			},	
    {ET_IO_TEST	,	ID_PAR_IO		,	TIPO_ETIQ		,	0			,	ID_NADA		,0,	ID_TAG_TEST_IO	},	
	{ET_TEMP_LECHE	,	ID_PAR_IO	,	TIPO_SINGLE_SM_SL	,	FLOAT_TEMP_LECHE	,	2		,2,			},
	{ET_OFFSET_LECHE,	ID_PAR_IO	,	TIPO_SHORT_SM_SL	,	SHORT_OFFSET_PT100	,	5		,0,			},
	{ET_TEMP_ACEITE	,	ID_PAR_IO	,	TIPO_SINGLE_SM_SL	,	FLOAT_TEMP_ACEITE	,	2		,1,			},	
    {"OFFSET ACEITE",	ID_PAR_IO	,	TIPO_SHORT_SM_SL	,	SHORT_OFFSET_PT100_ACEITE,	5		,0,			},
	{ET_AD_LECH	,	ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	SHORT_ADC_0		,	4		,0,			},
	{ET_AD_IMPR	,	ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	SHORT_ADC_1		,	4		,0,			},
	{ET_AD_ACEI	,	ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	SHORT_ADC_2		,	4		,0,			},
	{ET_AD_DESA	,	ID_PAR_IO		,	TIPO_SHORT_NM_ML	,	SHORT_ADC_3		,	4		,0,			},
	{ET_VOLUMEN	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_VOLUMEN_CAUDALIM	,	5		,1,			},
	{ET_CAUDAL	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_NM_ML	,	FLOAT_CAUDAL		,	5		,0,			},	
	{ET_Q_MINIMO	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_Q_MIN		,	5		,1,			},
    {ET_CORR_BOBINA	,	ID_PAR_CAUDALIMETRO	,       TIPO_SINGLE_NM_SL	,	FLOAT_CORRIENTE_BOBINA	,	12		,4,			},
    {ET_CERO	,	ID_PAR_CAUDALIMETRO	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_ZERO_CAUDALIMETRO},
    {ET_C_ELEC	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_ZEROELECTRODES	,	5		,0,			},
    {ET_K_ELECTRO,		ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_SENSORCONSTANT	,	5		,6,			},
	{ET_K_CABEZAL	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_K_CABEZAL		,	1		,5,			},	
	{ET_PORC_AD	,	ID_PAR_CAUDALIMETRO	,	TIPO_SHORT_NM_ML	,	SHORT_PORCENTAJE_AD	,	3		,0,			},
	{ET_Q_MAXIMO	,	ID_PAR_CAUDALIMETRO	,	TIPO_SHORT_SM_SL	,	SHORT_CAUDAL_MAXIMO	,	3		,0,			},	
	{ET_DECIMAL	,	ID_PAR_CAUDALIMETRO	,	TIPO_BIT_SM_ML		,	BIT_DECIMAL_EN_CARGA	,	0		,0,			},
    {ET_SERIE_CABEZAL,	ID_PAR_CAUDALIMETRO	,	TIPO_TXT_SM_SL		,	TXT_SERIE_CABEZAL	,	12		,1,			},
    {ET_V_REF	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_NM_SL	,	V_REF_CAUDALIMETRO	,	12		,0,			},
    {ET_UMBRAL_AIRE	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_CAUDALIM_UMBRAL_AIRE,	5		,0,			},
    {ET_IBOB_MAX	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_IBOBINA_MAX	,	5		,0,			},
    {ET_IBOB_MIN	,	ID_PAR_CAUDALIMETRO	,	TIPO_SINGLE_SM_SL	,	FLOAT_IBOBINA_MIN	,	5		,0,			},
	{ET_INVERTIR	,	ID_PAR_CAUDALIMETRO	,	TIPO_BIT_SM_ML		,	BIT_INVERSION_CAUDALIMETRO,	2		,0,			},
    {ET_APAGAR	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_IMP_DESCONECTAR	,	0		,0,			},	
    {ET_TICKET_CIP,		ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_IMPRIMIR_CIP	,	0		,0,			},
	{ET_LINEAS_VACIAS,	ID_PAR_IMPRESORA	,	TIPO_SHORT_SM_SL	,	SHORT_IMP_LINEAS_VACIAS	,	2		,0,			},
	{ET_CONTRASTE	,	ID_PAR_IMPRESORA	,	TIPO_SHORT_SM_ML	,	SHORT_CONTRASTE_IMPRESORA,	2		,0,			},
	{ET_IMPRIMIR_PARAM,	ID_PAR_IMPRESORA	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_IMPRESION_PARAMETROS},
    {ET_IMPR_7XXX	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_IMPRIMIR_INFOS_7XXX	,	2		,1,			},
	{ET_DES_PUERTA	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_PUERTA_DESHAB	,	2		,0,			},
	{ET_DES_PAPEL	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_PAPEL_DESHAB	,	2		,0,			},
	{ET_DES_TEMP	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_TEMP_DESHAB		,	2		,0,			},
    {ET_ELIGE_IMP	,	ID_PAR_IMPRESORA	,	TIPO_BIT_SM_ML		,	BIT_ELIGE_IMP		,	2		,0,			},
	{ET_PROBAR	,	ID_PAR_TOMAMUESTRAS	,	TIPO_ETIQ		,	0			,	0		,0,	ID_TAG_PROBAR_TOMAMUESTRAS},
    {ET_CANT_PASOS	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_LONGITUD_PULSO_TOMAM,	3		,0,			},
    {ET_TIEMPO_ON	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_LONGITUD_PULSO_TOMAM_ATRAS_ON, 3		,0,			},	
    {ET_TIEMPO_OFF	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_LONGITUD_PULSO_TOMAM_ATRAS_OFF, 3		,0,			},
    {ET_LT_P_COMIENZO,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_L_PARA_TOMAMUESTRA,	3		,0,			},
	{ET_CANT_PULSOS	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_CANT_PULSOS_TOMAM	,	5		,0,			},
	{ET_TIEMPO_CIP	,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_TMP_CIP_MUESTR	,	5		,0,			},
	{ET_CANT_ESTIMADA,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_TOMAM_CANTIDAD_ESTIMADA,	4		,0,			},
    {ET_TIEMPO_ATRAS,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_T_TOMAMUESTRA_ATRAS,	5		,0,			},
    {ET_CAUDAL_MINIMO,	ID_PAR_TOMAMUESTRAS	,	TIPO_SHORT_SM_SL	,	SHORT_CAUDAL_MINIMO_TOMAMUESTRA,5		,0,			},
	{ET_TB_ABIERTA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TB_ON		,	2		,0,			},
	{ET_TB_CERRADA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TB_OFF		,	2		,0,			},
	{ET_TC_ABIERTA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TC_ON		,	2		,0,			},
	{ET_TC_CERRADA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TC_OFF		,	2		,0,			},
	{ET_TD_BOMBA	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TD_BOMBA		,	2		,0,			},
	{ET_TD_DESAI	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TD_DESAIREADOR	,	2		,0,			},
	{ET_NIVEL_A	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_UMBRAL_DESAIR_A	,	3		,0,			},
	{ET_NIVEL_B	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_UMBRAL_DESAIR_B	,	3		,0,			},
	{ET_NIVEL_B1	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_UMBRAL_DESAIR_B1	,	3		,0,			},
	{ET_VOL_MAX	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_NM_ML	,	SHORT_MAX_L_DESAIR	,	3		,0,			},
	{ET_NIVEL_DESAI	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_NM_ML	,	SHORT_LITROS_DESAIREADOR,	4		,0,			},
	{ET_CALIB_MIN	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	SHORT_DESAI_CALIB_MIN	,	1		,0,	ID_TAG_DESAI_CALIB_MIN	},
	{ET_CALIB_MAX	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	SHORT_DESAI_CALIB_MAX	,	1		,0,	ID_TAG_DESAI_CALIB_MAX	},
	{ET_MIN_MANUAL	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	SHORT_DESAI_CALIB_MIN	,	4		,0,			},
	{ET_MAX_MANUAL	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	SHORT_DESAI_CALIB_MAX	,	4		,0,			},
	{ET_CALIB_RESET	,	ID_PAR_DESAIREADOR	,	TIPO_ETIQ		,	0			,	0		,0,	ID_TAG_DESAI_CALIB_RESET},
	{ET_TIEMPO_CIP	,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_ML	,	SHORT_TMP_CIP_DESAIREA	,	2		,0,			},
	{ET_LTS_OFFSET	,	ID_PAR_DESAIREADOR	,	TIPO_SINGLE_SM_SL	,	FLOAT_LTS_OFFSET_DESAIREADOR,	4		,1,			},
    {ET_ELIGE_DESAIREADOR ,	ID_PAR_DESAIREADOR	,	TIPO_SHORT_SM_SL	,	SHORT_ELIGE_DESAIREADOR	,	1		,0,			},
	{ET_TEMP_MAX	,	ID_PAR_PROCESOS		,	TIPO_FLOAT_SM_ML	,	FLOAT_TEMP_MAX		,	2		,0,			},
	{ET_MIN_L_TEMP	,	ID_PAR_PROCESOS		,	TIPO_SHORT_SM_SL	,	SHORT_MIN_L_TEMP_MEDICION,	3		,0,			},
//	{ET_TEMP_ACEI	,	ID_PAR_PROCESOS		,	TIPO_BIT_SM_ML		,	BIT_HABILITA_TEMP_ACEITE,	0		,0,			},	
	{ET_T_ACEITE_MAX,	ID_PAR_PROCESOS		,	TIPO_FLOAT_SM_SL	,	FLOAT_TEMP_ACEITE_MAX	,	2		,0,			},
	{ET_Q_0_PRINC,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	SHORT_Q0_PRINCIPIO	,	3		,0,			},
	{ET_Q_0_FINAL,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	SHORT_Q0_FINAL		,	3		,0,			},	
    {ET_Q_0_UMBRAL,		ID_PAR_PROCESOS		,	TIPO_SHORT_SM_SL	,	SHORT_CAUDAL_CERO_UMBRAL,	5		,0,			},	
    {ET_T_CIP	,	ID_PAR_PROCESOS		,	TIPO_SHORT_SM_ML	,	SHORT_TIEMPO_MAX_CIP	,	3		,0,			},
	{ET_RST_DATOS	,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_BORRAR_DATOS},
	{ET_RST_LITROS_TM,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_RESET_LITROS},
	{ET_RST_PARAM	,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_RESET_CONFIG},
	{ET_CONFIG_PEN1,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_CONFIG_A_PEN},
	{ET_CONFIG_PEN2,	ID_PAR_BASE_DATOS	,	TIPO_ETIQ		,	0			,	ID_PARAMETROS	,0,	ID_TAG_CONFIG_DESDE_PEN},
	{ET_BORR_RECOR	,	ID_PAR_BASE_DATOS	,	TIPO_BIT_SM_ML		,	BIT_BORRAR_BASE_RECORRIDO,	3		,0,			},
	{ET_BORR_TRANS	,	ID_PAR_BASE_DATOS	,	TIPO_BIT_SM_ML		,	BIT_BORRAR_BASE_TRANS	,	3		,0,			},
	{ET_BORR_PEN	,	ID_PAR_BASE_DATOS	,	TIPO_BIT_SM_ML		,	BIT_BORRAR_BASE_PEN_DRIVE,	3		,0,			},
	{ET_CONT_DISP	,	ID_PAR_SIM7000		,	TIPO_SHORT_SM_ML	,	SHORT_CONTRASTE_DISPLAY	,	1		,0,			},
	{ET_HORAS_ELECTRO,	ID_PAR_SIM7000		,	TIPO_SHORT_NM_SL	,	SHORT_HORAS_USO_ELECTRO	,	5		,0,			},
    {ET_HORAS_BOMBA	,	ID_PAR_SIM7000		,	TIPO_SHORT_SM_SL	,	SHORT_HORAS_USO_BOMBA	,	5		,0,			},
	{ET_SERIE_DISP	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	TXT_SERIE_DISPLAY	,	11		,0,			},
	{ET_SERIE_CAUD	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	TXT_SERIE_CAUDALIM	,	11		,0,			},
    {ET_SERIE_IMP	,	ID_PAR_SIM7000		,	TIPO_SHORT_NM_SL	,	SHORT_SERIAL_IMPRESORA	,	5		,0,			},
    {ET_VER_DISP	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	TXT_VERSION_DISPLAY	,	5		,0,			},
    {ET_DISPLAY_NUEVO,	ID_PAR_SIM7000		,	TIPO_BIT_SM_ML		,	BIT_DISPLAY_NUEVO       ,	0		,0,			},	
    {ET_VER_CAUD	,	ID_PAR_SIM7000		,	TIPO_TXT_NM_SL		,	TXT_VERSION_CAUDALIM	,	5		,0,			},
	{ET_BEEPER	,	ID_PAR_SIM7000		,	TIPO_BIT_SM_ML		,	BIT_BEEPER_ON		,	5		,0,			},
	{ET_PASSWORD	,	ID_PASSWORD_PARAM	,	TIPO_PASSWORD_SL	,	TXT_PASSWORD_NIVEL_1	,	10		,0,			},
	{ET_PASSWORD_1	,	ID_PAR_PASSWORD		,	TIPO_TXT_SM_SL		,	TXT_PASSWORD_NIVEL_1	,	10		,0,			},
	{ET_PASSWORD_2	,	ID_PAR_PASSWORD+NIVEL_2	,	TIPO_TXT_SM_SL		,	TXT_PASSWORD_NIVEL_2	,	10		,0,			},
	{ET_PASSWORD_3	,	ID_PAR_PASSWORD+NIVEL_3	,	TIPO_TXT_SM_SL		,	TXT_PASSWORD_NIVEL_3	,	10		,0,			},	
	{ET_TEMP	,	ID_CIP			,	TIPO_SINGLE_NM_ML	,	FLOAT_TEMP_LECHE	,	2		,1,			},
	{ET_0_VACIA_DESAI,	ID_FUNCIONES_PRINCIPAL	,	TIPO_ETIQ		,	0			,	ID_FUNCIONES_PRINCIPAL,0, ID_TAG_FUNCION_VACIAR	},
	{ET_1_REIMPRIMIR,	ID_FUNCIONES_PRINCIPAL	,	TIPO_ETIQ		,	0			,	ID_FUNCIONES_PRINCIPAL,0,		},
	{ET_2_OBSERVACION,	ID_FUNCIONES_PRINCIPAL	,	TIPO_ETIQ		,	0			,	ID_OBSERVACION	,0,			},
	{"3-ULT CARGA"	,	ID_FUNCIONES_PRINCIPAL_1,	TIPO_ETIQ	        ,	0			,	ID_FUNCIONES_PRINCIPAL,0, ID_TAG_ULT_CARGA	},
	{"4-PARAMETROS"	,	ID_FUNCIONES_PRINCIPAL	,	TIPO_ETIQ	        ,	0			,	ID_PASSWORD_PARAM,0,	ID_TAG_FUNCION_PARAMETROS},
    {"TAMBERO"	,	ID_DECOMISADA		,	TIPO_TXT_SM_SL		,	TXT_TAMBERO		,	16		,0,			},
	{"LITROS"	,	ID_DECOMISADA		,	TIPO_SINGLE_SM_SL	,	FLOAT_CANTIDAD_A	,	3		,0,			},
	{"INSOLTECH"	,	ID_PARAMETROS+NIVEL_3	,	TIPO_ETIQ		,	0			,	ID_INSOLTECH	,0,			},
	{ET_SERIE_DISP	,	ID_INSOLTECH	        ,	TIPO_TXT_SM_SL		,	TXT_SERIE_DISPLAY	,	11		,0,			},
	{ET_FECHA_DISP	,	ID_INSOLTECH		,	TIPO_TXT_NM_SL		,	TXT_FECHA_DISPLAY	,	8		,0,			},
	{ET_VER_DISP	,	ID_INSOLTECH		,	TIPO_TXT_NM_SL		,	TXT_VERSION_DISPLAY	,	5		,0,			},
	{ET_SERIE_CAUD	,	ID_INSOLTECH		,	TIPO_TXT_SM_SL		,	TXT_SERIE_CAUDALIM	,	11		,0,			},
	{ET_FECHA_CAUD	,	ID_INSOLTECH		,	TIPO_TXT_NM_SL		,	TXT_FECHA_CAUDALIM	,	8		,0,			},
	{ET_VER_CAUD	,	ID_INSOLTECH		,	TIPO_TXT_NM_SL		,	TXT_VERSION_CAUDALIM	,	5		,0,			},
    {ET_SERIE_IMP	,	ID_INSOLTECH		,	TIPO_SHORT_SM_SL	,	SHORT_SERIAL_IMPRESORA	,	5		,0,			},
	{ET_SERIE_EQUIPO,	ID_INSOLTECH		,	TIPO_TXT_SM_SL		,	TXT_SERIE_EQUIPO	,	11		,0,			},
	{ET_HORAS_ELECTRO,	ID_INSOLTECH		,	TIPO_SHORT_SM_SL	,	SHORT_HORAS_USO_ELECTRO	,	5		,0,			},	
    {ET_LEC_BARRAS   ,	ID_INSOLTECH		,	TIPO_BIT_SM_ML		,	BIT_LECTOR_BARRAS_ON	,	5		,0,			},	
    {ET_T_MICRO	   ,	ID_INSOLTECH		,	TIPO_SHORT_NM_ML	,	SHORT_TEMP_TEXAS	,	4		,0,			},
	{ET_BT_SERVICE	 ,	ID_INSOLTECH		,	TIPO_BIT_SM_ML		,	BIT_BLUETOOTH_SERVICE	,	2		,0,			},
	{ET_ECOLAT       ,	ID_INSOLTECH		,	TIPO_BIT_SM_ML		,	BIT_ECOLAT		,	5		,0,		},
	{ET_PUNTA_DEL_AGUA,	ID_INSOLTECH		,	TIPO_BIT_SM_ML		,	BIT_PUNTA_DEL_AGUA	,	5		,0,		},	
	{ET_BT_CEL       ,	ID_PAR_BLUETOOTH	,	TIPO_BIT_SM_ML		,	BIT_BT_CEL		,	5		,0,		},	
	{ET_BT_PAIR      ,	ID_PAR_BLUETOOTH	,	TIPO_TXT_SM_SL_ALFA	,	TXT_BT_ADDRESS		,	13		,0,		},
    {ET_GPRS    	 ,	ID_PAR_GPRS		,	TIPO_BIT_SM_ML		,	BIT_GPRS_ON		,	5		,0,			},	
    {ET_MODEM       ,       ID_PAR_GPRS             ,       TIPO_TXT_NM_SL          ,       TXT_IOT_MODEM           ,       10               ,0,                   0},
    {ET_MAC         ,       ID_PAR_GPRS            ,       TIPO_TXT_NM_SL            ,       TXT_IOT_MAC             ,       20               ,0,                   0},
    {ET_GPRSPOW     ,       ID_PAR_GPRS            ,       TIPO_TXT_NM_SL          ,       TXT_IOT_GPRS_POW      ,       20                ,0,                   0},
    {ET_GPS         ,       ID_PAR_GPRS            ,       TIPO_TXT_NM_SL            ,       TXT_IOT_GPS             ,       20               ,0,                   0},
    {ET_STATUS     ,       ID_PAR_GPRS            ,       TIPO_TXT_NM_SL          ,       TXT_IOT_STATUS      ,       20                ,0,                   0},       

    {ET_CANT_DIG_REMITO,	ID_PAR_BASE_DATOS	,	TIPO_SHORT_SM_SL	,	SHORT_CANT_DIG_REMITO	,	2		,0,			},
    {ET_CANT_DIG_TAMBO,	ID_PAR_BASE_DATOS	,	TIPO_SHORT_SM_SL	,	SHORT_CANT_DIG_TAMBO	,	2		,0,			},
*/
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