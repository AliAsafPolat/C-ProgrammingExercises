#include<stdio.h>

typedef union{
char id[20];
char newid[20];
}UnionId;

int main(){
int n;
UnionId id;

printf("Did you sign in before?(If answer is 'YES' please enter 1 else press a key.)");
scanf("%d",&n);

if(!(n-1)){
printf("Enter your id:");
scanf("%s",id.id);
printf("You joined system!  Welcome  %s",id.id);

}
else {
getchar();
printf("Choose an id :");
scanf("%s",id.newid);
printf("You have a new id! : %s ",id.newid);

}





return 0;
}
