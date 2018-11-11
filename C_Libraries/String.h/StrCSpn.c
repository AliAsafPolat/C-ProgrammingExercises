#include<stdio.h>
#include<string.h>

int main(){
	char str[]="Asaf is not the best.";
	char str1[]="i";
	int len;

	len = strcspn(str,str1);

	printf("First matched char is at %d \n",len+1);

//compare two string and return first matched char.in str1



return 0;

}
