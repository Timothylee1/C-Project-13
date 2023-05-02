/*!
@file       q.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Tutorial 8
@Tutorial   Character Counter   
@date       05/11/2021
@brief      This header file contains definitions of the functions initialize(int 
            latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt), wc(FILE *ifs, int 
            latin_freq[], int *ctrl_cnt, int *non_latin_cnt), and print_freqs(int const 
            latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt). These
            functions are called from function main() to compute the number of times a latin
            character, control character, and non latin and non control character is present
            in the input text file and prints it out to the std output stream. 
*//*______________________________________________________________________________________*/
#include <stdio.h>

/*!
@brief  This function initialize() is used to initialize (set to 0) the latin_freq[] array's
        elements, dereferenced ctrl_cnt and noon_latin_cnt to 0. The array has a predefined 
        size. The size is defined under the parameter size with a literal int value of 26 
        which is defined in main().  

@param  latin_freq is an array that contains type int elements
        counter and size are declared as type int
        ctrl_cnt and non_latin_cnt are declared as pointers to variable type int
		
@return Nothing
*//*_______________________________________________________________________________________*/
void initialize(int latin_freq[], int size, int *ctrl_cnt,
                int *non_latin_cnt) {

    //Repeats to set all elements in latin_freq to 0
    for (int counter = 0; counter < size; counter++) {
        latin_freq[counter] = 0;
    }
    *ctrl_cnt = 0;                                                  //sets *ctrl_cnt to 0
    *non_latin_cnt = 0;                                             //sets *non_latin_cnt to 0
}

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
        c is declared as type int
        ctrl_cnt and non_latin_cnt are declared as pointers to variable type int
        ch is declared as type char
        ifs is declared as pointer to type file
		
@return Nothing
*//*_______________________________________________________________________________________*/
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
    int c = 0;
    while ( (c = fgetc(ifs)) != EOF) {
        char ch = (char) c;
        //Check if corresponding element is a control character
        if (ch == '\a' || ch == '\b' || ch == '\f' || ch == '\n' ||
            ch == '\r' || ch == '\t' || ch == '\v')  {
            (*ctrl_cnt)++;                                          //increment the int variable pointed to by ctrl_cnt
        }
        //Check if corresponding element is a latin character   
        else if (ch >= 'A' && ch <= 'Z') {
            latin_freq[ch -'A']++;                                  //corresponding element in array latin_freq must be incremented
        }
        else if (ch >= 'a' && ch <= 'z') {
            latin_freq[ch -'a']++;                                  //corresponding element in array latin_freq must be incremented
        }
        //If non-latin or non-control characters
        else {                                                      //dereferencing non_latin_cnt pointing to an int value
            (*non_latin_cnt)++; 
        }
    }
}

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
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, 
                 int const *non_latin_cnt){
    //prints 'a' to 'z' to stdout    
    for(int x = 0; x < size; x++){
        printf("    %c", 97+x);                                     //97 corresponds to 'a'
    }
    printf("\n");
    
    //prints the element in the corresponding array subscript  
    int latin_char_cnt = 0;
    for(int y = 0; y < size; y++){
        printf("%5d", latin_freq[y]);
        latin_char_cnt += latin_freq[y];
    }

    //print count formatting
    printf("\nLatin chars             :%6d\n\
Non-Latin non-ctrl chars:%6d\nControl chars           :%6d\n\
", latin_char_cnt, *non_latin_cnt, *ctrl_cnt);
}
