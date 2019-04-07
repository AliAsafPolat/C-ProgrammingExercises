#include<stdio.h>
#include<string.h>
#define BOYUT 20
//**Brute Force 2** 

typedef enum {false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	
	for(i=0,j=0;i<textlen&&j<patlen;i++){				//Uzunluklardan küçük oldukları müddetçe devam et.
		
		if(pat[j]==text[i])					//Eşitse j yi artır ve kontrol etmeye devam et.
		j++;
		else{
		i=i-j;							//Eğer eşitlik durumu bozulduysa i yi bulunan j miktarları kadar azalt ve j yi sıfırla
		j=0;							//mesela asafali içinden ali arıyoruz ilk a lar eşleşti j=1 olcak ama s ile l eşleşmedi i=1-1 =0 olcak 
		}							//fakat for döngüsü satırına dönünce i  artırılcak ve i= değerini almış olcak ver safali içinden aramaya devam
	}								//edeceğiz.
	if(j==patlen)							//Eğer j pattern uzunluğuna eşitse bulmuşum demektir.
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
