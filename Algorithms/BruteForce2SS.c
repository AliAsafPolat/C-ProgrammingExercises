#include<stdio.h>
#include<string.h>
#define BOYUT 20
//**Brute Force 2** 

typedef enum {false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	
	for(i=0,j=0;i<textlen&&j<patlen;i++){	//Uzunluklardan küçük olduklarý müddetçe devam et.
		
		if(pat[j]==text[i])					//Eþitse j yi artýr ve kontrol etmeye devam et.
		j++;
		else{
		i=i-j;								//Eðer eþitlik durumu bozulduysa i yi bulunan j miktarlarý kadar azalt ve j yi sýfýrla
		j=0;								//mesela asafali içinden ali arýyoruz ilk a lar eþleþti j=1 olcak ama s ile l eþleþmedi i=1-1 =0 olcak 
		}									//fakat for döngüsü satýrýna dönünce i  artýrýlcak ve i= deðerini almýþ olcak ver safali içinden aramaya devam
	}										//edeceðiz.
	if(j==patlen)							//Eðer j pattern uzunluðuna eþitse bulmuþum demektir.
	return true;
	else
	return false;
	
}

int main() {
char text[BOYUT],pat[BOYUT];
int textlen,patlen;
boolean ret;
printf("Texti giriniz : ");
scanf("%s",text);	
textlen=strlen(text);
printf("Aradiginiz patterni giriniz : ");
scanf("%s",pat);
patlen=strlen(pat);
	
ret=bruteForce(text,textlen,pat,patlen);
if(ret){
	printf("Deger bulundu.\n");
}else
printf("Deger yok\n");
	
return 0;	
}
