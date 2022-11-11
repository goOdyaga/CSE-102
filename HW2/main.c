#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {

	int choose,x4,x5,sec,yas,yıl,exit=1;
	double puan1,yuzde;
	double  PL,PW,SL,SW,x1,x2,x3;
	while(exit)
	{

	printf("MENU\n"
					"\t1.P1\n"
					"\t2.P2\n"
					"\t3.P3\n"
					"\t4.exit\n"
						"choose\n");
	scanf("%d%*c",&choose);
	if(choose==1)
	{
		printf("\nwrite values for PL,PW,SL,SW\n");
		scanf("%lf %lf %lf %lf%*c", &PL,&PW,&SL,&SW);
		char res=dt1a(PW,PL,SL,SW);
		char res1=dt1b(PW,PL,SL,SW);
		if(res=='s')	/*we print first result */ 
				printf("Setosa\n");
		if(res=='v')
				printf("Virginica\n");
		if(res=='c')
				printf("Versicolor\n");
		if(res!=res1)/* if second result is equal to first result we dont print second result*/ 
		{

		if(res=='s')
				printf("Setosa\n");
		if(res=='v')
				printf("Virginica\n");
		if(res=='c')
				printf("Versicolor\n");
		}
}
  if(choose==2)
{
	printf("Write x1,x2 and x3 values:");
	scanf("%lf %lf %lf%*c",&x1,&x2,&x3);
	printf("write binary x4 x5 values(just 0 or 1):");
	scanf("%d %d%*c",&x4,&x5);
	double res2=dt2a(x1,x2,x3,x4,x5);
	double res3=dt2b(x1,x2,x3,x4,x5);
	int a=(res2-res3);
		if(a<0)
				a*=-1;/*we convert to substract of result of two function if substract of them is negative*/  
		if(res2==res3)
			printf("%lf\n",res2);
			if(CLOSE_ENOUGH>=a)/*if both answers are the same, that result will be given as the answer
to the problem. If the results differ, both decisions will be reported. Similarly, for regression (the
output is an ordinal number), if the two results are similar (within a threshold, defined as the
constant CLOSE_ENOUGH in util.h), the average will be printed otherwise both results will be
output.*/
				printf("%lf\n",(res2+res3)/2);
			else
					printf("first resulr=%.2lf  second result=%.2lf\n",res2,res3);		
			
}
if(choose==3)
{
	printf("wrire your exam year\n");/*we take of ecam year to student */
	scanf("%d%*c",&yıl);
	printf("write your bianry chose(0 medicine 1 is engineering)\n");/*binary number choose department o student*/
	scanf("%d%*c",&sec);
	printf("write your Grade\n");/*we take exam grade from student*/
	scanf("%lf%*c",&puan1);
	printf("write ypr age\n");/*we take age of student*/
	scanf("%lf",&yas);
	printf("write your pearcent peace");/* we take pearcent peace of exam's*/
	scanf("%lf",&yuzde);
	char res4=dt3a(puan1,yuzde,sec,yas,yıl);
	if(res4=='A') printf("you can go ankara university in engineering\n");
	if(res4=='U') printf("you can go uludag university in medicine department\n");
	if(res4=='N') printf("you can not go university that you want \n");
	if(res4=='K') printf("you can go koc university\n");
	if(res4=='G') printf("you can come gebze teknik universiy \n");
	if(res4=='L') printf("you can go abdullah gül uni\n");
	if(res4=='B') printf("you can go bogazici university\n");
	char res5=dt3b(puan1,yuzde,sec,yas,yıl);
	if(res4!=res5)/*if second reasult is equal to result one we don't print result*/
	{
		if(res5=='G') printf("you can come gebze teknik universiy \n");
		if(res5=='I') printf("you can go\n");
		if(res5=='K') printf("you can go koc university\n");
		if(res5=='B') printf("you can go bogazici university\n");
		if(res5=='N') printf("you can not go university that you want \n");
		if(res5=='.') printf("you took the result\n");
		if(res5=='U') printf("you can go uludag university in medicine department\n");
		if(res5=='H') printf("you can go hacettepe university\n");
		if(res5=='E') printf("you can go eskişehir university\n");
		if(res5=='A') printf("you can go ankara university in engineering\n");
		if(res5=='L') printf("you can go abdullah gül uni\n");
	}

}
if(choose==4)
	exit=0;/*if student want to quit to menu he/she  require to press 4 */
	}
    return 0;
}

