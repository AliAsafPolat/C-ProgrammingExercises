#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//**Boyer Moore Algoritmasý **
#define CHARALP 256
#define BOYUT 50
int* buildBadMatchTable(char pat[],int patlen,int alphsize){	//Burasý tabloyu oluþturma kýsmýdýr.
int *alp;						
alp=(int *)malloc(alphsize*sizeof(int));						//Tabloya yer açýldý.
		
int i;
for(i = 0;i<alphsize-1;i++){									//Önce alfabenin bütün elamanlarýna patternin uzunluðu girilmelidir
alp[i]=patlen;													//çünkü alfabeden olmayan bir harf geldiði zaman patternin uzunluðu kadar bir zýplama yapacaktýr.
}

for(i=0;i<patlen-1;i++){
	alp[pat[i]-'a']=patlen-1-i;									//Burada patlen-1-i nin anlamý þudur ki eðer ayný harften iki tane geçiyor ise pattern de
}																//ikinci gelenin i deðeri daha büyük olacaðý için önceden gelen deðerin üzerine yazýlýr.
return alp;														//Oluþturduðum tabloyu geri döndürüyorum.
}

int horspool(char text[],int textlen,char pat[],int patlen,int alphsize){
	int i,j;
	int *table=buildBadMatchTable(pat,patlen,alphsize);			//Fonksiyonumdan tabloyu alýyorum.
	
	i=patlen-1;													//i burada kaydýrma durumunu tutan deðiþken olarak görev alýr.
	while(i<textlen){											//Eðer text in uzunluðuna gelmiþsek artýk durmasý gerekli.
		j=0;													//j burada eþleþme durumlarýný tutmaktadýr.
		while(j<=patlen&&pat[patlen-1-j]==text[i-j])			//Bilindiði üzere bu algoritmada kelime asaf ise önce f harfi karþýlaþtýrýlýr
		j++;													//Eþleþme gözlenirse a harfine geçilir.
		if(j==patlen){											//pat[patlen-1-j]==text[i-j] bu yazýmýn mantýðý da budur önce patternin son harfi kontrol edilir.
		return i-patlen+1;										//Eðer eþleþme var ise patternin geçtiði yeri döndür.
		}else
		i=i+table[text[i]-'a'];									//Eþleþme yoksa text deki i nin tablodaki kaydýrma miktarý kadar kaydýrma saðlanýr.
	}
	return -1;
}

int main(){
char text[BOYUT],pat[BOYUT];
int textlen,patlen;
int ret;
printf("Texti giriniz : ");
scanf("%s",text);	
textlen=strlen(text);
printf("Aradiginiz patterni giriniz : ");
scanf("%s",pat);
patlen=strlen(pat);
	
ret=horspool(text,textlen,pat,patlen,28);
if(ret!=-1){
	printf("Deger text in %d inci indisinde bulundu.\n",ret);
}else
printf("Deger yok\n");
	
return 0;	
}
