#include<stdio.h>
#include<stdlib.h>

int main() {

	char scale = 'C';

	printf("Elige temperatura (C|F|K)):");
	
	scanf("%c",&scale);
	
	
	if (scale != 'F' && scale !='C' && scale !='K') {
		scale = 'C';
	}
	
	printf("The temperature IS! %c\n",scale);

	int start = 0;	
	int end;

	printf("Elige valor inicial (0-100)):");
	
	scanf("%d",&start);


	if (start < 0) {
		start = 0;
	}

	if (start > 100) {
		start = 100;
	}

	printf("Elige valor final (%d-100)):",start);

	scanf("%d",&end);

	if (end < start) {
		end = start + 1;
	}

	printf("The awesome values are! %d - %d\n",start,end);


	if (scale == 'K') {

		int tc = 0;
		int tf = 0;

		while(start <= end) {
			
			tc = start + 273;
			
			tf = (start - 273.15)* 1.8000 + 32.0;
			
			printf("The awesome temps are K: %d -> C: %d F: %d\n",start,tc,tf);			
			
			start += 5;
		}
	} else if (scale == 'F') {
		
		int tk = 0;
		int tc = 0;
		
		while(start <= end) {
			
			tk = (((start - 32) * 5)/9) + 273;
			
			tc = (((start - 32) * 5)/9);
			
			printf("The awesome temps are F: %d -> K: %d C: %d\n",start,tk,tc);			
			
			start += 5;
		}		
	} else if (scale == 'C') {
		
		int tf = 0;
		int tk = 0;
		
		while(start <= end) {
			
			tk = start - 273;
			
			tf = ((start * 9)/5) + 32;
			
			printf("The awesome temps are C: %d -> K: %d F: %d\n",start,tk,tf);			
			
			start += 5;
		}		
	}
	
	return 0;
}




