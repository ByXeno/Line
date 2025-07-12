#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"
#include "config.h"
#include "history.h"
#include <string.h>
#include <stdlib.h>

static int isBlink = 0;
static int BlinkCounter = 0;

static int EntryIndex = 0;
static char Tmp_Buf[BUF_LEN] = {0};

void RenderCursor(int pos);
void Parse(char* line,int* argc,char** argv);
void GoUpperInHistory(char* line);
void GoLowerInHistory(char* line);
void RemoveCharacter(char* line);
void Type(char* line);

#endif // UTILS_H
