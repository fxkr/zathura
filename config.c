/* See LICENSE file for license and copyright information */

#include "config.h"
#include "commands.h"
#include "completion.h"
#include "shortcuts.h"
#include "zathura.h"

void
config_load_default(zathura_t* zathura)
{
  if (!zathura || !zathura->ui.session) {
    return;
  }

  int int_value              = 0;
  char* string_value         = NULL;
  girara_session_t* gsession = zathura->ui.session;

  /* general settings */
  girara_mode_set(gsession, NORMAL);

  /* zathura settings */
  int_value = 10;
  girara_setting_add(gsession, "zoom-step",     &int_value, INT, false, "Zoom step",              NULL);
  int_value = 1;
  girara_setting_add(gsession, "page-padding",  &int_value, INT, true,  "Padding between pages",  NULL);
  int_value = 2;
  girara_setting_add(gsession, "pages-per-row", &int_value, INT, false, "Number of pages per row", NULL);

  string_value = "#FFFFFF";
  girara_setting_add(gsession, "recolor-dark-color",  string_value, STRING, false, "Recoloring (dark color)",  NULL);
  string_value = "#000000";
  girara_setting_add(gsession, "recolor-light-color", string_value, STRING, false, "Recoloring (light color)", NULL);

  /* define default shortcuts */
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_c,          NULL, sc_abort,             0,                   0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_Escape,     NULL, sc_abort,             0,                   0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_a,          NULL, sc_adjust_window,     NORMAL,              ADJUST_BESTFIT,  NULL);
  girara_shortcut_add(gsession, 0,                GDK_s,          NULL, sc_adjust_window,     NORMAL,              ADJUST_WIDTH,    NULL);
  girara_shortcut_add(gsession, 0,                GDK_i,          NULL, sc_change_mode,       NORMAL,              INSERT,          NULL);
  girara_shortcut_add(gsession, 0,                GDK_m,          NULL, sc_change_mode,       NORMAL,              ADD_MARKER,      NULL);
  girara_shortcut_add(gsession, 0,                GDK_apostrophe, NULL, sc_change_mode,       NORMAL,              EVAL_MARKER,     NULL);
  girara_shortcut_add(gsession, 0,                GDK_slash,      NULL, sc_focus_inputbar,    NORMAL,              0,               &("/"));
  girara_shortcut_add(gsession, GDK_SHIFT_MASK,   GDK_slash,      NULL, sc_focus_inputbar,    NORMAL,              0,               &("/"));
  girara_shortcut_add(gsession, 0,                GDK_question,   NULL, sc_focus_inputbar,    NORMAL,              0,               &("?"));
  girara_shortcut_add(gsession, 0,                GDK_colon,      NULL, sc_focus_inputbar,    NORMAL,              0,               &(":"));
  girara_shortcut_add(gsession, 0,                GDK_o,          NULL, sc_focus_inputbar,    NORMAL,              0,               &(":open "));
  girara_shortcut_add(gsession, 0,                GDK_O,          NULL, sc_focus_inputbar,    NORMAL,              APPEND_FILEPATH, &(":open "));
  girara_shortcut_add(gsession, 0,                GDK_f,          NULL, sc_follow,            NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                0,              "gg", sc_goto,              NORMAL | FULLSCREEN, TOP,             NULL);
  girara_shortcut_add(gsession, 0,                0,              "G",  sc_goto,              NORMAL | FULLSCREEN, BOTTOM,          NULL);
  girara_shortcut_add(gsession, 0,                GDK_J,          NULL, sc_navigate,          NORMAL,              NEXT,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_K,          NULL, sc_navigate,          NORMAL,              PREVIOUS,        NULL);
  girara_shortcut_add(gsession, GDK_MOD1_MASK,    GDK_Right,      NULL, sc_navigate,          NORMAL,              NEXT,            NULL);
  girara_shortcut_add(gsession, GDK_MOD1_MASK,    GDK_Left,       NULL, sc_navigate,          NORMAL,              PREVIOUS,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_Left,       NULL, sc_navigate,          FULLSCREEN,          PREVIOUS,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_Up,         NULL, sc_navigate,          FULLSCREEN,          PREVIOUS,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_Down,       NULL, sc_navigate,          FULLSCREEN,          NEXT,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_Right,      NULL, sc_navigate,          FULLSCREEN,          NEXT,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_k,          NULL, sc_navigate_index,    INDEX,               UP,              NULL);
  girara_shortcut_add(gsession, 0,                GDK_j,          NULL, sc_navigate_index,    INDEX,               DOWN,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_h,          NULL, sc_navigate_index,    INDEX,               COLLAPSE,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_l,          NULL, sc_navigate_index,    INDEX,               EXPAND,          NULL);
  girara_shortcut_add(gsession, 0,                GDK_space,      NULL, sc_navigate_index,    INDEX,               SELECT,          NULL);
  girara_shortcut_add(gsession, 0,                GDK_Return,     NULL, sc_navigate_index,    INDEX,               SELECT,          NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_i,          NULL, sc_recolor,           NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_R,          NULL, sc_reload,            NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_r,          NULL, sc_rotate,            NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_h,          NULL, sc_scroll,            NORMAL,              LEFT,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_j,          NULL, sc_scroll,            NORMAL,              DOWN,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_k,          NULL, sc_scroll,            NORMAL,              UP,              NULL);
  girara_shortcut_add(gsession, 0,                GDK_l,          NULL, sc_scroll,            NORMAL,              RIGHT,           NULL);
  girara_shortcut_add(gsession, 0,                GDK_Left,       NULL, sc_scroll,            NORMAL,              LEFT,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_Up,         NULL, sc_scroll,            NORMAL,              UP,              NULL);
  girara_shortcut_add(gsession, 0,                GDK_Down,       NULL, sc_scroll,            NORMAL,              DOWN,            NULL);
  girara_shortcut_add(gsession, 0,                GDK_Right,      NULL, sc_scroll,            NORMAL,              RIGHT,           NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_d,          NULL, sc_scroll,            NORMAL,              HALF_DOWN,       NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_u,          NULL, sc_scroll,            NORMAL,              HALF_UP,         NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_f,          NULL, sc_scroll,            NORMAL,              FULL_DOWN,       NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_b,          NULL, sc_scroll,            NORMAL,              FULL_UP,         NULL);
  girara_shortcut_add(gsession, 0,                GDK_space,      NULL, sc_scroll,            NORMAL,              FULL_DOWN,       NULL);
  girara_shortcut_add(gsession, GDK_SHIFT_MASK,   GDK_space,      NULL, sc_scroll,            NORMAL,              FULL_UP,         NULL);
  girara_shortcut_add(gsession, 0,                GDK_n,          NULL, sc_search,            NORMAL,              FORWARD,         NULL);
  girara_shortcut_add(gsession, 0,                GDK_N,          NULL, sc_search,            NORMAL,              BACKWARD,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_Tab,        NULL, sc_toggle_index,      NORMAL | INDEX,      0,               NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_m,          NULL, sc_toggle_inputbar,   NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_F5,         NULL, sc_toggle_fullscreen, NORMAL | FULLSCREEN, 0,               NULL);
  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_n,          NULL, sc_toggle_statusbar,  NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_q,          NULL, sc_quit,              NORMAL,              0,               NULL);
  girara_shortcut_add(gsession, 0,                GDK_plus,       NULL, sc_zoom,              NORMAL | FULLSCREEN, ZOOM_IN,         NULL);
  girara_shortcut_add(gsession, 0,                GDK_minus,      NULL, sc_zoom,              NORMAL | FULLSCREEN, ZOOM_OUT,        NULL);
  girara_shortcut_add(gsession, 0,                GDK_equal,      NULL, sc_zoom,              NORMAL | FULLSCREEN, ZOOM_ORIGINAL,   NULL);
  girara_shortcut_add(gsession, 0,                0,              "zI", sc_zoom,              NORMAL | FULLSCREEN, ZOOM_IN,         NULL);
  girara_shortcut_add(gsession, 0,                0,              "zO", sc_zoom,              NORMAL | FULLSCREEN, ZOOM_OUT,        NULL);
  girara_shortcut_add(gsession, 0,                0,              "z0", sc_zoom,              NORMAL | FULLSCREEN, ZOOM_ORIGINAL,   NULL);

  /* define default inputbar commands */
  girara_inputbar_command_add(gsession, "bmark",   NULL, cmd_bookmark_create, NULL,     "Add a bookmark");
  girara_inputbar_command_add(gsession, "bdelete", NULL, cmd_bookmark_delete, NULL,     "Delete a bookmark");
  girara_inputbar_command_add(gsession, "blist",   NULL, cmd_bookmark_open,   NULL,     "List all bookmarks");
  girara_inputbar_command_add(gsession, "close",   NULL, cmd_close,           NULL,     "Close current file");
  girara_inputbar_command_add(gsession, "info",    NULL, cmd_info,            NULL,     "Show file information");
  girara_inputbar_command_add(gsession, "print",   NULL, cmd_print,           cc_print, "Print document");
  girara_inputbar_command_add(gsession, "save",    NULL, cmd_save,            NULL,     "Save document");
}

void
config_load_file(zathura_t* zathura, char* path)
{
  if (zathura == NULL) {
    return;
  }

  girara_config_parse(zathura->ui.session, path);
}
