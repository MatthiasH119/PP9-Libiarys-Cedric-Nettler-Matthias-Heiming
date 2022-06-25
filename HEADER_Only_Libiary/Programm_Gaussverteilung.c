//      Autor:          Cedric-Julian Nettler		|	Matthias Heiming
//      Mail:           				|	matthias.heiming@stud.thga.de
//      Datum:          25.06.2022
//
//      Praktikum:	PP9, Header Only Libiary Aufgabe

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "Header_Hilfekatalog.h"
#include "Header_Gaussfunktionen.h"

char version[]="V00.1";

void Programm_Start(){

}

int main(int argc,char *argv[])
{
        char *vvalue = NULL;
        int option;
        opterr = 0;



        while ((option = getopt(argc, argv, "e:hv")) != -1)
        switch (option)
        {
                // -h (help):
                case 'h':
                        Header_Hilfekatalog();
                        break;
                // -e Eingabe -> Echo
                case 'e':
                        printf("%s \n", optarg);
                        break;
                // -v Version
                case 'v':
                        printf("%s \n", version);
                        break;
                //optional error handling
                case '?':
                        if (optopt == 'e')
                        {
                                fprintf (stderr, "This is not 'Nam, this is programming. There are rules! -%c requires an argument.\n", optopt);
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



        return 0;
}
