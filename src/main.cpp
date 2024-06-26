#include <Arduino.h>
#include <ArduinoJson.h>
#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <FS.h>
#include <SPIFFS.h>

#include "menu.h"
#include "comm_dis.h"

#define TAG "ESP-EXAMPLE"
#define APP_DISP_DEFAULT_BRIGHTNESS 50

/*******************************************************************************
* external functions
*******************************************************************************/
extern char check_teclado(void);
extern void mnu_select(char Tecla);
extern void mnu_show(void);
extern void init_variables(void);
extern unsigned char calculateChecksumDis(const String& data);

/*******************************************************************************
* external variables
*******************************************************************************/
extern edicion mnu_edicion;

/*******************************************************************************
* Private functions
*******************************************************************************/
void check_rx_commands(void);
void handleReceivedData(void *pvParameters);

/*******************************************************************************
* Private variables
*******************************************************************************/
ulong next_millis = 0;
ulong Timer_panRefresh = 0;
#define TIME_REFRESH_PAN 100 //ms

bool BombaON=false;

char Tecla;


struct msgboxst msgbox;
struct Dis Display;

QueueHandle_t receivedDataQueue;
String jsonData = ""; // Buffer for incoming data

void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(false);
    if (!SPIFFS.begin(true))
    {
        Serial.println("An error occurred while mounting SPIFFS");
    }
    Serial.println("SPIFFS mounted successfully");

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0f);

    lv_disp_get_default();
    auto disp = lv_disp_get_default();
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
    ui_init();
    init_variables();

    mnu_show();
    Serial2.begin(115200, SERIAL_8N1, GPIO_NUM_22, GPIO_NUM_27);

    receivedDataQueue = xQueueCreate(10, sizeof(DataInDis));
    if (receivedDataQueue == NULL)
    {
        Serial.println("Error creating the receivedData queue");
    }
}

void Led(void)
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 1000;
#ifdef BOARD_HAS_RGB_LED
        auto const rgb = (now / 2000) % 8;
        smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);
#endif
    }
}

DataInDis receivedData;
void loop()
{
    if(msgbox.visible==true)
        {
        lv_label_set_text(ui_msgtxt1, msgbox.text1);
        lv_label_set_text(ui_msgtxt2, msgbox.text2);
        lv_obj_clear_flag(ui_msgbox, LV_OBJ_FLAG_HIDDEN);
        }
    else
        {
        lv_obj_add_flag(ui_msgbox, LV_OBJ_FLAG_HIDDEN);     /// Flags
        }
    Led();
    sendDataDis(currentDataOutDis);
    receiveDataDis(receivedData);
    if(receivedData.teclado!=0)
        {
        mnu_select((char)receivedData.teclado);
        receivedData.teclado=0;
        }

    char tecla = check_teclado();
    if (tecla != 0)
    {
        if(tecla=='U')
            msgbox.visible=true;
        if(tecla=='D')
            msgbox.visible=false;
        mnu_select(tecla);
    }

    previousDataOutDis = currentDataOutDis;

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

    if (mnu_edicion.item_ON == true && millis() > mnu_edicion.ms_parpadea + TIEMPO_PARPADEA_EDICION)
    {
        mnu_show();
    }

    lv_timer_handler();
}
