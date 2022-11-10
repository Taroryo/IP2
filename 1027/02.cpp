#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_graph(const double x[], const double y[], const int N, const double a, const double b)
//
//  gnuplot を呼び出して，散布図(x,y) および 直線 y=ax+b を描画する関数
//
{
    // 【注意】このプログラムを動かすには https://sourceforge.net/projects/gnuplot/ 等からgnuplotをインストールする必要がある
    //  gnuplot の実行ファイルのフルパス．教室PCの場合は次の通り
    const char gp_cmd[] = "\"C:/Program Files/gnuplot/bin/gnuplot\" -persist";

    FILE *fp;
    fp = _popen(gp_cmd, "w");
    if(fp == NULL) {
        printf("popen() error");
        exit(1);
    }

    fprintf(fp, "set title 'Spring rate measurement and least square fitting'\n");
    fprintf(fp, "set xrange [0 : 10.0]\n");
    fprintf(fp, "set yrange [0 : 20.0]\n");
    fprintf(fp, "set xlabel '{/Arial:Italic x}[mm]'\n");
    fprintf(fp, "set ylabel '{/Arial:Italic y}[N]'\n");

    // フォントの変更
    fprintf(fp, "set title font 'Arial, 16'\n");
    fprintf(fp, "set xlabel font 'Arial,16'\n"); 
    fprintf(fp, "set ylabel font 'Arial,16'\n"); 
    fprintf(fp, "set key font 'Arial, 14'\n");
    fprintf(fp, "set tics font 'Arial, 12'\n");

    char buf[200];
    sprintf(buf, "plot (%lf*x+%lf) linecolor black title 'least square'", a, b);
    strcat(buf, ", '-' with points pt 7 linecolor black title 'measured data'\n");
    fprintf(fp, buf);

    int i;
    for(int i=0; i<N; i++) {
        fprintf(fp,"%f\t%f\n", x[i], y[i]);    // データの書き込み
    }  

    fprintf(fp, "e\n");

    fflush(fp);
    _pclose(fp);
}

double sum(double a[], int N)
{
    double sum = 0;
	for(int i=0;i<N;i++){
        sum += a[i];
    }
    return sum;
}

double inner_product(double a[],double b[],int N)
{
	double ip = 0;
    for(int i=0;i<N;i++){
        ip += a[i] * b[i];
    }
    return ip;
}

int main(void)
{ 
    const int N = 10;
    double x[N]={0, 1, 2, 3, 4, 5,  6,  7,  8, 9};	// 数値はランダム
    double y[N]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    
    double a = 1;
    double b = 1;

    double x_square[N];
    for(int i=0;i<N;i++){
        xsquare[i] = x[i]*x[i];
    }

    double xandy = sum(x,N)*sum(y,N);
    double bunbo = sum(x,N)*sum(x,N)-N*sum(xsquare,N);

    a = (xandy - N*inner_product(x,y,N))/bunbo;
    b = (inner_product(x,y,N)*sum(x,N)-sum(xsquare,N)*sum(y,N))/bunbo;

    draw_graph(x, y, N, a, b);

    return 0;
}
