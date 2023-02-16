#include <stdio.h>
#include<string.h>
#define MAX_SIZE 1005
char content[MAX_SIZE];
char input[MAX_SIZE];
char command[MAX_SIZE];

int main()
{
    gets(input);
    gets(command);

    /* your code here */
    int command_len = 0, input_len = 0, cursor = 0;
    command_len = strlen(command);
    input_len = strlen(input);
    //printf("%d %d\n", command_len, input_len);
    //correct!

    for(int i = 0; i < (command_len/2); i++)
    {
        //getchar();
        if(command[2*i+1] == 'b')
        {
            if(cursor > 0)
            {
                //printf("%d\n", cursor);
                input[cursor-1] = '\0';
                for(int j = cursor; j < (input_len); j++)
                {
                    input[j-1] = input[j];
                }
                input[input_len-1] = '\0';
                cursor--;
            }

        }
        else if(command[2*i+1] == 'r')
        {
            if(cursor < (input_len-1))
            {
                cursor++;
            }
        }
    }

        int newinputlen = 0;
                newinputlen = strlen(input);
                for(int i = 0; i < newinputlen; i++)
                {
                    content[i] = input[i];
                }

                printf("%s", content);

    return 0;

}






//The quick brown fox jumps over the lazy dog
//b/r/r/r/b
