/*
 * CS211 CompArch
 * Liu Liu
 * main.c
 */

#include "tokenizer.h"
/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the file name.
 */

int main(int argc, char ** argv){
	/*check the argument*/
	//printf("Running the file for the first time");
    
    char *file = argv[1];
    //Creating the Tokenizer Object
   
    //Safety to catch if no arguments were given
    if(argv[1]){
        
        TokenizerT *tokenizer;
        
        //Running TKCreate()
        tokenizer = TKCreate(file);
    
        TKPrint(tokenizer);
        TKDestroy(tokenizer);
        /*call TKPrint() with the returned object and print out the result + error message*/

        /*destroy all the dynamically allocated memory*/
	
    }
    dummyFunc();
    
    
	return 0;
}
