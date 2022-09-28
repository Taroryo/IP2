#include <stdio.h>
void input(float num[],int N)
{
    for(int i=0;i<N;i++){
        scanf("%f",&num[i]);
    }
}

float average(float num[],int N)
{
    float gokei=0;
    for(int i=0;i<N;i++){
        gokei += num[i];
    }
    return gokei/N;
}

void max_min(float num[],int N,float* max,float* min)
{
    *max = num[0]; *min = num[0];
    for(int i=0;i<N;i++){
        if(*max < num[i]){
            *max = num[i];
        } else if(*min > num[i]){
            *min = num[i];
        }
    }
}

void output(float num[],int N)
{
    for(int i=0;i<N;i++){
        printf("%f\n",num[i]);
    }
}