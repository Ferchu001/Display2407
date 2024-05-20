
//    Nivel, SubNivel, Etiqueta, Tipo, Nivel_Next, Cant_digitos, Nivel_Back, Tecla_Rapida, Pre_proceso, PostProceso, Variable_Asoc
#include "constantes.h"
#include "menu.h"
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

edicion mnu_edicion;



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
#define TXT_52 52
#define TXT_42 42


void mnu_show(void)
{
u_char k=0,j=0;
char Cant_Items_Nivel=0; //Cuenta la cantidad de Items en el nivel acutal en pantalla
int Items_Nivel[50];
int nivel_actual = menu[mnu_item_actual].Nivel;
char str_Aux[TAM_VAR_TXT];
char pan_Etiquetas[5][TAM_VAR_TXT];
char pan_item_sel=0;
char mnu_item_sel=0;
char pan_alin[5]={LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT};
char pan_txt[5]={TXT_52,TXT_52,TXT_52,TXT_52,TXT_52};

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

/******************Scroll******************************/
z=0;
while(VectorTotPan[pan_item_sel]-4>=VectorTotPan[z])
    pan_primer_item=++z;
if(pan_item_sel<pan_primer_item)
    pan_primer_item=pan_item_sel;

if(pan_item_sel<pan_primer_item)  pan_primer_item=pan_item_sel;
/******************************************************/

/*+++Guarda en pan_Etiquetas el texto a mostrar en pantalla dependiendo si los items ocupan 1 o 2 lineas+++*/
for(k=pan_primer_item,j=0;j<MAX_ITEMS_PAN && k<Cant_Items_Nivel ;k++,j++)
    {//j= indice item pantalla 1-4
    //k = indice de items en Vector
    strncpy(pan_Etiquetas[j], menu[Items_Nivel[k]].Etiqueta,TAM_VAR_TXT - 1);
    pan_txt[j]=TXT_52;        
    if(Items_Nivel[k]==mnu_item_actual)
        mnu_item_sel=j;
    switch(menu[Items_Nivel[k]].Tipo)
        {
        case TIPO_TXT_SM_ML:
        case TIPO_TXT_SM_SL:
            if(mnu_edicion.item_ON==true && k==pan_item_sel)
                {
                strncpy(str_Aux,mnu_edicion.str_dato,TAM_VAR_TXT - 1);
                if(millis()>mnu_edicion.ms_parpadea+TIEMPO_PARPADEA_EDICION)
                    {
                    mnu_edicion.ms_parpadea=millis();
                    if(mnu_edicion.digito_ON==true)
                        {
                        str_Aux[mnu_edicion.pos_digito]='_';
                        mnu_edicion.digito_ON=false;
                        }
                    else
                        {
                        mnu_edicion.digito_ON=true;
                        }
                    }
                strncpy(pan_Etiquetas[j+1],str_Aux,TAM_VAR_TXT - 1);
                }
            else
                {
                strncpy(pan_Etiquetas[j+1],variables_txt[menu[Items_Nivel[k]].Variable_Asoc],TAM_VAR_TXT - 1);                
                }
            j++;
            //Si esta en edicion titilar el cursor
            pan_alin[j]=LV_ALIGN_TOP_RIGHT;
            pan_txt[j]=TXT_42;
        break;
        default:
        break;
        }
    }
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/************Muestra Items en pantalla******************/
for(k=0;k<MAX_ITEMS_PAN;k++)
    {
    switch(k)
            {
            case 0:
            lv_obj_set_align(ui_Menu1, pan_alin[k]);
            switch(pan_txt[k])
                {
                case TXT_52:                
                    lv_obj_set_style_text_font(ui_Menu1, &ui_font_OpenSans52, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                case TXT_42:
                    lv_obj_set_style_text_font(ui_Menu1, &ui_font_OpenSansCSB42, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                }                
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
            switch(pan_txt[k])
                {
                case TXT_52:                
                    lv_obj_set_style_text_font(ui_Menu2, &ui_font_OpenSans52, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                case TXT_42:
                    lv_obj_set_style_text_font(ui_Menu2, &ui_font_OpenSansCSB42, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                }               
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
            switch(pan_txt[k])
                {
                case TXT_52:                
                    lv_obj_set_style_text_font(ui_Menu3, &ui_font_OpenSans52, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                case TXT_42:
                    lv_obj_set_style_text_font(ui_Menu3, &ui_font_OpenSansCSB42, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                }               
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
                    }                
                }
            else
                {
                lv_label_set_text_fmt(ui_Menu3, "");
                lv_obj_set_style_bg_color(ui_Fondo3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_Menu3, lv_color_hex(CLR_BLACK), LV_PART_MAIN | LV_STATE_DEFAULT); 
                }                    
            break;
            case 3:
            lv_obj_set_align(ui_Menu4, pan_alin[k]);
            switch(pan_txt[k])
                {
                case TXT_52:                
                    lv_obj_set_style_text_font(ui_Menu4, &ui_font_OpenSans52, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                case TXT_42:
                    lv_obj_set_style_text_font(ui_Menu4, &ui_font_OpenSansCSB42, LV_PART_MAIN | LV_STATE_DEFAULT);
                    break;
                }            
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
    switch(menu[mnu_item_actual].Tipo)
        {
        case TIPO_TXT_SM_ML:
        case TIPO_TXT_SM_SL:
            if(Tecla>='0' && Tecla<='9' && mnu_edicion.item_ON==true)
                {
                mnu_edicion.str_dato[mnu_edicion.pos_digito]=Tecla;
                if(++mnu_edicion.pos_digito>=menu[mnu_item_actual].Cant_digitos)
                    {
                    mnu_edicion.pos_digito=menu[mnu_item_actual].Cant_digitos-1;                
                    }
                }
        break;
        }


switch(Tecla)
    {
    case 'O': //Ok
    case 'o': //Ok        
    if(mnu_edicion.item_ON==false)
        {
        switch(menu[mnu_item_actual].Tipo)
            {
            case TIPO_TXT_SM_ML:
            case TIPO_TXT_SM_SL:
                strncpy(mnu_edicion.str_dato,variables_txt[menu[mnu_item_actual].Variable_Asoc],TAM_VAR_TXT-1);
                mnu_edicion.digito_ON=false;
                mnu_edicion.item_ON=true;
                mnu_edicion.ms_parpadea = millis();
                mnu_edicion.pos_digito=0;
                break;
            default:
                if(menu[mnu_item_actual].Nivel_Next==ID_NXT_ITEM )
                    {
                    mnu_cambio_menu(mnu_Nxt_item());
                    }
                else
                if(menu[mnu_item_actual].Nivel_Next!=ID_VOID)
                    {
                    pan_primer_item=0;//Si no se esta en edicion
                    mnu_cambio_menu(mnu_busca_nextNivel(mnu_item_actual));
                    }
            }
        }
    else //Editando variable
        {//Guardar Variable editada
        mnu_edicion.item_ON=false;
        strncpy(variables_txt[menu[mnu_item_actual].Variable_Asoc],mnu_edicion.str_dato,TAM_VAR_TXT-1);
        }
        break;
    case 'S': //Stop
    case 's': //Stop
        if(mnu_edicion.item_ON==true)
            {
            mnu_edicion.item_ON=false;
            }
        else
            {
            if(menu[mnu_item_actual].Nivel_Back!=ID_VOID)
                {
                pan_primer_item=0;//Si no se esta en edicion
                mnu_cambio_menu(mnu_busca_BackNivel(mnu_item_actual));
                }
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
        if(mnu_edicion.item_ON==true)
            {            
            if(++mnu_edicion.pos_digito>=menu[mnu_item_actual].Cant_digitos)
                {
                mnu_edicion.pos_digito=menu[mnu_item_actual].Cant_digitos-1;                
                }
            Serial.printf("mnu_edicion.pos_digito :  %d \n",mnu_edicion.pos_digito);
            }
        else
            {
            mnu_prov=mnu_Prev_item();
            if(mnu_prov>=0)
                {
                mnu_cambio_menu(mnu_prov);
                }
            }
        break;
    case 'D': //DOWN
    case 'd':        
        if(mnu_edicion.item_ON==true)
            {            
            if(mnu_edicion.pos_digito>0)
                mnu_edicion.pos_digito--;
//            Serial.printf("mnu_edicion.pos_digito :  %d \n",mnu_edicion.pos_digito);                
            }
        else
            {
            mnu_prov=mnu_Nxt_item();
            if(mnu_prov>=0)
                {
                mnu_cambio_menu(mnu_prov);
                }            
            }
        break;
    case 'r':
    case 'R'://Show menu y variables
        Serial.printf("Item_Actual: %d \n",mnu_item_actual);
        mnu_show();
        break;
    case 'c':// Pantalla Carga
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen2_screen_init);
        break;
    case 'm'://Menu
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
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
mnu_edicion.item_ON=false;
mnu_show();
//Ejecutar Pre_Proceso
Serial.printf("Item_Actual: %d \n",mnu_item_actual);
}