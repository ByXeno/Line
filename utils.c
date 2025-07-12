#include "utils.h"

void RenderCursor(int pos)
{
    DrawTextEx(font,">",(Vector2){.y=FONT_SIZE/2,.x= FONT_SIZE/2},FONT_SIZE,0,RAYWHITE);
    if(BlinkCounter == 0)
    {
	isBlink = (isBlink == 0) ?1:0;
	BlinkCounter = TARGET_FPS/2;
    }
    BlinkCounter--;

    Color color = (isBlink == 0) ? BLACK:WHITE;
    DrawTextEx(font,"|",(Vector2){.y=FONT_SIZE/2,.x= FONT_SIZE+pos*12},FONT_SIZE,0,color);
}

void GoUpperInHistory(char* line)
{
    if(GetEntryCount() - 1 - EntryIndex > 0)
    {
	EntryIndex++;
	if(EntryIndex == 1)
	{
	    memcpy(Tmp_Buf,line,BUF_LEN);
	}
	memset(line,0,BUF_LEN);
	char* entry = GetEntryFromHistory(EntryIndex - 1);
	memcpy(line,entry,strlen(entry));
    }
}

void GoLowerInHistory(char* line)
{
    if(EntryIndex > 0)
    {
	EntryIndex--;
	memset(line,0,BUF_LEN);
	if(EntryIndex == 0)
	{
	    memcpy(line,Tmp_Buf,BUF_LEN);
	}
	else
	{
	    char* entry = GetEntryFromHistory(EntryIndex - 1);
	    memcpy(line,entry,strlen(entry));
	}
    }
}

void RemoveCharacter(char* line)
{
    int last_c = strlen(line);
    if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))
    {
	int a = last_c;
	while(line[a] != ' ')
	{
	    a--;
	    if(a < 0) {a = 0;break;}
	}
	memset(&line[a],0,last_c-a);
    }
    else{
	line[last_c-1] = 0;
    }
}

void Parse(char* line,int* argc,char** argv)
{
    int i = 0;
    int last = 0;
    while(line[i] != 0)
    {
	if(line[i] == ' ')
	{
	    argv[*argc] = calloc(i-last,sizeof(char));
	    memcpy(argv[*argc],&line[last],i-last);
	    argv[*argc][i-last] = 0;
	    (*argc)++;
	    last = i+1;
	}
	i++;
    }
    if(i != last)
    {
	argv[*argc] = calloc(i-last,sizeof(char));
	memcpy(argv[*argc],&line[last],i-last);
	argv[*argc][i-last] = 0;
	(*argc)++;
    }
}

void Type(char* line)
{
    char c = 0;
    do
    {
	c = GetCharPressed();
	if(c != 0)
	{
	    if (strlen(line) >= BUF_LEN) {exit(1);}
	    line[strlen(line)] = c;
	}
    }while(c);
}

