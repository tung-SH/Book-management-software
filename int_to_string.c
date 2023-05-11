

// #include <stdio.h>
#include <stdlib.h>
// #include "setting.h"

/***************************************
 * last_digit -- 
 * 
 * example: last_digit(132) --> 2
 * 
*/
int last_digit(int n) {
    int result; 

    result = n % 10; 

    #ifdef DEBUG9 
        printf("last_digit(%d) is %d\n", n, result); 
    #endif

    return result; 
}

/*****************************************
 * remove_last_digit -- 
 * 
 * example: remove_last_digit(132) --> 13
*/
int remove_last_digit(int n) {
    int result; 

    result = (n - (n % 10)) / 10; 

    #ifdef DEBUG9 
        printf("remove_last_digit(%d) is %d\n", n, result); 
    #endif

    return result; 
}

/**************************************
 * reverse_str -- reverse the string 
 * 
*/
void reverse_str(char* str, int s) {
    static int num_call = 0; /* number of times function call */
    static int num_end = 0; /* number of times function end */

    ++num_call; 

    #ifdef DEBUG8 
    {   
        if (num_call == 1) {
            printf("The reversed string of \"%s\"", str); 
        }
        
    }
    #endif

    if (s >= 2) {
        char mid; 
        mid = str[1 -1]; 
        str[1 -1] = str[s -1]; 
        str[s -1] = mid; 

        reverse_str(str + 1, s - 2); 
    }

    ++num_end; 

    #ifdef DEBUG8
    {
        if (num_end == num_call) {
            printf(" is %s.\n", str); 
        }
    }
    #endif

}


/**************************************
 * itos -- convert int to string
 * 
*/
char* itos(int n) {
    char* result; 
    result = (char*)malloc(100); 

    int length = 1; 
    while (1) {
        if (n == 0) {
            result[length -1] = '\0'; 
            --length; 
            break; 
        }

        result[length -1] = last_digit(n) + 48;

        #ifdef DEBUG8
            printf("current character is %c.\n", result[length -1]); 
        #endif

        ++length;  

        n = remove_last_digit(n); 

    }

    #ifdef DEBUG7  
        printf("the string before reverse is %s", result); 
    #endif

    reverse_str(result, length); 

    return result; 
}


