#include<stdio.h>
int main()
{
    char mapping[15];
    for(int i = 0; i < 9; i++)
    {
        char a;
        scanf("%c", &mapping[i]);
        //printf("%c ", mapping[i]);
    }
    getchar();
    char want[10];
    for(int i = 0; i < 4; i++)
    {
       scanf("%c", &want[i]);
    }
    getchar();
    //printf("%s\n", want);
    for(int i = 0; i < 4; i++)
    {
        if(want[i] < 'a')
        {
            //printf("hi:%c%d\n", want[i], want[i]-'0');
            int rem = (want[i]-'0');
            printf("%c", mapping[rem-1]);
        }
        else
        {
            int rem;
            for(int j = 0; j < 9; j++)
            {
                if(want[i] == mapping[j]) rem = j;
            }
            printf("%d", rem+1);
        }
    }

}
