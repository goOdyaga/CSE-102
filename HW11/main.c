#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct table {
    char *table_name;
    char **field;
    char **type;
    bool *isNull;
    bool *isKey;
} table;

typedef struct tables {
   struct  tables *next; 
    table * t;
} tables;


typedef struct database {
    tables * tList; /* to be implemented as a linked list */
    int n; /* num of entries */
    char * name; /* table name */
    struct database *next;
} database;


void create_database(database *d,char *name);

void show_table(database *d);

void desc_table(database *d, table *t);

void insert_table(database *d, table *t); 

void remove_table(database *d, char *name);

void insert_key(database *d, table *t,bool key_value );

void edit_input(char *inp);

bool control_database1(database *d,char *name);
bool control_database2(database *d,char *name);

int main()
{
    database *data_root;
    data_root=(database *)malloc(sizeof(database));
    data_root->n=0;
    data_root->next=NULL;
    data_root->tList=(tables *)malloc(sizeof(tables));
    data_root->tList->next=NULL;
    char *temp=NULL;
    int control=0;
    database *data_root_temp=data_root;
    //database *temp_database;


    while(1)
    {
        printf("\t\tHySQL SYSTEMM\n"
                "1.Create Database System:\n"
                "2.Create a table for a Database system:\n"
                "3.Delete a Database system: \n"
                "4.Delete a Table:\n"
                "5.Write tables\n"
                "6.EXIT\n");
        temp=(char *)calloc(100,sizeof(char));
        fgets(temp,100,stdin);
        edit_input(temp);
        if(strcmp(temp,"1")==0)
        {
            control++;
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            printf("For new creating Please write your database name: ");
            fgets(temp,100,stdin);
            edit_input(temp);
            data_root_temp=data_root;
            create_database(data_root_temp,temp);
            data_root_temp=data_root;
            if(control>2)
                 printf("\n\ndata number->%d database name->%s database name->%s\n\n\n",data_root->n,data_root->name,data_root->next->name);
             printf("\n\ndata number->%d database name->%s\n\n\n",data_root->n,data_root->name);
           // free(temp);
        }
        else if(strcmp(temp,"2")==0)
        {
                printf("kontrol dataabase-> %s \n",data_root->name);
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            printf("Print your Database name for adding:\n");
            fgets(temp,100,stdin);
            edit_input(temp);
            if(control_database1(data_root_temp,temp))
            {
                //data_root_temp=data_root;
                free(temp);
                temp=(char *)calloc(100,sizeof(char));
                //char *temp_t=(char *)calloc(100,sizeof(char));
                table *temp_Table=(table *)malloc(sizeof(table));
                temp_Table->table_name=(char *)calloc(strlen(temp)+1,sizeof(char));
                printf("Write your table name: ");
                fgets(temp,100,stdin);
                edit_input(temp);
                strcpy(temp_Table->table_name,temp);
                free(temp);
                printf("***kontrol noktasi***\n");
                data_root_temp=data_root;   
                insert_table(data_root_temp,temp_Table);    
                data_root_temp=data_root;        
            }
            else
                printf("ERROR!!!\n Couldn't found database\n");
            
        }
        else if(strcmp(temp,"3")==0)
        {

        }
        else if(strcmp(temp,"4")==0)
        {
    
        }
        else if(strcmp(temp,"5")==0)
        {
            //temp_database=data_root;
            data_root_temp=data_root;
            show_table(data_root_temp);
            data_root_temp=data_root;
            // free(temp);
            // temp=(char *)calloc(100,sizeof(char));
            // printf("Print your Database name for adding:\n");
            // fgets(temp,100,stdin);
            // edit_input(temp);
            // if(control_database1(data_root,temp))
            // {
// 
            // }
            // else
                // printf("ERROR!!!\n Couldn't found database\n");
        }
        else if(strcmp(temp,"6")==0)
        {
            break;
        }
    }

    return 0;
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
void create_database(database *data_root,char *name)
{
    //database *temp=data_root;
    if(data_root->next==NULL)
    {
        //data_root=data_root->next;
        database *temp=(database *)malloc(sizeof(database));
        data_root->name=(char *)calloc(strlen(name)+1,sizeof(char));
        strcpy(data_root->name,name);
        temp->n=data_root->n;
        temp->n+=1;
        //data_root=realloc(data_root,(data_root->n+1)*sizeof(data_root));
        temp->next=NULL;
        data_root->next=temp;
       // database *temp2=(database *)malloc(sizeof(database));
       // data_root->next=temp2;
        return;
    }
    else
    {
        printf("-o-> %s \n",data_root->name);
        create_database(data_root->next,name);
    }
    
}

void insert_table(database *d, table *t)
{

    tables *temp=d->tList;
    tables *temp2=(tables *)malloc(sizeof(tables));
    temp2->next=NULL;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            printf("kontrol noktasi 2***\n");
            temp->t=t;    
            temp->next=temp2;
            break;
        }
        temp=temp->next;
    }
}

bool control_database1(database *d,char *name)
{
    if(d->next==NULL)
        return false;
    else if(strcmp(d->name,name)==0)
        return true;
    else
        control_database1(d->next,name);
}
bool control_database2(database *d,char *name)
{
    if(d->next==NULL)
        return false;
    else if(strcmp(d->name,name)==0)
    {
        char *temp=(char *)calloc(100,sizeof(char));
        table *temp_Table=(table *)malloc(sizeof(table));
        temp_Table->table_name=(char *)calloc(strlen(name)+1,sizeof(char));
        printf("Write your table name: ");
        fgets(temp,100,stdin);
        edit_input(temp);
        strcpy(temp_Table->table_name,temp);
        free(temp);
        printf("kontrol noktasi***\n");
        insert_table(d,temp_Table);
        return true;
    }
    else
        control_database2(d->next,name);
}

void show_table(database *d)
{
    if(d->next==NULL)
    {
        printf("kontrol4****\n");
        return;
    }
    else
    {
        while (d->tList->next!=NULL)
        {
           printf("%d : %s \n",d->n,d->tList->t->table_name);
           d->tList=d->tList->next;
        }
        show_table(d->next);
        
    }
}
