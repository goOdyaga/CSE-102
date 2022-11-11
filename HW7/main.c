#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m" /*colorful printf*/
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct
{
    char array_words[50][8];/*write words in this array with order of dictionary*/
    char puzzle[15][15],round_array[7][8];/*in here we have puzzle array we have round words */
    int location[2];/*for create puzzle each word first key location*/
    int round_word_location[7][2];/*in here we have choosen words location for puzzle*/
    int direction[7][3];/*in here we have 3 direction for words*/
    int control[7];/* this controller for unable to chose word that chosen one time*/
}words;

void take_words_file(words * file); /* this function for take words from file*/

void words_in_table(words * table);/* this function for put + sign all game table for creataing puzzle*/

void print_puzzle(words * table);/* print table*/

int add_word_table(words * table,char array[],int direct[]);/* this function for put words in table*/

void full_puzzle(words* table);/* thia function for put random letter instead of + sign*/

int contreol_word(words *table,char chosen_word[25],int location_word[2] );/* control words for game process*/

void add_x(words* table,int n);/* change words with X sign if given words is true*/

void zero_control(words *table);/* if given words is true controller index will be increase*/


int main()
{
    words my_words;
    take_words_file(&my_words);
    words_in_table(&my_words);
    zero_control(&my_words);
    char input[100],word[25];
    int point=0,i=-1,num[2],sum=0,count_num,count_word,life=3,result,number_words=7;
    while(1)
    {
        printf("Enter coordinates and word:");
        i=-1;
        while((input[++i]=getchar())&&input[i]!='\n');/* take input from users*/
        input[i]=0;/* add null character taken string*/
        i=-1;
        count_num=-1;
        count_word=-1;
        
        if(strcmp(input,":q")==0)
        {
            printf("Game is over . Your score is %d\n",point);
            break;/* given string is equal to :q we need to finish the game*/
        }
        while (input[++i]!=0)
        {
            if(input[i]>='0'&&input[i]<='9')
            {
                sum=(input[i]-'0')+sum*10;
                if(input[i+1]==' ')/* in here we take location that user want to us search*/
                {
                    num[++count_num]=sum;
                   // printf("%d ",count_num);
                    sum=0;
                }
            }
            if(input[i]>='a'&&input[i]<='z')/* in here we take users answer for words searching*/ 
                word[++count_word]=input[i];
        }
        word[++count_word]=0;

        int zero=0;
        while(input[zero]!=0)
        {
            input[zero]=0;/* in here add null every index of input for use again*/
            zero++;
        }
        //printf("=>%s\n",input);
        result=contreol_word(&my_words,word,num);/* controlling array*/
        printf("LIFE:%d\n",life);
        print_puzzle(&my_words);
        //printf("result=%d\n",result);
        if(result==1)
        {
            number_words --;/* remain words that user must to find for win game*/
            point+=2;
            if(number_words==0)
            {  
                printf("YOU WON!! Your point is %d\n",point); 
                printf("Dou you want to play again enter yes(Y/y)?\n");
                char restart[4];
                int j=-1;
                while((restart[++j]=getchar())&&restart[j]!='\n');
                restart[j]=0;
                //printf("%s %d %d %d\n",restart,strcmp("y",restart),strcmp("Y",restart),strcmp("yes",restart));
                if(strcmp("y",restart)==0||strcmp("Y",restart)==0||strcmp("yes",restart)==0)
                {       /*if user want to play game again we need to reset it's life for new game */
                    life=3;
                    words_in_table(&my_words);/*creating game table again*/
                    zero_control(&my_words);/*reset controller array*/
                }
                else 
                    break;/*if it don't want play again we have to finis game */
                for(int i=0;i<strlen(restart);i++)
                    restart[i]=0;
            }
            else
                printf("Founded!! You got 2 points. Your total points is %d \n",point);
        }
        else
        {
            life--;
            point-=2;
            printf("Wrong choice! You have only %d lefts\n",life);
            if(life==0)
            {
                printf("You couldnt won!! ,Dou you want to play again enter yes(Y/y)? \n");
                char restart[4];
                int j=-1;
                while((restart[++j]=getchar())&&restart[j]!='\n');
                restart[j]=0;
                printf("%s %d %d %d\n",restart,strcmp("y",restart),strcmp("Y",restart),strcmp("yes",restart));
                if(strcmp("y",restart)==0||strcmp("Y",restart)==0||strcmp("yes",restart)==0)
                {       /*if user want to play game again we need to reset it's life for new game */
                    life=3;
                    words_in_table(&my_words);
                    zero_control(&my_words);
                }
                else 
                    break;
                for(int i=0;i<strlen(restart);i++)
                    restart[i]=0;
            }
        }
    }
    //for(int i=0;i<50;i++)
    //    printf("%s\n",my_words.array_words[i]);

}


void take_words_file(words * file)
{
    FILE *p=fopen("wordlist.txt","r+");
    int count=0;
    while(!feof(p))
    {
        fscanf(p,"%s",file->array_words[count]);/*take words from file*/
      count++;
    }
    fclose(p);
}

void words_in_table(words * table)
{
    int number_w,i=0,count=0,a;
    int direct_w,in_table1,in_table2,total_direct[3],kontrol[50],location_word[7][2]; /* 0->horizontal 1->vertical 2->diagonal */
    char array[8],round_array[7][7];
    for(int a=0;a<15;a++) for(int b=0;b<15;b++) table->puzzle[a][b]='+';

    for(int o=0;o<50;o++) kontrol[o]=0;
    srand(time(NULL));
    
    while(1)
    {
        number_w=rand()%50;
        total_direct[1]=total_direct[2]=0;
        if(kontrol[number_w]==0)
        {
            //printf("hamza\n");
            kontrol[number_w]=1;
            total_direct[0]=rand()%3;
            table->location[0]=rand()%15;
            table->location[1]=rand()%15;
            if(table->location[0]>7) total_direct[1]=1;/*for reverse direct vertical*/
            if(table->location[1]>7) total_direct[2]=1;/*for reverse direct  horizontal*/
            
            strcpy(array,table->array_words[number_w]);
            array[strlen(table->array_words[number_w])]=0;
            //printf("%s\n",table->array_words[number_w]);
           // printf("%s\n",array);
           a=add_word_table(table,array,total_direct);
            i+=a;
            if(a==1)
            {
                strcpy(table->round_array[count],array);/* copy chosen words fromm file to in struct*/
                table->round_word_location[count][0]=table->location[0];
                table->round_word_location[count][1]=table->location[1];
                for(int o=0;o<3;o++)
                    table->direction[count][o]=total_direct[o];/* add location to struct*/
                printf("word=%s x=%d y=%d \n",table->round_array[count],table->round_word_location[count][0],table->round_word_location[count][1]);
                count++;
            }
        }
        if(i==7)/* if we add 7 game in puzzle we will finish loop*/
            break;
    }
    full_puzzle(table);/*for random letters*/
    print_puzzle(table);/*printing puzzle*/

}

int add_word_table(words * table,char array[],int direct[])
{
    int i=0,sum=0;;
    //printf("==>%d\n",strlen(array));
    if(direct[0]==0)
    {                                                                                          //     
        if(direct[2]==1)                                                                       //  here for control puzzle to add words empty location       
            for(int i=0;i<strlen(array);i++)                                                //
                if( table->puzzle[table->location[0]][table->location[1]-i]=='+') sum+=1;      //     
        else                                                                                   // 
            for(int i=0;i<strlen(array);i++)                                                   //         
                if(table->puzzle[table->location[0]][table->location[1]+i]=='+') sum+=1;       // 

        if(sum==strlen(array))
        {
            i=0;
            while(array[i]!=0)
            {
                //printf("dene");
                if(direct[2]==1)/*to go right*/
                    table->puzzle[table->location[0]][table->location[1]-i]=array[i];
                else/* to go left*/
                    table->puzzle[table->location[0]][table->location[1]+i]=array[i];
            i++;
            }
        return 1;
        }
        else
            return 0;
    }
    else if(direct[0]==1)
    {
        if(direct[1]==1)
            for(int i=0;i<strlen(array);i++)
                if( table->puzzle[table->location[0]-i][table->location[1]]=='+') sum+=1;                                                                   //  here for control puzzle to add words empty location  
        else if(direct[2]==1)
            for(int i=0;i<strlen(array);i++)
                if(table->puzzle[table->location[0]+i][table->location[1]]=='+') sum+=1;

        if(sum==strlen(array))
        {
            i=0;
            while(array[i]!=0)
            {
                            //printf("dene");

                if(direct[1]==1)/* for go down*/
                    table->puzzle[table->location[0]-i][table->location[1]]=array[i];
                else/* for go up*/
                    table->puzzle[table->location[0]+i][table->location[1]]=array[i];
            i++;
            }
        return 1;
        }
        else
            return 0;        
    }
    else if(direct[0]==2)/* this direct is for go diagonal*/
    {
        if(direct[1]==1)
        {

            if(direct[2]==1)
            {

                for(int i=0;i<strlen(array);i++)
                    if( table->puzzle[table->location[0]-i][table->location[1]-i]=='+') sum+=1;
            }
            else
                for(int i=0;i<strlen(array);i++)
                    if( table->puzzle[table->location[0]-i][table->location[1]+i]=='+') sum+=1;
        }

        else
        {

            if(direct[2]==1)
            {
                for(int i=0;i<strlen(array);i++)
                    if(table->puzzle[table->location[0]+i][table->location[1]-i]=='+') sum+=1;

            }
            else
                for(int i=0;i<strlen(array);i++)
                    if(table->puzzle[table->location[0]+i][table->location[1]+i]=='+') sum+=1;
        }

        if(sum==strlen(array))
        {
            i=0;
            while(array[i]!=0)
            {
                        // printf("dene");

                if(direct[1]==1)
                {

                    if(direct[2]==1)
                        table->puzzle[table->location[0]-i][table->location[1]-i]=array[i];
                    else
                        table->puzzle[table->location[0]-i][table->location[1]+i]=array[i];

                }
                else
                {
                    if(direct[2]==1)
                        table->puzzle[table->location[0]+i][table->location[1]-i]=array[i];
                    else
                        table->puzzle[table->location[0]+i][table->location[1]+i]=array[i];

                }
            i++;
            }
            return 1;
        }
        else
            return 0;
    }
//return 1;
}

void print_puzzle(words * table)
{
    for(int i=0;i<15;i++) 
    {
        for(int j=0;j<15;j++) 
        {
            if(table->puzzle[i][j]!='X')
                printf("%s%c%s ",KGRN,table->puzzle[i][j],KNRM);/* we will print puzzle in here*/
            else
                printf("%s%c%s ",KRED,table->puzzle[i][j],KNRM);


        }
        printf("\n");

    }    
}

void full_puzzle(words* table)
{
    char a=97;
    srand(time(NULL));/* adding random letter in puzzle*/
    a=rand()%26;
    for(int i=0;i<15;i++) for(int j=0;j<15;j++) if(table->puzzle[i][j]=='+'){ a=rand()%26+97;table->puzzle[i][j]=a;} 
}

int contreol_word(words *table,char chosen_word[25],int location_word[2] )
{
    int control=0,flag;
    for(int i=0;i<7;i++)
    {
        if(table->control[i]==0)
        {
            if(strcmp(table->round_array[i],chosen_word)==0)/* first control  user's input with random words*/
            {
                if(table->round_word_location[i][0]==location_word[0]&&table->round_word_location[i][1]==location_word[1])/* in here control words location*/
                {
                    add_x(table,i);
                    table->control[i]=1;
                    return 1;
                }
            }
        }    
    }
        return 0;
}

void add_x(words* table,int n)/* adding X sign table regard to direction that in struct*/
{                             /* this function to resembling to add_word_table function*/
    if(table->direction[n][0]==0)
    {
        if(table->direction[n][2]==1)
            for(int i=0;i<strlen(table->round_array[n]);i++)
                table->puzzle[table->round_word_location[n][0]][table->round_word_location[n][1]-i]='X';
        else
            for(int i=0;i<strlen(table->round_array[n]);i++)
                table->puzzle[table->round_word_location[n][0]][table->round_word_location[n][1]+i]='X';

    }
    if(table->direction[n][0]==1)
    {
        if(table->direction[n][1]==1)
            for(int i=0;i<strlen(table->round_array[n]);i++)
                table->puzzle[table->round_word_location[n][0]-i][table->round_word_location[n][1]]='X';
        else
            for(int i=0;i<strlen(table->round_array[n]);i++)
                table->puzzle[table->round_word_location[n][0]+i][table->round_word_location[n][1]]='X';

    }
    if(table->direction[n][0]==2)
    {
        if(table->direction[n][2]==1)
            if(table->direction[n][1]==1)
                for(int i=0;i<strlen(table->round_array[n]);i++)
                    table->puzzle[table->round_word_location[n][0]-i][table->round_word_location[n][1]-i]='X';
            else
                for(int i=0;i<strlen(table->round_array[n]);i++)
                    table->puzzle[table->round_word_location[n][0]+i][table->round_word_location[n][1]-i]='X';
        else
            if(table->direction[n][1]==1)
                for(int i=0;i<strlen(table->round_array[n]);i++)
                    table->puzzle[table->round_word_location[n][0]-i][table->round_word_location[n][1]+i]='X';
            else
                for(int i=0;i<strlen(table->round_array[n]);i++)
                    table->puzzle[table->round_word_location[n][0]+i][table->round_word_location[n][1]+i]='X';
    }
}

void zero_control(words * table)
{
    for(int i=0;i<7;i++ ) table->control[i]=0;/* reset control array*/
}
