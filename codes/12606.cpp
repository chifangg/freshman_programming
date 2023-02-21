#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int max = -1;
    int min = 1000000000;
    int N;
    scanf("%d", &N);
    //int x0;
    //scanf("%d", &x0);
    //printf("%d\n", x0);
    for(int i = 0; i <= N; i++)
    {
        int num;
        scanf(" %d", &num);
        if(num > max) max = num;
        if(num < min) min = num;
    }
    int result;
    result = (max - min) * 2;
    printf("%d\n", result);
    //printf("%d\n", result+x0);
}
