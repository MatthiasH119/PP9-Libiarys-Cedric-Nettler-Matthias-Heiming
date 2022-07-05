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

char version[]="V00.3";

int main(int argc,char *argv[])
{
    char *vvalue = NULL;
    int option;
    int start_application = 0;
    opterr = 0;

    FILE * instream;

    while ((option = getopt(argc, argv, "hsv")) != -1)
        switch (option)
        {
        //void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values, FILE ∗ output_stream)
        // -h (help):
        case 'h':
            Header_Hilfekatalog();
            break;
        // -s Starte Programm ...
        case 's':
            start_application = 1;
            break;
        // -v Version
        case 'v':
            printf("%s \n", version);
            break;
        //optional error handling
        case '?':
            if (isprint (optopt))//is character printable
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


    //Programmaufruf
    if (start_application == 1) {
        printf("\n... starting application ...\n");
        instream = fopen("instream.txt", "r");

        //error handling: test for file not existing
        if (instream == NULL)
        {
            printf("Error! Datei nicht gefunden\n");
            exit(1);
        }
        else
            static_gaussian_calculation (instream);

        fclose(instream);
    }

    return 0;
}
