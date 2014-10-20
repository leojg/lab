#include<stdio.h>
#include<stdlib.h>

void divide(int *a, int *b);

main() {
	
	int a;	
	int b;

	printf("Elige valor a:");
	
	scanf("%d",&a);

	printf("Elige valor b:");
	
	scanf("%d",&b);
	
	while(b!=0) {
		printf("The value of a is: %d\n",a);	
		printf("The value of b is: %d\n",b);	

		divide(&a,&b);

	}

	printf("MCD(a,b) is: %d\n",a);	
		
}

void divide(int *a, int *b) {
	int r = *a % *b;
	
	printf("The value of r is: %d\n",r);	
	
	*a = *b;
	*b = r;
		
}
