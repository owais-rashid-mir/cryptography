/*
Program : C program to implement RailFence Cipher.
Name : Owais Rashid
Enrollment Number : 21045110004
Semester : 2nd (MCA)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i, j, len, key, count, code[100][400];  //Global variables.
char str[400];

//Encryption function.
void encrypt()
{
    //Encrypting
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
    printf("\n");
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
    printf("\nThe encrypted text is: \n ");
    for(i=0; i<key; i++)
    {
        for(j=0; j<len; j++)
        {
            if(code[i][j] != 0)
            printf("%c", code[i][j]);
        }
    }
    printf("\n");
}

//Decryption function.
void decrypt()
{
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
    printf("\nThe decrypted text is: \n ");

    for(j=0; j<len; j++)
    {
        printf("%c", str[j]);
    }

    printf("\n");
}


int main()
{
    printf("Enter plain text: \n");
    gets(str);  // For multi-word strings.

    len = strlen(str);  //Getting the length of the string.

    printf("\nEnter key: \n");
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

    encrypt();  // Calling the encrypt() function.
    decrypt();  // Calling the decrypt() function.

    return 0;
    //END.
}

