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

	printf("Reading the FILE:  %s \n", argv[1]);
	
	TKCreate(argv[1]);		

	/*call TKPrint() with the returned object and print out the result + error message*/


	/*destroy all the dynamically allocated memory*/
	dummyFunc();

	return 0;
}
