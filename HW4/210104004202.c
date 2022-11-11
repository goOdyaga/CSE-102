#include<stdio.h>

#define KYEL  "\x1b[33m"
#define KBLU  "\x1b[34m"/*renkli yazmak için kullandığım definelar*/
#define KNRM  "\x1b[0m"

void write_coef_file(int a,int b,int c);


void write_graph();/* grafiği teminale yazmak için kullanıyorum*/

void write_file();/* grafiği graph.txt dosyasına yazdırıyorum*/ 

int find_backs_num(int num);/*karakter sayısını buluyorum*/

int main(){

    int control=1,chose;

    while(control)
    {
        printf("Select operation ...\n"
              "0 -> Enter the coefficients:\n"
              "1--> Draw the graph:\n"
              "2--> print graph into a .txt file\n"
              "3--> EXIT \n");
        printf("choise:");
        scanf("%d",&chose);
        if(!(chose<=3&&chose>=0))
            printf("Try again!!!\n");
        if(chose==0)
        {
            int a,b,c;
            printf("Please enter the coefficient for the following equation: x=a*(y*y)+b*y+c\n");
            printf("a:");
            scanf("%d",&a);
            printf("b:");/*kullanıcıdan denkleemin katsayılarını aldım*/ 
            scanf("%d",&b);
            printf("c:");
            scanf("%d",&c);
            write_coef_file(a,b,c);
       
        }

        if(chose==1)
        {
            FILE *p=fopen("coefficients.txt","r");
            if(p==NULL)/*eğer dosya yoksa hata mesajı bastıaracağım*/
                printf("dosya yok:\n");
            else
                write_graph();/*grafiği yazmak için kullandığım fonksiyon*/
            fclose(p);/*fonksiyonu kapattım*/
        }
        if(chose==2)
        {
            FILE *p=fopen("coefficients.txt","r");
            if(p==NULL)/*eğer dosya yoksa hata mesajı bastıaracağım*/
                printf("dosya yok:\n");/*grafiği graph.txt dosyasına yazdırmak iççin kullandıpım fonksiyon*/
            else
                write_file();
            fclose(p);
        }
        
        if(chose==3)
            control=0;/*menudeki exit fonksiyonu çalışsın diye control'ü sıfıra eşitleyip döngüden çıkartıyorum*/
    }
}

void write_coef_file(int a,int b,int c)
{
    FILE *p=fopen("coefficients.txt","w+");
    if(p==NULL)
        printf("File couldn't create\n");
    else
    {
        fprintf(p,"%d\n%d\n%d\n",a,b,c);/*sayıları alt alta yazmak için kullanıyorum*/
        printf("coefficients.txt file hs been created\n");
    }
    fclose(p);
}

void write_graph()
{
    int a,b,c;
    FILE *p=fopen("coefficients.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d %d %d",&a,&b,&c);/*sayıları coefficients.txt dosyasından çekiyorum*/
    }
    fclose(p);
    int y=15,x=-50;
    for(int i=0;i<=33;i++)
    {
        for(int j=0;j<=111;j++)
        {
            if(j==55&&i==0)
                printf("^");
            else if(j==55&&i==33)/*y ekseninin oklarını ayzdırdım*/
                printf("v");
            else if(j==55)
                printf("|");/*y ekseniini çizdim*/
            else  if(i==16&&j==0)
                printf("<");
            else if(i==16&&j==111)/* x ekseninin oklarını çizdim*/
                printf(">");
            else  if(i==16&&j!=111&&j!=0&&j!=55)
                printf("-");/*x eksenini çizdim*/
          
            else if(j==53&&i%5==1)
            {
                if(y==0)
                    y-=5;
                int back=find_backs_num(y);
                for(int i=1;i<back;i++)
                   printf("\b");/* y ekseninin soluna sayıları yazdırırken fazladan karakter kayması olmasın diye boişukları siliyorum*/
                printf("%s%d%s",KYEL,y,KNRM);/*sayıları renkli yazdırıyoum*/
                y-=5;
            }
            
            else if(i==17&&j%10==4)
            {
                 int back=find_backs_num(x);/*sayılar değiştiği işin karakter atılacak \b sayısı da değişiyor fonksiyon o sayıyı dönderiyor*/
                for(int i=1;i<back;i++)
                   printf("\b");/*x ekseninin altına sayıları yazdırırken fazladan karakter kayması olmasın diye boişukları siliyorum*/
               printf("%s%d%s",KYEL,x,KNRM);/*sayıları renkli yazdırıyoum*/
                x-=(-10);
            }
            else 
                printf(" ");/*boşluk attırıyorum boş yerler için*/
        }
        printf("\n");
    }
    printf("\033[33A");/*imleci grafiğin en başına taşıyorum*/
    printf("\033[111D");/* daha sonra grafik üstünde tekrar gezinerek curve va ya line ı çiziyorum*/

    for(int y=15;y>=-16;y--)
    {
        for (int  x = -55; x <=55;x++)
        {
            if(x==a*(y*y)+b*(y)+c)
                printf("%s#%s",KBLU,KNRM);/*hashtag i renklendiriyorum*/
            else    
                printf("\033[1C");/*eğer hashtag yazmicaksa imleci kaydırıyorum*/

        }
                printf("\033[1B");/*satır sonunda alt satıra geçiyorum ve imleci en başa alıyorum*/
                printf("\033[111D");
        
    }
}

int find_backs_num(int num)
{
    int i=0;
    if(num<0)
        i++;/* eğer sayı negatifse karakter artamsı gerek*/
    while(num!=0)
    {
        num/=10;/* her basamak için karaekter artıyor*/
        i++;
    }
    return i;
}

void write_file()
{
     int a,b,c;
    FILE *f=fopen("coefficients.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %d %d",&a,&b,&c);/*sayıları filedan çekiyorum*/
    }
    fclose(f);
    f =fopen("graph.txt","w");
    for(int y=15;y>=-15;y--)
    {
        for (int  x = -55; x <=55;x++)
        {
            if(x==(a*(y*y)+b*(y)+c)&&(x!=55&&x!=-55)&&(y!=15&&y!=-15))
                fprintf(f,"#");/* # işaretini bastırıcam*/
            else if(x==0&&y==15)
                fprintf(f,"^");
            else if(x==0&&y==-15)/* y ekseninin oklarını çizicem*/
                fprintf(f,"v");
            else if(x==0&&(y!=-15&&y!=15))
                fprintf(f,"|");/* y eksenini çiziyorum*/
            else if(y==0&&x==55)/* x ekseninin oklarını çizicem*/
                fprintf(f,">");
            else if(y==0&&x==-55)
                fprintf(f,"<");
            else if(y==0&&(x!=55&&x!=-55))
                fprintf(f,"-");/* x eksenin bastırıyorum*/
            else    
                fprintf(f," ");

        }
                fprintf(f,"\n");/* alt satıra geçiyorum*/
        
    }
    fclose(f);/* dosyayı kapatıyorum*/

}
