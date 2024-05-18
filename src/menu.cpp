
//    Nivel, SubNivel, Etiqueta, Tipo, Nivel_Next, Cant_digitos, Nivel_Back, Tecla_Rapida, Pre_proceso, PostProceso, Variable_Asoc
#include "menu.h"
#include "constantes.h"
#include <Arduino.h>
#include <ui/ui.h>
#define CLR_BLACK 0x000000
#define CLR_WHITE 0xFFFFFF
void mnu_show(void);

int mnu_busca_nextNivel(int item);
int mnu_busca_BackNivel(int item);
int mnu_Nxt_item(void);
int mnu_Prev_item(void);
void mnu_cambio_menu(int New_item);

int mnu_item_actual=0;
bool mnu_item_edicion = false;

int pan_primer_item=0;//Contiene el primer item a mostrar en Pantalla
char Item_Seleccionado=0;



/*****************Externas ***********************************/
extern signed short variables_short[MNU_TAM_VAR_SHORT];
extern char variables_txt[MNU_TAM_VAR_TXT][TAM_VAR_TXT];
extern signed short variables_short_iot[MNU_TAM_VAR_SHORT_IOT];
extern float variables_float[MNU_TAM_VAR_FLOAT];
/************************************************************/

#define MAX_ITEMS_PAN 4
#define ALNG_RIGHT 1
#define ALNG_LEFT  2

void mnu_show(void)
{
u_char k=0,j=0;
char Cant_Items_Nivel=0; //Cuenta la cantidad de Items en el nivel acutal en pantalla
int Items_Nivel[50];
int nivel_actual = menu[mnu_item_actual].Nivel;
char str_Text[TAM_VAR_TXT];
char pan_Etiquetas[5][TAM_VAR_TXT];
char pan_item_sel=0;
char mnu_item_sel=0;
char pan_alin[5]={LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT};
char cont_items_mostrar;
char z;
int VectorTotPan[50];
char TotPan=0;
for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) 
    {    
    if (menu[i].Nivel == nivel_actual) 
        {
        Items_Nivel[k]=i;
        if(i==mnu_item_actual)
            {
            Serial.print(">>");
            pan_item_sel=k;
            }
        Serial.println(menu[i].Etiqueta);
        switch(menu[Items_Nivel[j]].Tipo)
            {                
            case TIPO_TXT_SM_ML:
            case TIPO_TXT_SM_SL:
                TotPan+=2;                
                break;
            default:
                TotPan++;
            break;
            }
        VectorTotPan[k]=TotPan;
        k++;
        }    
    }    
Cant_Items_Nivel=k;
/* ---------- Scroll -------------*/
Serial.print("VectorTotPan[k]");
for(k=0;k<Cant_Items_Nivel;k++)    
    {
    Serial.print(k);
    Serial.print(" : ");
    Serial.println(VectorTotPan[k]);
    }
Serial.printf(" pan_primer_item: %d ,pan_item_sel%d \n ",pan_primer_item,pan_item_sel);
z=0;
while(VectorTotPan[pan_item_sel]-4>=VectorTotPan[z])
    pan_primer_item=++z;

//while(pan_item_sel>=pan_primer_item)
//    pan_primer_item++;
if(pan_item_sel<pan_primer_item)
    pan_primer_item=pan_item_sel;

if(pan_item_sel<pan_primer_item)  pan_primer_item=pan_item_sel;
Serial.printf(" pan_primer_item: %d ,pan_item_sel%d \n ",pan_primer_item,pan_item_sel);
/*--------------------------------*/
/*Guarda en pan_Etiquetas el texto a mostrar en pantalla dependiendo si los items ocupan 1 o 2 lineas*/
for(k=0,j=0;j<MAX_ITEMS_PAN && k<Cant_Items_Nivel ;k++,j++)
    {  
    strncpy(pan_Etiquetas[j], menu[Items_Nivel[pan_primer_item+k]].Etiqueta,TAM_VAR_TXT - 1);
    if(Items_Nivel[pan_primer_item+k]==mnu_item_actual)
        mnu_item_sel=j;
    switch(menu[Items_Nivel[pan_primer_item+k]].Tipo)
        {
        case TIPO_TXT_SM_ML:
        case TIPO_TXT_SM_SL:
            j++;
            strncpy(pan_Etiquetas[j],variables_txt[menu[Items_Nivel[pan_primer_item+k]].Variable_Asoc],TAM_VAR_TXT - 1);
            //Si esta en edicion titilar el cursor
            pan_alin[j]=LV_ALIGN_TOP_RIGHT;
        break;
        default:
        break;
        }
    }


for(k=0;k<MAX_ITEMS_PAN;k++)
    {
    switch(k)
            {
            case 0:
            lv_obj_set_align(ui_Menu1, pan_alin[k]);
            lv_label_set_text_fmt(ui_Menu1, pan_Etiquetas[k]);           
            if(mnu_item_sel==k) //Item Seleccionado
                {   
                lv_obj_set_style_bg_color(ui_Fondo1, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu1, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT); 
                }
            else
                {                                
                lv_obj_set_style_bg_color(ui_Fondo1, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu1, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);                               
                }    
            break;

            case 1:
            lv_obj_set_align(ui_Menu2, pan_alin[k]);
            if(k<Cant_Items_Nivel)
                {
                lv_label_set_text_fmt(ui_Menu2, pan_Etiquetas[k]); 
                if(mnu_item_sel==k) //Item Seleccionado
                    {
                    lv_obj_set_style_bg_color(ui_Fondo2, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu2, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);                    
                    }
                else
                    {                    
                    lv_obj_set_style_bg_color(ui_Fondo2, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu2, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                }
            else
                {
                lv_label_set_text_fmt(ui_Menu2, "");
                lv_obj_set_style_bg_color(ui_Fondo2, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu2, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT); 
                }
            break;
            case 2:
            lv_obj_set_align(ui_Menu3, pan_alin[k]);
            if(k<Cant_Items_Nivel)
                {
                lv_label_set_text_fmt(ui_Menu3, pan_Etiquetas[k]); 
                if(mnu_item_sel==k) //Item Seleccionado
                    {
                    lv_obj_set_style_bg_color(ui_Fondo3, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);                    
                    }
                else
                    {                    
                    lv_obj_set_style_bg_color(ui_Fondo3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu3, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }                }
            else
                {
                lv_label_set_text_fmt(ui_Menu3, "");
                lv_obj_set_style_bg_color(ui_Fondo3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT); 
                }                    
            break;
            case 3:
            lv_obj_set_align(ui_Menu4, pan_alin[k]);
            if(k<Cant_Items_Nivel)
                {
                lv_label_set_text_fmt(ui_Menu4, pan_Etiquetas[k]); 
                if(mnu_item_sel==k) //Item Seleccionado
                    {
                    lv_obj_set_style_bg_color(ui_Fondo4, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu4, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);                    
                    }
                else
                    {                    
                    lv_obj_set_style_bg_color(ui_Fondo4, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_Menu4, lv_color_hex(CLR_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }                    
                }
            else
                {
                lv_label_set_text_fmt(ui_Menu4, "");
                lv_obj_set_style_bg_color(ui_Fondo4, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu4, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT); 
                }                    
                
            break;                                
            }
        }
        
}


void mnu_select(char Tecla)
{
int mnu_prov;
//Busca si se presiono una tecla rapida
if(Tecla>='1' && Tecla<='9')
    for(int i=0;i<sizeof(menu) / sizeof(menu[0]); i++)
        {
        if(menu[i].Nivel==menu[mnu_item_actual].Nivel && menu[i].Tecla_Rapida==Tecla)
            {
            mnu_cambio_menu(mnu_busca_nextNivel(i));
            }
        }
switch(Tecla)
    {
    case '0':
        break;
    case '1':         
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        break;
    case '8':
        break;
    case '9':
        break;
    case 'O': //Ok
    case 'o': //Ok        
    if(mnu_item_edicion==false)
        {
        if(menu[mnu_item_actual].Nivel_Next==ID_NXT_ITEM )
            {
            Serial.println("NEXT>>>");
            mnu_cambio_menu(mnu_Nxt_item());
            }
        else
        if(menu[mnu_item_actual].Nivel_Next!=ID_VOID)
            {
            pan_primer_item=0;//Si no se esta en edicion
            mnu_cambio_menu(mnu_busca_nextNivel(mnu_item_actual));
            }
        }
    else //Editando variable
        {

        }
        break;
    case 'S': //Stop
    case 's': //Stop
        if(menu[mnu_item_actual].Nivel_Back!=ID_VOID)
            {
            Serial.println("BACK<<<");
            pan_primer_item=0;//Si no se esta en edicion
            mnu_cambio_menu(mnu_busca_BackNivel(mnu_item_actual));

            }
        break;
    case 'P'://Printer
    case 'p':
        break;
    case 'F': // Funcion
    case 'f':
        break;
    case 'U': //UP
    case 'u':
        mnu_prov=mnu_Prev_item();
        if(mnu_prov>=0)
            {
            Serial.println("UP^^^^");
            mnu_cambio_menu(mnu_prov);
            }
        break;
    case 'D': //DOWN
    case 'd':        
        mnu_prov=mnu_Nxt_item();
            if(mnu_prov>=0)
            {
            mnu_cambio_menu(mnu_prov);
            }            
        break;
    case 'm':
    case 'M'://Show menu y variables
        Serial.printf("Item_Actual: %d \n",mnu_item_actual);
        mnu_show();
        break;
    }
}


int mnu_busca_nextNivel(int item)
{
for(int i=0;i<sizeof(menu) / sizeof(menu[0]); i++)
    {
    if(menu[i].Nivel==menu[item].Nivel_Next)
        return i;// Busca el primero de la lista
    }
return 0; // No encontro ningun item que tenga eso para el proximo nivel
}

int mnu_busca_BackNivel(int item)
{
for(int i=0;i<sizeof(menu) / sizeof(menu[0]); i++)
    {
    if(menu[i].Nivel==menu[item].Nivel_Back)
        return i;// Busca el primero de la lista
    }
return 0; // No encontro ningun item que tenga eso para el proximo nivel
}

int mnu_Nxt_item(void)
{
for(int i=mnu_item_actual+1;i<sizeof(menu) / sizeof(menu[0]); i++)
    {
    if(menu[i].Nivel==menu[mnu_item_actual].Nivel)
        {        
        return i;
        }
    }
return -1;
}

int mnu_Prev_item(void)
{
for(int i=mnu_item_actual-1;i>=0; i--)
    {
    if(menu[i].Nivel==menu[mnu_item_actual].Nivel)
        {
        return i;
        }
    }
return -1;
}

void mnu_cambio_menu(int New_item)
{
Serial.printf("Item_Actual: %d \n",mnu_item_actual);
//Ejecutar Post_Proceso
mnu_item_actual=New_item;
mnu_item_edicion=false;
mnu_show();
//Ejecutar Pre_Proceso
Serial.printf("Item_Actual: %d \n",mnu_item_actual);
}