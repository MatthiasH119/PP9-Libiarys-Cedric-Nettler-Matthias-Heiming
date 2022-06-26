//      Autor:          Cedric-Julian Nettler		|	Matthias Heiming
//      Mail:           				|	matthias.heiming@stud.thga.de
//      Datum:          25.06.2022
//
//      Praktikum:	PP9, Header Only Libiary Aufgabe

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include "Header_Hilfekatalog.h"
#include "Header_Gaussfunktionen.h"

char version[]="V00.1";

void Programm_Start(){

}

int main(int argc,char *argv[])
{
        char *vvalue = NULL;
        int option;
	float expected_value = 1000.0;
	float std_deviation = 10.0;
	int amount_of_values = 100;
	int Programmstart = 0;			//prüft ob: e, s & n eingegeben!
        opterr = 0;



        while ((option = getopt(argc, argv, "e:hn:s:v")) != -1)
        switch (option)
        {
		//void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values, FILE ∗ output_stream)
                // -h (help):
                case 'h':
                        Header_Hilfekatalog();
                        break;
                // -e Liest Erwartungswert ein (float)
                case 'e':
                        expected_value = atof(optarg);
			Programmstart ++;
                        break;
		// -s Liest Standartabhweichung ein (float)
                case 's':
                        std_deviation = atof(optarg);
			Programmstart ++;
                        break;
		// -n Liest Anzahl der Werte ein (int)
                case 'n':
                        amount_of_values = atoi(optarg);
			Programmstart ++;
                        break;
                // -v Version
                case 'v':
                        printf("%s \n", version);
                        break;
                //optional error handling
                case '?':
                        if (optopt == 'e')
                        {
                                fprintf (stderr, "There are rules! -%c requires an argument! \n", optopt);
                        }
			else if (optopt == 's')
                        {
                                fprintf (stderr, "There are rules! -%c requires an argument! \n", optopt);
                        }
			else if (optopt == 'n')
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
		printf("\n\n... starting algorithm ... \n");
		print_gaussian_dist ( expected_value, std_deviation, amount_of_values );
		}
	else	{
		printf("\n\nto start algorithm: enter an expected value, a standart deviation and an amount of values:\n");
		printf("-e [expected value] -s [standart deviation] -n [amount of values]\n\n");
		}



        return 0;
}
