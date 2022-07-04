#include "static_gaussian.h"
#include <stdio.h>
#include <math.h>

void static_gaussian_calculation(FILE * instream) {
	//declarations
	float expected_value = 0.0;
	double std_deviation = 0.0;
	int buffer_instream_int[100];
	int sum_buffer_instream = 0;
	int amount_of_values = 100;
	int auxilary_std_deviation = 0;

	//fscanf instream
	for (int i=0; i<100; i++) {
		fscanf(instream, "%d, ", &buffer_instream_int[i]);
		//entwicklungshilfe:
		//printf("%d, ", buffer_instream_int[i]);
	}
	printf("\n");

	//calculate expected_value & std_devation:
	for (int i=0; i<100; i++) {
		sum_buffer_instream = sum_buffer_instream + buffer_instream_int[i];
	}
	expected_value = sum_buffer_instream / amount_of_values;

	for (int i=0; i<100; i++) {
		auxilary_std_deviation = auxilary_std_deviation + ( pow( (buffer_instream_int[i] - expected_value), 2 ) );
		//entwicklungshilfe:
		//printf("%i, ", auxilary_std_deviation);
	}
	std_deviation = sqrt(auxilary_std_deviation / amount_of_values); 
	
	//print output
	printf("\nexpected value: %.2f, standart deviation: %.2lf", expected_value, std_deviation);
	
	printf("\n... application finished ...\n\n");
}
