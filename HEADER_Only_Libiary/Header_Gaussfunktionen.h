void print_gaussian_dist ( float expected_value, float std_deviation, int amount_of_values, FILE * outstream ) {
    // Ausgeben der übergebenben Variablen
    printf("... application: running ...\n\n");
    printf("Your inputs: \n");
    printf("expected_value: %f \n", expected_value);
    printf("std_deviation: %f \n", std_deviation);
    printf("amount_of_values: %i \n", amount_of_values);

    //prüfen, ob min 100 Werte ausgegeben werden sollen
    if (amount_of_values < 100) {
        printf("\n\n... error ... \nplease ask for at least 100 values !\n\n");
        exit (1);
    }

    // Deklarationen
    float e=2.7183;
    float pi=3.1416;
    float space_between_values;
    int amount_of_values_half;
    int amount_of_each_single_value[121];
    float gaussian_dist_single_values[121];
    float gaussian_density_function[121];
    float gaussian_density_function_scaled[121];

    // gaussian density function -> Werte der Dichtefunktion: von -3.0 * Sigma in 0.05er Schritten bis +3.0 Sigma; ges.: 121 Werte
    for (int i=0; i<121; i++) {
        gaussian_density_function[i] = (1/(sqrt(2*pi))) * pow (e, (-0.5 * (-3.0 + (0.05 * i)) * (-3.0 + (0.05 * i))));
    }

    // bilde Summe der gaussian_density_function und erhöhe alle Werte gleichmäßig, sodass die Summe größer als amount_of_values ist
    float counter_sum_scaled=0;

    for (int i=0; amount_of_values > counter_sum_scaled; i++) {
        counter_sum_scaled=0;
        for (int j=0; j<121; j++) {
            counter_sum_scaled=counter_sum_scaled + (gaussian_density_function[j] * (i*0.05 +1));
        }
        if (counter_sum_scaled > amount_of_values) {
            for (int k=0; k<121; k++) {
                gaussian_density_function_scaled[k]=0.5 + gaussian_density_function[k] * (i*0.05 +1);
                amount_of_each_single_value[k]= (int) gaussian_density_function_scaled[k];
            }
        }
    }

    // berechne die gaussian_dist_single_values
    for (int i=0; i<121; i++) {
        gaussian_dist_single_values[i]=expected_value + (std_deviation * (-3.0 + (0.05 * i)));
    }
    //printf Gauss Verteile Zahlen
    if (outstream == stdout)
        printf("\nGaussian distributed values: \n");
    else
        printf("\nData printed to given outstream \n");

    for (int i=0; i<121; i++) {
        for (int j=0; j<amount_of_each_single_value[i]; j++) {
            fprintf(outstream, "%.2f, ", gaussian_dist_single_values[i]);
        }
        fprintf(outstream, "\n");
    }

    printf("\n ... application: finished ... \n\n");
}
