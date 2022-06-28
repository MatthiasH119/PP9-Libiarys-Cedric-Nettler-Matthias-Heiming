//      Autor:          Cedric-Julian Nettler                   |       Matthias Heiming
//      Mail:           cedric-julian.nettler@stud.thga.de      |       matthias.heiming@stud.thga.de
//      Datum:          28.06.2022
//
//      Praktikum:      PP9, Static linked Libiary Aufgabe

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include "Header_Hilfekatalog2.h"
#include <static_gaussian.h>

char version[]="V00.1";

int main(int argc,char *argv[])
{
        char *vvalue = NULL;
        int option;
        int Programmstart = 0;
	float expected_value = 0.0;
	float std_deviation = 0.0;
        opterr = 0;

	FILE * instream;
	instream = abc;

        while ((option = getopt(argc, argv, "i:hv")) != -1)
        switch (option)
        {
                //void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values, FILE ∗ output_stream)
                // -h (help):
                case 'h':
                        Header_Hilfekatalog();
                        break;
		// -e Liest Erwartungswert ein (float)
                case 'i':
                        instream = fopen(optarg, "r");
                        break;
		// -v Version
                case 'v':
                        printf("%s \n", version);
                        break;
                //optional error handling
                case '?':
                        if (optopt == 'i')
                        {
                                fprintf (stderr, "There are rules! -%c requires an argument! \n", optopt);
                        }
                        else if (isprint (optopt))//is character printable
                        {
                                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                        }
                        else
                        {
                                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                        }
                        Header_Hilfekatalog();
                        return 1;
                default:
                abort ();
        }

	if (Programmstart == 3) {
                printf("\n\n... starting application ... \n");
                print_gaussian_dist ( expected_value, std_deviation, amount_of_values, outstream );
                }
        else    {
                printf("\n\nto start algorithm: enter an expected value, a standart deviation and an amount of values:\n");
                printf("-e [expected value] -s [standart deviation] -n [amount of values]\n\n");
                printf("enter -h for further information \n");
                }

	if (instream == abc)
		instream = fopen("insteam.txt", "r");
	
	void static_gaussian (instream);
	
	fclose(instream);

        return 0;
}