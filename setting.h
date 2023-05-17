#include <stdio.h>
/**********************************
 * DEBUG -- main debugging used for a specific main program 
 * 
*/
#define DEBUG
/**************************************
 * DEBUG1 -- debbugging used for the main function used in a 
 *      specific program 
 * 
*/
#define DEBUG1
/****************************************
 * DEBUG2 -- debugging used for second sub function used for main function 
 *      used in a specific program 
 *   
*/
#define DEBUG2
/**********************************
 * DEBUG3 -- debugging used for third sub function used for main function 
 *      used in a specific program 
 * 
*/
// #define DEBUG3
/*********************************
 * DEBUG4 -- debugging used for fourth sub function used for main function 
 *      used in a specific program 
 * 
*/
// #define DEBUG4
/*********************************
 * DEBUG5 -- debugging used for fifth sub function used for main function 
 *      used in a specific program 
 * 
*/
// #define DEBUG5
/**********************************
 * DEBUG9 -- debugging used for most mini function used generally 
 * 
 * example:   
 *      9  <-- last_digit(1239)
*/
// #define DEBUG9
/************************************
 * DEBUG8 -- debugging used for second most mini function used generally
 *  
*/
// #define DEBUG8
/***********************************
 * DEBUG7 -- debugging used for third most mini function used generally 
 * 
*/
// #define DEBUG7

FILE* debug_file; /* use when can't use stdout */

void setup_debug_file(void) {
    debug_file = fopen("debug.txt", "w");
}