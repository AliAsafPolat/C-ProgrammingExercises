#include<stdio.h>
#include<string.h>

typedef struct student {
char name[20];
char surname[20];
int age;


}StudentInput[5];

int main(){
int i,n,adult=0;


printf("How many students been ?  ");scanf("%d",&n);
struct student students[n];

for (i=0;i<n;i++){
printf("Enter Students' informations :\n");
scanf("%s %s %d",students[i].name,students[i].surname,&students[i].age);
}

for (i=0;i<n;i++){
if (students[i].age>20)
adult+=1;
}

printf("Adults count: %d",adult);

return 0;

}

