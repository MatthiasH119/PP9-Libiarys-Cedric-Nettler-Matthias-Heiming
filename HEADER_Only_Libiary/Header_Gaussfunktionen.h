#include <math.h>

void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values ) {
	// Ausgeben der übergebenben Variablen
	printf("\n\n... application: running ...\n\n");
	printf("expected_value: %f \n", expected_value);
	printf("std_deviation: %f \n", std_deviation);
	printf("amount_of_values: %i \n", amount_of_values);

	//prüfen, ob min 100 Werte ausgegeben werden sollen
	if (amount_of_values < 100) {
		printf("please ask for at least 100 values !");
		exit;
		}

	// Deklarationen
	float e=2.718;
	float space_between_values;
	int amount_of_values_half;
	float gaussian_dist_values[amount_of_values+1];

	// Halbieren der Anzahl der Variablen
	if ((amount_of_values % 2) == 0)
		amount_of_values_half = amount_of_values / 2;
	else
		amount_of_values_half = (amount_of_values + 1) / 2;
	
	//Berechne Platz zwischen zwei Werten
	space_between_values = amount_of_values_half / (3 * std_deviation);
	printf("%f \n", space_between_values);

	//Berechene Gauss Verteilte Werte
	for (int i=0; i<amount_of_values_half; i++) {
		gaussian_dist_values[i] = pow (e, (-1 * std_deviation) * ((space_between_values * i)-expected_value) * ((space_between_values * i)-expected_value));

		gaussian_dist_values[i+amount_of_values_half]=gaussian_dist_values[i] * (-1) ;

	}

	//Bubblesort ?!?!
	

	//printf Gauss Verteile Zahlen
	printf("Gaussian disted values: \n");
	for (int i=0; i < (amount_of_values_half * 2); i++) {
		printf("%.1f", gaussian_dist_values[i]);	
	}
}
