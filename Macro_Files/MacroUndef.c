#include<stdio.h>
#define MIN 5

int main(){
int i;

i=MIN;
printf("Before undef: %d\n",i);
#undef MIN
#define MIN 8
i=MIN;
printf("After undef and def: %d\n",i);




return 0;
}
