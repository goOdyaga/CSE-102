#include<stdio.h>
#include<stdlib.h>
#include "util.h"

#include<stdio.h>
#include<stdlib.h>
#include "util.h"

void generate_sequence(int xs,int currentlen,int seqlen,int *seq)
{
    if(currentlen==seqlen-1)/* if currentlen arrive seqlen we will finsh recursion function*/
        return;
    if((xs&1)==0)/*controlling number evenc conditions */
    {
        seq[++currentlen]=xs;
        generate_sequence(xs>>1,currentlen,seqlen,seq);/* after adding number in seq array if number is even we divide by 2 and recalling function*/
    }
    else
    {
        seq[++currentlen]=xs;
        generate_sequence((3*xs+1),currentlen,seqlen,seq);/*after adding number in seq array else multiply by 3 and add 1 number  and recalling function*/
    }
}

void print_sequence(int *p,int len)
{
    printf("{");
    for(int i=0;i<len;i++)
        i <len-1 ? printf("%d, ",p[i]) : printf("%d}\n",p[i]) ;/* printing arrays*/
}

void check_loop_iterative(void (*f)(int,int,int,int *), int xs, int seqlen, int *loop, int *looplen)
{
	int	*arr = (int *)calloc(seqlen, sizeof(int));/*create new array with calloc and send aray with f function that name is generate_sequence*/ 
	f(xs, -1, seqlen, arr);

	printf("\nChecking if there is a loop of length %d...", (*looplen));
    int control=0;
    if(*looplen==1)
    {
        printf("\nNo loop found.\n\n");/*if looplen equal 1 that means there is no loop in sequence array*/
        return;
    }
    int ls=(seqlen-(2*(*looplen))),le=(seqlen-(*looplen));/*I will use *ls and *le in has_loop , *le-*ls is equal to looplen*/
    control=has_loop(arr,seqlen,*looplen,&ls,&le);
    if(control==0)/* this means we couldn't find loop in array and recursion check_loop_iterative funciton and decrease looplen, and search another loop in differnet looplen in sequence array*/ 
    {
        (*looplen)--;
        free(arr);
        check_loop_iterative(f,xs,seqlen,loop,looplen);
    }
    else
    {
        printf("\nLoop detected with a length of %d.\n",*looplen);
        for (int i = 0; i < *looplen; i++)
            loop[i]=arr[ls+i];/*after find loop we copy loop numbers in loop array*/
        printf("The indexes of the loop's first occurance %d(first digit), %d(last digit)\n",ls,le);
        free(arr);
        return;
    }
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    if(looplen==0)/*loop need to be end of arr array . So that ı have searched arr end lengt of looplen*/
    {//                                                    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        int *location=(int *)calloc(2,sizeof(int));//        |       |       |*      |?      |
                                                        //    0.L       1.L     2.L      3.L
        if(start_loop_loc((*le-*ls),arr,n,3,location))//                      *le -*ls= looplen      
        {                                              // I am contolling loop end of array  => n-looplen-((*le)-*ls)  this index location is * sign locatiom       
        *ls=location[0];                                // and n-looplen point to ? sign index
        *le=location[1];                                //*le -*ls is always be same but  ı am decreasing looplen so that ı am controlling one more index*/ 
        }  
        else
            *(le)-=1;                                           //if ı found loop ı control o 1.L because there it can be in found loop but ı dont control 0.L
        return 1;                                       // because loop number couldnt be 4 if it be 4 this means my looplen number must be 2*looplen
    }                                                   // so that ı just control 1.L
    if(arr[n-looplen-((*le)-*ls)]==arr[n-looplen])         //stat_loop_loc control 1.L with the  same method with haas_loop function but it incluse for loop not recursion 
        has_loop(arr,n,looplen-1,ls,le);
    else 
        return 0;
}

void hist_of_firstdigits(void (*f)(int,int,int,int *), int xs, int seqlen, int *h, int digit)
{
    if(digit>=seqlen)
        return;
	int	*arr = (int *)calloc(seqlen+1, sizeof(int));
	f(xs, -1, seqlen, arr);
    h[find_digit(arr[digit])-1]++;/*find_digit return number and ı increase to realting index*/
    free(arr);
    hist_of_firstdigits(f,xs,seqlen,h,digit+1);/* ı use digit for searching arr indexes*/
}

int find_digit(int num)
{
    if(num<10)/* if number is less than 10 ı retur number*/
        return num;
    find_digit(num/10);/* to find first digit ı have divide by 10 until the number less than 10*/ 
}

int start_loop_loc(int looplen,int *main_array,int n,int size,int control[])
{
    int sum=0;
    if(n-size*looplen<0)
        return 0;/* if there is no enough element for control ı will return 0*/
    for(int i=0;i<looplen;i++)
    {
        if(main_array[n-(size*looplen)+i]!=main_array[n-((size-1)*looplen)+i])
            sum+=1;
    }
    if(sum==0)
    {
        control[0]=n-size*looplen;/*control array include true value of ls and le */
        control[1]=n-(size-1)*looplen-1;
        start_loop_loc(looplen,main_array,n,size+1,control);
        return 1;
    }
    else 
        return 0;
}

int my_strcmp(char *str1,char *str2)
{
    int i=0;
    if(my_strlen(str1)!=my_strlen(str2))/*for camparing length of strşng requaried to same*/
        return 0;
    while(str1[i]!='\0')
    {
        if(str1[i]!=str2[i])
            return 0;/*for differen character we return 0*/
    i++;
    }
    return 1;/*if we come here it means strings be same*/
}

int my_strlen( char *str)
{
    int i=0;
    while(str[i]!='\0')/* this for  found string length*/
        i++;
    return i;
    
}
