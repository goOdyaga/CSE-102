#include<stdio.h>
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

void printMap (int table[][30]) ;/*for printing map*/

void create_Map(int table[][30],int x1,int y1,int x2,int y2);/*for creating map*/

int dice (void);/*to take dixe number*/

int startGame (void);/*it return us player who play first*/
/*void winner_two(int table[][30],int control);
void winner_one(int table[][30],int control);*/

int move_player1(int table[][30]);/*thıs function will control player 1 movement*/
int move_player2(int table[][30]);/*thıs function will control player 2 movement*/

int main()
{
    int table[15][30],player;
    create_Map(table,1,1,3,3);/*we call create_map for creating game table*/

    printMap(table);/*and printing map on screen*/
    player=startGame();/*learning who will start first*/ 
    printf("player %d will start game :\n",player);
    int control=0;
    if(player==1)/*if player 1 will start first we must call player 1's move function*/
    {
        while(1)
        {
            control=move_player1(table);    
            if(control==0)
                break;    
            control=move_player2(table);
            if(control==0)
                break;    
        }
    }
    else
    {
         while(1)/*if player 2 will start first we must call player 2's move function*/
        {
            control=move_player1(table);    
            if(control==0)
                break;    
            control=move_player2(table);
            if(control==0)
                break;    
        }
    }
}

void printMap (int table[][30])
{
    int x,y;

  
    for(x=0;x<15;x++)
    {
        for(y=0;y<30;y++)
        {
            if(table[x][y]=='X')
            printf("%s%c%s",KRED,table[x][y],KNRM);//
            else if(table[x][y]==':')//
            printf("%s%c%s",KBLU,table[x][y],KNRM);//
            else if(table[x][y]=='_')//
            printf("%s%c%s",KGRN,table[x][y],KNRM);//we print map colorful
            else if(table[x][y]=='1'||table[x][y]=='2')//
            printf("%s%c%s",KMAG,table[x][y],KNRM);//
            else if(table[x][y]=='.')//
            printf("%s%c%s",KBLU,table[x][y],KNRM);//
            else    //
                printf("%c",table[x][y]);//
        }
        printf("\n");
    }
}

int startGame (void)
{
    
    char c;
    int p1,p2;
    printf("To start game , players should dice and decide who is going to start first according to it ...\n");
    printf("PLAYER 1... Please ENTER to dice ");
    getchar();/*wating player for press ENTER*/
    p1=dice();
    printf("DICE:%d\n",p1);
    printf("PLAYER 2... Please ENTER to dice ");
    getchar();
    p2=dice();
    printf("DICE:%d\n",p2);
    if(p1>p2)/*if player 1's dice is bigger than 2's dice we return 1*/ 
        return 1;
    else if(p1==p2)
        startGame();/*if dice's are equal we recall function for again want to player to dice*/
    else
     return 2;/*else we return 2*/
}
int dice (void)
{
    int a;
 
    srand(time(NULL));/* dice function */
    a=rand()%6+1;
    return a;
}

int move_player1(int table[][30])
{
    int dice_1;
    //dice_1=5;
    dice_1=dice();
    int a,control=0,b,control2=0;
       printf("\n%sPLAYER 1 Press ENTER to dice\n",KGRN);
    getchar();
    printf("DICE:%d%s\n",dice_1,KNRM);    
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<30;y++)
        {
            if(table[x][y]=='1')/*we searching array until find player 1 location*/
            {
                control2=1;/* control for finis lıne*/
                a=(x+dice_1)%15;
                b=(y+dice_1)%30;
                if(x==1)/* to go right*/
                    {
                        if(y+dice_1<=29)
                        {
                            table[x][y]=' ';
                            if(table[x][y+dice_1]=='X')/*if player come to peanlty point go step back*/
                                table[x][y+dice_1-2]='1';
                            else if((y+dice_1)==29)
                                table[x+1][y+dice_1-1]='1';
                            else
                                table[x][y+dice_1]='1';
                        }
                        else if(((y+dice_1)>29))/*to turn corner*/ 
                        {
                            a=y+dice_1-29;
                            table[x][y]=' ';
                            table[x+a][y+dice_1-a-1]='1';   
                        }
                    }
                else if(y==28)/* to go down*/
                {
                    if((x+dice_1)<=14)
                    {
                        table[x][y]=' ';
                        if(table[x+dice_1][y]=='X')/*if player come to penalty point go step back*/
                            table[x+dice_1-2][y]='1';
                        else if(x+dice_1==14)
                            table[x+dice_1-1][y-1]='1';
                        else
                            table[x+dice_1][y]='1';
                    }
                    else if(((x+dice_1)>14))/*to turn corner*/ 
                    {
                    
                        table[x][y]=' ';
                        table[x+dice_1-(x+dice_1)%13][y-(x+dice_1)%13]='1';   
                    }
                }
                else if(x==13)/* to go left*/
                {
                    if((y-dice_1)>=0)
                    {
                        table[x][y]=' ';
                        if(table[x][y-dice_1]=='X')/*if player come to penalty point go step back*/
                            table[x][y-dice_1+2]='1';
                        else if(y-dice_1==0)
                            table[x-1][y-dice_1+1]='1';
                        else
                            table[x][y-dice_1]='1';
                    }
                    else if(((y-dice_1)<0))/*to turn corner*/
                    {
                     a=dice_1-y;   
                        table[x][y]=' ';
                        table[x-a-1][y-dice_1+a+1]='1';   
                    }
                }
                else if(y==1)
                {
                    if(((x-dice_1)>=0))
                    {
                        table[x][y]=' ';
                        if(x-dice_1==1) /* conntrol finish line*/
                            control++;
                        if(x-dice_1==0)
                        {
                            table[x-dice_1+1][y+1]='1';
                            control=1;/* control finish line */
                        }
                        else
                            table[x-dice_1][y]='1';
                    }
                    else if(((x-dice_1)<0))/* to turn corner*/ 
                    {
                        
                        control=1;
                        a=dice_1-x;
                        table[x][y]=' ';
                        table[x-dice_1+a+1][y+a]='1';   
                    }
                }  
            }
            if(control2==1)
            {
                if(table[2][1]==' ')
                            table[2][1]='_';
                printMap(table);
                if(control==1)/*if player pass to finish line we finish game and print winner name*/
                {
                   
                    printf("WINNER IS PLAYER 1 :))\n");
                    return 0;
                }
                else
                    return 1;
            }
        }
    }
       
}

int move_player2(int table[][30])
{
    int dice_1;
    dice_1=dice();
    int a,control=0,b,control2=0;
    printf("\n%sPLAYER2 ...Press ENTER to dice\n",KYEL);
    getchar();
    printf("DICE:%d%s\n",dice_1,KNRM);
    
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<30;y++)
        {
            if(table[x][y]=='2')/*we searching array until find player 1 location*/
            {
                control2=1;/* control for finis lıne*/
                a=(x+dice_1)%15;
                b=(y+dice_1)%30;
                   if(x==3)/* to go right*/
                    {
                        if(((y+dice_1)<=27))
                        {
                            table[x][y]=' ';
                            if(table[x][y+dice_1]=='X')/*if player come to peanlty point go step back*/
                                table[x][y+dice_1-2]='2';
                            else if(y+dice_1==27)
                                table[x+1][y+dice_1-1]='2';
                            else
                                table[x][y+dice_1]='2';
                        }
                        else if(((y+dice_1)>27))
                        {
                            a=y+dice_1-27;
                            table[x][y]=' ';
							if(table[x+a][y+dice_1-a-1]=='X')
									table[x+a-2][y+dice_1-a-1]='2';
							else
                            	table[x+a][y+dice_1-a-1]='2';   
                        }
                    }
                else if(y==26)/* to go down*/
                {
                        if(((x+dice_1)<=12))
                        {
                            table[x][y]=' ';
                            if(table[x+dice_1][y]=='X')/*if player come to penalty point go step back*/
                                table[x+dice_1-2][y]='2';
                            else if(x+dice_1==12)
                                table[x+dice_1-1][y-1]='2';
                            else
                                table[x+dice_1][y]='2';
                                //table[x+dice_1][y]='2';
                        }
                        else if(((x+dice_1)>12))
                        {
                            a=(x+dice_1)-12;
                            table[x][y]=' ';
                            table[x+ dice_1-a-1][y-a-1]='2';   
                        }
                }
                    else if(x==11)/* to go left*/
                    {
                      
                        if(((y-dice_1)>=2))
                        {
                            table[x][y]=' ';
                            if(table[x][y-dice_1]=='X')/*if player come to peanlty point go step back*/
                                table[x][y-dice_1+2]='2';
                            else if(y-dice_1==2)
                                table[x-1][y-dice_1+1]='2';
                            else
                                table[x][y-dice_1]='2';
                        }
                        else if(((y-dice_1)<2))
                        {
                         a=(dice_1+2)-y;   
                            table[x][y]=' ';
                            table[x-a][y-dice_1+a+1]='2';   
                        }
                    }
                    else if(y==3)/* to go up*/
                    {
                        if(((x-dice_1)>=2))
                        {
               
                            table[x][y]=' ';
                            if(x-dice_1==3) 
                                control++;
                            if(x-dice_1==2)
                            {
                                table[x-dice_1+1][y+1]='2';
                                control=1;
                            }
                            else
                                table[x-dice_1][y]='2';
                        }
                        else if(((x-dice_1)<2))
                        {
                            
                            table[x][y]=' ';
                           
                            a=3-(x-dice_1);
                                table[x-dice_1+a][y+a]='2';
                                control=1;
                        }
                    } 
            }
            if(control2==1)
            {
                 if(table[4][3]==' ')
                                table[4][3]='_';
                printMap(table);
                if(control>=1)
                {
                    printf("WINNER IS PLAYER 2 :))\n");
                    return 0;
                }
                else
                    return 1;
            }
        }
    }
    
}
void create_Map(int table[][30],int x1,int y1,int x2,int y2)
{
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<30;y++)
        {
            if((x==1&&y==14)||(x==7&&y==28)||(x==13&&y==14))
                table[x][y]='X';
            else if((x==3&&y==10)||(x==3&&y==18)||(x==5&&y==26)||(x==10&&y==26)||(x==11&&y==10)||(x==11&&y==18))
                table[x][y]='X';
            else if((x==2&&y==1)||(x==4&&y==3))
                table[x][y]='_';/*we create map for each special condition*/
            else if(x==x1&&y==y1)
                table[x][y]='1';
            else if(x==x2&&y==y2)
                table[x][y]='2';
            else if(x==0||x==14)
                table[x][y]='.';
            else if((y==0||y==29)&&(x!=0&&x!=14))
                table[x][y]=':';
            else if((x==2||x==12)&&(y>1&&y<28))
                table[x][y]='.';
            else if((y==2||y==27)&&(x>2&&x<12))
                table[x][y]=':';
            else if((x==4||x==10)&&(y>3&&y<26))
                table[x][y]='.';
            else if((y==4||y==25)&&(x>4&&x<10))
                table[x][y]=':';
            else
                table[x][y]=' ';
        }
    }
}

