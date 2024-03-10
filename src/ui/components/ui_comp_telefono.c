// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT Telefono

lv_obj_t * ui_Telefono_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Telefono;
    cui_Telefono = lv_img_create(comp_parent);
    lv_obj_set_width(cui_Telefono, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Telefono, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Telefono, -11);
    lv_obj_set_y(cui_Telefono, 34);
    lv_obj_set_align(cui_Telefono, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Telefono, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Telefono, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TELEFONO_NUM);
    children[UI_COMP_TELEFONO_TELEFONO] = cui_Telefono;
    lv_obj_add_event_cb(cui_Telefono, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Telefono, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Telefono_create_hook(cui_Telefono);
    return cui_Telefono;
}
