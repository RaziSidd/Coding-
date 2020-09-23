// CSC A48 - Exercise 10 - Breaking Caesar Cipher+
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// Updated by F. Estrada, March 2020.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>		// Yes, you can use functions from the string library!

#define MAX_STR_LEN 2048

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the specified password (please see the exercise
 // description to see how that works).
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'.
 //
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, using different passwords,
 //     and verify it works in
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
 //
 // You should re-use your solution from Ex9, if you did not complete Ex9, here's
 // your chance to complete it.
 
	int length = strlen(plaintext);
	int length_password = strlen(password);
	int y = 0;
	//printf("pass is : %s \n",password);
	for (int x = 0; x < length; x++){
		
		if (y > length_password){
			y = 0;
		}
	 
		plaintext[x] = plaintext[x] + password[y];
		y++;
	}
 
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the password used to encrypt it.
 //
 // The function has the same constraints as 'caesar_cipher()', that is, it
 // must respect the 'end-of-string' delimiter, and ensure no other
 // character becomes 'end-of-string' after decoding.
 //
 // Be smart about how you implement this function!
 //
 // Re-use your solution for Ex9, or complete this function if you did not
 // do so last week.
 //
 
	int length = strlen(cryptotext);
	int length_password = strlen(password);
	//printf("pass is : %s \n",password);
	int y = 0;

	for (int x = 0; x < length; x++){
		if (y > length_password){
			y = 0;
		}
	 
		cryptotext[x] = cryptotext[x] - password[y];
		y++;
	}
    
}

void caesar_breaker(unsigned char crypto_message[MAX_STR_LEN], unsigned char password[MAX_STR_LEN], unsigned char dictionary[10][MAX_STR_LEN])
{
 // This function takes as input
 // - One line of text encrypted using Caesar Cipher+
 // - An array to hold the password that cracks the cipher
 // - A dictionary to be used for a dictionary-attack (here it only has 10 entries, each is a string)
 //
 // The function determines which is the word in the dictionary that cracks the cipher, and returns it
 // by updating the 'password' string with the correct password.
 //
 // TO DO: Complete this function
 //
 // Constraints: You can assume the input message contains only valid text characters (letters, numbers,
 //              and punctuation signs)
 //              The message is somehow related to A48, it was written by Paco
 //              That's it, you should think about how to use this information to solve your task.
 //              there are many ways to approach this problem, some better than others. Think carefully!
	
	
	char A48_Keys[26][MAX_STR_LEN] = {"Hello","All","A48","people","reminder","on-line","lecture","recursion", 
	"please","read","notes","before","watch","lecture","forget","complete","BST","assignment",  
	"hope","learned","lots","complexity","sorting","Paco","Harrington","related"};
	char crypto_message_copy[MAX_STR_LEN] = "";
	strcpy(crypto_message_copy, crypto_message);
	int breaker = 0;
	for(int c = 0; c < 10 ; c++){
		strcpy(crypto_message,crypto_message_copy);
		if (breaker == 1){
			break;
		}
		
		caesar_decipher(crypto_message, dictionary[c]);
		for(int x = 0; x < 26; x++){
			if (strstr(crypto_message, A48_Keys[x]) != NULL){
				//printf("the pass is : %s \n", dictionary[c]);
				strcpy(password,dictionary[c]);
				//printf("the pass is new : %s \n", password);
				//printf("the crypto_message is %s \n", crypto_message);
				strcpy(crypto_message,crypto_message_copy);
				//printf("the crypto_message is now %s \n", crypto_message);
				breaker = 1;
				return;
			}
				
		}

	}
    
}

#ifndef __testing

int main()
{

    unsigned char a_passage[5][MAX_STR_LEN]={"Hello All A48 people! this is a reminder that the on-line lecture\n",
                                    "will be on recursion, please make sure you've read the notes,\n",
                                    "before you watch the lecture!\n",
                                    "Also, don't forget to complete your BST assignment. We hope you've\n",
                                    "learned lots about complexity and sorting!\n"};

    unsigned char dictionary[10][MAX_STR_LEN]={"Zucchini",
				      "Carrot",
                      "Radish",
				      "Broccoli",
				      "Eggplant",
				      "Cilantro",
				      "Sweet Potato",
				      "Tomatoes",
				      "Garlic",
				      "Arugula"};

    unsigned char password[MAX_STR_LEN];

    printf("**** Original input text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Encode the input test lines
	
    caesar_cipher(a_passage[0],dictionary[0]);
    caesar_cipher(a_passage[1],dictionary[3]);
    caesar_cipher(a_passage[2],dictionary[5]);
    caesar_cipher(a_passage[3],dictionary[8]);
    caesar_cipher(a_passage[4],dictionary[9]);
	
    // VERY IMPORTANTLY
    // It should be clear to you, we will test your code with a DIFFERENT message,
    // encoded using DIFFERENT entries in the dictionary, and also a DIFFERENT
    // dictionary! so be sure to test very well!
    
    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Crack the passwords for each text line, and use them to decrypt the text
    printf("\n\n***** Decoding message! *****\n\n");
    for (int i=0; i<5; i++)
    {
        memset(&password[0],0,MAX_STR_LEN*sizeof(unsigned char));   // Clear out password
        caesar_breaker(a_passage[i],password,dictionary);           // Try to get the password for this message
	caesar_decipher(a_passage[i],password);                     // Use the password to decrypt
	// You should check here that your code retrieved the correct password!
	printf("Password=%s, decoded message=%s",password,a_passage[i]);
    }

    return 0;
}

#endif
