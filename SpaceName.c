#include <stdio.h>
int main(){
char s[100];
scanf("%[^\n]%*c",s);
printf("%s",s);

return 0;
}
