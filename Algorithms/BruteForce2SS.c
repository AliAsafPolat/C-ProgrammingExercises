#include<stdio.h>
#include<string.h>
#define BOYUT 20
//**Brute Force 2** 

typedef enum {false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	
	for(i=0,j=0;i<textlen&&j<patlen;i++){	//Uzunluklardan k���k olduklar� m�ddet�e devam et.
		
		if(pat[j]==text[i])					//E�itse j yi art�r ve kontrol etmeye devam et.
		j++;
		else{
		i=i-j;								//E�er e�itlik durumu bozulduysa i yi bulunan j miktarlar� kadar azalt ve j yi s�f�rla
		j=0;								//mesela asafali i�inden ali ar�yoruz ilk a lar e�le�ti j=1 olcak ama s ile l e�le�medi i=1-1 =0 olcak 
		}									//fakat for d�ng�s� sat�r�na d�n�nce i  art�r�lcak ve i= de�erini alm�� olcak ver safali i�inden aramaya devam
	}										//edece�iz.
	if(j==patlen)							//E�er j pattern uzunlu�una e�itse bulmu�um demektir.
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
