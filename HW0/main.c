#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");


    /* A fractional number: num1/den1 */
    printf("write numerator and denominator\n");
    scanf("%d %d",&num1,&den1);
    /*denominator can not be 0 for fractional number*/
    if ( den1==0 ) return 0;
    /* A fractional number: num2/den2 */
     printf("write numerator and denominator\n");
    scanf("%d %d",&num2,&den2);
    /*denominator can not be 0 for fractional number*/
    if ( den2==0 ) return 0;
    /* An unitilized fractional number */

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
 	fraction_print(num3, den3);
   if ( num3==0) 
		 printf("\nResult is 0(zero); ");    
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
   fraction_print(num3, den3);
 	if ( num3==0) 
		 printf("\nResult is 0(zero); ");    
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
   if ( num3==0)  
			printf("\nResult is 0(zero); ");    
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
     fraction_print(num3, den3);
	if ( num3==0) 
			 printf("\nResult is 0(zero); ");     
     printf("\n");
     if( den3 == 0)
       printf("undefined value for division because of denominator\n");
    printf("\n");
    return(0);
}
