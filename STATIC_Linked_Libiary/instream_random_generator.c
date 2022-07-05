#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 500
#define SIZE 100
#define NUMS_TO_GENERATE 100

//Version: V10.2

int main() {

	int random_normalverteilt_temp01[NUMS_TO_GENERATE];
	int random_normalverteilt_temp02[NUMS_TO_GENERATE];

	FILE * outstream;
	outstream = fopen("instream.txt", "w");


	//erstellt zwei Normalverteilte Zahlenreihen
	srand(time(NULL));
	for (int i = 0; i < NUMS_TO_GENERATE; i++){
                random_normalverteilt_temp01[i] = rand() % MAX;
        }

	for (int i = 0; i < NUMS_TO_GENERATE; i++){
                random_normalverteilt_temp02[i] = rand() % MAX;
        }


	//erstellt aus den beiden Normalverteilten Zahlenreihen eine Gaussverteilte und schreibt diese in "instream.txt"
    	for (int i = 0; i < NUMS_TO_GENERATE; i++){
		fprintf(outstream, "%d, ", (random_normalverteilt_temp01[i] + random_normalverteilt_temp02[i]));
    	}

    	fclose(outstream);

    	return 0;
}	
