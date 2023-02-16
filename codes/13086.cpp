#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char find(int n, long long int k, long long int len[], char f0[], char f1[])
{
    if(n == 0) return f0[k];
    if(n == 1) return f1[k];
    if(k >= len[n-2]) return find(n-1, k-len[n-2], len, f0, f1);
    else return find(n-2, k, len, f0, f1);
}


int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char f0[2020], f1[2020];
        long long int len[100];
        long long int n, k;
        scanf("%s%s", f0, f1);
        scanf("%lld%lld", &n, &k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);
        for(int i = 2; i <= n; i++)
        {
            len[i] = len[i-1] + len[i-2];
        }
        char ans;
        ans = find(n, k, len, f0, f1);
        printf("%c\n", ans);
    }
}
