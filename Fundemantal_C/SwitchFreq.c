#include<stdio.h>

int main(){
	int i,n,j;
	int ch;
	int count_0=0,count_1=0,count_2=0,count_3=0,count_4=0,count_5=0,count_6=0,count_7=0,count_8=0,count_9=0;
	

	printf("Enter 'a' to exit\n");
	while ((ch=getchar())!='a'){
	
	
		
		switch(ch){
		
			case 0:
				count_0+=1;
				break;
			
			case '1':
				count_1+=1;
				break;
			
			case '2':
				count_2+=1;
				break;
			
			case '3':
				count_3+=1;
				break;
				
			case '4':
				count_4+=1;
				break;
				
			case '5':
				count_5+=1;
				break;
				
			case '6':
				count_6+=1;
				break;
			
			case '7':
				count_7+=1;
				break;
				
			case '8':
				count_8+=1;
				break;
			
			case '9':
				count_9+=1;
				break;	
									
		
		
		
			}
			
		}
		j=0;
		printf("0");
		while(j<count_0&&count_0!=0){
		
		printf("*");
		j++;}
		
		
		printf("\n");
		j=0;
		
		
		printf("1");
		while(j<count_1&&count_1!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("2");
		while(j<count_2&&count_2!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("3");
		while(j<count_3&&count_3!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("4");
		while(j<count_4&&count_4!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("5");
		while(j<count_5&&count_5!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("6");
		while(j<count_6&&count_6!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("7");
		while(j<count_7&&count_7!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("8");
		while(j<count_8&&count_8!=0){
		printf("*");
		j++;}
		printf("\n");
		j=0;
		
		printf("9");
		while(j<count_9&&count_9!=0){		
		printf("*");
		j++;}
			
	
	
	
	
	
	
	return 0;
}
