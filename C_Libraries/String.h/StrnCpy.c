#include <stdio.h>
#include <string.h>

int main () {
	   char src[40];
	      char dest[12];
	        
	         memset(dest, '\0', sizeof(dest));
		    strcpy(src, "This is Asaf's Repo");
		       strncpy(dest, src, 10);

		          printf("Final string : %s\n", dest);
			     
			     return(0);
}
