#include "history.h"

void InitHistory()
{
    history = (History) {
	.entries = calloc(8,sizeof(char*)),
	.entry_cap = 8,
	.entry_count = 0,
	};
}

void FreeHistory()
{
    for (int i = 0; i < history.entry_count; i++) {
	free(history.entries[i]);
    }
    history = (History){0};
}

void WriteHistory()
{
    FILE* fptr = fopen(Path,"w");
    if(fptr == NULL)
    {
	fprintf(stderr,"Couldnt open the history file for the writing!\n");
	exit(1);
    }

    char tmp[1024] = {0};
    for (int i = 0; i < history.entry_count; i++) {
	sprintf(tmp,"%s\n",history.entries[i]);
	fwrite(tmp,sizeof(char),strlen(tmp),fptr);
    }
    fclose(fptr);
}

void LoadHistory()
{
    FILE* fptr = fopen(Path,"r");
    if(fptr == NULL)
    {
	return;
    }
    char tmp[1024] = {0};
    int len = 0;
    while(fgets(tmp,1024,fptr) != NULL)
    {
	len = strlen(tmp);
	tmp[len-1] = 0;
	AddToHistory(tmp);
    }
    fclose(fptr);
}

void AddToHistory(const char* entry)
{
    if(history.entry_cap > history.entry_count)
    {
	history.entries[history.entry_count++] = strdup(entry);
    }
    else
    {
	history.entries = realloc(history.entries,sizeof(history.entries[0])*history.entry_cap*2);
	history.entry_cap *= 2;
	history.entries[history.entry_count++] = strdup(entry);
    }
}

char* GetEntryFromHistory(const unsigned int index)
{
    if(index >= history.entry_count) {return 0;}
    return history.entries[index];
}


char* GetCopyOfEntryFromHistory(const unsigned int index)
{
    if(index >= history.entry_count) {return strdup("");}
    return strdup(history.entries[index]);
}

int GetEntryCount()
{
    return history.entry_count;
}
