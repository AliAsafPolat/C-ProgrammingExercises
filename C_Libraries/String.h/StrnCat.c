#include<stdio.h>
#include<string.h>

int main(){

	char dest[50];
	char src[50];

	strcpy(src,"Asaf Reis");
	strcpy(dest,"How are you?");

	printf("This is destination: %s \nThis is source:%s \n",dest,src);

	strncat(dest,src,5);
	printf("Current dest: %s",dest);
	
	//strncat(dest,)





return 0;
}
