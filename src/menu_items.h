#ifndef MENU_ITEMS_H
#define MENU_ITEMS_H

#define MAX_ITEM 231 // cantidad de items de menu_para3


//-----------indices de cada matriz de variables-----------------
#define TXT_REMITO 0
#define TXT_ACOPLADO 1 // remolque =
#define TXT_TAMBERO 2  // el numero de tambero es de 4 digitos, extraidos del codigo de barras de 16 digitos (digitos 7 al 10) por ejemplo en el codigo 0315103929024078 el numero de tambero es 3929
#define TXT_UNIDAD 3   // 6 digitos, tambien llamado numero de camion, identifica al camion truckno
#define TXT_CUENTA 4   // 9 digitos numero de chofer DRIVERNO
#define TXT_RECORRIDO 5
#define TXT_PASSWORD_NIVEL_1 6  // password usado en el menu de parametros
#define TXT_VERSION_DISPLAY 7   // version de soft del display
#define TXT_SERIE_DISPLAY 8     // numero de serie del caudalimetro
#define TXT_FECHA_DISPLAY 9     // fecha en la que se edito el numero de serie del display
#define TXT_VERSION_CAUDALIM 10 // version de soft del caudalimetro
#define TXT_SERIE_CAUDALIM 11   // numero de serie del display
#define TXT_FECHA_CAUDALIM 12   // fecha en la que se edito el numero de serie del caudalimetro
#define TXT_PASSWORD_NIVEL_2 13 //
#define TXT_PASSWORD_NIVEL_3 14 //
#define TXT_SERIE_CABEZAL 15    // en este campo se guarda el numero de serie del cabezal que se utiliza con el caudalimetro
#define TXT_NOMBRE_RENGLON_1 16
#define TXT_NOMBRE_RENGLON_2 17
#define TXT_BT_ADDRESS 18 // Direccion del dispositivo BLuetoooth para transferir archivo
#define TXT_SERIE_EQUIPO 19
#define TXT_NUM_LINEA 20
#define TXT_MUESTRA 21
#define TXT_NRO_REC 22 // Nro de recorrido entrado por chofer por teclado con cada nuevo recorrido
#define TXT_CHOFER 23  // Nro de chofer entrado por chofer por teclado con cada nuevo recorrido
#define TXT_REMITO_TRASBORDO 24
#define TXT_NRO_TRASBORDO 25
#define TXT_IOT_MODEM 26
#define TXT_IOT_MAC 27
#define TXT_IOT_GPRS_POW 28
#define TXT_IOT_GPS 29
#define TXT_IOT_STATUS 30

#define MNU_TAM_VAR_TXT 31 // OJO *********************************************Modificar este cada vez que se agrega una variable

#define SHORT_ELEC_MEMORIA_CIST 0 // puede valer 1,2 o 3 (dependiendo si es compartimento ABC)
#define SHORT_ELECCION_ORIGEN 1   // idem anterior, pero se usa solo en trasvase para indicar la cisterna de origen
#define SHORT_KILOMETROS_RECORRIDOS 2
#define SHORT_LITROS_DESAIREADOR 3    //(l)cantidad de litros en el desaireador
#define SHORT_UMBRAL_DESAIR_B 4       //(l)umbral casi superior del desaireador
#define SHORT_UMBRAL_DESAIR_A 5       //(l)umbral inferior del desaireador
#define SHORT_FACTOR_DESAIREADOR 6    // factor que divide la entrada de AD
#define SHORT_COMPARTIMENTO_A 7       // tiene el numero de la 1er cisterna donde se carga
#define SHORT_COMPARTIMENTO_B 8       // tiene el numero de la 2da cisterna donde se carga
#define SHORT_COMPARTIMENTO_C 9       // tiene el numero de la 3er cisterna donde se carga
#define SHORT_TMP_CIP_DESAIREA 10     //(seg)tiempo en segundos desde el encendido del degasador, hasta que se apaga
#define SHORT_TMP_CIP_MUESTR 11       //(seg)tiempo en segundos paraa que el sacamuestras no es activado durante la limpieza cip
#define SHORT_TMP_CIP_TOTAL 12        //(seg)tiempo en segundos del ciclo de CIP
#define SHORT_DESAI_CALIB_MIN 13      // nivel de desaireador qeu se considera como vacio en codigos de ADC
#define SHORT_CANTIDAD_CISTERNAS 14   // cantidad de cisternas con las que cuenta el camion
#define SHORT_FACTOR_KM 15            // cantidad de pulsos por kilometro
#define SHORT_MIN_L_TEMP_MEDICION 16  //(l) cantidad de litros minimos necesarios para empezar a tomar como valida la temperatura medida
#define SHORT_SEGUNDOS_BOMBA 17       //(seg) cantidad de segundos de uso de la bomba (se usa para contar las horas de uso)
#define SHORT_DESAI_CALIB_MAX 18      // nivel de desaireador qeu se considera como vacio en codigos de ADC
#define SHORT_TIEMPO_MAX_CIP 19       //(seg) tiempo despues del cual se considera finalizado el CIP
#define SHORT_LONGITUD_PULSO_TOMAM 20 //(mseg) logitud del pulso del tomamuestra
#define SHORT_CANT_PULSOS_TOMAM 21    // cantidad de pulsos que se le da al tomamuestra durante la recepcion
#define SHORT_UMBRAL_DESAIR_B1 22     //(l)umbral superior del desaireador
#define SHORT_TAMANO_CIST_1 23        //(l)indica el tamaño de la cisterna en cuestion
#define SHORT_TAMANO_CIST_2 24
#define SHORT_TAMANO_CIST_3 25
#define SHORT_TAMANO_CIST_4 26
#define SHORT_TAMANO_CIST_5 27
#define SHORT_PROM_TEMP_CUENTA 28
#define SHORT_HORAS_USO_BOMBA 29 //(horas) cantidad de horas de uso de la bomba
// #define SHORT_VELOCIDAD_MAXIMA    30        //(km/h) velocidad maxima a partir de la cual se genera un codigo de error
#define SHORT_Q0_FINAL 31                       //(s) tiempo despues del cual la medicion es terminada cuando el flujo es 0
#define SHORT_Q0_PRINCIPIO 32                   //(s) tiempo despues del cual la medicion es terminada cuando el flujo es 0 al principio del procesos
#define SHORT_IMP_LINEAS_VACIAS 33              // cantidad de lineas en blanco que inserta la impresora despues de una impresion
#define SHORT_L_PARA_TOMAMUESTRA 34             //(l) cantidad de litros que tienen que pasar antes de empezar a usar el tomamuestras
#define SHORT_TOMAM_CANTIDAD_ESTIMADA 35        //(l) cantidad de litros que se toman como estimados cuando no se tiene informacion del tambo en cuestion
#define SHORT_ADC_0 36                          // ultimo valor del AD que esta en el canal 0
#define SHORT_ADC_1 37                          // ultimo valor del AD que esta en el canal 1
#define SHORT_ADC_2 38                          // ultimo valor del AD que esta en el canal 2
#define SHORT_ADC_3 39                          // ultimo valor del AD que esta en el canal 3
#define SHORT_STATUS 40                         // informacion sobre el estado de la recepcion
#define SHORT_CAUDAL_MAXIMO 41                  // Aca se guarda el caudal maximo /1000
#define SHORT_MAX_L_DESAIR 42                   //(l) capacidad total en litros del desaireador
#define SHORT_TB_OFF 43                         //(s) cantidad de segundos en los que esta prendido el desaireador estado B
#define SHORT_TB_ON 44                          //(s) cantidad de segundos en los que esta apagado el desaireador estado B
#define SHORT_TC_OFF 45                         //(s) cantidad de segundos en los que esta prendido el desaireador estado C
#define SHORT_TC_ON 46                          //(s) cantidad de segundos en los que esta apagado el desaireador estado C
#define SHORT_TD_BOMBA 47                       //(s) cantidad de segundos que tarda en apagar la bomba en el estado D
#define SHORT_TD_DESAIREADOR 48                 //(s) cantidad de segundos que tarda en apagar la el desaireador en el estado D
#define SHORT_SERIAL_IMPRESORA 49               // numero de serie de la impresora
#define SHORT_NIVEL_USUARIO_ACTUAL 50           // indica el nivel de usuario que esta actualmente editando el menu de parametros
#define SHORT_CONTRASTE_IMPRESORA 51            // numero de 1 a 10 que define el contraste de la imrpesora
#define SHORT_NIVEL_SEGURIDAD 52                // parte de menu.c define el nivel de seguridad
#define SHORT_PORCENTAJE_AD 53                  // parametro del caudalimetro, indica el porcentaje de ADC utilizado
#define SHORT_MUESTRAS_TOMADAS 54               // aca guardo la cantidad de muestras tomadas por el tomamuestras (este dato lo transmite el caudalimetro)
#define SHORT_OFFSET_PT100 55                   // offset de la medicion de la pt100 en ohm*100
//#define SHORT_OFFSET_PT100_ACEITE 56            // offset de la medicion de la pt100 en ohm*100 del aceite
//#define SHORT_CONTRASTE_DISPLAY 57              // contraste del display
#define SHORT_HORAS_USO_ELECTRO 58              //(horas)cantidad de horas que tiene en uso el equipo sin hacerle mantenimiento
#define SHORT_T_TOMAMUESTRA_ATRAS 59            //(mseg)milisegundos que el tomamuestra debe andar patras
#define SHORT_DB_CONTADOR_RUTA 60               // contador de ruta que se usa en la base de datos
#define SHORT_VERSION_FIRMWARE 61               //
#define SHORT_TEMP_TEXAS 62                     // temperatura tomada del sensor interior del texas
#define SHORT_CAUDAL_MINIMO_TOMAMUESTRA 63      // caudal minimo necesario para que ande el tomamuestras
#define SHORT_CAUDAL_CERO_UMBRAL 64             // Valor de caudal a partir del cual se interpreta que el caudal es distinto de cero
#define SHORT_CANT_DIG_REMITO 65                // Fija la cantidad exacta de digitos de Remito que se van a aceptar.
#define SHORT_LONGITUD_PULSO_TOMAM_ATRAS_ON 66  // (ms) tiempo ON  del pulso del tomamuestras hacia atras
#define SHORT_LONGITUD_PULSO_TOMAM_ATRAS_OFF 67 // (ms) tiempo OFF  del pulso del tomamuestras hacia atras
#define SHORT_CANT_DIG_TAMBO 68
#define SHORT_ELIGE_DESAIREADOR 69
#define SHORT_OBS_TAMBO 70
#define SHORT_IOT_GPRS_POW 71
#define SHORT_TIEMPO_USO_CIP 72
#define MNU_TAM_VAR_SHORT_IOT 73
#define MNU_TAM_VAR_SHORT 74 // OJO *********************************************Modificar este cada vez que se agrega una variable

#define FLOAT_DISPONIBLE_SIST_1 0 //(l)cantidad de litros disponibles en la cisterna 1
#define FLOAT_DISPONIBLE_SIST_2 1
#define FLOAT_DISPONIBLE_SIST_3 2
#define FLOAT_DISPONIBLE_SIST_4 3
#define FLOAT_DISPONIBLE_SIST_5 4
#define FLOAT_UTILIZADOS_SIST_1 5 //(l)cantidad de litros utilizados en la cisterna 1
#define FLOAT_UTILIZADOS_SIST_2 6
#define FLOAT_UTILIZADOS_SIST_3 7
#define FLOAT_UTILIZADOS_SIST_4 8
#define FLOAT_UTILIZADOS_SIST_5 9
#define FLOAT_LITROS_A_CARGAR 10        //(l)cantidad estimada de litros a cargar (se usa para el chupamuestras)
#define FLOAT_TEMP_LECHE 11             //(ºC)temperatura de la leche
#define FLOAT_TEMP_ACEITE 12            //(ºC)temperatura del aceite de la bomba
#define FLOAT_CANTIDAD_A 13             //(l)cantidad de leche en la cisterna A (el numero es el que tiene cargado compartimento A)
#define FLOAT_CANTIDAD_B 14             //(l)cantidad de leche en la cisterna B (el numero es el que tiene cargado compartimento B)
#define FLOAT_CANTIDAD_C 15             //(l)cantidad de leche en la cisterna C (el numero es el que tiene cargado compartimento C)
#define FLOAT_TOTAL_L_RECORR 16         //(l)cantidad total de litros del recorrido (desde arranque hasta fin)
#define FLOAT_TEMP_MAX 17               //(ºC)temperatura maxima que puede tomar la leche
#define FLOAT_TEMP_MAX_ALCANZADA 18     //(ºC)indica la temperatura maxima alcanzada durante la carga
#define FLOAT_TEMP_MIN_ALCANZADA 19     //(ºC)indica la temperatura minima alcanzada durante la carga
#define FLOAT_TEMP_ACEITE_MAX 20        //(ºC)temperatura del aceite de la bomba maxima
#define FLOAT_TEMP_LECHE_SUMA 21        //(ºC)temperatura del aceite de la bomba maxima
#define FLOAT_CAUDAL 22                 //(l/h) caudal
#define FLOAT_SENSORCONSTANT 23         // PARAMETRO DEL CAUDALIMETRO
#define FLOAT_ZEROELECTRODES 24         // PARAMETRO DEL CAUDALIMETRO
#define FLOAT_VOLUMEN_CAUDALIM 25       // VOLUMEN QUE ME ENVIA EL CAUDALIMETRO
#define FLOAT_Q_MIN 26                  // caudal minimo (parametrod del caudalimetro)
#define FLOAT_TEMP_LECHE_PROMEDIO 27    // promedio de la temperatura, se recalcula cuando se frena la carga = FLOAT_TEMP_LECHE_SUMA/
#define FLOAT_CORRIENTE_BOBINA 28       // parametro del caudalimtro, indica la corriente que circula por las bobinas
#define FLOAT_K_CABEZAL 29              // canal auxiliar con la tension medida por el caudalimetro
#define V_REF_CAUDALIMETRO 30           // tension de referencia que manda el caudalimetro
#define FLOAT_CAUDALIM_UMBRAL_AIRE 31   // umbral de deteccion de electrodos al aire.
#define FLOAT_IBOBINA_MAX 32            // Valor maximo que se tolera para corriente de bobina
#define FLOAT_IBOBINA_MIN 33            // Valor minimo para corriente de bobina.
#define VOLUMEN_DESAIREADOR_INICIO 34   // Valor en litros del desaireador al comenzar la carga
#define VOLUMEN_DESAIREADOR_FIN 35      // Valor en litros del desaireador al terminar la carga
#define FLOAT_LTS_OFFSET_DESAIREADOR 36 // Valor de offset inicial del primer reedswitch del desaireador
#define FLOAT_VOLUMEN_TOTAL 37
#define MNU_TAM_VAR_FLOAT 39 // OJO   *********************************************Modificar este cada vez que se agrega una variable

#define FECHA_ACTUAL 0         // fecha y hora actual
#define FECHA_ARRANQUE 1       // hora de arranque
#define FECHA_FIN 2            // hora de finalizacion
#define FECHA_ARRANQUE_RECEP 3 // fecha de arranque de la recepcion
#define FECHA_FIN_RECEP 4      // idem fin
#define MNU_TAM_VAR_FECHA 5    // OJO   *********************************************Modificar este cada vez que se agrega una variable

#define BIT_CISTERNA 0      // indica si la cisterna esta encendida
#define BIT_VALVULA_DESAI 1 // Activa la valvula de escape del degasificador
#define BIT_TOMA_MUESTRA 2  // activa el piston tomamuestra
// #define BIT_SANCOR                3   //Indica que tiene que usar todo en Modo SANCOR.
#define BIT_PUNTA_DEL_AGUA 3
#define BIT_TOMA_MUESTRA2 4          // Control Tomamuestras 2
#define BIT_BT_CEL 5                 // Activa la nueva transmision por Bluetooth para el celular.
#define BIT_INVERSION_CAUDALIMETRO 6 // le indica al caudalimetro quE se le esta dando bola a los valores de volumen y caudal (esto se pone en cero para que el caudalimetro haga tareas de housekeeping)
#define BIT_NO_ACTUALIZAR_VOL 7      // mientras este bit este en uno el caudalimetro no va a medir volumen ni caudal (esto es para que no haga locuras cuando tiene los electrodos al aire)
#define BIT_PUERTA_DESHAB 8          // indica si esta deshabilitada la deteccion de puerta abierta en la impresora
#define BIT_PAPEL_DESHAB 9           // indica si esta deshabilitada la deteccion de papel en la impresora
#define BIT_TEMP_DESHAB 10           // indica si esta deshabilitada la deteccion de temperatura alta en la impresora
#define BIT_IMP_DESCONECTAR 11       // indica que la impresora esta desconectada y no debe usarse
#define BIT_DISPLAY_NUEVO 12         // Display Blanco (Esto corre el offset lateral del display
#define BIT_BLUETOOTH_SERVICE 13     // si esta en si, se habilita la conexion bluetooth para recolectar datos
#define BIT_IMPRIMIR_CIP 14          // indica si se imprime el tiket de limpieza
#define BIT_ERROR_COMM 15            // indica que hay error de comunicacion con el caudalimetro
#define BIT_LLAVE 16                 // chamuyo para hacer andar bien un cacho de codigo
#define BIT_ECOLAT 17                // indica que debe usar las opciones de ECOLAT
#define BIT_INDICA_RECEPCION 18      // este bit se usa para debuguear con el programa bt_service, lo que hace es indicar cuando se esta en una recepcion y cuando termina
#define BIT_MANUAL 19                // indica si la bomba esta en modo manual (si = 0 entonces es automatica)
#define BIT_CAUD_SATURA_ADC_MAX 20   // indica que saturo el ADC del caudalimetro
#define BIT_CAUD_SATURA_ADC_MIN 21   // indica que saturo el ADC del caudalimetro
#define BIT_GPRS_ON 22               // indica si el GPRS esta encendido
#define BIT_BEEPER_ON 23             // indica si debe sonar el beeper
#define BIT_DECIMAL_EN_CARGA 24      // indica si se muestra un digito decimal en la pantalla de carga(por default, no)
// #define BIT_BLUETOOTH_ON          25
#define BIT_ELIGE_IMP 25
#define BIT_LECTOR_BARRAS_ON 26
#define BIT_IMPRIMIR_INFOS_7XXX 27   // indica si se imprimen o no los codigos de error 7xxx
#define BIT_BORRAR_BASE_RECORRIDO 28 // indica si la base de datos se borra al comienzo de cada recorrido o no
#define BIT_BORRAR_BASE_TRANS 29     // indica si la base de datos se borra despues de una transmision exitosa*/
#define BIT_CONTROL_AUTO 30          // indica que el control de la carga de IO es automatico
#define BIT_BORRAR_BASE_PEN_DRIVE 31 // si esta en "si" indica que al terminar de descargar los datos al pen drive se pueden borrar los datos locales

//------------------------------------------------

//-----------TIPOS DE ITEMS-------------------
#define TIPO_NO_DIBUJAR 0
#define TIPO_ETIQ 1 // el item es una etiqueta simple que contiene submenu (cuando se le da enter, padre[0]=item_actual)
// #define TIPO_ETIQ_TITULO    2   //esta etiqueta hace las veces de titulo de menu, se muestra resaltada pero no se permite seleccionarla

#define TIPO_FLOAT_NM_ML 2 // FLOAT, SU=sin unidades, NM=no modificable, ML=misma linea
#define TIPO_FLOAT_NM_DL 3 // idem, DL= diferente linea (se imprime en el sector para tal motivo)
#define TIPO_FLOAT_SM_ML 4 // FLOAT, SU=sin unidades, SM=si modificable, ML=misma linea
#define TIPO_FLOAT_SM_DL 5 // idem, DL= diferente linea (se imprime en el sector para tal motivo)
#define TIPO_FLOAT_SM_SL 6
#define TIPO_FLOAT_NM_SL 7
#define TIPO_FLOAT_NM_SL_CERO 8 // si el numero es < 0 lo muestra como cero (invento para la serenisima)

#define TIPO_SINGLE_NM_ML 9   // muestra un single con la cantidad de digitos enteros, y decimales pedidos (en las columnas de hijo y param2 respectivamente)
#define TIPO_SINGLEZ_NM_ML 10 // idem anterior, pero si el numero es menor que cero lo muestra como cero
#define TIPO_SINGLE_SM_SL 11  // editable!

#define TIPO_SHORT_NM_ML 12 // SHORT, SU=sin unidades, NM=no modificable, ML=misma linea
#define TIPO_SHORT_NM_DL 13 // idem, DL= diferente linea (se imprime en el sector para tal motivo)
#define TIPO_SHORT_SM_ML 14 // SHORT, SU=sin unidades, SM=si modificable, ML=misma linea
#define TIPO_SHORT_SM_DL 15 // idem, DL= diferente linea (se imprime en el sector para tal motivo)
// #define TIPO_SHORT_SM_ML_UP 16  //modificable, misma linea, pero es up/down
#define TIPO_SHORT_SM_SL 16
#define TIPO_SHORT_NM_SL 17

#define TIPO_TXT_NM_ML 18   // campo de texto NM=no modificable, ML=en la misma linea que la etiqueta
#define TIPO_TXT_SM_ML 19   // campo de texto SM=si modificable, ML=en la misma linea que la etiqueta
#define TIPO_TXT_NM_SL 20   // campo de texto NM=no modificable, SL=en la linea siguiente a la de la etiqueta
#define TIPO_TXT_SM_SL 21   // campo de texto SM=si modificable, SL=en la linea siguiente a la de la etiqueta
#define TIPO_TXT_NM_DL 22   // campo de texto NM=no modificable, DL=en la linea de datos
#define TIPO_TXT_SM_DL 23   // campo de texto SM=si modificable, DL=en la linea de datos
#define TIPO_PASSWORD_SL 24 // muestra un campo que es como un campo de texto solo que se muestran ******, el valor valido asociado se guarda en la variable TXT que tiene asociada

#define TIPO_BIT_NM_ML 25 // bit (ON-OFF) se debe indicar en parametro el bit que se quiere modificar de variable_bit
#define TIPO_BIT_SM_ML 26 // bit (ON-OFF)

#define TIPO_ICONO 27 // similar a etiqueta solo que se muestra un icono de 32x32 con scroll horizontal, no se puede mezclar con otro tipo de item en una misma pantalla de menu, como parametro esta la referencia a la tabla de animacion de iconos

// #define TIPO_FECHA_SM_SL    28  //campo de fecha completa modificable en la siguiente linea el campo parametro indica la posicion en la matriz de variables fecha que le corresponde
#define TIPO_FECHA_NM_SL 29 // campo de fecha completa modificable en la siguiente linea el campo parametro indica la posicion en la matriz de variables fecha que le corresponde

#define TIPO_HORA_SM_SL 30   // campo de hora completa modificable en la siguiente linea el campo parametro indica la posicion en la matriz de variables fecha que le corresponde
#define TIPO_FECHA2_SM_SL 31 // muestra solo la fecha (no la hora), modificable en la siguiente linea
#define TIPO_HORA_NM_SL 32   // campo de hora completa no modificable en la siguiente linea el campo parametro indica la posicion en la matriz de variables fecha que le corresponde
#define TIPO_FECHA2_NM_SL 33 // muestra solo la fecha (no la hora), no modificable en la siguiente linea

// #define TIPO_FLOAT_SM_ML_CIENTOS 35     //muestra solo multiplos de 100, y la edicion tambien es de multiplos de 100
#define TIPO_SINGLE_NM_SL 34 // muestra un single con la cantidad de digitos enteros, y decimales pedidos (en las columnas de hijo y param2 respectivamente)

#define TIPO_TXT_SM_SL_ALFA 35

// #define TIPO_IOT_TXT    36
#define TIPO_IOT_SHORT 37
//--------------------------------------------

/* tags*/
#define ID_TAG_RECORRIDO 1
#define ID_TAG_REMITO 2
#define ID_TAG_NUM_LINEA 3
#define ID_TAG_REMITO_ACOPLADO 4
#define ID_TAG_REMITO_CONFIRMA 5
#define ID_TAG_TAMBERO_CONFIRMA 6
#define ID_TAG_LITROS_MUESTRA 7
#define ID_TAG_NRO_MUESTRA 8
#define ID_TAG_CIST_DEST1 9
#define ID_TAMBO_OBS1 10
#define ID_TAG_CARGANDO 14
#define ID_TAG_SE_ELIGIO_SIST 14
#define ID_TAG_TRAS_ORIG1 15
#define ID_TAG_TRAS_DEST1 17
#define ID_TAG_PANTALLA_DATOS 20
#define ID_TAG_OPCIONES_POST_CARGA 21 // ingresa en el menu post carga
#define ID_TAG_ELIJE_OTRA_CISTERNA 22
#define ID_TAG_PAUSA 23
#define ID_TAG_FIN_CARGA 24
#define ID_TAG_TRANSMITIR 25
#define ID_TAG_PARAMETROS_VEHICULO 26
#define ID_TAG_FIN_CIP 34
#define ID_TAG_TAREA_ITEM0 35
#define ID_TAG_TRASVASE 36
#define ID_TAG_RECORRIDO_TAREA 35 // primer item del menu de tareas
#define ID_TAG_FIN_RECORRIDO 39
#define ID_TAG_TRASBORDO 37
#define ID_TAG_OBSERVACION 38
#define ID_TAG_CAPACIDAD_CISTERNA 40
#define ID_TAG_PANTALLA_DESTINO 41 // pantalla de destino de trasvase
#define ID_TAG_COMENZAR_TRASVASE 42
#define ID_TAG_CONFIRMA_TRANSVASE 42
#define ID_TAG_OPCIONES_POST_TRAS 43
#define ID_TAG_PAUSA_TRASVASE 44
#define ID_TAG_FIN_TRASVASE 45
#define ID_TAG_PARAMETROS 71
#define ID_TAG_FUNCION_VACIAR 74
#define ID_TAG_FUNCION_PRINCIPAL 77
#define ID_TAG_ZERO_CAUDALIMETRO 82
#define ID_TAG_TAMBO_OBS 83
#define ID_TAG_IMPRESION_PARAMETROS 114
#define ID_TAG_BORRAR_DATOS 115
#define ID_TAG_OBSERVACION_0 117
#define ID_TAG_RESET_LITROS 127
#define ID_TAG_RESET_CONFIG 128
#define ID_TAG_ULT_CARGA 138
#define ID_TAG_FUNCION_PARAMETROS 139
#define ID_TAG_PROBAR_TOMAMUESTRAS 171
#define ID_TAG_PULSO_TOMAMUESTRAS 172
#define ID_TAG_TEST_IO 173
#define ID_TAG_DESAI_CALIB_MIN 174
#define ID_TAG_DESAI_CALIB_MAX 175
#define ID_TAG_DESAI_CALIB_RESET 176
#define ID_TAG_CONFIG_A_PEN 177
#define ID_TAG_CONFIG_DESDE_PEN 178
#define ID_TAG_RESET_DEBUG_COMM 179
#define ID_TAG_TAMBERO 180
#define ID_TAG_TRANSF_CEL 181
#define ID_TAG_MUESTRA 182
#define ID_TAG_GPRS_TEST 183
#define ID_TAG_NRO_REC 184
#define ID_TAG_CHOFER 185
#define ID_TAG_NRO_TRASBORDO 186
#define ID_TAG_REMITO_TRASBORDO 187

// #define ID_TAG_NAVEGAR_TOUR
// #define ID_TAG_NAVEGAR_INTAKE

#define NIVEL_1 0
#define NIVEL_2 1
#define NIVEL_3 2

//---------ID de los menus (los define van de 5 en 5)!!!!--------------------
#define ID_ROOT 245      // item raiz a partir del cual se muestran los otros
#define ID_PRINCIPAL 1 // menu principal, nivel de seguridad 0
#define ID_CIP       2 // codigo de numero de acoplado, imprimir tiket de inicio
#define ID_RECORRIDO_D 3   // pantalla de ingreso de remito, manual o automatico con el lector de codigo
#define ID_RECORRIDO_I 4   // pantalla de ingreso de remito, manual o automatico con el lector de codigo

#define ID_TAMBO 5


#define ID_NUM_TAMBERO 20  // codigo de numero de tambero, indicar litros esperados
#define ID_NUM_MUESTRA 21
#define ID_CAPA_CISTERNA 25   // mostrar capacidad de cada cisterna
#define ID_CAPA_CISTERNA_2 26 // mostrar capacidad de cada cisterna
#define ID_CAPA_CISTERNA_3 27 // mostrar capacidad de cada cisterna
#define ID_CAPA_CISTERNA_4 28 // mostrar capacidad de cada cisterna
#define ID_CAPA_CISTERNA_5 29 // mostrar capacidad de cada cisterna

#define ID_ELIGE_CISTERNA 30 // elige cisterna de destino

#define ID_TRANS_ORIGEN 35   // elige cisterna de origen para transvase
#define ID_TRANS_ORIGEN_2 36 // elige cisterna de origen para transvase

#define ID_TRANS_DESTINO_DUMMY 40
#define ID_TRANS_DESTINO_3 42 // elige cisterna de origen para transvase
#define ID_TRANS_DESTINO_4 43 // elige cisterna de origen para transvase
#define ID_TRANS_DESTINO_5 44 // elige cisterna de origen para transvase

#define ID_CAPA_TRANS 45   // muestra la capacidad de los destinos para realizar el transvase
#define ID_CARGANDO 50     // pantalla donde se va cargando el vaso
#define ID_TRANSVASANDO 55 // pantalla donde se va cargando el vaso
#define ID_DUMMY 60
#define ID_ELIGE_FIN_CARGA 65
#define ID_PARAMETROS 70
#define ID_PARAMETROS_4 74


#define ID_DATOS_CARGA 80

#define ID_TAREA 85   // aca se elije cual ed las tareas se va a realizar(tambo, transvase, fin recorrido, observaciones, decomisada)
#define ID_TAREA_3 87 // aca se elije cual ed las tareas se va a realizar(tambo, transvase, fin recorrido, observaciones, decomisada)

#define ID_MUESTRA 90       // menu donde se cargan la cantidad de litros a cargar
#define ID_LITROS_CARGAR 91 // menu donde se cargan la cantidad de litros a cargar
#define ID_CONFIRMA_TRANSVASE 96
#define ID_ELIGE_FIN_TRASVASE 100
#define ID_OBSERVACION 105

#define ID_PAR_VEHICULO 110
#define ID_PAR_VEHICULO_2 111
#define ID_PAR_VEHICULO_3 112
#define ID_PAR_VEHICULO_4 113
#define ID_PAR_VEHICULO_5 114

#define ID_PAR_ODOMETRO 115
// #define ID_PAR_VALORES      120+NIVEL_2
#define ID_PAR_BLUETOOTH 120
#define ID_PAR_TIEMPOS 125
#define ID_PAR_SIM7000 130
#define ID_PAR_IMPRESORA 135
#define ID_PAR_TOMAMUESTRAS 140
#define ID_PAR_DESAIREADOR 145

#define ID_PASSWORD_PARAM 150
/* A futuro: utilizar para desarrollar la navegacion sobre la base de datos.
#define ID_DB_NAVEGAR_TOUR 151
#define ID_DB_NAVEGAR_INTAKE 152
*/
#define ID_FUNCIONES_PRINCIPAL 155 // si se aprieta la tecla de funcion en el principal se muestra este menu
#define ID_FUNCIONES_PRINCIPAL_1 156

#define ID_DECOMISADA 160 // si se aprieta la tecla de funcion en el principal se muestra este menu
#define ID_INSOLTECH 165

#define ID_PAR_IO 170
#define ID_PAR_PROCESOS 175
#define ID_PAR_BASE_DATOS 180
#define ID_PAR_CAUDALIMETRO 185
#define ID_PAR_PASSWORD 190

#define ID_BLUETOOTH_ON 200
#define ID_LECTOR_BARRAS_ON 201

#define ID_PAR_GPRS 210

// #define ID_PARAM_IOT  215

#define ID_TRASBORDO 220
#define ID_TAMBO_OBS 225

#define ID_MAX 12
#define ID_VOID 255 // no tiene submenu
#define ID_NADA 250 // cuando el menu_padre es igual a ID_NADA no se dibuja en pantalla (esto es para que dibuje otra funcion)

//--------------------------------------------

//---------Frames de los ICONOS ------------

//------------------------------------------

#endif
