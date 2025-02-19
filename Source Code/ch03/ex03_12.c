#include <stdio.h>

int main()
 {
	int y; 
	int x = 1;
	int total = 0; 
	while ( x <= 10 ) {
		y = x * x * x; 
		printf("%d\n", y); 
		total += y; 
		++x; 
	} // end while
	
	printf("The total is %d \n", total); 
} // end main
