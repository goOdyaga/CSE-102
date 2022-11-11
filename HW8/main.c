#include<stdio.h>
#include<stdlib.h>
#include "util.h"



int main()
{
    
    int slen,xs,*loop,chose;
    while(1)
    {
        printf("WELCOME HW8:\n"
                "\t1.Start HW8\n"
                "\t2.EXIT\n");
        char c,*temp=(char *)calloc(200,sizeof(char));
        int control=-1;
        fgets(temp,200,stdin);/* get string from user for menu choosing*/
        temp[my_strlen(temp)-1]='\0';/*gets taking '\n' before '\0' because of that we change '\n' with '\0'*/
        if(my_strcmp(temp,"1"))
        {
            printf("Please enter the sequence length:");
            scanf("%d%*c",&slen);
            int *array=(int *)calloc(slen,sizeof(int));
            printf("Please ente fird element:");
            scanf("%d%*c",&xs);
            generate_sequence(xs,-1,slen,array);
            printf("\nSequence:");
            print_sequence(array,slen);/*print  sequence array*/
            free(array);
            int looplen=(slen/2);
            loop=(int *)calloc((slen/2),sizeof(int));
            check_loop_iterative(generate_sequence,xs,slen,loop,&looplen); 
            if(looplen>=2)/* print loop array*/
            {
                printf("Loop:");
                print_sequence(loop,looplen);
                free(loop);
            }
            int *h=(int *)calloc(10,sizeof(int));
            hist_of_firstdigits(generate_sequence,xs,slen,h,0);
            printf("\nHistogram of the sequence:");/* print histogram array*/ 
            print_sequence(h,9);  
            free(h);
            printf("\n");
            free(temp);
        }
        else if(my_strcmp(temp,"2"))
            break;
        else
        {
            printf("Invalid choosen please try again !!!\n");
            free(temp);
        }
    }
    return 0;
}
