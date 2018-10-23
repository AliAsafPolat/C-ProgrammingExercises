#include<stdio.h>
#include<stdlib.h>
int square(int a){
a=a*a;
return a;
}
int self(int a){

return a;}

int main(){

int sum=0,i,n,m;
int (*pf)();
printf("Son degeri giriniz:");scanf("%d",&m);


printf("Method seçiniz:  \n");
printf("1-)Kareler Toplamı\n2-)Kendi Toplamları\n");
printf("Seçiminiz:  ");scanf("%d",&n);


if (n==1)
pf=square;
else if (n==2)
pf=self;
else{
printf("Hatalı Seçim Yaptınız Tekrar Seçim Yapınız.");
exit(0);
}


for(i=1;i<=m;i++){
sum=sum+(*pf)(i);
}

printf("Aradiginiz sonuc:  %d\n",sum);


return 0;
}
