#include<stdio.h>
#include<stdio.h>
#define BOYUT 20
//**Brute Force Search Algorithm**
typedef enum{false,true
}boolean;

boolean bruteForce(char text[],int textlen,char pat[],int patlen){
	int i,j;
	for(i=0;i<=textlen-patlen;i++){			//Textin bakacaðým son kýsmý patternin uzunluðunu kadar gerisi olacaktýr.
		j=0;
		while(j<patlen&&pat[j]==text[i+j]){	//Burada j ve patlen arasýnda eþitlik durumu olmamalý çünkü döngü içerisinde artýrým oluyor.
			j++;							//Ayný geldikçe j yi artýrýyorum.
		}
		if(j==patlen)						//Eðer uzunluklar aynýysa bulmuþum demektir.
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
