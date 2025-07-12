#ifndef HISTORY_H
#define HISTORY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char** entries;
    unsigned int entry_count;
    unsigned int entry_cap;  
} History;

static const char* Path = "./line.his"; 
static History history = {0};

void InitHistory();
void FreeHistory();
void WriteHistory();
void LoadHistory();
void AddToHistory(const char* entry);
char* GetCopyOfEntryFromHistory(const unsigned int index);
char* GetEntryFromHistory(const unsigned int index);
int GetEntryCount();

#endif // HISTORY_H
