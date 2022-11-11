#include<stdio.h>
#include "utils.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"/* write for colorful title*/
#define KNRM  "\x1B[0m"
int main(){

	int x,y,z,n,f_i,control_id,password,control_login;
	float amount;
	char identity[11];
	printf("Enter the first integer:");
	scanf("%d",&x);
	printf("\nEnter the second integer:");
	scanf("%d",&y);
	printf("\nEnter the divisor:");
	scanf("%d",&z);
	f_i=find_divisible(x,y,z);/*if function return -1 its means that there is not divided by z int*/
	if(f_i==-1)
	printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);

	if(f_i!=-1)
	{
			printf("The first integer between %d and %d divided by %d is %d",x,y,z,f_i);
		printf("\nEnter the number how many next:");
		scanf("%d",&n);/*we take nth didivisble number*/
		f_i=find_nth_divisible(n,f_i,z); 	
		if(f_i<y) 
			printf("The %d rd integer between %d and %d divided by %d is %d\n",n+1,x,y,z,f_i);
		else
			 printf("No possible to find %dth divisible between %d and %d divided by %d\n",n,x,y,z);
	}
	printf("%s\"WELCOME CREATE CUSTOMER PAGE:%s\"\n",KRED,KNRM);/*we take identity for create customer*/
	printf("write your 11 digits identitiy number\n");
	scanf("%s",identity);/*we take password for create customer*/
	control_id=validate_identity_number(identity);/*we control identity algorithm*/	
	printf("Write your 4 digits password:\n");
	scanf("%d",&password);
		if((password<10000&&password>999)&&control_id==1)/*password must be 4 digits*/
		{		
			create_customer(identity,password);
			printf("%s\"WELCOME LOGıN PAGE%s\"\n",KRED,KNRM);	
			printf("Write your identity number:\n");
			scanf("%s",identity);
			printf("Enter your password:\n");/*again we take identitiy and password from customer for login */
			scanf("%d",&password);
			control_login=check_login(identity,password);
			if(control_login==1)
			{
				printf("%s“Login Successful”%s\n",KGRN,KNRM);
				printf("Enter your withdraw amount:\n");
				scanf("%f",&amount);/*for succseful login we take amoun of money*/
				amount=withdrawable_amount(amount);/*amount must be 10,20 or 50 times */
				printf("%sWithdrawable amount is:%.0f%s",KGRN,amount,KNRM);
			}
			else
				printf("%sInvalid identity number or password%s\n",KRED,KNRM);
		}
		else/*for unsuccesful login write this messages screen*/
		printf("%sInvalid identity number or password%s\n",KRED,KNRM);
	return 0;
}
