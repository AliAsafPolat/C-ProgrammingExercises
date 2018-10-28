#include<stdio.h>
#include<string.h>
union Student{
char name[20];
char surname[15];
int number;

};

int main(){
union Student Student1;

strcpy(Student1.name,"AliAsaf");
strcpy(Student1.surname,"Polat");
Student1.number=1515;


printf("%s\n",Student1.name);//Will Lost
printf("%s\n",Student1.surname);//Will Lost
printf("%d",Student1.number);//Will printed because it is the value that last given 

}
