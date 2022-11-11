#include<stdio.h>
#include<string.h>
#include "utils.h"
int find_divisible(int x, int y, int z)
{
	if(x<y)/*x must be less than y if else we return -1*/
	{
		for(int i=x+1;i<=y;i++)
		{
			if(i%z==0)/*when ths equation equals to zero we will find divisible number and return it*/
				return i;
		}
		return -1;/*if we can not find divisible number we will retun -1*/
	}
	else return -1;

}

int find_nth_divisible(int n, int f_i,int z)
{
	for(int i=0;i<n;i++) f_i+=z;/*we add z to f_i n times and we will find nth divisible number*/

	return f_i;
}
int validate_identity_number(char identity_number [])
{
 	int i=0;
	int doub_sum=0,odd_sum=0;
	if(identity_number[0]==48)/*if first number of identity has 0 we zterun 0*/
		return 0;	
		while(identity_number[i]!=0)/*in the array  there is a string and end of this string there is NULL(\0 or 0) because of that we control array untill NULL */
		{	if(identity_number[i]<'0'||identity_number[i]>'9')
				return 0;
			if(i<9)
			{
				if(i%2==1)/*we add double step in same value*/
					doub_sum+=identity_number[i]-48;/*char array take numbers ascıı value due to we substract 48 the index number of  char array */
				else/*we add odd step in same value*/
					odd_sum+=identity_number[i]-48;
			}
			 if(i==9)
				if(identity_number[i]!=(((7*odd_sum)-doub_sum)%10+48))/*we apply algoritm that says us multiply odd_summ 7  times an substract even_sum finally mod10 this equalition and it must be equaş 10. number of idenity*/
					return 0;
			 if(i==10)
				if(identity_number[i]!=((doub_sum+odd_sum+(identity_number[9]-48))%10+48))/*11.digit must be equal to sum of first 10 digit and we control that*/
					return 0;
			i++;
		}
	if(i==11)/*if identity just have 11 digits we return 0*/
		return 1;
 return 0;
}

int create_customer(char identity_number [], int password)
{
	FILE *custom;
	int i=0;
	identity_number[11]=0;/*while sending array another function NULL is chancing place because of that we add NULL again right place,so that %s take righ chars in array*/
	custom=fopen("customeraccount.txt","w");/*weopen a file in write mode*/
	if(custom==0)
			printf("file couldn't open sorry\n");
	else
	{
		fprintf(custom,"%s,%d",identity_number,password); /*we write info in file*/
	fclose(custom);
	}
}


int check_login(char identity_number [], int password)
{
	char identity[12];
	int o=0,old_pass;
	while(identity_number[o]!=0)
		o++;
	if(o!=11)
		return 0;
	o=0;
	FILE* custom;
	identity_number[11]=0;
	custom=fopen("customeraccount.txt","r");
	fscanf(custom,"%[^,]%*c %d",identity,&old_pass);/* we take identity and password*/
	identity[11]=0;
	fclose(custom);
	printf("%s %d\n",identity,old_pass);
	while(o<11)
		{
			if((identity[o]!=identity_number[o])&&(password!=old_pass))
				return 0;/*if identities or password are differen we return 0*/
		o++;
		}
	return 1;
}
int withdrawable_amount(float cash_amount)
{
	return cash_amount - ((int)cash_amount)%10;/*times 10 20 or 50 is summary time of 50 becaouse of that we substract of mode of amount from than amount*/
}
