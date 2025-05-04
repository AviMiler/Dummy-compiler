#include "macro.h"


#define DELETE_SPACES while (token && (*token==' ' || *token=='\t')) token+=1;

char* trimBefore(char* line){
    char * resulte=line;
    while (*resulte==' '){
        resulte++;
    }
    return resulte;
}

int setMacros(FILE * file,labels_trie * labelsTrie,char * fileName){
    
    char line[100],tokenP[100],*token,*macro,* label,* newFile;
    int lineNumber,isMacro,mcrIdexn,NFIndex,errorFlag,macroSize,newFileSize,i;
    FILE *amFile;
    labels_trie * lt;
    
    token=tokenP;
    lineNumber=isMacro=mcrIdexn=NFIndex=errorFlag=macroSize=newFileSize=0;
    label=0;
    
    macro=malloc(1*sizeof(char));
    newFile=malloc(1*sizeof(char));
printf("-1");
    while (fgets(line,LINE_SIZE+2, file) != NULL){
        
        lineNumber++;
        
        strcpy(token,line);
  
	DELETE_SPACES 
	if(*token=='\n' || *token=='\0'){
	    fgets(line,LINE_SIZE+2, file);
	    lineNumber++;
	    if(line==NULL)
	        break;
	}
        if(strlen(token)>4 && (strncmp("mcro",token,4)) && (isspace((*token+=5)) || token==0)){printf("f");
            if(!checkMacroLabel(token,line,lineNumber,file,label))
            	isMacro=1; 
            else
                errorFlag=1;
            
            while (isMacro && fgets(line,100,file)){
                
                if (strncmp((token=trimBefore(line)),"endmcro",7)!=0){
                    if(checkEndMacro(file,line,token,lineNumber))
                        errorFlag=1;
                    isMacro=0;
                }
                macroSize += strlen(line);
                macro = realloc(macro, macroSize * sizeof(char));printf("%s %s b\n",macro+mcrIdexn,line);
                strcpy((macro+mcrIdexn),line);printf("c\n");
                mcrIdexn+=strlen(line);
            
            }
            mcrIdexn=0;
            if(*label && !errorFlag){
            	if(insert(label,macro,0,0,labelsTrie)){;printf("c\n");
            	     printf("#at preassembler: in line %d the label %s already defined\n",lineNumber,label);
            	}
            }
	}
	token=trimBefore(line);printf("0");
	for (i = 0; token[i] != '\n' && token[i] != '\t' && token[i] != '\0' && token[i] != ' '; i++)
            ;printf("1");
	if((lt=trieSearch(token,i,labelsTrie))!=NULL){printf("2");
	
	    newFileSize += strlen(lt->macro);printf("f");
	    newFile = realloc(newFile, newFileSize * sizeof(char));
	    strcpy(newFile+NFIndex,lt->macro);
   	    NFIndex+=strlen(lt->macro);
	
	}
	printf("3");
	newFileSize += strlen(line);
	newFile = realloc(newFile, newFileSize * sizeof(char)); 
	strcpy(newFile+NFIndex,line);
	NFIndex+=strlen(line);
           
    }
    printf("4");
    amFile = fopen(strcat(fileName,".am"), "w+");
    fprintf(amFile,"%s",newFile);
    free(macro);
    free(newFile);

return 0;
}
