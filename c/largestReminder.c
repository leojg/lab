#include<stdio.h>
#include<stdlib.h>

void order_rests(float *rests, int size);
float get_coeficient(int *votes,int *seats,char *type);
void largestReminder(int *votes, int *seats, int *options, int numberOfOptions);

main() {
	
/*	int options[6] = {2387,2105,1230,1132,2587,559};

	int optionsSize = 6;
	
	int votes = 10000;

	int seats = 13;
*/
	
	int votes;
	
	printf("Ingresa total de votos:");
	
	scanf("%d",&votes);

	int seats;
	
	printf("Ingresa total de bancas:");
	
	scanf("%d",&seats);

	int optionsSize;
	
	printf("Ingresa total de opciones:");
	
	scanf("%d",&optionsSize);
	
	int options[optionsSize];
	
	int i = 0;
	
	for (; i < optionsSize; i++) {
		int optionVotes;

		printf("Ingresa votos de opcion %d:",i);
		
		scanf("%d",&optionVotes);
		
		options[i] = optionVotes;
	}
	
	largestReminder (&votes,&seats,options,optionsSize);
	
}

void largestReminder(int *votes, int *seats, int *options, int numberOfOptions) {
	
	printf("Votos: %d \n",*votes);
	
	printf("Bancs: %d \n",*seats);
	
	printf("Opciones: %d \n",numberOfOptions);

	
	char coeficients[3] = {'H','D','I'};
	
	int x = 0;
	
	while(x < 3) {
		
		printf("\n********-********-********\n");
	
		
		float q = get_coeficient(votes,seats,&coeficients[x]); 
		
		printf("Coeficiente: %f - tipo: %c \n",q,coeficients[x]);
			
		float rests[numberOfOptions];
		
		int i = 0;
		
		int occupedSeats[numberOfOptions];
		
		int freeSeats = *seats;
		
		while (i < numberOfOptions) {
			
			int optionVotes = options[i];
			
			int optionSeats = optionVotes / q;
			
			float optionRest = (float)optionVotes - ((float)optionSeats * q);
	
			rests[i] = optionRest;
			
			occupedSeats[i] = optionSeats;
			
			freeSeats = freeSeats - optionSeats;
			
			i++;		
		}
			
		if (freeSeats > 0) {
			
			i = 0;
	
			float aux_rest[numberOfOptions];
	
			
			while (i < numberOfOptions) {
				aux_rest[i] = rests[i];
				i++;
			}
			
	
			order_rests(rests,numberOfOptions);
			
			i = 0;
			
			while(i < numberOfOptions && freeSeats > 0) {
				
				int j = 0;
				
				while (j < numberOfOptions) {
					if (aux_rest[j] == rests[i]) {
						break;
					}
					j++;
				}
				
				occupedSeats[j] += 1;
				
				freeSeats--;
				i++;
				
			}
			
	
		printf("Bancas Reacomodadas: %d \n",freeSeats);
				
			i = 0;
			
			while(i < numberOfOptions) {
				printf("Bancas de la opcion %d: %d \n",i,occupedSeats[i]);
				i++;
				
			}
					
			
		}
	
		x ++;
	
	}
	
}

float get_coeficient(int *votes,int *seats,char *type) {
	float q = 0.0;
	if (*type == 'H') {
		q = (float)*votes / (float)*seats;
	} else if (*type == 'D') {
		q = 1 + ((float)*votes / ((float)*seats + 1));
	} else if (*type == 'I') {
		q = (float)*votes / ((float)*seats + 2.0);		
	}
	
	return q;
}

void order_rests(float *rests, int size) {
	int i = 0;
	
	for(;i < size-1; i++) {
		int j = 0;
		
		
		for (;j < size-i-1; j++) {
			
			if (rests[j] < rests[j+1]) {
				float aux = rests[j];
				rests[j] = rests[j+1];
				rests[j+1] = aux;
			}
		}
	}
	
	i = 0;
			
}

