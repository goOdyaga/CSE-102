#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder}Shapes;

typedef enum{Area=1,Perimeter,Volume}Calculators;

int select_shape ();

int select_calc ();

int calculate (int(* f)(), int(* p)());

int calc_triangle(int calc);

int calc_quadrilateral(int calc);

int calc_circle(int calc);

int calc_pyramid(int calc);

int calc_cylinder(int calc);

int find_big(int num1,int num2);/*Dörtgen eşitsizliği için kullandım*/

int find_small(int num1,int num2);/*Dörtgen eşitsizliği için kullandım*/

int main()
{
    int control=1;
    while(control)
    {
        control=calculate(select_shape,select_calc);
    }
    return 0;

}

int select_shape ()
{
    int chose=-1,flag=0;
    char c;
        printf("Select a shape the calculation\n"
                    "\t1.Triangle\n"
                    "\t2.Quadrilateral\n"
                    "\t3.Circle\n"
                    "\t4.Pyramid\n"
                    "\t5.Cylinder\n"
                    "\t0.EXIT\n");
        scanf("%d",&chose);
        while((c=getchar())&&c!=10)
        {
            if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
        }
        if(flag>0)
        {
            return -1;
        }
        else
            return chose;/*girilmezse seçilen değer dönecek*/

}

int select_calc ()
{
    int chose=-1,flag=0;
    char c;
        printf("Select calculator\n"
                    "\t1.Area\n"
                    "\t2.Perimeter\n"
                    "\t3.Volume\n"
                    "\t0.EXIT\n");
        scanf("%d",&chose);
        while((c=getchar())&&c!=10)
        {
            if(c>32)/*space veya tab gibi ifadeler tanımsız değer olmadığı için koşul dışına alıyoruz*/ 
                flag++;/*buffera tanımsız bir değer girildiği zaman flag artacak ve fonksiyon tekrar çağırılacak*/ 
        }
        if(flag>0)
        {
            return -1;
        }
        else
            return chose;/*girilmezse seçilen değer dönecek*/
}

int calculate (int(* f)(), int(* p)())/*f shape fonksiyoun p calculate fonksiyonu*/
{
    Shapes chose_s=-1;
    Calculators chose_c=-1;
   // int control=1;
    int control_3=1;
    printf("Welcome to the geometric calculator!\n");
        chose_s=f();/*kullanıcı şekil seçimi yapıyor*/
        if(chose_s==0)
            return chose_s;/*eğer EXIT yaparsa 0 döndericez*/
        else if(chose_s>0&&chose_s<6)
        { 
            //int control_2=1; 
                chose_c=p();/*hesap türü seçeceğiz*/
                if(chose_c==0)
                    return 1;/*eğer çıkak isterse ana menüye edönderecceğiz*/
                else if  (chose_c>0&&chose_c<4) 
                {
                    switch (chose_s)
                    {
                        case Triangle:
                                while(control_3)
                                {
                                    control_3=calc_triangle(chose_c);/*üçgen hesabı için seçilen işlemle beraber fonksiyonu çağıracağız*/
                                    if(control_3==0) calculate(select_shape,select_calc);/*calculate tipinden sonra tekrar şekil seçmek isterse fonksiyonu tekrar çağırıyouz*/
                                    if(control_3==2) chose_c=p();/*tekrar calculate tipi seçmek için değer returnlüyorum*/
                                    if(control_3==1)/*eğer yanlıi ınput alınırsa error basılacak*/
                                        printf("ERROR!! Invalid entry for Triangle sides\n");
                                }
                                control_3=1;
                            break;
                        case Quadrilateral:
                                while(control_3)
                                {
                                    control_3=calc_quadrilateral(chose_c);/*dörtgen hesabı için seçilen işlemle beraber fonksiyonu çağıracağız*/
                                    if(control_3==0) calculate(select_shape,select_calc);/*calculate tipinden sonra tekrar şekil seçmek isterse fonksiyonu tekrar çağırıyouz*/
                                    if(control_3==2) chose_c=p();/*tekrar calculate tipi seçmek için değer returnlüyorum*/
                                    if(control_3==1)/*eğer yanlış ınput alınırsa error basılacak*/
                                        printf("ERROR!! Invalid entry for Quadrilateral sides\n");
                                }
                                control_3=1;
                            break;
                        case Circle:
                                while(control_3)
                                {
                                    control_3=calc_circle(chose_c);/*circle hesabı için seçilen işlemle beraber fonksiyonu çağıracağız*/
                                    if(control_3==0) calculate(select_shape,select_calc);/*calculate tipinden sonra tekrar şekil seçmek isterse fonksiyonu tekrar çağırıyouz*/
                                    if(control_3==2) chose_c=p();/*tekrar calculate tipi seçmek için değer returnlüyorum*/
                                    if(control_3==1)/*eğer yanlış ınput alınırsa error basılacak*/
                                        printf("ERROR!! Invalid entry for Circle radius\n");
                                }
                                control_3=1;
                                break;
                        case Pyramid:
                            while(control_3)
                            {
                                control_3=calc_pyramid(chose_c);/*pyramıd hesabı için seçilen işlemle beraber fonksiyonu çağıracağız*/
                                if(control_3==0) calculate(select_shape,select_calc);/*calculate tipinden sonra tekrar şekil seçmek isterse fonksiyonu tekrar çağırıyouz*/
                                if(control_3==1)/*eğer yanlış ınput alınırsa error basılacak*/
                                printf("ERROR!! Invalid entry for Pyramid's base side\n");
                                if(control_3==2)
                                printf("ERROR!! Invalid entry for Pyramid's slant heigt \n");
                                if(control_3==3)
                                printf("ERROR!! Invalid entry for Pyramid's height \n");
                                if(control_3==4) chose_c=p();/*tekrar calculate tipi seçmek için değer returnlüyorum*/
                            }
                            control_3=1;
                            break;
                        case Cylinder:
                          while(control_3)
                            {
                                control_3=calc_cylinder(chose_c);/*cylınder hesabı için seçilen işlemle beraber fonksiyonu çağıracağız*/
                                if(control_3==0) calculate(select_shape,select_calc);/*calculate tipinden sonra tekrar şekil seçmek isterse fonksiyonu tekrar çağırıyouz*/
                                if(control_3==1)/*eğer yanlış ınput alınırsa error basılacak*/
                                printf("ERROR!! Invalid entry for Cylinder radıus\n");
                                if(control_3==2)
                                printf("ERROR!! Invalid entry for Cylınder's heigt \n");
                                if(control_3==3) chose_c=p();/*tekrar calculate tipi seçmek için değer returnlüyorum*/
                            }
                            control_3=1;
                            break;
                    }
                }  
                else
                {
                    printf("ERROR!! Invalid value for chosing ,try again!!\n");/*yanlı input için calculate fonksiyounu tekrara çağırılacak*/      
                    return 1;
                }   
           
        }
        else   
        {
            printf("ERROR!! Invalid value for chosing ,try again!!\n");/*yanlı input için calculate fonksiyounu tekrara çağırılacak*/
            return 1;
        }
  
    
  

}

int calc_triangle(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float edge1=-1,edge2=-1,edge3=-1;
    char c;
    int control=1,flag=0;
    float sum;
    switch (chose_c1)
    {
        case Area:
                printf("Enter 3 sides of triangles:");
                scanf("%f",&edge1);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(edge1>0)
                {
                    scanf("%f",&edge2);
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)
                            flag++;
                    }
                    if(flag>0)
                        return 1;/*buffer boşaltacak invalid değer girilmesi durumunda*/
                    if(edge2>0)
                    {
                        scanf("%f",&edge3);
                         while((c=getchar())&&c!=10)
                        {
                            if(c>32)
                                flag++;
                        }
                        if(flag>0)
                            return 1;
                        if(edge3>0)
                        {
                            if(((abs(edge1-edge2))<(abs(edge3)))&&(edge3<(abs(edge1+edge2))))/*eğer kenarlar valid ve üçgen eşitsizliği de sağlanıyorsa bu ifin içinş girecek ve değeri bastıracak*/
                            {
                                control=0;
                                float s;
                                s=(float)(edge1+edge2+edge3)/2;
                                sum=sqrt(s*(s-edge1)*(s-edge2)*(s-edge3));/*üçgen alan formülü*/
                                printf("area of TRIANGLE %.2f\n",sum);
                            return 2;

                            }
                            else
                                return 1;
                        }
                        else
                            return 1;
                    }               /*herhangi bir kenar hatalı girilirse returnler sayesinde tekrar kaner sorgulama ekranı açılacak*/
                    else
                        return 1;
                }
                else
                    return 1;
            break;
        case Perimeter:
            printf("Enter 3 sides of triangles:\n");
            scanf("%f",&edge1);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(edge1>0)
            {
                scanf("%f",&edge2);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(edge2>0)
                {
                    scanf("%f",&edge3);
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)
                            flag++;
                    }
                    if(flag>0)
                        return 1;
                    if(edge3>0)
                    {
                        if(((abs(edge1-edge2))<(abs(edge3)))&&(edge3<(abs(edge1+edge2))))/*eğer kenarlar valid ve üçgen eşitsizliği de sağlanıyorsa bu ifin içinş girecek ve değeri bastıracak*/
                        {
                            control=0;
                            sum=edge1+edge2+edge3;/*üçgen çevre formülü*/
                            printf("perimeter of TRIANGLE %.2f\n",sum);
                            return 2;
                        }
                        else
                            return 1;
                    }
                    else
                        return 1;
                }  /*herhangi bir kenar hatalı girilirse returnler sayesinde tekrar kaner sorgulama ekranı açılacak*/
                else
                    return 1;
            }
            else
                return 1;
        case Volume:
            printf("ERROR!! you cannot calculate the Triangle volume!!\n");
            return 2;
        break;
    }
    
    return 0;
}

int calc_quadrilateral(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float edge1=-1,edge2=-1,edge3=-1,edge4=-1;
    char c;
    int control=1,flag=0;
    float sum;
    switch (chose_c1)
    {
         case Area:
       
            printf("Enter 4 sides of quadrilateral:\n");
            printf("a=>");
            scanf("%f",&edge1);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(edge1>0)
            {
                printf("b=>");
                scanf("%f",&edge2);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(edge2>0)
                {
                    printf("c=>");
                    scanf("%f",&edge3);
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)
                            flag++;
                    }
                    if(flag>0)
                        return 1;
                    if(edge3>0)
                    {
                        printf("d=>");
                        scanf("%f",&edge4);
                        while((c=getchar())&&c!=10)
                        {
                            if(c>32)
                                flag++;
                        }
                        if(flag>0)
                            return 1;
                        if(edge4>0)/*eğer kenarlar validse bu ifin içine girecek*/
                        {
                            int sum1=abs(edge1-edge3),sum2=abs(edge2-edge4);
                            int big,small;/*burada iki tane dörtegen için iki tane üçgen eşitiszliği kullandım*/
                            big=find_big(sum1,sum2);//                                                                      
                            small=find_small(edge1+edge3,edge2+edge4);//                                     /\          1.|a-b|<x<|a+b|.3                                     
                            if(big<small)//                                                               a /  \ b        2.|c-d|<x<|c+d|.4                                                      
                            {//                                                                            /_x__\          bu iki eşitsizlikte 1 ve 2 den büyük olanı 3 v 4den küçük olanı alacağız                                           
                                float s;//                                                                 \    /           eğer x tanımlı bir aralıkta çıkarsa dörtgen tanımlı olacaktır                                          
                                s=(edge1+edge2+edge3+edge4)/2;//                                          c \  /  d              find_big fonksiyonu 1 ve 2den büyük olanı find_small fonksiyonu 3 ve 4den küçük olanu bulacaktır
                                sum=sqrt((s-edge1)*(s-edge2)*(s-edge3)*(s-edge4));//                         \/                   
                                printf("area of Quadrilateral %.2f\n",sum);//                                               
                                return 2;//                                                                                 
                            }
                            else
                                 return 1;
                        }
                        else
                            return 1;
                    }
                    else/*eğer kenarlar veya eşitsizlik tanımlı olmazsa tekrar keanr isteyecek*/
                        return 1;
                }
                else
                    return 1;
            }
            else
                return 1;        
            break;
        case Perimeter:
            printf("Enter 4 sides of quadrilateral:\n");
            printf("a=>");
            scanf("%f",&edge1);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(edge1>0)
            {
                printf("b=>");
                scanf("%f",&edge2);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(edge2>0)
                {
                    printf("c=>");
                    scanf("%f",&edge3);
                    while((c=getchar())&&c!=10)
                    {
                        if(c>32)
                            flag++;
                    }
                    if(flag>0)
                        return 1;
                    if(edge3>0)
                    {
                        printf("d=>");
                        scanf("%f",&edge4);
                        while((c=getchar())&&c!=10)
                        {
                            if(c>32)
                                flag++;
                        }
                        if(flag>0)
                            return 1;
                        if(edge4>0)
                        {
                            int sum1=abs(edge1-edge3),sum2=abs(edge2-edge4);
                            int big,small;/*alan için uyguladığımız tüm formuller ve eşitsizlikler burada da geçerli*/ 
                            big=find_big(sum1,sum2);
                            small=find_small(edge1+edge3,edge2+edge4);
                            if(big<small)
                            {
                                sum=edge1+edge2+edge3+edge4;
                                printf("perimeter of Quadrilateral %.2f\n",sum);
                                return 2;
                            }
                            else
                                 return 1;
                        }
                        else
                            return 1;
                    }
                    else/*invalid kenarlar girerse tekrar keanr sorulacak*/
                        return 1;
                }
                else
                    return 1;
            }
            else
                return 1;  
            break;
        case Volume:/*dörtgende hacim olmadığı için hesap yapamaayız*/
            printf("ERROR!! you cannot calculate the Quadrilateral volume!!\n"); 
            return 2;
    }
}

int calc_circle(int calc)
{
     Calculators chose_c1;
    chose_c1=calc;
    float radius=-1;
    int control=1,flag=0;
    char c;
    switch (chose_c1)
    {
    case Area:
            printf("Enter circle radius:\n");
            scanf("%f",&radius);/*çember alanı için sadece radıusa ihtiyacımız var sadece onu kontrol edeceğiz*/
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(radius>0)
            {   
                printf("area of Circle %.2f\n",3.14*radius*radius);/*çember alan formulu π*r*r formulu kullanılr*/
                return 2;
            }
            else    
                return 1;
    case Perimeter:
            printf("Enter circle radius:\n");
            scanf("%f",&radius);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(radius>0)
            {   
                printf("perimeter of circle %.2f\n",3.14*radius*2);/*çember çevre formulu 2*π*r formulu uygulanır*/
                    return 2;
            }
            else
                return 1;
    case Volume:
        printf("ERROR!! you cannot calculate the Circle volume!!\n"); 
        return 2;/*çemberin hacmi bulunamaz*/
    }
  
}

int calc_pyramid(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float slant_h=-1,base_s=-1,height=-1;
    int control=1,flag=0;
    char c;
    switch (chose_c1)
    {
        case Area:
            printf("Please enter base side of pyramid\n");
            scanf("%f",&base_s);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;/*kare piramitin taban kenarı yan yüz yüksekliğini alacağız */
            if(base_s>0)
            {   
                printf("Please enter slant hight of pyramid\n");/*ve bunlarla taban alanı ve yan yüz alanlarını bulacağız*/
                scanf("%f",&slant_h);//                                                                                                                                                                 
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;//                                                                                                                       
                if(slant_h>0)//                                                                                                                                                               
                {//                                                                                                                                                           
                    printf("BASE SURFACE of Pyramid:%.2f\n",base_s*base_s);//       a*a taban alanı                                                                                                                                                    
                    printf("LATERAL SURFACE of pyramid:%.2f\n",2*base_s*slant_h);//                2*a*h toplam yan yüz alanı                                                                                                                                                 
                    printf("AREA of Pyramid %.2f\n",(base_s*base_s)+(2*base_s*slant_h));//              a*(a+2*h) toplam piramit alanı                                                                                                                                                   
                    return 4;//                                                                                                                                                                 
                }//                                                                                                                                                                 
                else//                                                                                                                                                                  
                    return 2;/*2 dönme sebebi slant height hatalı olduğunu yazdırmak içindir*/                  //                    tanımsız kenar girme durumunda error verilecek                                                                                                                           
            }//                                                                                                                                                                 
            else   //                                                                                                                                                                    
                return 1;/*1dönme sebebi base side hatalı olduğunu yazdırmak içindir*/                                                                                                                                 
        
    case Perimeter:
        printf("Please enter base side of pyramid\n");
        scanf("%f",&base_s);/*kare piramitin taban kenarı yan yüz yüksekliğini alacağız */
        while((c=getchar())&&c!=10)
        {
            if(c>32)
                flag++;
        }
        if(flag>0)
            return 1;
        if(base_s>0)
        {
            printf("Perimeter of pyramid base is:%.2f\n",4*base_s);/*ve bunlarla taban çevrsini  bulacağız ---> 4*a */
            return 4 ;
        }
        else
            return 1;
        break;
    case Volume:
            printf("Please enter base side of pyramid\n");
            scanf("%f",&base_s);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(base_s>0)
            {   
                printf("Please enter  height of pyramid\n");
                scanf("%f",&height);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(height>0)
                {
                    printf("VOLUME of PYRAMIDE %.2f\n",(base_s*base_s*height)/3); /*piramid hacmi bulacağız (a*a*h)/3 */
                    return 4;
                }
                else
                    return 3;/*3 dönme sebebi heightın  hatalı olduğunu yazdırmak içindir*/
            }
            else    
                return 1;/*1dönme sebebi base side hatalı olduğunu yazdırmak içindir*/
       
    }
}   

int calc_cylinder(int calc)
{
      Calculators chose_c1;
    chose_c1=calc;
    float radius=-1,height=-1;
    int control=1,flag=0;
    char c;
    switch (chose_c1)
    {
    case Area:
        
            printf("Please enter radius of cylinder\n");
            scanf("%f",&radius);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(radius>0)
            {   
                printf("Please enter height of cylinder\n");/*cylinder için radıus ve h yüksekliği alcağız*/
                scanf("%f",&height);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(height>0)
                {
                    printf("BASE SURFACE area of Cylinder:%.2f\n",2*3.14*radius*radius);/*taban alanı π*r*r formülü ile hesaplanacak*/
                    printf("LATERAL SURFACE of Cylinder:%.2f\n",2*3.14*radius*height); /*yan yüz alanı 2*π*r*h formülü ile hesaplanacak*/
                    printf("AREA of CYLINDER %.2f\n",(2*3.14*radius*height)+(2*3.14*radius*radius));/*toplam alan hesaplanır*/
                    return 3;
                }
                else
                return 2;/*2 dönnme sebebi heightın hatalı olduğunu yazdırmak için*/
            }
            else    
                return 1;  /*1dönme sebebi radiusun hatalı olduğunu yazdırmak içindir*/      
    case Perimeter:
            printf("Please enter radius of cylinder\n");
            scanf("%f",&radius);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(radius>0)
            {   
                    printf("BASE SURFACE perimeter of Cylinder:%.2f\n",2*3.14*radius);/*çevre için sadece alt taban alanını hesaplıypruz*/
                    return 3;
            }
            else    
                return 1; 
    case Volume:
            printf("Please enter radius cylinder\n");
            scanf("%f",&radius);
            while((c=getchar())&&c!=10)
            {
                if(c>32)
                    flag++;
            }
            if(flag>0)
                return 1;
            if(radius>0)
            {   
                printf("Please enter hight of cylinder\n");/*cylinder için radıus ve h yüksekliği alcağız*/
                scanf("%f",&height);
                while((c=getchar())&&c!=10)
                {
                    if(c>32)
                        flag++;
                }
                if(flag>0)
                    return 1;
                if(radius>0)
                {
                    printf("VOLUME of CYLINDER %.2f\n",3.14*radius*radius*height);/*hacim için π*r*r*h formülü kullanıyoruz*/
                    return 3;
                } 
                else
                    return 2;/*2 dönnme sebebi heightın hatalı olduğunu yazdırmak için*/
            }
            else    
                return 1;/*1dönme sebebi radiusun hatalı olduğunu yazdırmak içindir*/
    }
}

int find_big(int num1,int num2)
{
    if(num1>num2)
        return num1;/*dörgen eşitsizliğinde büyük olan mutlak değeri buluyoruz*/
    else
        return num2;
}

int find_small(int num1,int num2)
{
     if(num1<num2)
        return num1;/*dörgen eşitsizliğinde küçük olan mutlak değeri buluyoruz*/
    else
        return num2;
}
