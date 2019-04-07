#include<stdio.h>
#include<stdio.h>
#define BOYUT 20
//**Brute Force Search Algorithm**
typedef enum{false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	for(i=0;i<=textlen-patlen;i++){			//Textin bakacağım son kısmı patternin uzunluğunu kadar gerisi olacaktır.
		j=0;
		while(j<patlen&&pat[j]==text[i+j]){	//Burada j ve patlen arasında eşitlik durumu olmamalı çünkü döngü içerisinde artırım oluyor.
			j++;				//Aynı geldikçe j yi artırıyorum.
		}
		if(j==patlen)				//Eğer uzunluklar aynıysa bulmuşum demektir.
		return true;
		
	}
	return false;
}

int main(){
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
