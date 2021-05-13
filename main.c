#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int  i; //
extern double f1(double x);
extern double f11(double x);
  
extern double f2(double x);
extern double f21(double x);
  
extern double f3(double x);
extern double f31(double x);
  
double integral(double (*f)(double),double a, double b, double esp2)
{
    int n=1,j;
    i=0;
    double s1,s;
    double h, k1 = 0, k2 = 0;

     h = (b-a)/n;
    k1 = 0, k2 = 0;
    for(j = 1; j < n; j += 2) {
    k1 += f(a + j*h);
    k2 += f(a + (j+1)*h);
    }
    s1 = h/3*(f(a) + 4*k1 + 2*k2);
    do {
     s = s1;
     n = 2 * n;

     h = (b-a)/n;
     k1 = 0, k2 = 0;
    for(j = 1; j < n; j += 2)
    {
     k1 += f(a + j*h);
     k2 += f(a + (j+1)*h);
    }

    s1 = h/3*(f(a) + 4*k1 + 2*k2);
    i++;
  }
  while (fabs(s1 - s) > esp2/2);
  return s1;
}

void help(void){
    printf("Исполняемый файл?(назвать) ");
    printf("Доступные ключи: \n");
    printf(" -func: выводит функции\n");
    printf(" -i: число итераций \n");
    printf(" -roots: абсциссы точек пересечения кривых\n");
    printf(" -tests: тестирование программ\n");


}


double  root(double (*f)(double),double (*f1)(double), double (*g)(double), double (*g1)(double), double a, double b, double eps1)
{
    i = 0;
    double x=(b+a)/2,h=1;
    while(fabs(h) > (eps1)/2)
    {
        h=(f(x)-g(x))/(f1(x)-g1(x));
        x=x-h;
        i++;
    }
     return x;
}


double fX1(double x)
{
    return x;
}

double fX11(double x)
{
    return x/x;
}

double fX2(double x)
{
    return -x+5;
}

double fX21(double x)
{
    return -x/x;
}

double fXX(double x)
{
    return 1/x;
}
double fXX1(double x)
{
    return -1/(x*x);
}

void Test(){
    double esp= 1e-5;
printf("Вводимые функции: f1(x) = x; f2(x) = -x+5; f3(x) = 1/x\n");
    double x = root(fX1,fX11,fX2,fX21,2,3,esp);
    printf("Вычисляемая абцисса пересечения функций f1 и f2: %.3lf;   Вычисленная абцисса пересечения функций: %.3lf\n",x,2.5);

    x = root(fXX,fXX1,fX2,fX21,4,5,esp);
    printf("Вычисляемая абцисса пересечения функций f2 и f3: %.3lf;   Вычисленная абцисса пересечения функций: %.3lf\n",x,4.791);

    x = root(fX1,fX11,fXX,fXX1,0.5,2,esp);
    printf("Вычисляемая абцисса пересечения функций f1 и f3: %.3lf;  Вычисленная абцисса пересечения функций: %.5lf\n",x,1.0);


    double a;
    a = integral(fX1,0,1,esp);
    printf("Вычисляемая площадь под графиком функции f1 на интервале [0;1]: %.3lf; Вычисленная площадь под графиком функции f1 на интервале: %.3lf\n",a,0.5);

    a = integral(fX2,1,2,esp);
    printf("Вычисляемая площадь под графиком функции f2 на интервале [1;2]: %.3lf; Вычисленная площадь под графиком функции f2 на интервале: %.3lf\n",a,3.5);

    a = integral(fXX,1,2,esp);
    printf("Вычисляемая площадь под графиком функции f3 на интервале [1;2]: %.3lf; Вычисленная площадь под графиком функции f3 на интервале: %.3lf\n",a,0.693);


}


int main(int a, char **b)
{
    int fr=0, fi=0;
    int c;
    if(a!=0){
        for(c=0; c < a; c++)
        {
            if(strcmp("-i", b[c])==0)
            {
                fi=1 ;
            }
            if(strcmp("-roots", b[c])==0)
            {
                fr=1;
            }
            if(strcmp("-tests", b[c])==0)
            {
                Test();
                return 0;
            }
            if(strcmp ("-help", b[c]) ==0)
            {
                help();
                return 0;
            }
            if(strcmp("-func",b[c])==0)
            {
                printf("f1 =  3 / ((x − 1)^2+ 1)\t f2 = sqrt(x + 0.5) \t f3 =  exp(−x)");
                return 0;
            }
        }
    }
    double root1 = root(f1, f11, f2, f21, 1.5, 2, 1e-5 );
    if(fi){
        printf(" Число итераций f1=f2 : %u\n ",i);

    }
    double root2 = root(f2, f21, f3, f31, 0, 1, 1e-5 );
    if(fi){
        printf(" Число итераций f2=f3 : %u\n ",i);

    }
    double root3 = root(f1, f11, f2, f21, -0.5, 0, 1e-5 );
    if(fi){
        printf(" Число итераций f1=f3 : %u\n ",i);

    }
    double integral1 = integral(f1, root3, root1,1e-5);

    double integral2 = integral(f2, root2, root1,1e-5);

    double integral3 = integral(f3, root3, root2,1e-5);

    if(fr){
        printf(" Площадь фигуры, ограниченной тремя кривыми: %lf\n", integral1-integral2-integral3);
    }

    return 0;
}
