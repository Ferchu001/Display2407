SET(SOURCES components/ui_comp_label2.c
    components/ui_comp_panel1.c
    components/ui_comp_textarea2.c
    components/ui_comp.c
    screens/ui_Screen1.c
    screens/ui_Screen2.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_OpenSansCSB42.c
    fonts/ui_font_OpenSansCSB48.c
    fonts/ui_font_OpenSansCSB96.c
    fonts/ui_font_OpenSans102.c
    fonts/ui_font_OpenSans52.c)

add_library(ui ${SOURCES})
