#include "config.h"

Font font = {0};

void SetFont()
{
    for (int i = 0; i < PRELOAD_COUNT; i++) codepoints[i] = i;    
    font = LoadFontEx(FONT_LOC,FONT_SIZE,codepoints,glyphCount);
    SetTextureFilter(font.texture,TEXTURE_FILTER_POINT);
}
