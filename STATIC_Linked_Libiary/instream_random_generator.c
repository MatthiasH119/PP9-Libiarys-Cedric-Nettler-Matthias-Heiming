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

	FILE * outstream;
	outstream = fopen("instream.txt", "w");

    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
	fprintf(outstream, "%d, ", rand() % MAX);
    }

    fclose(outstream);

    return 0;
}	
