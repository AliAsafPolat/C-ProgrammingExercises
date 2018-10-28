#include<stdio.h>
int square(short int num){
int answer;
answer=num*num;
return answer;

}


int main(){
short int sayi;
int karesi;


printf("Deger giriniz:\n"); scanf("%hi",&sayi);

karesi=square(sayi);

printf("%d",karesi);

return 0;

}
