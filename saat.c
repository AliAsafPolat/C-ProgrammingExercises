
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//delay func

int main(){

int i,z,k,l,saniye,saat,dakika;

printf("Saati belirleyiniz:\n");

printf("Saniye degiskenini giriniz:"); scanf("%d",&saniye);

printf("Saat degiskenini giriniz:"); scanf("%d",&saat);

printf("Dakika degiskenini giriniz:"); scanf("%d",&dakika);
z=0;
while (z=1){

printf ("%02d : %02d : %02d \n",saat,dakika,saniye);

saniye+=1;
if ( saniye == 60){
dakika += 1;
saniye = 0;
}
if ( dakika== 60){

dakika=0;
saniye=0;
saat+=1;
}
if (saat==24){
saat=0;
dakika=0;
saniye=0;

}

sleep(1);//delay(1000);

}


return 0;


}
