/*
 * CS211 CompArch
 * Liu Liu
 * tokenizer.c
 */

#include "tokenizer.h"
#include <string.h>
#include <ctype.h>

/* change the 'return NULL' after you finished the code */
/* functions specifications are in tokenizer.h */

void dummyFunc(){

}

TokenizerT *TKCreate(char * ts){
	/* fill in your code here */

	printf("Into TKCreate with the FILE: %s \n", ts);
//	Node *head = (Node *)malloc(sizeof(Node));
//	Node *tail = (Node *)malloc(sizeof(Node));

    char* str = (char *)malloc(sizeof(char));
    
    FILE *file;
    file = fopen(ts, "r");
    
    while(fgets(str, 50, file)){
        char *tmp = str;
        
        while(*tmp != '\0'){
            
            char *nexttoken = TKGetNextToken(tmp);
            
            printf("THE NEXT TOKEN: %s\n", nexttoken);
            tmp++;
        
        }
    }

/* you might need more than a few helper functions */

/* SAMPLE LOGIC:
 * traverse through the file line by line
 * in each line, repeatedly call TKGetNextToken() until the end of line
 * store the result from TKGetNextToken() to your structure
 * interpret the informations and store the interpretation in your structure
*/

	return NULL;
}

void TKDestroy( TokenizerT * tk ) {
	/* fill in your code here */
}

char *TKGetNextToken( char * start ) {
    	/* fill in your code here */
    char * ptr = start;
    char * tmp = start;
    
    int index = 0;
    
    while(*ptr != ' '){
        ptr++;
        index++;
    }
    char *token = (char *)malloc(index+1);
    strncpy(token, tmp, index++);
    
	return token;
}

void TKPrint(TokenizerT *tk){
	/* fill in your code here */
}
