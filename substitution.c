#include <stdio.h>
#include <string.h>
#include <ctype.h>

int alpha(char key[27])
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
}

int once(char key[27])
{
     char b[] = "abcdefghijklmnopqrstuvwxyz";
    int yes = 0;
    for (int i = 0; i < strlen(b); i++)
    {
        for (int k = 0; k < strlen(key); k++)
        {
            if (b[i] == tolower(key[k]))
            {
                yes += 1;
                break;
            }
        }
    }
    if (yes != 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void encrypt(char key[], char message[])
{
    char b[] = "abcdefghijklmnopqrstuvwxyz";
    char code[strlen(message)];
    printf("ciphertext: ");
    for (int i = 0; i < strlen(message); i++)
    {
        if (ispunct(message[i]) || isblank(message[i]))
        {
            printf("%c", message[i]);
        }
        else
        {
            for (int j = 0; j < strlen(b); j++)
            {
                if (islower(message[i]))
                {
                    if (b[j] == message[i])
                    {
                        printf("%c", tolower(key[j]));
                    }
                }

                else if (isupper(message[i]))
                {
                    if (toupper(b[j]) == message[i])
                    {
                        printf("%c", toupper(key[j]));
                    }
                }
            }
        }
    }
}
int main(int argc , char *argv[])
{

    int a = 0,b;
    char key[27], message[200];

    if (argc!=2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    strcpy(key,argv[1]);

    a = alpha(key);
    b = once(key);

    if (strlen(key) != 26)
    {
        printf("Error!! The key is not valid ! Enter 26 characters . \n");
        return 1;
    }
    else if (a == 1)
    {
        printf("Error!! The key is not valid ! Enter alphabets only .\n");
        return 1;
    }
    else if (b == 1)
    {
        printf("Error!! The key is not valid ! Enter each alphabet exactly once .\n");
        return 1;
    }
    printf("plaintext: ");
    fgets(message,sizeof(message),stdin);

    encrypt(key, message);
    printf("\n");
    return 0;
}
