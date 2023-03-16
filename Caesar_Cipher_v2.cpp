/*
Program : C++ program to implement Caesar Cipher.
Name : Owais Rashid
Enrollment Number : 21045110004
Semester : 2nd (MCA)
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

char text[100], ch;     //Global variables.
int i, key;

//Encryption function.
void encrypt()
{
    //Encrypting the text.
	for(i=0; text[i]!='\0'; ++i)
	{
		ch = text[i];

		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch + key;
			if(ch >= 123)
			{
				ch = ch - 123 + 97;
			}
            text[i] = ch;
		}

		else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch + key;
			if(ch > 90)
			{
				ch = ch - 90 + 65;
			}
			text[i] = ch;
		}

		else
		{
			cout << "Numbers, characters and spaces are not allowed.\n";
			exit(1);
		}
	}   //End of For() loop.

    cout<< "\nEncrypted text = " << text << endl;
}

//Decryption function.
void decrypt()
{
    //Decrypting the text
	for(i=0; text[i]!='\0'; ++i)
	{
		ch = text[i];
		if(ch >= 'a' && ch <= 'z')
		{
            ch = ch - key;
            if(ch < 97)
            ch = ch + 26;

            text[i] = ch;
		}

        else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch - key;
			if(ch <= 65)
			{
				ch = ch + 25;
			}
			text[i] = ch;
		}
	}   //End of For() loop.
	cout<<"\ndecrypted text = "<<text<<endl;
}

int main()
{
	cout << "Enter plain text: " << endl;
	gets(text);		//For multi-word strings

	cout << "\nEnter key: \n";
	cin >> key;

	encrypt();      // Calling the encrypt() function.
	decrypt();      // Calling the decrypt() function.

	return 0;
	//END
}


