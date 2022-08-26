//********************************************************************
//*                    EEE2046 C template                  *
//*==================================================================*
//* WRITTEN BY: Mitra Ramchuran  	                 		     *                                            *
//*==================================================================*
//* PROGRAMMED IN: CODEBlocks                                                *
//* TARGET: How to display values to the screen, read in values from the keyboard, create preprocessor constants, loops and functions using C. Use these skills to write a decimal to radix-i conversion program.

//*==================================================================*
//* DESCRIPTION: RADIX-i Converter                                                  *
//*                                                                  *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include <stdio.h>
#include <stdint.h>
#include <math.h>
//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Mitra Ramchuran"
#define YEAR "2022"
//====================================================================
// GLOBAL VARIABLES
//====================================================================

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char * Dec2RadixI(int decValue, int radValue){
    // initialize list of all characters up to hexadecimal
    char hexaArray[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    float logn2 = (log10(decValue))/(log10(radValue));
    static char answer[100];
    int res, rem;

    res = decValue;

    if (res == 0){
        answer[0] = hexaArray[0];
    }
    // manual calculation, the same as the one learnt in number systems, with the order of remainders reversed along the way
    for (int i = logn2 ; i >= 0 ; i--){
        rem = ( (int) res)%radValue;
        answer[i] =  hexaArray[rem];
        res = res/radValue;
    }
    printf("The radix-%d value is 0" , radValue);

    for (int i = 0 ; i < ((int)logn2)+1 ; i++){
        printf("%c",answer[i]);
    }
    printf("%s","\n");
    return answer;
}
//====================================================================
// MAIN FUNCTION
//====================================================================
int main (void)
{
    // initial header
    printf("%s\n", "*****************************");           //start of header
    printf(" %s\n", TITLE);
    printf(" Written by: %s\n" ,AUTHOR);
    printf(" Date: %s\n" , YEAR);
    printf("%s\n", "*****************************");           //end of header

    int radix, decimal, result, remainder;
    float logn;
    char *answer;

    int trigger = 0;
    while(trigger == 0){

        // code to get decimal number
        printf("%s", "Enter a decimal number: ");
        scanf("%d" ,&decimal);
        if (decimal < 0){break;}
        printf("The number you have entered is %d\n", decimal);

        // code to get radix
        printf("%s", "Enter a radix for the converter between 2 and 16: ");
        scanf("%d" ,&radix);
        if (radix < 0){break;}
        printf("The radix you have entered is %d\n", radix);

        // log-2, since C does not have log-n function, logarithmic law of log-n(x) = log(x)/log(n)
        logn = (log10(decimal))/(log10(radix)) ;
        printf("The log%d of the number is %.2f\n" , radix , logn);

        // result of integer division
        result = (int) (decimal/radix);
        printf("The integer result of the number divided by %d is %d\n" , radix , result);

        // remainder after integer division
        remainder = decimal%radix;
        printf("The remainder is %d\n" , remainder);

        // decimal to radix-i function call
        answer = Dec2RadixI(decimal , radix);
    }

    printf("%s","EXIT");

	return 0;
}							// End of main


//********************************************************************
// END OF PROGRAM
//********************************************************************
