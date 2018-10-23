#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
char name [20];
char surname[20];
int number;

};

struct student *InputValue(struct student *p){//if ı use void function(void InputValue(struct student *p)) here it will be same bcz it changes reference.
strcpy(p->name,"Mehmet");
strcpy(p->surname,"Ferkan");//İnformations updating....
p->number=89;

return p;

}

void show (struct student *p){
printf("Informations of students:\nName :%s\nSurname: %s\nNumber:%d",p->name,p->surname,p->number);


}

int main(){
struct student *hold;

struct student student1={"Asaf","Polat",546};//This informations will  change.

hold=InputValue(&student1);

printf("%s %s %d",hold->name,hold->surname,hold->number);

return 0;
}
