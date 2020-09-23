#include<ctype.h>
#include<stdio.h>

int get_length(char input[1024])
{
	int count = 0;
	for(int x = 0; x < 1024; x++){
		if(input[x] != '\0' ){
			count+=1;
		}
		else{
			return count;
		}
	}
		
	
}

int strcpy_mine(char input[1024], char input_2[1024])
{
	 for (int i = 0; input[i] != '\0'; ++i) {
        input_2[i] = input[i];
    }
}

void pidgin(char* input) 
{
	int length = get_length(input);
	char placeholderone = {' '};
	
	for(int x = 0; x < length; x = x + 2){
			placeholderone = input[x]; 
            input[x] = input[x + 1]; 
            input[x + 1] = placeholderone;
	
	}
	printf("%s\n",input);
	
}
void vowel_caser(char* input)
{
	int length = get_length(input);
	
	for(int x = 0; x < length; x++){
		if (islower(input[x])){
			if (input[x] =='a' || input[x] =='e' ||input[x] == 'i' ||input[x] =='o' ||input[x] =='u' ){
				input[x] = toupper(input[x]);
			}
		}else if (isupper(input[x])){
			if (input[x] =='A' || input[x] =='E' ||input[x] == 'I' ||input[x] =='O' ||input[x] =='U' ){
				input[x] = tolower(input[x]);
			}
		}
	
	}
	printf("%s",input);
	
}
int main()
{
	char row[] = "A strIng is jUst a bunch Of chArs sittIng togEthEr in A row!";
	printf("%s\n" , row);
	pidgin(row);
	vowel_caser(row);
	return 0; 
	

}
