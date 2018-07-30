#include<stdlib.h>
#ifndef _STRINGLIB1_
#define _STRINGLIB1_
/*========================================================================
======================== function: string_cmp ============================
A function to compare if two strings have the same content (are equal)
@param_0: The first string to be compared  
@param_1: The second string to be compared
@return: It returns 0 if the two given string are equal
@return: It returns 1 if the first string is higher than the second one
@return: It returns -1 if the second string is lesser than the second one
==========================================================================*/
int string_cmp(char *str1, char *str2);

/*========================================================================
======================== function: string_length =========================
A function to get the size of a string
@param_0: The inputted string to be measured
@return: It returns the length of the inputted string (int)
==========================================================================*/
int string_length(char *str);

/*========================================================================
======================== function: string_copy ===========================
A function to copy a string from a source to a destiny
@param_0: The destiny string that will be receive content from another one
@param_1: The string source that will be copied
==========================================================================*/
void string_copy(char *dest, char *src);

/*========================================================================
===================== function: string_concat ============================
A function to concatenate two given strings
@param_0: First string, it'll be putted at the begining of the resultant string
@param_1: Second string, it'll be putted at the end of the resultant string
@return: A string that's the result of concatenation of second string
at the end of the first string
==========================================================================*/
char* string_concat(char *str1, char *str2);

/*========================================================================
===================== function: string_init_cut ==========================
A function to cut a string from the begining until a given index (inclusive)
@param_0: A string that will be cutted from the begining
==========================================================================*/
void string_init_cut(char *str, int index);

/*========================================================================
===================== function: substring_at_be ==========================
A function to get a substring through a begin index and a end index, given
a string
@param_0: A source string
@param_1: An int that indicates the inital index of the substring (inclusive)
@param_2: An int that indicates the end index of the substring (inclusive)
@return: It returns a substring that correspond the given indexes
==========================================================================*/
char* substring_at_be(char *str, int begin, int end);



#endif