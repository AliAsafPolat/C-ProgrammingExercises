#include<stdio.h>

typedef struct{
char name[20];
int number;

}Student;

int main(){

int i,j;

Student *p;
Student student2_3[2];


for (i=0;i<2;i++){
printf("%d th student's id:",i+1);
scanf("%s %d",student2_3[i].name,&student2_3[i].number);
}

p=&student2_3[0];

for (i=0;i<2;i++){
printf("Name: %s  \nNumber:%d\n",(p+i)->name,(p+i)->number);


}


return 0;
}
