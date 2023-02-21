#include<stdio.h>

int main()
{
    int num, times;
    scanf("%d%d", &num, &times);
    char str[200010];
    char change[27] = {0};
    scanf("%s", str);
    for(int i = 0; i < 26; i++)
    {
        change[i] = 'a' + i;
    }
    for(int i = 0; i < times; i++)
    {
        char a, b;
        getchar();
        scanf("%c %c", &a, &b);
        for(int j = 0; j < 26; j++)
        {
            if(change[j] == a)
            {
                change[j] = b;
            }
            else if(change[j] == b)
            {
                change[j] = a;
            }
        }


        //printf("%c %c\n", change[a-'a'], b);
        //printf("%c %c\n", change[b-'a'], a);
    }
    //printf("%s\n", change);
    for(int i = 0; i < num; i++)
    {
        str[i] = change[str[i]-'a'];
            //else if(str[j] == b) str[j] = a;
        //printf("%s\n", str);
    }
    for(int i = 0; i < num; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");


}

