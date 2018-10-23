#include<stdio.h>

struct student{
char name[20];
char surname[20];
int number;
};

int main(){

struct student students[3];
int i;

for (i=0;i<3;i++){
printf("Enter %d th student's info:(Order: Name,Surname,Number) ",i+1);
scanf("%s %s %d",students[i].name,students[i].surname,&students[i].number);

}
for (i=0;i<3;i++){
printf("Here is %d th student's infos: %s %s %d \n",i,students[i].name,students[i].surname,students[i].number);

}


return 0;
}
