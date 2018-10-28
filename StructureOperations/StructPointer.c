#include<stdio.h>
#include<string.h>
struct student {

char name[20];
char surname[20];
int number;
};

int main(){
struct student student1;
struct student *hold;
strcpy(student1.name,"Asaf");
strcpy(student1.surname,"Reis");
student1.number=15;

hold=&student1;

//printf("%s %s %d",student1.name,student1.surname,student1.number);
printf("%s %s %d",hold->name,hold->surname,hold->number);






}
