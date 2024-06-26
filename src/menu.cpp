
//menu.cpp
#include "constantes.h"
#include "menu.h"
#include <Arduino.h>
#include <ui/ui.h>
#include "struct_defines.h"

#define CLR_BLACK 0x000000
#define CLR_WHITE 0xFFFFFF
void mnu_show(void);

int mnu_busca_nextNivel(int item);
int mnu_busca_BackNivel(int item);
int mnu_busca_Nivel(int Nivel);
int mnu_Nxt_item(void);
int mnu_Prev_item(void);
void mnu_cambio_menu(int New_item);
char mnu_validar_password(char password[]);

void PostMenu(void);
void PreMenu(void);

void Inicializa_var_tour(void);
void Inializa_var_Tambo(void);

int mnu_item_actual=0;
int mnu_item_back=0;

edicion mnu_edicion;

int pan_primer_item=0;//Contiene el primer item a mostrar en Pantalla
int pan_primer_item_back=0;
//char Item_Seleccionado=0;

/*****************Externas ***********************************/
extern struct Var variables;

extern void save_variables(const char* path);
extern void save_ini_recorrido(void);

extern bool BombaON;
extern struct msgboxst msgbox;

extern struct reg_cip cip;
extern struct reg_tour tour;
extern struct reg_tambo tambo;
extern struct reg_info info;
extern struct reg_trasvase trasvase;
/************************************************************/

void mnu_trae_dato_edit(void);

#define MAX_ITEMS_PAN 4
#define ALNG_RIGHT 1
#define ALNG_LEFT  2
#define TXT_52 52
#define TXT_42 42


void mnu_show(void)
{

u_char k=0,j=0;
char Cant_Items_Nivel=0; //Cuenta la cantidad de Items en el nivel acutal en pantalla
int Items_Nivel[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int nivel_actual = menu[mnu_item_actual].Nivel;
char str_Aux[TAM_VAR_TXT];
char pan_Etiquetas[5][TAM_VAR_TXT];
int pan_item_sel=0;
char mnu_item_sel=0;
char pan_alin[5]={LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT,LV_ALIGN_TOP_LEFT};
char pan_txt[5]={TXT_52,TXT_52,TXT_52,TXT_52,TXT_52};
int l;
char z;
int VectorTotPan[50];
char TotPan=0;
char format[20];
float valor;
//char str_aux[TAM_VAR_TXT];
for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) 
    {    
    if (menu[i].Nivel == nivel_actual) 
        {
        Items_Nivel[k]=i;
        if(i==mnu_item_actual)
            {
            pan_item_sel=k;
            }
        switch(menu[Items_Nivel[j]].Tipo)
            {                
            case TIPO_ETIQ:
                TotPan+=1;
                break;
            default:
                TotPan+=2;
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

if(pan_item_sel<pan_primer_item) 
    pan_primer_item=pan_item_sel;
/******************************************************/
//Serial.printf("pan_primer_item :%d / pan_item_sel: %d / Cant_Items_Nivel: %d \n",pan_primer_item,pan_item_sel,Cant_Items_Nivel);

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
        case TIPO_TXT_M:
        case TIPO_TXT_ALFA:
        case TIPO_SHORT_M:
        case TIPO_SINGLE_N:
        case TIPO_SINGLE_ZN:
        case TIPO_SINGLE_M:        
        case TIPO_HORA_SM_SL:
        case TIPO_FECHA_SM_SL:        
            if(mnu_edicion.item_ON==true && k==pan_item_sel)
                {
                strncpy(str_Aux,mnu_edicion.str_dato,TAM_VAR_TXT - 1);
                mnu_edicion.ms_parpadea=millis();
                if(mnu_edicion.digito_ON==true)
                    {
                    str_Aux[mnu_edicion.pos_digito]='_';
                    str_Aux[mnu_edicion.pos_digito+1]='\0';
                    mnu_edicion.digito_ON=false;
                    }
                else
                    {                 
                    mnu_edicion.digito_ON=true;
                    }
                strncpy(pan_Etiquetas[j+1],str_Aux,TAM_VAR_TXT - 1);
                }
            else
                {
                switch(menu[Items_Nivel[k]].Tipo)
                    {
                    case TIPO_TXT_M:
                    case TIPO_TXT_ALFA:                
                    case TIPO_HORA_SM_SL:
                    case TIPO_FECHA_SM_SL: 
                        strncpy(pan_Etiquetas[j+1],variables.vtxt[menu[Items_Nivel[k]].Variable_Asoc],TAM_VAR_TXT - 1);
                        Serial.printf("k: %d\n",k);
                        Serial.printf("Items_Nivel[k]: %d\n",Items_Nivel[k]);
                        Serial.printf("variables.vtxt[menu[Items_Nivel[k]].Variable_Asoc] %s\n",variables.vtxt[menu[Items_Nivel[k]].Variable_Asoc]);
                        break;
                    case TIPO_SHORT_M:
                        sprintf(pan_Etiquetas[j+1],"%d",variables.vshort[menu[Items_Nivel[k]].Variable_Asoc]);
                        Serial.printf("k: %d\n",k);
                        Serial.printf("variables.vshort[menu[Items_Nivel[k]].Variable_Asoc] %d\n",variables.vshort[menu[Items_Nivel[k]].Variable_Asoc]);
                        break;                    
                    case TIPO_SINGLE_M:
                    case TIPO_SINGLE_N:
                    case TIPO_SINGLE_ZN:
                        valor = variables.vfloat[menu[Items_Nivel[k]].Variable_Asoc];
                        if(menu[Items_Nivel[k]].Tipo==TIPO_SINGLE_ZN)
                            if (valor < 0)  valor = 0;
                        sprintf(format, "%%.%df", menu[Items_Nivel[k]].Cant_digitos);
                        sprintf(pan_Etiquetas[j+1],format,valor);
                        break;
                    default:
                         break;
                    }
                }
            pan_alin[j+1]=LV_ALIGN_TOP_RIGHT;
            pan_txt[j+1]=TXT_42;
            j++;
        break;
        case TIPO_BIT_M:
            if(mnu_edicion.item_ON==true && k==pan_item_sel)
                {
                strncpy(str_Aux,mnu_edicion.str_dato,TAM_VAR_TXT - 1);
                mnu_edicion.ms_parpadea=millis();
                if(mnu_edicion.digito_ON==true)
                    {
                    strcpy(str_Aux,"__");
                    mnu_edicion.digito_ON=false;
                    }
                else
                    {
                    mnu_edicion.digito_ON=true;
                    }
                strncpy(pan_Etiquetas[j+1],str_Aux,TAM_VAR_TXT - 1);
                }
            else
                {
                if(variables.vbit&(1<<menu[Items_Nivel[k]].Variable_Asoc))
                    {
                    strncpy(pan_Etiquetas[j+1],"SI",TAM_VAR_TXT - 1);
                    }
                else
                    {
                    strncpy(pan_Etiquetas[j+1],"NO",TAM_VAR_TXT - 1);
                    }
                }
            pan_alin[j+1]=LV_ALIGN_TOP_RIGHT;
            pan_txt[j+1]=TXT_42;
            j++;
            break;
        case TIPO_PASSWORD_SL:
            mnu_edicion.ms_parpadea=millis();
            for(l=0;l<mnu_edicion.pos_digito;l++)
                str_Aux[l]='*';           
            if(mnu_edicion.digito_ON==true)
                {
                str_Aux[l]='_';               
                mnu_edicion.digito_ON=false;
                }
            else
                {
                str_Aux[l]='*';
                mnu_edicion.digito_ON=true;
                }
            str_Aux[l+1]='\0';
            strcpy(pan_Etiquetas[j+1],str_Aux);
            Cant_Items_Nivel=2;
            pan_alin[j+1]=LV_ALIGN_TOP_RIGHT;
            pan_txt[j+1]=TXT_42;
            j++;
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
            if(k<TotPan)//Cant_Items_Nivel)
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
                lv_label_set_text_fmt(ui_Menu2, " ");
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
           if(k<TotPan)//Cant_Items_Nivel)
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
                lv_label_set_text_fmt(ui_Menu3, " ");
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
           if(k<TotPan)//Cant_Items_Nivel)
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
                lv_label_set_text_fmt(ui_Menu4, " ");
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
//char str_aux[TAM_VAR_TXT];
if(menu[mnu_item_actual].Nivel== ID_PAN_CARGA)
    {
    switch(Tecla)
        {
        case 'S':
        //Apagar Bomba
        Serial.println("Hola 1");
        if(BombaON)//Si es primera vez, mostrar cartel 
            {// 'Carga Detenida'
            // 'Pres STOP para elegir'
            BombaON=false;
            msgbox.visible=true;
            sprintf(msgbox.text1,"Carga Detenida");
            sprintf(msgbox.text2,"Pres STOP");            
            }
        else
            {
            msgbox.visible=false;
            pan_primer_item=0;//Si no se esta en edicion
            mnu_cambio_menu(mnu_busca_BackNivel(mnu_item_actual));
            }
        break;    
        }
    return;
    }
if(menu[mnu_item_actual].Nivel==ID_PAN_IO)
    {
    switch(Tecla)
    {
        case '0':
            //Poner en 0 el volumen
            break;
        case '1':
            //Encender/Apagar Bomba
            break;

        case 'S':
            //Apagar Bomba
            //Cerrar Valvula Desaireador
            //Apagar TM
            pan_primer_item=0;//Si no se esta en edicion
            mnu_cambio_menu(mnu_busca_BackNivel(mnu_item_actual));
            break;
    }
    return;
    }
if(Tecla>='0' && Tecla<='9' )
    {
    if(mnu_edicion.item_ON==false && menu[mnu_item_actual].Tipo==TIPO_ETIQ)
        {
        //Busca si tiene tecla rapida        
        for(int i=0;i<sizeof(menu) / sizeof(menu[0]); i++)
            {
            if(menu[i].Nivel==menu[mnu_item_actual].Nivel && menu[i].Tecla_Rapida==Tecla)
                {
                if(menu[i].Nivel_Next==ID_PASSWORD)
                    {
                    mnu_cambio_menu(mnu_busca_nextNivel(i));
                    mnu_edicion.digito_ON=false;
                    mnu_edicion.item_ON=true;
                    mnu_edicion.ms_parpadea = millis();
                    mnu_edicion.pos_digito=0;
                    strcpy(mnu_edicion.str_dato,"");
                    }
                else
                    {
                    mnu_cambio_menu(mnu_busca_nextNivel(i));
                    }
                }
            }
        }       
    else
        {
        if(mnu_edicion.item_ON==false)
            {
            mnu_trae_dato_edit();
            }
        switch(menu[mnu_item_actual].Tipo)
            {
            case TIPO_TXT_M:
            case TIPO_SHORT_M:          
            case TIPO_PASSWORD_SL:
                mnu_edicion.item_ON=true;
                mnu_edicion.str_dato[mnu_edicion.pos_digito+1]='\0';
                mnu_edicion.str_dato[mnu_edicion.pos_digito]=Tecla;
                if(++mnu_edicion.pos_digito>=menu[mnu_item_actual].Cant_digitos)
                    mnu_edicion.pos_digito=menu[mnu_item_actual].Cant_digitos-1;                
                break;                
            case TIPO_SINGLE_M:
                mnu_edicion.item_ON=true;
                mnu_edicion.str_dato[mnu_edicion.pos_digito+1]='\0';
                mnu_edicion.str_dato[mnu_edicion.pos_digito]=Tecla;
                 if(++mnu_edicion.pos_digito>=15)
                     mnu_edicion.pos_digito=15;
                break;
            case TIPO_HORA_SM_SL:
            case TIPO_FECHA_SM_SL:
                mnu_edicion.item_ON=true;
                mnu_edicion.str_dato[mnu_edicion.pos_digito]=Tecla;            
                if(++mnu_edicion.pos_digito>7)
                    mnu_edicion.pos_digito=7;
                if(mnu_edicion.pos_digito==2 || mnu_edicion.pos_digito==5 )//Esta parado sobre ':' o sobre '-' == Avanza 1
                    mnu_edicion.pos_digito++;
                break;
            case TIPO_TXT_ALFA:
                mnu_edicion.item_ON=true;
                switch(Tecla)
                    {
                    case '0':
                        mnu_edicion.str_dato[mnu_edicion.pos_digito]='-';
                        break;
                    case '1':
                        mnu_edicion.str_dato[mnu_edicion.pos_digito]=' ';
                        break;
                    case '2':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'A')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='A';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'C')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='A';
                        break;
                    case '3':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'D')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='D';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'F')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='D';
                        break;
                    case '4':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'G')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='G';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'I')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='G';
                        break;
                    case '5':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'J')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='J';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'L')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='J';
                        break;
                    case '6':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'M')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='M';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'O')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='M';
                        break;
                    case '7':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'P')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='P';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'S')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='P';
                        break;
                    case '8':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'T')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='T';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'V')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='T';
                        break;
                    case '9':
                        if(mnu_edicion.str_dato[mnu_edicion.pos_digito]<'W')
                            mnu_edicion.str_dato[mnu_edicion.pos_digito]='W';
                        else
                            if(++mnu_edicion.str_dato[mnu_edicion.pos_digito]>'Z')
                                mnu_edicion.str_dato[mnu_edicion.pos_digito]='W';
                        break;                    
                    }

                break;
            default:
                break;
            }
        }
    }
switch(Tecla)
    {
    case 'O': //Ok
    case 'o': //Ok
    Serial.println("-------------OK-------------");
    if(mnu_edicion.item_ON==false)
        {
        mnu_trae_dato_edit();
        }
    else //Editando variable
        {//Guarda Variable editada
        mnu_edicion.item_ON=false;
        switch(menu[mnu_item_actual].Tipo)
            {
            case TIPO_HORA_SM_SL:
                //if(validarHora(mnu_edicion.str_dato))
                    strncpy(variables.vtxt[menu[mnu_item_actual].Variable_Asoc],mnu_edicion.str_dato,TAM_VAR_TXT-1);
                break;
            case TIPO_FECHA_SM_SL:
                //if(validarFecha(mnu_edicion.str_dato))
                    strncpy(variables.vtxt[menu[mnu_item_actual].Variable_Asoc],mnu_edicion.str_dato,TAM_VAR_TXT-1);
                break;
            case TIPO_TXT_M:
            case TIPO_TXT_ALFA:
                strncpy(variables.vtxt[menu[mnu_item_actual].Variable_Asoc],mnu_edicion.str_dato,TAM_VAR_TXT-1);
                Serial.printf("mnu_item_actual: %d\n",mnu_item_actual);
                Serial.printf("variables.vtxt[menu[mnu_item_actual].Variable_Asoc]: %s\n",variables.vtxt[menu[mnu_item_actual].Variable_Asoc]);
                break;
            case TIPO_SHORT_M:
                variables.vshort[menu[mnu_item_actual].Variable_Asoc]=atoi(mnu_edicion.str_dato);
                break;
            case TIPO_SINGLE_M:
                variables.vfloat[menu[mnu_item_actual].Variable_Asoc]=atof(mnu_edicion.str_dato);
                break;
            case TIPO_BIT_M:
                if(!strcmp(mnu_edicion.str_dato,"SI"))                    
                    variables.vbit|=(1<<menu[mnu_item_actual].Variable_Asoc);
                else
                    variables.vbit&=~(1<<menu[mnu_item_actual].Variable_Asoc);
                break;
            default:
            break;
            }

            mnu_prov=mnu_Nxt_item();
            if(mnu_prov>=0)
                {
                mnu_cambio_menu(mnu_prov);
                switch(menu[mnu_item_actual].Tipo)
                    {//Todos los editables
                    case TIPO_SINGLE_M:
                    case TIPO_BIT_M:
                    case TIPO_SHORT_M:
                    case TIPO_TXT_M:
                    case TIPO_TXT_ALFA:
                    case TIPO_FECHA_SM_SL:
                    case TIPO_HORA_SM_SL:                    
                //        mnu_trae_dato_edit();
                        break;
                    default:
                        break;
                    }
                }
            else
                {
                if(menu[mnu_item_actual].Nivel_Next!=ID_VOID)
                    {
                    // switch(menu[mnu_item_actual].Post_Proceso)
                    //     {
                    //     case POST_INIT_VAR_RECORRIDO:
                    //         //Variables de recorrido en cero.
                    //         Serial.println("POST_INIT_VAR_RECORRIDO");
                    //         Init_tour();
                    //         break;
                    //     case POST_START_RECORRIDO:
                    //         Serial.println("Save Recorrido");                
                    //         save_ini_recorrido();
                    //     break;
                    //     }
                    pan_primer_item=0;//Si no se esta en edicion
                    mnu_cambio_menu(mnu_busca_nextNivel(mnu_item_actual));
                    }
                }

        mnu_show();
        if(menu[mnu_item_actual].Nivel ==  ID_PASSWORD)
            {
            if(mnu_validar_password(mnu_edicion.str_dato))
                {
                mnu_cambio_menu(mnu_busca_Nivel(ID_PARAMETROS));
                }
            else
                {
                //Llamar  a MessageBox("Incorrecto",3);
                mnu_edicion.digito_ON=false;
                mnu_edicion.item_ON=true;
                mnu_edicion.ms_parpadea = millis();
                mnu_edicion.pos_digito=0;
                strcpy(mnu_edicion.str_dato,"");                
                }
            }
        }
        break;
    case 'S': //Stop    
    case 's': //Stop
    Serial.println("-----------STOP------------");
        if(menu[mnu_item_actual].Nivel==ID_PASSWORD)
            {
            pan_primer_item=0;
            mnu_cambio_menu(mnu_busca_Nivel(ID_FUNCIONES));
            }
        else
            {
            if(menu[mnu_item_actual].Nivel_Back==ID_MEMORIA)
                {
                pan_primer_item=pan_primer_item_back;
                mnu_cambio_menu(mnu_item_back);
                }
            else
                {
                if(mnu_edicion.item_ON==true)
                    {
                    mnu_edicion.item_ON=false;
                    mnu_show();
                    }
                else
                    {
                    if(menu[mnu_item_actual].Nivel_Back!=ID_VOID)
                        {
                        pan_primer_item=0;//Si no se esta en edicion
                        mnu_cambio_menu(mnu_busca_BackNivel(mnu_item_actual));
                        }
                    }
                }
            switch(menu[mnu_item_actual].Post_Proceso)
                {
                case POST_SAVE_PARAM:
                save_variables("/parametros.txt");
                break;
                case POST_START_RECORRIDO:
//                save_ini_recorrido();
                break;

                }
            }
        break;
    case 'P'://Printer
    case 'p':
    case '.'://Printer
       if(mnu_edicion.item_ON==false)
            {
            //Avanza impresora
            }
        else
            {
            if(menu[mnu_item_actual].Tipo==TIPO_SINGLE_M)
                {                
                mnu_edicion.str_dato[mnu_edicion.pos_digito]='.';
                mnu_edicion.str_dato[mnu_edicion.pos_digito+1]='\0';
                if(++mnu_edicion.pos_digito>=15)
                    {
                    mnu_edicion.pos_digito=15;                
                    }
                }
            }
        break;
    case 'F': // Funcion / '-'
    case 'f':
    //No se puede llamar a la funcion en el medio de una carga
    if(mnu_edicion.item_ON==true)
        {
        switch(menu[mnu_item_actual].Tipo)
            {
            case TIPO_SINGLE_M:
                mnu_edicion.str_dato[mnu_edicion.pos_digito]='-';
                mnu_edicion.str_dato[mnu_edicion.pos_digito+1]='\0';
                if(++mnu_edicion.pos_digito>=menu[mnu_item_actual].Cant_digitos)
                    {
                    mnu_edicion.pos_digito=menu[mnu_item_actual].Cant_digitos-1;                
                    }
                break;
            }
        }
        else
            {
            if(menu[mnu_item_actual].Nivel!=ID_PASSWORD)
                {
                mnu_item_back= mnu_item_actual;
                pan_primer_item_back=pan_primer_item;
                mnu_cambio_menu(mnu_busca_Nivel(ID_FUNCIONES));
                }
            }
        break;
    case 'U': //UP
    case 'u':
        Serial.println("-----------UP------------");
        if(mnu_edicion.item_ON==true)
            {
            if(menu[mnu_item_actual].Tipo==TIPO_BIT_M)
                {
                if(strcmp(mnu_edicion.str_dato,"SI"))
                    strncpy(mnu_edicion.str_dato,"SI",TAM_VAR_TXT - 1);
                else
                    strncpy(mnu_edicion.str_dato,"NO",TAM_VAR_TXT - 1);
                }
            else
                {
                switch(menu[mnu_item_actual].Tipo)
                    {
                    case TIPO_HORA_SM_SL:
                    case TIPO_FECHA_SM_SL:   
                        if(++mnu_edicion.pos_digito>7)
                            mnu_edicion.pos_digito=7;
                        if(mnu_edicion.pos_digito==2 || mnu_edicion.pos_digito==5 )//Esta parado sobre ':' o sobre '-' == Avanza 1
                            mnu_edicion.pos_digito++;
                        break;
                    default:
                        // if(++mnu_edicion.pos_digito>=menu[mnu_item_actual].Cant_digitos)
                        //     {
                        //     mnu_edicion.pos_digito=menu[mnu_item_actual].Cant_digitos-1;                
                        //     }
                        break;
                    }                
                }
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
        Serial.println("----------------DOWN--------------");
        if(mnu_edicion.item_ON==true)
            {
            if(menu[mnu_item_actual].Tipo==TIPO_BIT_M)
                {
                if(strcmp(mnu_edicion.str_dato,"SI"))
                    strncpy(mnu_edicion.str_dato,"SI",TAM_VAR_TXT - 1);
                else
                    strncpy(mnu_edicion.str_dato,"NO",TAM_VAR_TXT - 1);
                }
            else
                {
                switch(menu[mnu_item_actual].Tipo)
                    {
                    case TIPO_HORA_SM_SL:
                    case TIPO_FECHA_SM_SL:   
                        if(mnu_edicion.pos_digito>0)
                            mnu_edicion.pos_digito--;
                        if(mnu_edicion.pos_digito==2 || mnu_edicion.pos_digito==5 )//Esta parado sobre ':' o sobre '-' == Avanza 1
                            mnu_edicion.pos_digito--;
                        break;
                    default:
                        // if(mnu_edicion.pos_digito>0)
                        //     mnu_edicion.pos_digito--;           
                        break;
                    }
                }
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
//        Serial.printf("Item_Actual: %d \n",mnu_item_actual);
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

void mnu_trae_dato_edit(void)
{
char format[20];
switch(menu[mnu_item_actual].Tipo)
    {
    case TIPO_TXT_M:
    case TIPO_TXT_ALFA:
    case TIPO_HORA_SM_SL:
    case TIPO_FECHA_SM_SL:            
        strncpy(mnu_edicion.str_dato,variables.vtxt[menu[mnu_item_actual].Variable_Asoc],TAM_VAR_TXT-1);
        mnu_edicion.digito_ON=false;
        mnu_edicion.item_ON=true;
        mnu_edicion.ms_parpadea = millis();
        mnu_edicion.pos_digito=0;
        break;
    case TIPO_SHORT_M:
        sprintf(mnu_edicion.str_dato,"%d",variables.vshort[menu[mnu_item_actual].Variable_Asoc]);
        mnu_edicion.digito_ON=false;
        mnu_edicion.item_ON=true;
        mnu_edicion.ms_parpadea = millis();
        mnu_edicion.pos_digito=0;
        break;
    case TIPO_SINGLE_M:
        sprintf(format, "%%.%df", menu[mnu_item_actual].Cant_digitos);
        sprintf(mnu_edicion.str_dato,format,variables.vfloat[menu[mnu_item_actual].Variable_Asoc]);
        mnu_edicion.digito_ON=false;        
        mnu_edicion.item_ON=true;
        mnu_edicion.ms_parpadea = millis();
        mnu_edicion.pos_digito=0;
        break;
    case TIPO_BIT_M:
        mnu_edicion.digito_ON=false;
        mnu_edicion.item_ON=true;
        mnu_edicion.ms_parpadea = millis();
        mnu_edicion.pos_digito=0;
        if(variables.vbit&(1<<menu[mnu_item_actual].Variable_Asoc))
            {
            strncpy(mnu_edicion.str_dato,"SI",TAM_VAR_TXT - 1);
            }
        else
            {
            strncpy(mnu_edicion.str_dato,"NO",TAM_VAR_TXT - 1);
            }
        break;                
    default://No editables    
        switch(menu[mnu_item_actual].Nivel_Next)
            {
            case ID_NXT_ITEM:
                mnu_cambio_menu(mnu_Nxt_item());
                break;
            default:
                if(menu[mnu_item_actual].Nivel_Next!=ID_VOID)
                    {
                    pan_primer_item=0;//Si no se esta en edicion
                    mnu_cambio_menu(mnu_busca_nextNivel(mnu_item_actual));
                    }
                break;
            }
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

int mnu_busca_Nivel(int Nivel)
{
for(int i=0;i<sizeof(menu) / sizeof(menu[0]); i++)
    {
    if(menu[i].Nivel==Nivel)
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
mnu_edicion.item_ON=false;
PostMenu();

mnu_item_actual=New_item;
//mnu_item_back= mnu_item_actual;
//pan_primer_item_back=pan_primer_item;
PreMenu();

mnu_show();
}


char mnu_validar_password(char password[])
{

  if(!strcmp(password,variables.vtxt[TXT_PASSWORD_MEM_1]) || !strcmp(password,PASSWORD_FIX))
    return 1;
  else
    return 0;
// mnu_msgbox(MSG_INVALIDO, MNU_MSGBOX_CUALQUIER);
}

void PostMenu(void)
{
switch(menu[mnu_item_actual].Post_Proceso)
    {
    case POST_INIT_VAR_RECORRIDO:
        //Variables de recorrido en cero.
        Serial.println("POST_INIT_VAR_RECORRIDO");
        Inicializa_var_tour();
        break;
    case POST_START_RECORRIDO:
        Serial.println("Save Recorrido");                
        save_ini_recorrido();
        
    break;
    }    
}

extern struct Dis Display;
void PreMenu(void)
{
switch(menu[mnu_item_actual].Pre_proceso)
    {
     case PRE_PAN_CARGA:
        BombaON=true;
        //Enciende Bomba
        //Display.Actual=2;
        //Display.Change=true;
     break;
     case PRE_EDIT_ON:
        mnu_edicion.item_ON=true;
        mnu_trae_dato_edit();
        break;
     default:
     break;
    }
}

void Inicializa_var_tour(void)
{
    strcpy(variables.vtxt[TXT_REMITO],"");
    strcpy(variables.vtxt[TXT_NUM_LINEA],"");
    strcpy(variables.vtxt[TXT_NRO_REC],"");
    strcpy(variables.vtxt[TXT_CHOFER],"");
}

void Inializa_var_Tambo(void)
{
    variables.vfloat[FLOAT_CANTIDAD_A]=0.0;
    variables.vfloat[FLOAT_CANTIDAD_B]=0.0;
    variables.vfloat[FLOAT_CANTIDAD_C]=0.0;
    variables.vfloat[FLOAT_TEMP_LECHE_PROMEDIO]=0.0;
    variables.vfloat[FLOAT_TEMP_MIN_ALCANZADA]=99.9;
    variables.vfloat[FLOAT_TEMP_MAX_ALCANZADA]=-9.9;
}