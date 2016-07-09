/*
 * CS211 CompArch
 * Liu Liu
 * tokenizer.c
 */

#include "tokenizer.h"
/* change the 'return NULL' after you finished the code */
/* functions specifications are in tokenizer.h */

void dummyFunc(){

}

TokenizerT *TKCreate(char * ts){
	/* fill in your code here */

	printf("Into TKCreate with the FILE: %s \n", ts);
	
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
	return NULL;
}

void TKPrint(TokenizerT *tk){
	/* fill in your code here */
}
