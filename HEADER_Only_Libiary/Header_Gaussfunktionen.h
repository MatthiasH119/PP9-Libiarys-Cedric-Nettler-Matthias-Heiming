void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values ) {
        // Ausgeben der übergebenben Variablen
        printf("... application: running ...\n\n");
        printf("Your inputs: \n");
        printf("expected_value: %f \n", expected_value);
        printf("std_deviation: %f \n", std_deviation);
        printf("amount_of_values: %i \n", amount_of_values);

        //prüfen, ob min 100 Werte ausgegeben werden sollen
        if (amount_of_values < 100) {
                printf("please ask for at least 100 values !");
                exit;
                }

        // Deklarationen
        float e=2.7183;
        float pi=3.1416;
        float space_between_values;
        int amount_of_values_half;
        int amount_of_each_single_value[109];
        float gaussian_dist_single_values[109];
        float gaussian_density_function[109];
        float gaussian_density_function_scaled[109];

        // gaussian density function -> Werte der Dichtefunktion: von -2.7 * Sigma in 0.05er Schritten bis +2.7 Sigma; ges.: 109 Werte
        for (int i=0; i<109; i++) {
                gaussian_density_function[i] = (1/(sqrt(2*pi))) * pow (e, (-0.5 * (-2.7 + (0.05 * i)) * (-2.7 + (0.05 * i))));
        }

        // bilde Summe der gaussian_density_function und erhöhe alle Werte gleichmäßig, sodass die Summe größer als amount_of_values ist
        float counter_sum_scaled=0;

        for (int i=0; amount_of_values > counter_sum_scaled; i++) {
                counter_sum_scaled=0;
                for (int j=0; j<109; j++) {
                counter_sum_scaled=counter_sum_scaled + (gaussian_density_function[j] * (i*0.05 +1));
                }
                if (counter_sum_scaled > amount_of_values) {
                        for (int k=0; k<109; k++){
                                gaussian_density_function_scaled[k]=gaussian_density_function[k] * (i*0.05 +1);
                                amount_of_each_single_value[k]= (int) gaussian_density_function_scaled[k];
                        }
                }
        }

        // berechne die gaussian_dist_single_values
        for (int i=0; i<109; i++) {
                gaussian_dist_single_values[i]=expected_value + (std_deviation * (-2.7 + (0.05 * i)));
        }
	//printf Gauss Verteile Zahlen
        printf("\nGaussian distributed values: \n");
        for (int i=0; i<109; i++) {
                for (int j=0; j<amount_of_each_single_value[i]; j++) {
                        printf("%.1f, ", gaussian_dist_single_values[i]);
                }
                printf("\n");
        }

        printf("\n\n ... application: finished ... \n\n");
}
