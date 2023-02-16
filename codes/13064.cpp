#include<stdio.h>
#include<string.h>

int main()
{
    int woodcount[10] = {0};
    char comment[15][10000];
    int sentencecount[10] = {0};
    while((getchar()) != EOF)
    {
        //getchar();
        int now = 0;
        scanf("%d", &now);
        getchar();
        getchar();
        getchar();
        gets(comment[now]);
        int nowlen = 0;
        nowlen = strlen(comment[now]);
        int flag = 0;
        //printf("%s\n", comment[now]);
        for(int i = 0; i < nowlen-3; i++)
        {
           if(comment[now][i] == 'w' && flag == 0)
            {
                if(comment[now][i+1] == 'o' || comment[now][i+1] == '0')
                {
                    if(comment[now][i+2] == '0' || comment[now][i+2] == 'o')
                    {
                        if(comment[now][i+3] == 'd' || (comment[now][i+3] == 'c' && comment[now][i+4] == 'l'))
                        {
                            woodcount[now] ++;
                            flag = 1;
                        }
                    }
                }
            }

            else if(comment[now][i] == 'v' && flag == 0)
            {
                if(comment[now][i+1] == 'v')
                {
                    if(comment[now][i+2] == 'o' || comment[now][i+2] == '0')
                    {
                        if(comment[now][i+3] == '0' || comment[now][i+3] == 'o')
                        {
                            if(comment[now][i+4] == 'd' || (comment[now][i+4] == 'c' && comment[now][i+5] == 'l'))
                            {
                                woodcount[now] ++;
                                flag = 1;
                            }
                        }
                    }
                }
            }

            if(comment[now][i] == '.')
            {
                sentencecount[now] ++;
                flag = 0;
            }
        }
        sentencecount[now]++;
        //if(woodcount[now] > sentencecount[now]) woodcount[now] = sentencecount[now];

    }
    //woodcount[9]--;
    for(int i = 0; i < 10; i++)
    {
        printf("%d %d\n", woodcount[i], sentencecount[i]);
    }



}

