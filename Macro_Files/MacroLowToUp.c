#include<stdio.h>
#define To_Lower(e) ((e)+('a'-'A'))

int main(){
char ch;

ch='A';
printf("Before To_Lower:%c\n",ch);

ch=To_Lower(ch);
printf("After To_Lower:%c\n",ch);


return 0;
}
