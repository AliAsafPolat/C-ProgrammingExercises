#include<stdio.h>
#include<string.h>

struct student{
char name[20];
char surname[20];
int number;

};

void show(struct student *p){ //Reference is taken.
printf("Informations of Student: \nName: %s \nSurname: %s \nNumber : %d\n",p->name,p->surname,p->number);



}


int main(){
struct student student1={"Asaf","Polat",1717};
show (&student1); //We send with refence for  pointer.

}
