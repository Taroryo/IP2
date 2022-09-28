#include <stdio.h>

int main()
{
    FILE *fpio = fopen("50data.txt","r");
    if(!fpio){
        printf("error\n");
        return 1;
    }

    int i,n;
    float gokei=0;
    for(i=0;i<50;i++){
        fscanf(fpio,"%d",&n);
        gokei += n;
        printf("%d\n",n);
    }
    printf("average = %.2f\n",gokei/50);
    fclose(fpio);
    return 0;
}