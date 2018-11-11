#include<stdio.h>
#include<string.h>

int main(){

char str1[]="asaf";
char str2[]="ASAF";

	int ret;

	ret=strcoll(str1,str2);

	if (ret<0)
		printf("Str2 is greater .\n");
	else if (ret>0)
		printf("Str1 is greater . \n");
else printf("They are equal. \n");

		//Difference between strcmp is byte operations.I will not explain that exactly but comparision with str,strcmp is faster than strcoll.
		//
		//





return 0;

}
