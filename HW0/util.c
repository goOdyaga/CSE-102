#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
     *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
*n3 = n1*n2;
*d3 = d1*d2;
fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
*n3 = n1*d2;
*d3 = n2*d1;   
/*devide two negative number result is positive*/
/*to find true GCD convert negative number to positive number*/
	if (*n3 < 0 && *d3 < 0 )
		{ 
			*n3 *= -1;
			*d3 *= -1;
		}
fraction_simplify(n3, d3);

} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
int index =2;
int a ;
int b ;
int gcd=1;
/*just one number is negative use otherone number in while loop for find true GCD*/
		 if(*n < 0 && *d > 0)
		 {
			while(index<=*d)
			{

				a=*n%index;
				b=*d%index;
					if(a==b&&a==0)
					{	
					gcd=index;	
					}
			index++;
		
			}
		 }
/*just one number is negative use otherone number in while loop for find true GCD*/
		 else if (*d < 0 && *n > 0)
		 {
			while(index<=*n)
			{

				a=*n%index;
				b=*d%index;
					if(a==b&&a==0)
					{	
					gcd=index;	
					}
			index++;
			}
		 }
/* there is no negative number  we can use a number that not important which one in while loop  */ 		
		else
			while( index <= *d)
			{
				a=*n%index;
				b=*d%index;
					if(a==b&&a==0)
					{	
						gcd=index;	
					}
				index++;
			}
		*n=*n/gcd;
		*d=*d/gcd;
} /* end fraction_div */

