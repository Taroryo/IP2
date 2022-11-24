#include <stdio.h>
#include <stdlib.h>
#include <complex>
using namespace std;
const double pi = 2.0*asin(1.0);
void dft(double in[], complex<double> out[], const int N)
{
    const double dt = 1.0 / 44100.0;
    for(int i=0; i<N; i++) {
        out[i] = complex<double>(0.0, 0.0);
    }

    for(int f=0; f<N; f++) {
        for(int t=0; t<N; t++) {
            out[f] += in[t] * exp( complex<double>(0.0, -2.0 * pi * f * t/N) ) * dt;
        }
    }
}

int main(void)
{
    const int N = 20000;
    static double orig_data[N];
    static complex<double> dft_data[N];
    const double sampling_freq = 44100;
    const char fname1[] = "1つ目のデータ", fname2[] = "2つ目のデータ", fname3[] = "3つ目のデータ";
    FILE* filepointer1;
    FILE* filepointer2;
    FILE* filepointer3;
    filepointer1 = fopen(fname1,"r");
    filepointer2 = fopen(fname2,"r");
    filepointer3 = fopen(fname3,"r");

    // 1つ目のデータの計算
    for(int i=0;i<N;i++) {
        fscanf(filepointer1
, "%lf", &orig_data[i]);
    }
    fclose(filepointer1);
    dft(orig_data, dft_data, N);
    FILE* fpo;
    fpo = fopen("outputdata_1.csv","w");
    fprintf(fpo, "Freq(Hz), Power(-)\n");
    for(int i=0; i<=N/2+1; i++) {
        fprintf(fpo, "%lf, %lf \n", i*(sampling_freq/2)/(N/2+1), norm(dft_data[i]));
    }
    fclose(fpo);

    // 2つ目のデータの変換
    for(int i=0;i<N;i++) {
        fscanf(filepointer2, "%lf", &orig_data[i]);
    }
    fclose(filepointer2);
    dft(orig_data, dft_data, N);
    fpo = fopen("outputdata_2.csv","w");
    fprintf(fpo, "Freq(Hz), Power(-)\n");
    for(int i=0; i<=N/2+1; i++) {
        fprintf(fpo, "%lf, %lf \n", i*(sampling_freq/2)/(N/2+1), norm(dft_data[i]));
    }
    fclose(fpo);

    // 3つ目のデータの変換
    for(int i=0;i<N;i++) {
        fscanf(filepointer3, "%lf", &orig_data[i]);
    }
    fclose(filepointer3);
    dft(orig_data, dft_data, N);
    fpo = fopen("outputdata_3.csv","w");
    fprintf(fpo, "Freq(Hz), Power(-)\n");
    for(int i=0; i<=N/2+1; i++) {
        fprintf(fpo, "%lf, %lf \n", i*(sampling_freq/2)/(N/2+1), norm(dft_data[i]));
    }
    fclose(fpo);

    return 0;
}
