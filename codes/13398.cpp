#include<stdio.h>
char all[100][10];
int count = 0;
void sort(char word[], char listed[])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5-i; j++)
        {
            if(listed[word[j]-'a'] > listed[word[j+1]-'a'])
            {
                int temp = word[j];
                word[j] = word[j+1];
                word[j+1] = temp;
            }
        }
    }
    //printf("%s ", word);
    for(int i = 0; i < 6; i++)
    {
        all[count][i] = word[i];
    }
    count ++;
    //printf("%s ", all[count-1]);
}

void sort2(int num)
{
    for(int q = 0; q < num-1; q++)
    {
        for(int j = 0; j < num-1-q; j++)
        {
            for(int i = 0; i < 6; i++)
            {
                if(all[j][i] > all[j+1][i])
                {
                    for(int k = 0; k < 6; k++)
                    {
                        int tmp = all[j][k];
                        all[j][k] = all[j+1][k];
                        all[j+1][k] = tmp;
                    }
                }
                if(all[j][i] < all[j+1][i]) break;
            }
        }
    }

}

int main()
{
    int num;
    char list[30];
    char listed[30];
    char word[30];
    scanf("%d", &num);
    scanf("%s", list);
    for(int i = 0; i < 26; i++)
    {
        listed[list[i]-'a'] = i;
    }
    for(int i = 0; i < num; i++)
    {
        scanf("%s", word);
        sort(word, listed);
    }
    sort2(num);
    for(int i = 0; i < num-1; i++)
    {
        printf("%s ", all[i]);
    }
    printf("%s\n", all[num-1]);

}
/*2
cbadefghijklmnopqrstuvwxyz
abcabc ababab
*/
