/*!
@file       q.h
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Tutorial 8
@Tutorial   Character Counter   
@date       05/11/2021
@brief      This header file contains declarations of functions initialize(int 
            latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt), wc(FILE *ifs, int 
            latin_freq[], int *ctrl_cnt, int *non_latin_cnt), and print_freqs(int const 
            latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt). These
            functions are defined in q.c and are called in the function main() in qdriver.c.
*//*______________________________________________________________________________________*/

/*!
@brief  This function initialize() is used to initialize (set to 0) the latin_freq[] array's
        elements, dereferenced ctrl_cnt and noon_latin_cnt to 0. The array has a predefined 
        size. The size is defined under the parameter size with a literal int value of 26 
        which is defined in main().  

@param  latin_freq is an array that contains type int elements
        size is declared as type int
        ctrl_cnt and non_latin_cnt are declared as pointers to variable type int
		
@return Nothing
*//*______________________________________________________________________________________*/
void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt);

/*!
@brief  This function wc() computes the frequency of latin characters in latin_freq array, 
        control characters that ctrl_cnt is pointing to, and non latin, non control 
        characters non_latin_cnt is pointing to, present in the input text file (declared 
        in main()). 
        For every non latin, non control character present, the dereferenced non_latin_cnt 
        is incremented. 
        For every control character detected, the dereferenced ctrl_cnt is incremented.
        For every latin character (A-Z & a-z), regardless of its case sensitivity, the 
        latin_freq array's corresponding element gets incremented. E.g. if 'A' or 'a' is 
        detected, latin_freq[0] will be incremented, similarly for 'Z' or 'z', latin_freq[25]
        gets incremented.


@param  latin_freq is an array that contains type int elements
        ctrl_cnt and non_latin_cnt are declared as pointers to variable type int
        ifs is declared as pointer to type file
		
@return Nothing
*//*_______________________________________________________________________________________*/
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt);

/*!
@brief  This function printf_freqs() prints the frequency of latin characters in latin_freq 
        array, control characters that ctrl_cnt is pointing to, and non latin, non control 
        characters non_latin_cnt is pointing to. The total number of latin characters are 
        computed by summing each element in the array. The output to std stream will display
        every lowercase latin character in alphabetical order horizontally with its 
        corresponding element listed on a newline in similar fashion. Afterwhich, the total
        count of each frequncies are listed as such:
        Latin chars             :     3
        Non-Latin non-ctrl chars:     2
        Control chars           :     6

@param  latin_freq is an array that contains type int elements
        x, y, latin_char_cnt and size are declared as type int
        ctrl_cnt and non_latin_cnt are declared as pointers to variable type int
		
@return Nothing
*//*_______________________________________________________________________________________*/
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt);
