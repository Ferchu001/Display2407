/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <Arduino.h>
#include <Arduinojson.h>
#include <esp32_smartdisplay.h>
#include <ui/ui.h>

#include "menu.h"


#define TAG "ESP-EXAMPLE"
#define APP_DISP_DEFAULT_BRIGHTNESS 50

/*******************************************************************************
* external functions
*******************************************************************************/
extern char check_teclado(void);
extern void mnu_select(char Tecla);
extern void mnu_show(void);
extern void reset_variables(void);

/*******************************************************************************
* external variables
*******************************************************************************/
extern edicion mnu_edicion;


/*******************************************************************************
* Private functions
*******************************************************************************/
void check_rx_commands(void);

/*******************************************************************************
* Private variables
*******************************************************************************/
ulong next_millis=0;
ulong Timer_panRefresh=0;
#define TIME_REFRESH_PAN 100 //ms

struct Dis
{
    int Actual = 0;
    bool Change = false;
} Display;


void setup()
{

    Serial.begin(115200);
    Serial.setDebugOutput(false);

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0f);

    lv_disp_get_default();
    auto disp = lv_disp_get_default();
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
    ui_init();
    reset_variables();

    mnu_show();
//    Serial2.begin(115200, SERIAL_8N1, GPIO_NUM_22, GPIO_NUM_27);
}
void Led(void)
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 500;

#ifdef BOARD_HAS_RGB_LED
        auto const rgb = (now / 2000) % 8;
        smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);
#endif
    }
}

void loop()
{
    char Tecla;
    Led();
    check_rx_commands();
    if (Display.Change == true)
    {

        switch (Display.Actual)
        {
        case 1:
            _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
            break;
        case 2:
            _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen2_screen_init);
            break;
        case 6:
            _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
            break;
        default:
            _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
            break;
        }
        Display.Change = false;
        Serial.println("Cambio a Display: " + String(Display.Actual));
    }
    Tecla=check_teclado();
    if(Tecla!=0)
        {
        mnu_select(Tecla);
        }
        if(mnu_edicion.item_ON==true && millis()>mnu_edicion.ms_parpadea+TIEMPO_PARPADEA_EDICION)    
            mnu_show();
        
    lv_timer_handler();
}
/***************************Comandos*********************/
/*
1) PANTALLA: XX
2) PRODUCTO:XX
3) PRECIO:XX
4) USUARIO:XX
5) LED:XX
6) SONIDO:XX
7) WIFI: XX
8) PASS:XX
9) NRO_MAQUINA:XX
10) QR:XX


* RESET:XX
* UPGRADE:XX

*/
void check_rx_commands(void)
{
    if (Serial2.available())
    {
        String jsonCommand = Serial2.readStringUntil('\n'); // Lee el comando JSON hasta encontrar una nueva línea
        Serial.println("Comando recibido en Display: ");
        Serial.println(jsonCommand);
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, jsonCommand);

        if (error)
        {
            Serial.println("Error al analizar el comando JSON");
        }
        else
        {
            String sPantalla = doc["PANTALLA"];
/*            String sProducto = doc["PRODUCTO"];
            String sPrecio = doc["PRECIO"];
            String sCliente = doc["CLIENTE"];
            String sDescripcion = doc["DESCRPCION"];
            String sOperacion = doc["NRO_OPERACION"];
            String sLed = doc["LED"];
            String sSonido = doc["SONIDO"];
            String sWifi = doc["WIFI"];
            String sPass = doc["PASS"];
            String sNro_maquina = doc["NRO_MAQUINA"];
            String sQR = doc["QR"];
            String sStatus = doc["STATUS"];
            String sVer_Master = doc["VER_MASTER"];
            String sReset = doc["RESET"];
            String sUpgrade = doc["UPGRADE"];
*/
            if (doc.containsKey("PANTALLA"))
            {
                if (Display.Actual != sPantalla.toInt())
                {
                    Display.Actual = sPantalla.toInt();
                    Display.Change = true;
                }
            }
/*            if (doc.containsKey("PRODUCTO"))
            {
                if (sProducto != "NULL")
                {
                    DatosCompra.Producto = sProducto;
                    lv_label_set_text_fmt(ui_Producto, DatosCompra.Producto.c_str());
                }
            }
            if (doc.containsKey("PRECIO"))
            {
                if (sPrecio != "NULL")
                {
                    DatosCompra.Precio = sPrecio;
                    lv_label_set_text_fmt(ui_Precio, DatosCompra.Precio.c_str());
                }
            }
            if (doc.containsKey("CLIENTE"))
            {
                if (sCliente != "NULL")
                {
                    DatosCompra.Cliente = sCliente;
                    // lv_label_set_text_fmt(ui_Cliente, DatosCompra.Cliente.c_str());
                }
            }
            if (doc.containsKey("DESCRIPCION"))
            {
                if (sDescripcion != "NULL")
                {
                    DatosCompra.Descripcion = sDescripcion;
                    // lv_label_set_text_fmt(ui_Descripcion, DatosCompra.Descripcion.c_str());
                }
            }
            if (doc.containsKey("NRO_OPERACION"))
            {
                if (sOperacion != "NULL")
                {
                    DatosCompra.NroOperacion = sOperacion;
                    // lv_label_set_text_fmt(ui_Operacion, DatosCompra.Operacion.c_str());
                }
            }
            */
        }
    }
}
