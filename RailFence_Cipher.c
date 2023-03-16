//RailFence Cipher.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i, j, len, key, count, code[100][400];
    char str[400];

    printf("Enter plain text: \n");
    gets(str);  // For multi-word strings.

    len = strlen(str);  //Getting the length of the string.

    printf("Enter key: \n");
    scanf("%d",&key);

    // Filling the array 'code' with zeroes.
    for(i=0; i<key; i++)
    {
        for(j=0; j<len; j++)
        {
            code[i][j] = 0;
        }
    }

    count=0;
    j=0;

    // Encrypting
    while(j < len)
    {
        //Making sure that the below two loops don't execute concurrently, at the same time.
        if(count % 2 == 0)
        {
            // Moving downwards in the array.
            for(i=0; i<key; i++)
            {
                code[i][j] = (int)str[j];
                j++;
            }
        }

        else
        {
            // Moving upwards in the array.
            for(i=key-2; i>0; i--)
            {
                code[i][j] = (int)str[j];
                j++;
            }
        }
       count++;
    }

    // Printing the pattern of the text.
    for(i=0; i<key; i++)
    {
        for(j=0; j<len; j++)
        {
            printf("%c", code[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Printing the encrypted text.
    printf("The encrypted text is: \n ");
    for(i=0; i<key; i++)
    {
        for(j=0; j<len; j++)
        {
            if(code[i][j] != 0)
            printf("%c", code[i][j]);
        }
    }
    printf("\n");

    //Decrypting.
    while(j < len)
    {
        //Making sure that the below two loops don't execute concurrently, at the same time.
        if(count %2 == 0)
        {
            //Moving downwards in the array.
            for(i=0; i<key; i++)
            {
                str[j] = code[i][j];
                j++;
            }
        }

        // Moving upwards in the array.
        else
        {
            for(i=key-2; i>0; i--)
            {
                str[j] = code[i][j];
                j++;
            }
        }
       count++;
    }

    //Printing the decrypted text.
    printf("The decrypted text is: \n ");

    for(j=0; j<len; j++)
    {
        printf("%c", str[j]);
    }

    printf("\n");

    return 0;
    //END.
}

