#include <iostream>
#include <complex>
#include <math.h>
#include <stdio.h>
using namespace std;

const double pi = 2.0*asin(1.0);

// square_waves function
void sqw(double x[], int n){
    int count = 1;
    for(int i=0;i<n;i++){
        if(count<=5){
            x[i] = -1;
        } else {
            x[i] = 1;
        }
        if(count>=10){
            count = 1;
        } else {
            count++;
        }
    }
}

// sin_waves function
void siw(double x[], int n, double f1, double f2, double f3)
{
    int i;
    for(i=0; i<n; i++) {
        x[i] = (  1  * sin(  5*pi*i/n * f1 )
                + 2 * cos(  5*pi*i/n * f2 )
                + 3 * sin(  5*pi*i/n * f3 ) );
    }
}

void fourier(complex<double> answer[],double f,double d[])
{
    // number of divisions of the discrete Fourier transform
    const int N = 100;
    answer[0] = 0;
    complex<double> index;
    for (int t = 0; t < N; t++)
    {
        // substitution of real and imaginary parts
        index = complex<double>( 0 , -2*pi*f*t/N );
        answer[0] += d[t]*exp(index);
    }
}

int main(void)
{
    const int N=100;
    double a[100],b[1000];

    sqw(a,N);
    // Set frequency
    double f1,f2,f3;
    f1 = 10;
    f2 = 20;
    f3 = 30;
    siw(b,N,f1,f2,f3);

    complex<double> ans1[1], ans2[1];
    printf("Fourier transform of square_waves function\n");
    for(int i=0;i<100;i++){
        fourier(ans1,i,a);
        if(ans1[0].imag()>=0){
            printf("f=%d : F = %.5f + %.4f i\n",i,ans1[0].real(),ans1[0].imag());
        }else{
            double minus_imag = -1*ans1[0].imag();
            printf("f=%d : F = %.5f - %.4f i\n",i,ans1[0].real(), minus_imag );
        }
    }
    printf("Fourier transform of sin_waves function\n");
    for(int i=0;i<100;i++){
        fourier(ans2,i,b);
        if(ans2[0].imag()>=0){
            printf("f=%d : F = %.5f + %.4f i\n",i,ans2[0].real(),ans2[0].imag());
        }else{
            double minus_imag = -1*ans2[0].imag();
            printf("f=%d : F = %.5f - %.4f i\n",i,ans2[0].real(), minus_imag );
        }
    }
}
