#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char ori[4] = "OuQ";
char todo(long long int n, long long int k, long long int len[])
{
	if(n == 0) return ori[k];
    else if(k == 0) return 'O';
    else if(k == len[n]-1) return 'Q';
    else if(k == (len[n-1]+1)) return 'u';
    else
    {
        if(k <= (len[n-1])) return todo(n-1, k-1, len);
        else return todo(n-1, k - len[n-1]-2, len);
    }
}

int main()
{
    long long int k, l, r;
    while(scanf("%lld%lld%lld", &k, &l, &r) != EOF)
    {
        //printf("%lld %lld %lld\n", k, l, r);
        long long int len[10000];
        len[0] = 3;
        for(int i = 1; i <= k; i++)
        {
            len[i] = len[i-1] * 2 + 3;
        }
/*
        for(int i = 0; i <= k; i++)
        {
            printf("%lld ", len[i]);
        }
        */
        for(int i = l; i <= r; i++)
        {
            char ans;
            ans = todo(k-1, i, len);
            printf("%c", ans);
        }
        printf("\n");

    }
}


