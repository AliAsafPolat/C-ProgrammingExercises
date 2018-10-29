#include<stdio.h>
//#include<conio.h>
int main(){
	
	char deneme='B';
	int sayi=5;
	char karakter='A';
	float ondalik=5.4;
	
	int *p_sayi;
	char *p_karakter,*p_karakter2;
	float *p_ondalik;
	p_karakter2=&deneme;
	 p_sayi=&sayi;
	 p_karakter=&karakter;
	 p_ondalik=&ondalik;
	

	printf("%c nin adresi :%p\n",deneme,p_karakter2);
	printf("%d nin adresi :%p\n",sayi,p_sayi);
	printf("%c nin adresi :%p\n",karakter,p_karakter);
	printf("%.1f nin adresi :%p\n",ondalik,p_ondalik);
	
	p_sayi+=10;
	printf("%p\n",p_sayi);
	
	return 0;
}
