/* See LICENSE file for copyright and license details. */
#define XF86XK_AudioLowerVolume	0x1008FF11   /* Volume control down        */
#define XF86XK_AudioMute	0x1008FF12   /* Mute sound from the system */
#define XF86XK_AudioRaiseVolume	0x1008FF13   /* Volume control up          */
#define XF86XK_MonBrightnessUp   0x1008FF02  /* Monitor/panel brightness */
#define XF86XK_MonBrightnessDown 0x1008FF03  /* Monitor/panel brightness */
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#35455e";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "www", "file", "term", "note", "vm", "vid", "soc", "dw", "misc" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      	instance    title       tags mask     isfloating   monitor */
	{ "Gimp",   	  NULL,       NULL,       0,            1,           -1 },
	{ "Firefox", 	  NULL,       NULL,       1 << 0,       0,           -1 },
	{ "Qutebrowser", 	  NULL,       NULL,       1 << 0,       0,           -1 },
	{ "Pcmanfm", 	  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "URxvt",   	  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Emacs",   	  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Mpv",     	  NULL,       NULL,       1 << 5,       0,           -1 },
	{ "Celluloid",    NULL,       NULL,       1 << 5,       0,           -1 },
	{ "Transmission", NULL,       NULL,       1 << 7,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *volumeup[] = { "amixer", "-q", "sset", "Master", "1%+", NULL };
static const char *volumedown[] = { "amixer", "-q", "sset", "Master", "1%-", NULL };
static const char *volumemute[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "toggle", NULL };
static const char *brightnessdown[] = { "brightnessctl", "set", "1-", NULL };
static const char *brightnessup[] = { "brightnessctl", "set", "1+", NULL };
static const char *browser[] = { "qutebrowser", NULL };
static const char *browser2[] = { "firefox", NULL };
static const char *files[] = { "pcmanfm", NULL };
static const char *emacs[] = { "emacs", NULL };
static const char *screenshot[] = { "scrot", NULL };

//Use XEV to find which keys you press

static Key keys[] = {
	/* modifier                     key       		 function        argument */
	{ MODKEY,                       XK_p,     		 spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,		 spawn,          {.v = termcmd } },
	{ MODKEY, 	                0xffbe,			 spawn,          {.v = browser } },
	{ MODKEY|ShiftMask,           	0xffbe,			 spawn,          {.v = browser2 } },
	{ MODKEY,        	    	0xffbf,			 spawn,          {.v = files } },
	{ MODKEY,            		0xffc1, 		 spawn,          {.v = emacs } },
	{ 0,	        		XF86XK_MonBrightnessUp,	 spawn,          {.v = brightnessdown } },
	{ 0,            		XF86XK_MonBrightnessUp,	 spawn,          {.v = brightnessup } },
	{ 0,              		XF86XK_AudioLowerVolume, spawn,          {.v = volumedown } },
	{ 0,              		XF86XK_AudioMute,	 spawn,          {.v = volumemute } },
	{ 0,             		XF86XK_AudioRaiseVolume, spawn,          {.v = volumeup } },
	{ MODKEY,             		XK_Return,		 spawn,          {.v = screenshot } },
	{ MODKEY,                       XK_b,     		 togglebar,      {0} },
	{ MODKEY,                       XK_j,     		 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,     		 focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,     		 incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,     		 incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, 		zoom,           {0} },
	{ MODKEY,                       XK_Tab,    		view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      		killclient,     {0} },
	{ MODKEY,                       XK_t,      		setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      		setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      		setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  		setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, {0} },
	{ MODKEY,                       XK_0,     		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  		focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

