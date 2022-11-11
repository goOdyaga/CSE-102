#include<stdio.h>
#include<math.h>
int sum (int n1, int n2, int flag);

int multi (int n1, int n2, int flag);

void write_file (int number);

int isprime (int a);

void print_file ();

void sort_file ();

int find_range(int num);/*bulduğumuz sayıyı silmek için whitespace atıyoruz ama basamak sayısı kadar atmamıi gerek bunun için bu fonksiyon bulduğumuz sayının basamk sayısını returnlüyor*/

int find_num_num(); /*result.txt dosyasının içinde kaç tane int değer olduğunu returnlüyor*/

void print_temp(int num1 , int num2 ,int num3 ,int j); /*bulduğumuz küçük sayıları temp.txt dosyasının içine yazamak için kullanıyoruz*/

void copy_temp_result(); /*temp.txt dosyasını tesult.txt içine yazıyoruz*/

int main()
{

    int control=1,num1,num2,choose,flag,operation,result,prime,control_prime;
    while(control)
    {
        printf("Select operation\n"
                "1.Calculate sum/multiplication between two numbers:\n"
                "2.calculate prime numbers\n"
                "3.Show number sequence in file\n"
                "4.Sort number sequence in file\n"
                "5.EXIT\n");
        scanf("%d%*c",&choose);
        switch (choose)
        {
            case 1:
                printf("please enter '0' for sum, enter '1' for multiplication: ",&operation);
                scanf("%d",&operation);
                if(operation>1||operation<0)
                    printf("Please try again\n");
                else
                {
                    switch(operation)
                    {
                        case 0:
                            
                            printf("please enter '0' for work on even number, enter '1' for work on odd number:");
                            scanf("%d%*c",&flag);
                            if(flag>1||flag<0)
                            printf("Please try again\n");
                            else
                            {
                                switch (flag)
                                {
                                    case 1:
                                    
                                        printf("please enter two different number\n");
                                        printf("first number:");
                                        scanf("%d%*c",&num1);
                                        printf("second number:");
                                        scanf("%d%*c",&num2);
                                        if(num1<num2)
                                        {
                                            printf("=%d\n",result=sum(num1,num2,flag));
                                            write_file (result);
                                            printf("Result is written result.txt file\n");
                                        }
                                        else
                                        {
                                            printf("=%d\n",result=sum(num2,num1,flag));
                                            write_file (result);
                                            printf("Result is written result.txt file\n");
                                        }
                                    break;
                                    
                                    case 0:
                                        printf("please enter two different number\n");
                                        printf("first number:");
                                        scanf("%d%*c",&num1);
                                        printf("second number:");
                                        scanf("%d%*c",&num2);      
                                            if(num1<num2)
                                            {
                                                printf("=%d\n",result=sum(num1,num2,flag));
                                                write_file (result);
                                                printf("Result is written result.txt file\n");
                                            }
                                            else
                                            {
                                                printf("=%d\n",result=sum(num2,num1,flag));
                                                write_file (result);
                                                printf("Result is written result.txt file\n");
                                            }
                                    break;
                                }
                            }
                        break;
                   
                    case 1:
                        
                        printf("please enter '0' for work on even number, enter '1' for work on odd number:");
                        scanf("%d%*c",&flag);
                        if(flag>1||flag<0)
                            printf("Please try again\n");
                        else
                        {

                            switch (flag)
                            {
                                case 1:
                                    
                                    printf("please enter two different number\n");
                                    printf("first number:");
                                    scanf("%d%*c",&num1);
                                    printf("second number:");
                                    scanf("%d%*c",&num2);
                                    if(num1<num2)
                                    {
                                        printf("=%d\n",result=multi(num1,num2,flag));
                                        write_file (result);
                                        printf("Result is written result.txt file\n");
                                    }
                                    else
                                    {
                                        printf("=%d\n",result=multi(num2,num2,flag));
                                        write_file (result);
                                        printf("Result is written result.txt file\n");
                                    }
                                break;
                                
                                case 0:
                                        
                                    printf("please enter two different number\n");
                                    printf("first number:");
                                    scanf("%d%*c",&num1);
                                    printf("second number:");
                                    scanf("%d%*c",&num2);
                                    if(num1<num2)
                                    {
                                        printf("=%d\n",result=multi(num1,num2,flag));
                                        write_file (result);
                                        printf("Result is written result.txt file\n");
                                    }
                                    else
                                    {
                                        printf("=%d\n",result=multi(num2,num2,flag));
                                        write_file (result);
                                        printf("Result is written result.txt file\n");
                                    }
                                break;
                            }
                        }
                        
                        break;
                    }
                }
            
            break;
        
            case 2:
                printf("Please an integer:");
                scanf( "%d",&prime);
                for(int i=2;i<prime;i++)
                {
                    control_prime=isprime(i);
                    if(control_prime==0)
                        printf("%d is a prime\n",i);
                    else    
                        printf("%d is not prime.it is dividible by %d\n",i,control_prime);
                }
            break;

            case 3:
                printf("Result:\n");
                print_file();
                printf("\n");   
            break;
            
            case 4:
                sort_file();
                printf("\n");
            break;
           
            case 5:
                control=0;
            break;
        }
    }
return 0;
}

void write_file (int number)
{
    FILE *fp=fopen("result.txt","a");
        fprintf(fp," %d",number);/*part1 den gelen sayıları file içine ayzıyoruz*/
    fclose(fp);
}

int sum (int n1, int n2, int flag)
{
    int sum=0,control=0;
    char d=8;/*for delete more plus sign*/
    for(int i=n1+1;i<n2;i++)
    { 
        if(i%2==flag) /* flag 0 olduğu için çift sayıları alıcah ifin için*/
        {
            if(control==0)
            {
                printf("%d",i,d);/*2+4+6+8=x ifadesinde 2 den önce + olmadığı için yazmamamıi gerekn conditionı belirtdik*/
                sum+=i;
                control++;
            }
            else
            {
                printf("+%d+%c",i,d);/* +%c ifadesi 2+4+6+ ifadesinde son + işaretini silmek için kullandım*/ 
                sum+=i;
            }
        }
    }
return sum;
}

int multi (int n1, int n2, int flag)
{
  int multi=1,control=0;
    char d=8;/*for delete more plus sign*/
    for(int i=n1+1;i<n2;i++)
    {
        if(i%2==flag) /* flag 1 olduğu için tek sayıları alıcah ifin için */
        {
            if(control==0)
            {
                printf("%d",i,d);/*2*4*6*8=x ifadesinde 2 den önce * olmadığı için yazmamamıi gerekn conditionı belirtdik*/
                multi*=i;
                control++;
            }
            else
            {
                printf("*%d*%c",i,d);/* +%c ifadesi 2*4*6* ifadesinde son * işaretini silmek için kullandım*/
                multi*=i;
            }
        }
    }
return multi;  
}

int isprime (int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return i;
    }
return 0;
}

void print_file ()
{
    int a;
	char b;
  FILE *fp=fopen("result.txt","r");    
  while (!feof (fp))
    {  
    	fscanf (fp, "%d", &a);    /*file içindeki int değerleri printliyoruz*/ 
    	printf ("%d ",a);
    }
    fclose(fp);
}
void sort_file ()
{
 int a,b,x,d=1,num1=0,num2=0,num3=0,j=0,m,i;//ALGORİTMA: önce filedaki sayı adedini buluyorum.sonra 3'e bölüp 1 ekliyorum ve sonucu for döngüsüne sokuyorum
 //çünkü sayıları 3 er 3er sileceğim.Daha sonra for içinde ikinci bir for'a sokuyorum burada da en küçük 3 sayıyı buluyorum ve her bulduğum sayıyın yerine whitespace atarak siliyorum 
 char c=49;//sayıların basamağına göre spac atacağım için basamak sayısını bulmam gerek burada find_range fonksiyonu devereye giriyor.
int num=find_num_num();//ikinci forun içinde iki tane while döngüsü var bunların biri filedan sayı çekiyor diğeride çektiğim sayıyı komple file ile kıyaslıyor
						//daha sonra for un içinde i değişkenine göre bulduğum sayıları num1 num2 veya num3 e atıyorum ve bunları print_temp fonksiyonuna yolluyorum.her ikinci forun başında bu num ları sıfırlıyorum
int temp;//böylece bunları flag olarak kullanmışda olacağım çünkü eğer fonksiyona giden değer sıfırsa demek oluyorki o sayıya bişey atanmadı ve file yazdırmıyorum.yani şöyle file içindeki sayı adedi 3 ün katı olmayabilir
temp=num;
if(num%3!=0)//bu durmda son 2 sayı veya 1 sayı sadece num1 veya (num2 ve num1) atanır diğerleri 0 olur bunların yazdırılmaması gerek.sıfırn yazılması için tek şart var o da ilk sayı sıfır olursa o durumda j yani giden üçlü sayısı
	num=(num/3+1);//yanii en dıştaki forun değişjeni 0 olursa geçerli bu da print_temp fonksiyounda kondişinda belirtildi.içerdki fonksiyon kaç sayı bulacağı ile ilgili eğer sayı%3=1 ise son durumda bir sayı%3=2 ise 2 sayı olacak 
else
	num/=3;//bu durumda içerdeki for 1 veya iki kere dönmeli buda ikinci forun altında koşullandırıldı.ilk while içinde önce fgetc() ile bir karakter alıyoruz eğer efof() ise direkt döngüden atıyoruz boşluksa sayı almıyoruz ki fscanf farklı değerleri okuyabilsin
			//eğer feof() deilse imlec bir geri gitmeli ve imlecin yeri de tutulmalı ki eğer küçük sayı ilk while da tuttuğum sayı ise silebileyim.
  FILE *fp=fopen("result.txt","r+");//ikinci while da aynısı farkı da if kondişınında küçük sayı buluyor ve fscanf sayı alamazsa imlecin yeerini koruyor böylece sayıyı silebiliyoruz
  for(j=0;j<num;j++)//açıklamalar= 266_269 ==>> eğer sayı 3 etam bölünüyorsa 1 eklemye gerek yok çünkü int tam bölünür aksi takdirde eksik bölme yapar 1 eklemek durumuında kalırız
     {//265==>>nump temp değişkenine atıyoruz çünkü döngüde 3 ile modunu kullanırken tempi kullanacağız.num 3 e bölündüğü için eski değer kaybolacak
    	num1=num2=num3=-1;	//274==>sayıları sıfırlıyoruz
        for( i=d;i<=3;i++)//275==> d değişkeni kullanma sebebimiz ikinci forun kaç kere döneceğini belirlemek 334 ile 339 satırları arasında d değişşkeni versiğimiz sayılarla döngü kod kontrolünde dönüyor.böyle temp.txt dosyasına fazladan sayı yazılmıyor
        {//
            fseek(fp,0,SEEK_SET);//277==>imlec satır başına atılıyor
            while (1)//
            {  //
                c=fgetc(fp);//280-284==>feof ve boşlık durumu kontrol eddiliyor
                if(feof(fp))//
                    break;//
                else//
                    fseek(fp,-1,SEEK_CUR);//
                if(c!=' ')//
                {   //285==>eğer boşluk yoksa aldığım char bir sayını charıdır bu yüzden imlec bir geri gider ve sayıyı komple alır
                    fseek(fp,-1,SEEK_CUR);//
                    fscanf (fp, "%d", &a); //
                    m=ftell(fp);//
                    break;//
                }//
                else//
                {   //
                    fseek(fp,1,SEEK_CUR);//291==>eğer boşluk yoksa direkt sayı alınır
                    fscanf (fp, "%d", &a); //
                    m=ftell(fp);//
                    break;//
                }//
            }//
            fseek(fp,m+1,SEEK_SET);//
            b=a;//301==>eğer aşağıdaki while sayı bulamazsa yani tek sayı kaldı ve onu dayukarıda aldı silmek için imlecin yerine ihtiyacım var a sayısını hem x hem de b ye atıyorum  
            x=a;//eğer scanf farklı sayı alamaz ve boşluklar yüzünden de sayı alamaz buffer boş olmadığı için hep aynı sayıyı kontrol edecek ve imlec kayacak 
            while (1)//x sayısı imlecin yerini koruyor böylece son kalan 1 veya 2 sayıyı silebiliyoruz 
            {  //
              //
                    fscanf (fp, "%d", &b); //
                    if(a>=b && x!= b)//301. satırda bhsedilen koşullar
                    {//
                        a=b;//
                        x=b;//
                        m=ftell(fp);    //
                    }//
                //
                        //
                c=fgetc(fp);//
                if(feof(fp))//316-319==>feof ise bitir deilse imleci geri çek
                    break;//
                else//
                    fseek(fp,-1,SEEK_CUR);//
            }//
            int z=find_range(a);//321==>sayı basamağını bul
            fseek(fp,m-(1*z),SEEK_SET);//imleci sayının başın alıp başından itibaren white space atılır
            for(int i=0;i<z;i++)//
                fprintf(fp," ");    //whitesapca atıp sayı sil find arngedden geln sayı kadar whitespace at sayını tamamı silinmiş olur
            fseek(fp,-1,SEEK_CUR);//
            if(i==1)//
                num1=a;   //
            if(i==2)//
                num2=a;   //num1 num2 ve num3 e değer ataması yapılır yapılmazsa -1 atanır ve flag olarak kullanılır
            if(i==3)//
                num3=a;   //
        }//
        print_temp(num1 , num2 ,num3,j);//
		if(temp%3==2&&j==num-2)//
			d=2;//ikinci for döngüsnün kaç kere döneceğine bakar eğer ilk ife girerse 2 kere ikinci if e girerse bir defa ağer iflere girmezse 3 defa dönecek
		if(temp%3==1&&j==num-2)//
			d=3;//
		else	//
			d=1;//
    //
    }//
fclose(fp);//dosyayı kapatıyoruz
copy_temp_result();  //temp.txt dosyasını result.txt içine yazıyoruz
print_file();//result.txt dosyasını yazdırıyoruz
remove("temp.txt");
}

int find_range(int num)
{
    int i=0;
    while(i<12345)
    {
        num/=10;/*csayıyıcher 10 a böldüğümüzde bir basamak buluruz*/
        i++;
        if(num==0)/*tek basamkalı sayıyı 10 a bölersek sonuç 0 olur*/
            break;
    }
    return i;
}
int find_num_num()
{
    FILE *p=fopen("result.txt","r");
    int i=0,num;
    while(!feof(p))
    {
        fscanf(p,"%d",&num);/* Her bulunan int değeri için counter artıyor*/ 
        i++;
    }
    return i; /* counterı returnluyoz */
}
void print_temp(int num1 , int num2 ,int num3,int j)
{
    FILE * p=fopen("temp.txt","a+"); /* Bulduğumuz sayıları geçici file a yazma işlemlerini yapıyoruz*/
	if(j==0 && num1 ==0 ) /* sıralamaya göre ilk sayının alabileceği en küçük değer 0 olur*/ 
        fprintf(p,"%d ",num1);
	else if(num1!=-1) /* ilk sayı dışında -1 gelirse yazdırmıyoruz*/
        fprintf(p,"%d ",num1);
        if(num2!=-1)/* ilk sayı dışında -1 gelirse yazdırmıyoruz*/
            fprintf(p,"%d ",num2);
        if(num3!=-1)/* ilk sayı dışında -1 gelirse yazdırmıyoruz*/
            fprintf(p,"%d ",num3);
        fclose(p);
}
void copy_temp_result()
{
    FILE *p=fopen("result.txt","w+");
    FILE *f=fopen("temp.txt","r");
    int a;  
    while(!feof(f))
    {
        fscanf(f,"%d",&a);/*tempden çektiğimiz verileri resultın içine tekrar yazıyoruz*/
		if(feof(f)) /*feof gelince direkt çıkması gerek yoksa result.txtye bir int fazla yazarız*/
			break;
        fprintf(p," %d",a);
    }   
    fseek(p,-1,SEEK_CUR);
    fclose(f);
    fclose(p);
}

