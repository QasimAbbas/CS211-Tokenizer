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
    
    //Create the Tokenizer Object that holds the Linked List
    TokenizerT *token = (TokenizerT *)malloc(sizeof(TokenizerT));
    token->head = NULL;
    token->tail = NULL;
	//printf("Into TKCreate with the FILE: %s \n", ts);
    
    
    //Create string to hold line in FGETS
    char* str = (char*)malloc(sizeof(char));
    
    //Create TempNode to insert into Linked List
    Node* tmpNode = (Node *)malloc(sizeof(Node));
    
    FILE *file;
    file = fopen(ts, "r");
    char *nexttoken = malloc(sizeof(char));
    
    //Loop through every line in file to the end
    while(fgets(str, 50, file) != NULL){
        char *tmp = str;
        
        //Scan through each character unitl end of line is there
        while(*tmp != '\0' && (nexttoken = TKGetNextToken(tmp))){
            
            if (*nexttoken == '\0') break;
            
            //Search for Token in the original STR and move the tmp pointer forward
            strstr(tmp, nexttoken);
            tmp += strlen(nexttoken);
            
            
            //Add Nodes to the Linked List
            tmpNode = (Node *)malloc(sizeof(Node));
            tmpNode->data = nexttoken;
            
            if(token->head == NULL){
                token->head = tmpNode;
            } else if(token->tail == NULL){
                token->head->next = tmpNode;
                token->tail = tmpNode;
                
            }else{
                token->tail->next = tmpNode;
                token->tail = tmpNode;
            }
            tmp++;
            
        }
    }
    fclose(file);
    
    //Assign Types to the Nodes
    Node *printer = token->head;
    while(printer != NULL){
        
        if(isDecimal(printer->data)){
            printer->type = isDecimal(printer->data);
        }else if(isOctal(printer->data)){
             printer->type = isOctal(printer->data);
        }else if(isHex(printer->data)){
            printer->type = isHex(printer->data);
        }else if(isFloating(printer->data)){
             printer->type = isFloating(printer->data);
        }else{
             printer->type = NULL;
        }
        
        
        printer = printer->next;
    }
    
    /* you might need more than a few helper functions */
    
    /* SAMPLE LOGIC:
     * traverse through the file line by line
     * in each line, repeatedly call TKGetNextToken() until the end of line
     * store the result from TKGetNextToken() to your structure
     * interpret the informations and store the interpretation in your structure
     */
    

	return token;
}

//Check if Decimal
char *isDecimal(char* str){
    
    //Create pointer that points towards the orginals string
    char *ptr = str;
    char*type;
    type = NULL;
    
    //Use Boolean to check if every letter is a valid Decimal
    int isValidDec = 1;
    
    //Increment through every letter to make sure it's a Decimal
    while(*ptr != '\0'){
        if(*ptr > '0' && *ptr <= '9'){
                //printf("IS VALID DEC: %c\n", *ptr);
            isValidDec = 1;
            
        }else{
            isValidDec = 0;
            break;
        }
        ptr++;
   }
    
    //Assign Type if Decimal if every character is a decimal
    if(isValidDec){
        type = "Decimal";
    }
    
    return type;
}

//Check if Octal
char *isOctal(char *str){
    //Create pointer that points towards the orginals string
    char *ptr = str;
    char*type;
    type = NULL;
    
    //Create boolean to check if every term is Octal
    int isValidOct = 1;
    
    //Check if first character is 0
    if(*ptr == '0'){
        
        //Iterate through every letter to determine if they are Octal
        while(*ptr != '\0'){
            if(*ptr >= '0' && *ptr <= '7'){
                //printf("IS VALID DEC: %c\n", *ptr);
                isValidOct = 1;
            
            }else{
                isValidOct = 0;
                break;
            }
        
            ptr++;
        }
    }else if(*ptr != '0'){
        //printf("IS NOT VALID OCT: %s\n", ptr);
        isValidOct = 0;
    }
    
    //Assign Octal
    if(isValidOct){
        type = "Octal";
    }
    
    return type;
    
}

//Check if Hex
char *isHex(char *str){
    //Assign Pointer to original string
    char *ptr = str;
    
    //Check if second Character has x
    if(ptr[1] == 'x' || ptr[1] == 'X'){
        
        return "Hex";
        
    }else{
        return NULL;
    }
    
    return NULL;
}

//Check if Floating
char *isFloating(char *str){
    //Assign pointer to orginal string
    char*ptr = str;
    
    //Check if ., e, E exists in string
    if(strchr(ptr, '.') || strchr(ptr, 'e') || strchr(ptr, 'E')){
        return "float";
        
    }
    
    return NULL;
}


void TKDestroy( TokenizerT * tk ) {
	/* fill in your code here */
    //Free Token
    free(tk);
}

char *TKGetNextToken( char * start ) {
    	/* fill in your code here */
    
    //Pointer to orginal string
    char * ptr = start;
    
    //Pointer for copying the string
    char * tmp = start;
    
    
    //Index of String
    int index = 0;
    
    //Iterate through string until reached space, end of line, or next line to determine length of string
    while(*ptr != ' ' && *ptr != '\0' && *ptr != '\n'){
        ptr++;
        index++;
    }
    char *token = (char *)malloc(index+1);
    strncpy(token, tmp, index++);
    
	return token;
}

void TKPrint(TokenizerT *tk){
	/* fill in your code here */
    
    //Pointer to original token
    TokenizerT *token = tk;
     Node *run = token->head;
    
    
    //Create result + error msg files
     FILE *results = fopen("results", "ab+");
     FILE *error = fopen("error.msg", "ab+");
    
    
    //Traverse Linked List and write Type and Data to File
    while(run != NULL){
        
        if(run->next){
        
            //Check if type exists, if not error
            if(run->type){
                fprintf(results, "%s ", run->type);
                fprintf(results, "%s\n", run->data);
            
            }else{
                fprintf(error, "[0x%x]\n", *run->data);
            }
            
        }else{
            //Check if type exists, if not error WIHTOUT /n
            if(run->type){
                fprintf(results, "%s ", run->type);
                fprintf(results, "%s", run->data);
                
            }else{
                fprintf(error, "[0x%x]", *run->data);
            }

        }
        
        //Iterate LL:
        run = run->next;
    }
    
    //Close the files being used.
    fclose(results);
    fclose(error);
    
}
