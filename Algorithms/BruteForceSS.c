#include<stdio.h>
#include<stdio.h>
#define BOYUT 20
//**Brute Force Search Algorithm**
typedef enum{false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	for(i=0;i<=textlen-patlen;i++){			//Textin bakaca��m son k�sm� patternin uzunlu�unu kadar gerisi olacakt�r.
		j=0;
		while(j<patlen&&pat[j]==text[i+j]){	//Burada j ve patlen aras�nda e�itlik durumu olmamal� ��nk� d�ng� i�erisinde art�r�m oluyor.
			j++;							//Ayn� geldik�e j yi art�r�yorum.
		}
		if(j==patlen)						//E�er uzunluklar ayn�ysa bulmu�um demektir.
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
