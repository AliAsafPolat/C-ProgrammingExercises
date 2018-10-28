#include<stdio.h>
struct student{
char name[20];
char surname[20];
int number;


};

void show (struct student a){
printf("Infos of Student : %s %s %d ",a.name,a.surname,a.number);//We sent struct student1;

}

struct student EnterValue(){
struct student new1;
printf("Enter Infos:");
scanf("%s %s %d",new1.name,new1.surname,&new1.number);
return new1;

}


int main(){
   	struct student student1=EnterValue();
show(student1);


return 0;
}
