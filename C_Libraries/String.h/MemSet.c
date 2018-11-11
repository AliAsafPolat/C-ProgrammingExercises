#include<stdio.h>
#include<string.h>

int main(){
char str[50];

strcpy(str,"This is Asaf's Repository.");
puts(str);

memset(str,'U',5);
puts(str);

return 0;

}
