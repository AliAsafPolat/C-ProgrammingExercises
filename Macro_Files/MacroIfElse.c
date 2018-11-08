#include<stdio.h>
#define x 5

#if x==5
	
	#undef x
	#define x 6
#elif x==8
	#undef x
	#define x 9
#else 
	#undef x
	#define x 1506
#endif

int main()
{

	printf("\n %d \n",x);



	return 0;
}

