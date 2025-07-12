#ifndef CONFIG_H
#define CONFIG_H

#include "raylib.h"

#define FONT_LOC "Roboto.ttf"
#define FONT_SIZE 28
#define TARGET_FPS 60
#define PRELOAD_COUNT 128
#define BUF_LEN 1024

extern Font font;
static const int glyphCount = PRELOAD_COUNT;
static int codepoints[PRELOAD_COUNT];
    
void SetFont();

#endif // CONFIG_H
