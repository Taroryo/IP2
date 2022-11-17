#include <stdio.h>
#include <complex>
#include <math.h>
using namespace std;

const double pi = 2.0*asin(1.0);

void square_wave(double x[], int n){
    int count = 1;
    for(int i=0;i<n;i++){
        if(count<=5){
            x[i] = -1;
        } else {
            x[i] = 1;
        }
        if(count>=10){
            count = 1;  // reset
        } else {
            count++;
        }
    }
}

void sin_waves(double x[], int n, double f1, double f2, double f3)
{
    int i;
    for(i=0; i<n; i++) {
        x[i] = (  1.6  * sin(  2*pi*i/n * f1 )
                + 3.2 * cos(  2*pi*i/n * f2 )
                + 6.4 * sin(  2*pi*i/n * f3 ) );
    }
}

int main(void)
{
    FILE *fp1,*fp2;
    char filename1[] = "squarewaves.csv";
    char filename2[] = "sinwaves.csv";
    fp1 = fopen(filename1,"w");
    fp2 = fopen(filename2,"w");

    const int N=100;
    const int M=1000;

    double a[N],b[M];

    square_wave(a,N);
    for(int i=0;i<N;i++){
        fprintf(fp1,"%f\n",a[i]);
    }

    double f1= 10,f2= 20,f3= 30;
    sin_waves(b,M,f1,f2,f3);
    for(int i=0;i<M;i++){
        fprintf(fp2,"%f\n",b[i]);
    }

    fclose( fp1 );
    fclose( fp2 );
}
