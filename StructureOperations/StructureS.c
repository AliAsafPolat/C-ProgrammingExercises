#include<stdio.h>
#include<string.h>
struct Adress{
char suburb[20];
char street[20];
char avenue[15];

};

struct student{
char name[15];
char surname[20];
int number;
int age;
struct Adress adress;

};
int main(){
struct student student1;

strcpy(student1.name,"Asaf"); //ı cant use student1.name="Asaf" because it is char array so ı can use strcopy func.
strcpy(student1.surname,"Polat");
student1.number=132;
student1.age=24;
strcpy(student1.adress.suburb,"HomeWithGarden.");
strcpy(student1.adress.street,"7.th Street");
strcpy(student1.adress.avenue,"1023.th avenue");


printf("%s %s %d %d %s  %s  %s",student1.name,student1.surname,student1.number,student1.age,student1.adress.suburb,student1.adress.street,student1.adress.avenue);

return 0;
}
