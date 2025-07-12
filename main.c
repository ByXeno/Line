#include "raylib.h"
#include "history.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1024,56,"Line");

    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(TARGET_FPS);

    InitHistory();
    LoadHistory();
    
    SetFont();
    
    char line[BUF_LEN] = {0};

    char* argv[128] = {0};
    int argc = 0;
    
    while(!WindowShouldClose())
    {
	if(IsKeyPressed(KEY_UP))
	{
	    GoUpperInHistory(line);
	}
	
	if(IsKeyPressed(KEY_DOWN))
	{
	    GoLowerInHistory(line);
	}
	
	if(IsKeyPressed(KEY_BACKSPACE) && (strlen(line) != 0))
	{
	    RemoveCharacter(line);
	}
	if(IsKeyPressedRepeat(KEY_BACKSPACE) && (strlen(line) != 0))
	{
	    if(IsKeyDown(KEY_BACKSPACE) && strlen(line) != 0)
	    {
		line[strlen(line) - 1] = 0;
	    }
	}
	if(IsKeyPressed(KEY_ENTER))
	{
	    if(strlen(line) == 0) {break;}
	    AddToHistory(line);
	    //Parse(line,&argc,argv);
	    break;
	}
	Type(line);

	
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTextEx(font,line,(Vector2){.y=FONT_SIZE/2,.x= FONT_SIZE},FONT_SIZE,0,RAYWHITE);
	RenderCursor(strlen(line));
	EndDrawing();
    }

    for (int i = 0; i < argc; i++) {free(argv[i]);}
    UnloadFont(font);
    WriteHistory();
    FreeHistory();
    CloseWindow();
    return 0;
}
