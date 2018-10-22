#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int x1,x2,b,i,v1,v2;
	x1=0;
	x2=4;
	v1=3;
	v2=2;

char* a ;
    if (((x1>x2) && (v1>v2)) || ((x1<x2) && (v1<v2))){
       b=2;
	   a=(char*)malloc(2*sizeof(char));
        a[0]='N';   
        a[1]='O';}
  
    
    else if (abs(x1-x2)%abs(v1-v2)==0){
       b=3;
	    a=(char*)malloc(3*sizeof(char));
        a[0]='Y';   
        a[1]='E';
        a[2]='S';
 
        
    }
        
    else 
        {
       b=2;
	    a=(char*)malloc(2*sizeof(char));
        a[0]='N';   
        a[1]='O';
    }
    
    for(i=0;i<b;i++)
    printf("%c",a[i]);
    
    return 0;
}
