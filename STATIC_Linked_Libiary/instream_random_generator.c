/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	time_t t;

	srand(time(&t));

        int i;
	
        for (i = 0; i < 100; i++){
                printf("%d\n",rand());
        }

        exit(EXIT_SUCCESS);
}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500
#define SIZE 100
#define NUMS_TO_GENERATE 100

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        printf("%d\n", rand() % MAX);
    }

    exit(EXIT_SUCCESS);
}	
