/*
 * CS211 CompArch
 * Liu Liu
 * tokenizer.h
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _TOKENIZER_H
#define _TOKENIZER_H

void dummyFunc();

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 * Design your structure carefully. A good structure will always make a program much easier to implement.
 */

//The Datastructure that will be used is a Linked List.  The Nodes are created by the struct Tokenizer_LL with the values of Data, Type, and Node next

typedef struct Tokenizer_LL{
	char* data;
	char* type;
    struct Tokenizer_LL *next;

} Node;

//Since the Data Structure needs to be held, the Struct TokenizerT will hold the head and tail, and the entire Linked List

typedef struct TokenizerT_ {
	/* fill in your code here */
	Node *head;
	Node *tail;

} TokenizerT;


/*
 * TKCreate creates a new TokenizerT object for a given file name
 * TKCreate should open the file and read the file line by line.
 * If you are following the steps in description, 'lexer' / 'parser' should both be implemented here
 * If you are not following the steps, the output of TKCreate should be a pointer to a TokenizerT object which contains all the information needed for writer
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate( char * ts );


/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk );


/*
 * TKGetNextToken is a helper function that would be used by TKCreate when traversing through each line in the file
 * This function would take a char* as input, indicating where it should start
 * Then returns a char* pointing to a string which is a copy of the next token
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( char * start );
    

/*
 * TKPrint would take a Tokenizer object and use the information stored in that object to print out all the result to file "result" and file "error.msg"
 * If you are following the result, implement the 'writer' here
 */

void TKPrint(TokenizerT *tk);

//Determine if token is a Decimal
char *isDecimal(char* str);

//Determine if token is Octal
char *isOctal(char *str);

//Detemnine if token is Hex
char *isHex(char *str);

//Determine if token is floating
char *isFloating(char *str);

#endif
