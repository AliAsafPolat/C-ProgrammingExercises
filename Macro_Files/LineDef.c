#include<stdio.h>

int main(){

	printf("Current line is %d \n",__LINE__);

#line 250
	printf("Current line is %d \n",__LINE__);

#line 21

	printf("Current line is %d \n",__LINE__);






return 0;
}
