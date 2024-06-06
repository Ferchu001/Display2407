#include <Arduino.h>
#define TECLADO_USB

char check_teclado(void);

#ifdef TECLADO_USB

char check_teclado(void)
{
//bool receiveData(Data& data) {
    static String jsonData = "";
    while (Serial2.available() > 0) {
        char c = Serial2.read();
        if (c == '{') {
            jsonData = "";
        }
        jsonData += c;
        if (c == '}')
          {
            Serial.println(jsonData);
          }
    }

return 0;
// if (!Serial.available()) {
//     return 0;
//   }
// char tecla = Serial.read();
// return tecla;
}
#else

#endif
