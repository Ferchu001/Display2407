#include "constantes.h"
#include "menu_tabla.h"
#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>
#include "struct_defines.h"

extern void load_variables(const char* path);
extern void save_variables(const char* path);

/*struct Var{
int vshort[MNU_TAM_VAR_SHORT];
signed short viot[MNU_TAM_VAR_SHORT_IOT];
char vtxt[MNU_TAM_VAR_TXT][TAM_VAR_TXT];
float vfloat[MNU_TAM_VAR_FLOAT];

long bit=0x00;
};
*/
struct Var variables;

void reset_variables(){
    int i;
    for(i=0;i<MNU_TAM_VAR_SHORT;i++)          //reseteo a los valores por default
      variables.vshort[i]=variables_short_limites[i][VALOR_DEFAULT];

    for(i=0;i<MNU_TAM_VAR_FLOAT;i++)          //reseteo a los valores por default
      variables.vfloat[i]=variables_float_limites[i][VALOR_DEFAULT];

    for(i=0;i<MNU_TAM_VAR_TXT;i++)          //reseteo a los valores por default
      strcpy(variables.vtxt[i],variables_txt_default[i]);
      variables.vbit=variables_bits_default;
    
}

void init_variables()
{
      // Comprobar si el archivo existe
    if (SPIFFS.exists("/parametros.txt")) {
        // Si el archivo existe, cargar las variables
        load_variables("/parametros.txt");
    } else {
        // Si el archivo no existe, resetear las variables y guardarlas
        reset_variables();
        save_variables("/parametros.txt");
    }

}


