#include<stdio.h>
char wordlist[105][10];
int count = 0;

void sort(char word[])
{
    for (int i = 0; i < 5; i ++)
    {
        for (int j = 0; j < 5-i; j ++)
        {
            if (word[j] > word[j+1])
            {
                int tmp = word[j];
                word[j] = word[j+1];
                word[j+1] = tmp;
            }
        }
        //printf("%c", word[i]);
    }
    //printf("%s ", word);
    for(int i = 0; i < 6; i++)
    {
        wordlist[count][i] = word[i];
    }
    count++;
}

void sort2(int num)
{
	int i = 0, k = 0;

	for(int q = 0; q < num-1; q++)
    {
        for(int j = 0; j < num-1-q; j++)
        {
            i = 0;
            k = 0;
            while(i < 6)
            {
                if(wordlist[j][i] > wordlist[j+1][i])
                {
                    while(k < 6)
                    {
                        int temp = wordlist[j][k];                              //aabbcc
                        wordlist[j][k] = wordlist[j+1][k];                      //aaabbb
                        wordlist[j+1][k] = temp;
                        k++;
                    }
                    break;
                }
                if(wordlist[j][i] < wordlist[j+1][i]) break;
                i++;
            }

                //else break;
        }
    }

}



int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        char word[10];
        scanf("%s", word);
        sort(word);

        //printf("%s ", wordlist[i]);

    }
    sort2(num);
    for(int i = 0; i < num-1; i++)
    {
        printf("%s ", wordlist[i]);
    }
    printf("%s\n", wordlist[num-1]);

}
