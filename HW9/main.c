#include<stdio.h>
#include<stdlib.h>
#include<string.h>
union Person
{
char name[50];
char address[50];
int phone;
}Person;
union Loan
{
float amount;
float interestRate;
int period;
}Loan;
struct BankAccount
{
union Person Customer;
union Loan Loans[3];
}BankAccount;

struct BankAccount **resize_struct(struct BankAccount **obj,int *p);/*increse STRUCT array size*/

struct BankAccount ** addCustomers(struct BankAccount **obj,int *p,int *l);/*ADD NEW CUSTOMER in array*/

void listCostumers(struct BankAccount **obj,int *p);/* list customers*/

int taking_loat_size_file(char *info);/*taking customer's loat number from file*/

void newLoan(struct BankAccount **obj,int *p,int *i);/*adding new loan for customer*/

float calculateLoan(float amount, int period, float interestRate);/*calculate loan size*/

void adding_loan_to_file(char *name,float loan_amount,int period);/*add loan to file*/

void edit_input(char *inp);/* change \n with \0 from text that users input or taking from file*/

int strlenmy(char *str);/* search 2 space */

int learn_hypen_location(char *l);/*learn hyphen location*/

int learn_ID();/*learn user ıd in by lookink file*/

int control_file_for_custome(char *str);/*control file is for adding customer */

void getReport();/*taking inputs from file*/

float takefloat(char *str,int *period,int a);/*taking float number a string and convert to float number*/

int main()
{
    int size_of_struct=1;
    struct BankAccount **obj=NULL;
    int chose,new_loan_size=0,flag=0;
    char c;
    while(1)
    {
        flag=0;
        printf("==============================================\n"
            "    Welcome to the Bank Management System\n"
            "==============================================\n"
            "\t1.List All Customers\n"
            "\t2.Add new Customers\n"
            "\t3.New Loan Application\n"
            "\t4.Report MEnu\n"
            "\t5.Exit system\n"); 
            scanf("%d",&chose);
            while((c=getchar())&&c!=10)
            {
                if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                    flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
            }
            if (flag!=0)
                printf("Invalid operation\n");
            else if(chose==1)
                    listCostumers(obj,&size_of_struct);
            else if(chose==2)
              obj=  addCustomers(obj,&size_of_struct,&new_loan_size);
            else if(chose==3)
                newLoan(obj,&size_of_struct,&new_loan_size);
            else if(chose==4)
                getReport();
            else if(chose==5)
                break;
    }
    return 0;
}
struct BankAccount **resize_struct(struct BankAccount **obj,int *p)
{
    struct BankAccount **pl=(struct BankAccount**)calloc(sizeof(struct BankAccount *),*p);/*create new memory*/
    for(int i=0;i<(*p);i++)/*create struct array*/
    	pl[i]=(struct BankAccount *)calloc(3,sizeof(struct BankAccount));
    for(int i=0;i<(*p)-1;i++)
    {
   	    for(int j=0;j<3;j++)/*copy element inobj to new memory*/
    	  pl[i][j]=obj[i][j];
    }
    if(obj!=NULL)
    	free(obj);
    return pl;/*return adress of new memory*/
}

struct BankAccount ** addCustomers(struct BankAccount **obj,int *p,int *l)
{
    char c;
    int flag=0;
    obj=resize_struct(obj,p);
    int a=learn_ID();/*in here we learn all user number for user index for if user isn't in txt file*/
    printf("Write your name PLEASE!!\n");
    fgets(obj[(*p)-1][0].Customer.name,50,stdin);/*taking customer name firstly*/
    edit_input(obj[*p-1][0].Customer.name);
    if(control_file_for_custome(obj[*p-1][0].Customer.name))/*controlling text for user name if there there isn't user name in file we can add user name*/
    {
        char temp2[10];
        printf("You are already have BANK ACCOUNT !!!\n");
        printf("if You want to take loan please press 1\n");/* if user want to take loan we send him loan page */
        fgets(temp2,10,stdin);
        edit_input(temp2);
        if(strcmp(temp2,"1")==0)
            newLoan(obj,p,l);
        else return obj ;/*else sending main menu*/
    }
    printf("Write your adress PLEASE!!\n");/*if name user isn't in text we can take him another information*/
    fgets(obj[*p-1][1].Customer.address,50,stdin);
    edit_input(obj[*p-1][1].Customer.address);
    printf("Write your phone number PLEASE!!\n");
    scanf("%d",&(obj[*p-1][2].Customer.phone));
    while((c=getchar())&&c!=10)
    {
        if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
            flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
    }
    if(flag!=0)
    {
        printf("Invalid operation\n");
        //free(obj);
        return addCustomers(obj,p,l);
    }
        
    FILE *pf=fopen("customer.txt","a+");
    fprintf(pf,"%d-%s %s %d 0                                                  \n",a,obj[*p-1][0].Customer.name,obj[*p-1][1].Customer.address,obj[*p-1][2].Customer.phone);
    fclose(pf);/*we write user all information in file before name we write user index number after phone we write loan number */
    (*p)++;
    return obj;
}

void listCostumers(struct BankAccount **obj,int *p)
{
    for(int i=1;i<=(*p)-1;i++)/* in here we printing user's all information*/ 
    {
        printf("Customer ID:\t%d\n",i);
        printf("Customer name:\t%s\n",obj[i-1][0].Customer.name);
        printf("Customer adress:\t%s\n",obj[i-1][1].Customer.address);
        printf("Customer phone number:\t%d\n",obj[i-1][2].Customer.phone);
    }
}

void newLoan(struct BankAccount **obj,int *p,int *i)
{
    struct BankAccount **new_obj=(struct BankAccount **)malloc(sizeof(struct BankAccount*));
    new_obj[0]=(struct BankAccount *)calloc(3,sizeof(struct BankAccount));
    char buffer[50],*buffer1,c;
    FILE *pf=fopen("customer.txt","r+");
    printf("Welcome to the Loan Page\n");
    printf("Please write your name ");/*we taking user name for text controlling*/
    fgets(buffer,50,stdin);
    edit_input(buffer);
    int loan=5,controller=0,index,flag=0;
    float loan_amount;
    if(control_file_for_custome(buffer))/*if user name is in text file we can give him for credit*/
    {
        fseek(pf,0,SEEK_SET);/*controlling file again for user loan number*/ 
        while(!feof(pf))
        {
            
            buffer1=(char *)calloc(1000,sizeof(char));/*taking all line in text filr*/
            fgets(buffer1,1000,pf);
            edit_input(buffer1);
            if(strncmp(buffer,buffer1+learn_hypen_location(buffer1),strlen(buffer))==0)/*with strncmp() we controlling all line up to user input but without hyphen because there are index number before name*/ 
            {/* if user name is OK we control loan number*/
                loan=taking_loat_size_file(buffer);
                if(loan<4)/*if it less than 4 ıt couldn't take credit anymore*/
                {
                    printf("Please write your loan amount ");
                    scanf("%f",&(new_obj[0][0].Loans[loan].amount));
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                            flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
                    }
                    if(flag!=0)
                    {
                        free(new_obj);
                        printf("Invalid operation\n");
                        return;
                    }
                    printf("Please write your loan amount's interestRate ");
                    scanf("%f",&(new_obj[0][1].Loans[loan].interestRate));
                    flag=0;
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                            flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
                    }
                    if(flag!=0)
                    {
                        free(new_obj);
                        printf("Invalid operation\n");
                        return;
                    }
                    printf("Please write your loan amount's Period ");
                    scanf("%d",&(new_obj[0][2].Loans[loan].period));
                    flag=0;
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                            flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
                    }
                    if(flag!=0)
                    {
                        free(new_obj);
                        printf("Invalid operation\n");
                        return;
                    }
                    loan_amount=calculateLoan(new_obj[0][0].Loans[loan].amount,new_obj[0][2].Loans[loan].period,new_obj[0][1].Loans[loan].interestRate);
                    adding_loan_to_file(buffer,loan_amount,new_obj[0][2].Loans[loan].period);/*adding loan amount to file*/
                    free(new_obj);
                }
                else
                {
                    printf("You couln't take credit .Because you have already 3 loan!!\n");
                }

                break;
            }
            i++;
            free(buffer1);
        }
        fclose(pf);

    }
    else
    {
        fclose(pf);/*if user no account for taking credit we send him to adding customer page*/ 
        char new_temp[10];
        printf("you don't have any account for this operation ,Do you want to open an account\n");
        printf("Please press 1 if you want or press another thing\n");
        fgets(new_temp,10,stdin);
        edit_input(new_temp);
        if(strcmp(new_temp,"1")==0)
            addCustomers(obj,p,i);
    }
}

int taking_loat_size_file(char *info)
{
    FILE *p=fopen("customer.txt","r+");
    char *temp;
    int m;
    fseek(p,0,SEEK_SET);
    while (!feof(p))
    {
        temp=(char *)calloc(1000,sizeof(char));
        m=ftell(p);
        fgets(temp,1000,p);
        edit_input(temp);
        if(strncmp(temp+learn_hypen_location(temp),info,strlen(info))==0)/* firstly search user name in file if we found we control line in temp array*/
        {
            int i=0;
            while(temp[i]!=0)
            {
                if(i>0)
                {
                    if(temp[i-1]==' '&&temp[i]>='0'&&temp[i]<='3'&&temp[i+1]==' ')/*we controllin loan number*/
                    {
                        if(temp[i]<'3')/* if it less than 3 we increase it and write again temp on file */
                        {
                            temp[i]+=1;
                            fseek(p,m,SEEK_SET);/*m is invlude first cursor of line*/ 
                            fprintf(p,"%s",temp);   
                            fclose(p);
                            return temp[i]-48;/*we returning loan number after increasing*/
                        }
                    }
                }
            i++;
            }
        }
        free(temp);
    }
    return 5;/*else return 5 for couln't take input customer*/
    fclose(p);
}

float calculateLoan(float amount, int period, float interestRate)
{
    if(period==0)/*we calculating loan with recursive function */
        return amount;
    period-=1;
    return (1+interestRate)*calculateLoan(amount,period,interestRate);
}

void adding_loan_to_file(char *name,float loan_amount,int period)
{
    FILE *p=fopen("customer.txt","r+");/*after calculating loan ı write it customer's line*/
    char temp[20000];
    int m_tell;
    while (!feof(p))
    {
        m_tell=ftell(p);
        fscanf(p,"%[^\n]%*c",temp);
        if(strncmp(temp+learn_hypen_location(temp),name,strlen(name))==0)/*this condition control file for customers account information*/
        {
            fseek(p,m_tell+strlenmy(temp),SEEK_SET);
            fprintf(p," (%d)%.2f",period,loan_amount);/*in here ı write loan with it's period*/
            fclose(p);
            break;
        }
    }
    
}

void edit_input(char *inp)
{
    int i=0;
    while(inp[i]!=0)/*fgets() taking ınput with \n becausse of that ı change \n with \0 */
    {
        if(inp[i]==10)
            inp[i]=0;
    i++;
    }
}

int strlenmy(char *str)
{
    int i=0;
    while(str[i]!=0)/*for write loan in line ı need to move cursor right please . after print customer information ı print space for print much thing because of that ı need to know empty location for printing loan*/ 
    {
        if(str[i]==' '&&str[i+1]==' ')
        return i;
    i++;
    }
    return 0;
}

int control_file_for_custome(char *str)
{
    FILE *p=fopen("customer.txt","r+");
    char *temp;
    fseek(p,0,SEEK_SET);
    while(!feof(p))
    {
        temp=(char *)calloc(1000,sizeof(char));
        fgets(temp,1000,p);
        edit_input(temp);
        if(strncmp(temp+learn_hypen_location(temp),str,strlen(str))==0) /*control file for customer that has ben in file*/
        {
            if(temp[strlen(str)+learn_hypen_location(temp)]==32)//in file before user name there is index number and hypen so that ı control temp arrays with true adress 
            {                   //1-hamza konac (it wil be temp)
                free(temp);//    ı need to control temp for user name ı starting with temp+2 adress
                return 1;//
            }
        }
    free(temp);
    }
    return 0;
}

void getReport()
{
    char temp[50];
    float numbers[3];
    char *temp2,c;
    int loan_number, control,period[3],m=0, float_control=-1,costumer_index=0,name_controller=0,flag=0;
    FILE *p=fopen("customer.txt","r+");
    printf("Please write your name\n");
    fgets(temp,50,stdin);
    printf("Write your loan number:");
    scanf("%d",&loan_number);
    flag=0;
    while((c=getchar())&&c!=10)
    {
        if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
            flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
    }
    if(flag!=0)
    {
        printf("Invalid operation\n");
        return;
    }
    edit_input(temp);
    fseek(p,0,SEEK_SET);
    while(!feof(p))
    {
        temp2=(char *)calloc(1000,sizeof(char));
        fgets(temp2,1000,p);
        edit_input(temp2);
        if(strncmp(temp2+learn_hypen_location(temp2),temp,strlen(temp))==0)/*firstl search customer name in file*/
        {
            int i=0;
            name_controller++;
            while(temp2[i]!=0)
            {                   /*if ı could found name ı resarch loans*/ 
                if(i>4)
                {
                    if(temp2[i-1]==' '&&(temp2[i]>='0'&&temp2[i]<='3')&&temp2[i+1]==' ')
                    {       /*in this condition ı learn loan numbers*/
                        control=temp2[i]-48;
                        int j=i;
                        j++;
                        int a=0;
                        char *string_to_double=(char *)calloc(50,sizeof(char));
                        for(int o=0;o<control;o++)
                        {       /*ı taking this loop for forcontrol loan amount*/
                            int a=0;        
                            while(temp2[j]!=0)
                            {
                                string_to_double[a]=temp2[j];
                                if(temp2[j]=='.')
                                {
                                    for(int s=1;s<4;s++)
                                        string_to_double[a+s]=temp2[j+s];
                                    string_to_double[a+4]=0;
                                    a+=4;
                                    j+=4; /*string_to_double this array taking float number but like a string*/
                                    float c=takefloat(string_to_double,period,m);/* and this function conserv strşng to float number*/
                                    m++;
                                    numbers[++float_control]=c;/*this arraay storing float numbes period array storing loan's periods*/
                                    if(o!=control-1)
                                    {
                                        free(string_to_double);
                                        string_to_double=(char *)calloc(50,sizeof(char));
                                        break;
                                    }
                                }
                                a++;
                                j++;           
                            }
                        }
                    }
                }
            i++;
            }
        }
        free(temp2);
    }
    if(name_controller==0)
    {
        printf("Sorry we couldn't found your name in our bank\n");
        return;
    }
    else if(loan_number>control)
        printf("You haven't got loan that you want to see\n");
    else
    {
        printf("Total credit value = %.2f\n",numbers[loan_number-1]);/*ın here we printing user loan's ınformation*/
        float per_credit=(numbers[loan_number-1])/(float)(period[loan_number-1]);
        for(int i=0;i<period[loan_number-1];i++)
        {
            printf("%d. month Installment = %.2f\n",i+1,per_credit);
        }
    }
}
float takefloat(char *str,int *period,int a)
{

    int i=0,j=0;
    char new[50];
    int number=0;
    while(str[i]!=')')
    {
        if((str[i]>='0'&&str[i]<='9'))/*(12)2335.12 is sample loan in file we need to ignore brackets*/
            number=(str[i]-48) + number*10;
        i++;
    }
    period[a]=number;
    i++;
    while(str[i]!=0)/*we taking only float part of array*/
    {
        new[j]=str[i];
        i++;
        j++;
    }
    new[j]=0;
    return atof(new);/*and returning float number witf atof() function*/
}

int learn_ID()  /*this function counting custumer number for new customer index*/
{                   
    int a=0;
    char temp[10000];
    FILE *p=fopen("customer.txt","r+");
    if(p!=NULL)
    {
        fseek(p,0,SEEK_SET);
        while(!feof(p))
        {
            fgets(temp,10000,p);
            a++;
        }
        fclose(p);
    }
    else return 0;
    return a;
}

int learn_hypen_location(char *l)
{
    int i=0;
    while(l[i]!=0)
    {
        if(l[i]=='-')/*this function will use by strncmp for adress scrolling*/  
            return i+1; /*1-hamza konac*/ /*this sample show as hpen location and scrolling*/
    i++;
    }
}
