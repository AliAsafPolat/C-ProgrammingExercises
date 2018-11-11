#include <stdio.h>
#include <string.h>

int main () {
	   char src[40];
	      char dest[100];
	        
	         memset(dest, '\0', sizeof(dest));
		    strcpy(src, "Asaf was here.This is his Repo.");
		       strcpy(dest, src);

		          printf("Final string : %s\n", dest);
			     
			     return(0);
}
