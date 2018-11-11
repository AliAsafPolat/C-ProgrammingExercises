#include<stdio.h>
#include<string.h>

//This destination should be large enough to contain the concenatenated resulting string.
//Add source to end of destination.


int main(){

	char src[50],dest[50];

	strcpy(src," Asaf Reis");
	strcpy(dest,"How are you?");

	strcat(dest,src);

	printf("Final string is : %s ",dest);




return 0;
}
