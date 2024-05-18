#include <Arduino.h>
#define TECLADO_USB

char check_teclado(void);

#ifdef TECLADO_USB

char check_teclado(void)
{
if (!Serial.available()) {
    return 0;
  }
char tecla = Serial.read();
return tecla;
}
#else

#endif
