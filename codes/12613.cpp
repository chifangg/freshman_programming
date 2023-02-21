#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        long long int A, B;
        long long int num = 0;
        scanf("%d%d", &A, &B);
        num = A * ((floor)(log10(B+1)));
        printf("%lld\n", num);
    }
}
