// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT TextArea2

lv_obj_t * ui_TextArea2_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_TextArea2;
    cui_TextArea2 = lv_textarea_create(comp_parent);
    lv_obj_set_width(cui_TextArea2, 150);
    lv_obj_set_height(cui_TextArea2, 70);
    lv_obj_set_x(cui_TextArea2, 75);
    lv_obj_set_y(cui_TextArea2, 32);
    lv_obj_set_align(cui_TextArea2, LV_ALIGN_CENTER);
    lv_textarea_set_text(cui_TextArea2, "TextArea");
    lv_textarea_set_placeholder_text(cui_TextArea2, "Placeholder...");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TEXTAREA2_NUM);
    children[UI_COMP_TEXTAREA2_TEXTAREA2] = cui_TextArea2;
    lv_obj_add_event_cb(cui_TextArea2, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_TextArea2, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_TextArea2_create_hook(cui_TextArea2);
    return cui_TextArea2;
}
