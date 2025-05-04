#ifndef CHEKCERS_H
#define CHEKCERS_H 

#include "data.h"
#include "structers.h"



line_data checkLine(char line[LINE_SIZE+1],FILE *,int );
int checkMacroLabel(char * ,char * ,int ,FILE *,char *);
int checkEndMacro(FILE * ,char * ,char * ,int);
#endif
