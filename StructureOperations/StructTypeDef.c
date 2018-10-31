#include<stdio.h>

typedef struct{
char name[20];
int number;


}Student;

int main(){
int i;
Student student1={"Asaf",1212};			//Student1's info
Student student2_3[2]={{"John",1545},{"Carl",8787}};//Student2 and student3's infos

printf("Name:%s \nNumber:%d\n",student1.name,student1.number);


for (i=0;i<2;i++){
printf("Name:%s \nNumber:%d\n",student2_3[i].name,student2_3[i].number);

}





return 0;
}
