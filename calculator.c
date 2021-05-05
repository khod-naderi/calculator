/**
 * @file
 * A simple calculator that get all  parameters in one line!
 * @author [Ali Naderi](https://github.com/khod-naderi)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function split 
 * @returns pointer to more string | chr its character operator | output its part of splited the string
 * @return NULL in EOF string
 * Responsible in split staring and get operator character 
 * @param string, its string for splite,  chr its address for set operator character , ouput its address for set part of splited the string
*/
char* split(char *string, char *chr, char *output){
    int seek=0;
    for(seek; seek<strlen(string); seek++){
        switch(*(string + seek)){
            case '+':
            case '-':
            case '/':
            case '*':
                *(chr) = *(string + seek);
                goto setChar;
                break;
            default:
                break;
        }
    }
    setChar:
    memcpy(output, string  , seek);
    *(output + seek ) = '\0';
    if( (seek + 1) >= strlen(string)){
        return NULL;
    }
    return (string + seek + 1);
}

/**
 * @brief Function str2int 
 * @return ouput, its converited int
 * Responsible in convert string to int
 * @param string, its string for convert to int
*/
int str2int(char *string){
    register int ouput=0;
    for(int i=0; i<strlen(string); i++){
        ouput *= 10;
        switch(*(string + i)){
            case '0':
                ouput += 0;
                break;
            case '1':
                ouput += 1;
                break;
            case '2':
                ouput += 2;
                break;
            case '3':
                ouput += 3;
                break;
            case '4':
                ouput += 4;
                break;
            case '5':
                ouput += 5;
                break;
            case '6':
                ouput += 6;
                break;
            case '7':
                ouput += 7;
                break;
            case '8':
                ouput += 8;
                break;
            case '9':
                ouput += 9;
                break;
            default:
                ouput /= 10;
                break;
        }
    }
    return ouput;
}


/**
 * @brief Main function
 * @returns 0 on exit
*/
int main() {
    char *string = malloc(500), *out = malloc(200), chr; // getting memory
    char oldChar = '+'; // old char for this operate
    float sum=0; //  output of sum all
    printf("> > >  ");
    fgets(string, 500, stdin);
    while(1){
		///////////////////////////////
		// send string in here for split it.
		// chr is address for give character operator 
		// out is address for give part splited of string
		// Recursive value is address of more string
		//////////////////////////////
        string = split(string, &chr, out);
        switch(oldChar){
            case '+':
                sum += str2int(out);
                break;
            case '-':
                sum -= str2int(out);
                break;
            case '/':
                sum = sum / str2int(out);
                break;
            case '*':
                sum *= str2int(out);
                break;
            default:
                break;
        }
        oldChar = chr;
        if(string == NULL) break; //  EOF
    }
    printf("sum is: %.2f", sum);
    free(string);
    free(out);
    return 0;
}