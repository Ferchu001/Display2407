#include "constantes.h"
#include "menu_tabla.h"
#include <Arduino.h>

int variables_short[MNU_TAM_VAR_SHORT];

signed short variables_short_iot[MNU_TAM_VAR_SHORT_IOT];
char variables_txt[MNU_TAM_VAR_TXT][TAM_VAR_TXT];
float variables_float[MNU_TAM_VAR_FLOAT];

long variables_bit=0x00;

void reset_variables(){
    int i;
    for(i=0;i<MNU_TAM_VAR_SHORT;i++)          //reseteo a los valores por default
      variables_short[i]=variables_short_limites[i][VALOR_DEFAULT];

    for(i=0;i<MNU_TAM_VAR_FLOAT;i++)          //reseteo a los valores por default
      variables_float[i]=variables_float_limites[i][VALOR_DEFAULT];

    for(i=0;i<MNU_TAM_VAR_TXT;i++)          //reseteo a los valores por default
      strcpy(variables_txt[i],variables_txt_default[i]);
}