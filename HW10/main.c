#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_BLOCK_SIZE 10
typedef struct { 
    int * array; 
    int currentsize; 
    int maxsize;
} stack;
stack *board1,*board2,*board3;
int push(stack * s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at a time */

int pop(stack * s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a time */

stack * init_return(); /* initializes an empty stack */

int init(stack * s); /* returns 1 if initialization is successful */

int for_gaming(stack *board1,stack *board2,stack *board3,int len);

int learn_last_element(stack *s);

int learn_board(stack *s1,stack *s2,stack *s3,int number);

int main()
{
    board1=init_return();
    board2=init_return();
    board3=init_return();
    board1->array=board2->array=board3->array=NULL;
    board1->currentsize=board2->currentsize=board3->currentsize=0;
    int control,disc;
    printf("Please enter Number of Disc\n");
    scanf("%d",&disc);/* taking disc number from user*/
    board1->maxsize=board2->maxsize=board3->maxsize=disc+1;
    int i=0; 
    for(i=disc;i>0;i--)
        control=push(board1,i);    /*push number to stack array*/    
    for_gaming(board1,board2,board3,disc);
    return 0;
}

stack * init_return() /* initializes an empty stack */
{
    stack * new=NULL;
    new=(stack *)malloc(sizeof(stack));
    if(init(new))/* control malloc creating memory ıf not again call function for creating*/
        return new;
    else 
        init_return();
}

int push(stack * s, int d)
{
    if(s->currentsize<s->maxsize)
    {
        if(s->currentsize!=0)
        {
            if(learn_last_element(s)>d)/* we couldn't add big value in stack*/
            {
                int *p=(int *)calloc(s->currentsize+1,sizeof(int));/*create new array for pushing*/
                for(int i=0;i<s->currentsize;i++)
                    p[i]=s->array[i];/* copying old elements*/
                free(s->array);/* free old elments*/
                s->array=p;
                s->array[s->currentsize]=d;/* add new element*/
                s->currentsize++;
                return 1;
            }
            else 
                return 0;
        }
        else    
            {/*if there is no value in array apply this operations*/
                int *p=(int *)calloc(s->currentsize+1,sizeof(int));
                s->array=p;
                s->array[s->currentsize]=d;
                s->currentsize++;
                return 1; 
            }
    }
    else
        fprintf(stderr,"You arrived max array length , for pushing elemenet please pop elemnt in array\n");
}
int pop(stack * s)
{
    if(s->currentsize>0)/*we take last value from stack*/
    {
        int *p=(int *)calloc(s->currentsize-1,sizeof(int));/* for decreasing array size we crete new arrray*/ 
        int value=s->array[s->currentsize-1];
        int i;
        for( i=0;i<s->currentsize-1;i++)
            p[i]=s->array[i];/* we copyin elemnts without last element*/
        free(s->array);
        s->array=p;
        s->currentsize-=1;
        return value;/* return last value*/
    }
    else
        fprintf(stderr,"array is empty pop operations\n");
    
}

int init(stack * s)
{
    if(s==NULL)
        return 0;/* control for null operations*/
    return 1; 
}

int for_gaming(stack *board1,stack *board2,stack *board3,int len)
{   
    stack **new=(stack **)calloc(3,sizeof(stack*));
    new[0]=board1;
    new[1]=board2;
    new[2]=board3;
    int j,control;
        for(int i=1;i<pow(2,len);i++)/*it is for step each chose*/
        {
            for(j=len-1;j>=0;j--)
            {
                if(i%(int)(pow(2,j))==0)/*to chose disc for move*/
                    break;
            }
            j+=1;
            if(len%2==1)/*movemnet change with by number of total number's odd or even type*/
            {
                if(j%2==0)
                {
                    control=(learn_board(new[0],new[1],new[2],j)+1)%3;
                    printf("Move the disk %d from '%d' from '%d'\n",j,learn_board(new[0],new[1],new[2],j)+1,control+1);
                    push(new[control],pop(new[(learn_board(new[0],new[1],new[2],j))]));/*taking number from by pop and pussh*/
                }
                else
                {                 
                    control=(learn_board(new[0],new[1],new[2],j)+2)%3;
                    printf("Move the disk %d from '%d' from '%d'\n",j,learn_board(new[0],new[1],new[2],j)+1,control+1);
                    push(new[control],pop(new[(learn_board(new[0],new[1],new[2],j))]));
                }

            }
            else if(len%2==0)
            {
                if(j%2==0)
                {
                    control=(learn_board(new[0],new[1],new[2],j)+2)%3;
                    printf("Move the disk %d from '%d' from '%d'\n",j,learn_board(new[0],new[1],new[2],j)+1,control+1);
                    push(new[control],pop(new[(learn_board(new[0],new[1],new[2],j))]));
                }
                else
                {
                    control=(learn_board(new[0],new[1],new[2],j)+1)%3;
                    printf("Move the disk %d from '%d' from '%d'\n",j,learn_board(new[0],new[1],new[2],j)+1,control+1);
                    push(new[control],pop(new[(learn_board(new[0],new[1],new[2],j))]));
                }

            }

        }   
}

int learn_last_element(stack *s)/*find last value a spesific board*/
{
    if(s->currentsize!=0)
        return s->array[s->currentsize-1];
    else return 0;
}

int learn_board(stack *s1,stack *s2,stack *s3,int number)/*Find for borad a spesific value*/
{
    if(learn_last_element(s1)==number)
        return 0;
    if(learn_last_element(s2)==number)
        return 1;
    if(learn_last_element(s3)==number)
        return 2;
}
