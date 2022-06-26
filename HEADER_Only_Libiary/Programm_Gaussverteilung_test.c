/*
 * Gauß_Algorithmus.c
 *
 *  Created on: Aug 12, 2014
 *      Author: zechpreller
*/
#include <stdio.h>
#include <math.h>

//***********************************************************************************//
int main()
{
	int i_hor = 0;									//innerer Schleifenzähler (Einlesen)
	int i_ver = 0;									//äußerer Schleifenzähler (Einlesen
	int length;									//Länge des Arrays
	int Spalte = 0;									//Spalte in welcher das Element eliminiert werden soll
	int Zeile = 0;									//Zeile welche bearbeitet wird
	double lin_var[length][length+1];						//Array für das lin-Gleichungssystem
	double zw_sp[length+1];								//Array für die Eliminierung
	double mult_var;
	double result_array[length];							//Array in welchem die Lösung der Variablen steht

	double calc_mult_var(int Spalte, int Zeile,int length)				//mult Variable Deklaration
	{
		double calc_mult_var = lin_var[Zeile][Spalte]/lin_var[Spalte][Spalte]*(-1);
		return(calc_mult_var);
	}

	void calc_add_array(Spalte, Zeile, length)					//eliminiert eine Variable in einer Zeile
											//bearbeitet das Array lin_var
											//eliminert nur die Variable in einer Zeile
	{
		int i_add_array = 0;							//äußerer Schleifenzähler (calc add array)
		int i_add_array_sub = 0;						//inner Schleifenzähler (-"-)
		mult_var = calc_mult_var(Spalte,Zeile, length);
		for (; i_add_array < length+1; i_add_array++)
		{
			zw_sp[i_add_array] = mult_var*lin_var[Spalte][i_add_array];


		}
		for (i_add_array_sub = 0; i_add_array_sub < length+1; i_add_array_sub++)
		{
			lin_var [Zeile] [i_add_array_sub] = lin_var [Zeile] [i_add_array_sub] + zw_sp [i_add_array_sub];
		}
	}

	void swap_lines (int Zeile1, int Zeile2, int length)
	{
		double swap_array[length+1];
		int i_swap_array = 0;
		for(; i_swap_array < length+1; i_swap_array++)
		{
			swap_array[i_swap_array] = lin_var[Zeile1][i_swap_array];
			lin_var[Zeile1][i_swap_array] = lin_var[Zeile2][i_swap_array];
			lin_var[Zeile2][i_swap_array] = swap_array[i_swap_array];
		}
		printf("\nDie %i. Zeile wurde mit der %i. Zeile getauscht.\n",Zeile1+1, Zeile2+1);
	}

	void swap_spalte(int Spalte1, int Spalte2, int length)
	{
		double swap_spalte_array[length];
		int i_swap_spalten = 0;
		for (; i_swap_spalten < length; i_swap_spalten++)
		{
			swap_spalte_array[i_swap_spalten] = lin_var[i_swap_spalten][Spalte1];
			lin_var[i_swap_spalten][Spalte1] = lin_var[i_swap_spalten][Spalte2];
			lin_var[i_swap_spalten][Spalte2] = swap_spalte_array[i_swap_spalten];
		}
		printf("\nDie %i. Spalte wurde mit der %i. Spalte getauscht.\n",Spalte1+1,Spalte2+1);
	}

	int check_array_spalten (int length)
	{
		int i_check_spalten = 0;
		int i_check_spalten_sub = 0;
		int switched_spalte = 0;
		for (;i_check_spalten < length; i_check_spalten++)
		{
			if (lin_var[i_check_spalten][i_check_spalten] == 0)
			{
				i_check_spalten_sub = i_check_spalten+1;
				for (;i_check_spalten_sub < length; i_check_spalten_sub++)
				{
					if (lin_var[i_check_spalten_sub][i_check_spalten] != 0 && lin_var[i_check_spalten][i_check_spalten_sub] != 0 && lin_var[i_check_spalten][i_check_spalten] == 0 )
						swap_spalte(i_check_spalten, i_check_spalten_sub, length);
					{
						switched_spalte = 1;
					}
				}
			}
		}
		return (switched_spalte);
	}

	int check_array_before (int Spalte,int Zeile,int length)
	{
		int i_check_before = Zeile;
		int i_add = 0;
		int return_value = 0;
		for (; i_check_before < length; i_check_before++)
		{
			if (lin_var[i_check_before][i_check_before] == 0)
			{
				i_add = i_check_before+1;
				for (;i_add < length ; i_add++ )
				{
					if (lin_var[i_add][i_check_before] != 0 && lin_var[i_check_before][i_add])
					{
						swap_lines(i_check_before, i_add, length);
						return_value = 1;
					}
				}
			}
		}
		return(return_value);
	}

	void check_array_before_inverted (int length)
	{
		int i_check_before = length;
		int i_add = 0;

		for (; i_check_before > 0; i_check_before--)
		{
			if (lin_var[i_check_before][i_check_before] == 0)
			{
				i_add = i_check_before-1;
				for (;i_add > 0 ; i_add-- )
				{
					if (lin_var[i_add][i_check_before] != 0 && lin_var[i_check_before][i_add])
					{
						swap_lines(i_check_before, i_add, length);
					}
				}
			}
		}
	}

	void errase_downstairs (Spalte,Zeile,length)
	{
		int i_errase_spalte = 0;
		int i_switch_spalte = 0;
		int switched_line = 0;
		for (;i_switch_spalte < length-1 ; i_switch_spalte++)
		{
			switched_line = check_array_before (0, 0, length);
			switched_line = check_array_spalten (length);
			Spalte = i_switch_spalte;
			Zeile = Spalte;
			i_errase_spalte = Spalte;
			if (switched_line == 1)
			{
				i_switch_spalte = 0;
				i_errase_spalte = 0;
				Zeile = 0;
				Spalte = 0;
			}
			else
			{
				for (;i_errase_spalte < length ; i_errase_spalte++)
				{
					Zeile = Zeile+1;
					calc_add_array(Spalte, Zeile, length);
				}
			}
		}
	}

	void errase_upstairs (Spalte,Zeile,length)
	{
		int i_errase_spalte = 0;
		int i_switch_spalte = 1;
		for (;i_switch_spalte < length ; i_switch_spalte++)
		{
			Spalte = i_switch_spalte;
			i_errase_spalte = 0;
			Zeile = Spalte;
			for (;i_errase_spalte < Spalte ; i_errase_spalte++)
			{
				Zeile = Zeile-1;
				calc_add_array(Spalte, Zeile, length);
			}
		}
	}

	void array_out(int length)
	{
		int i_out_hor = 0;
		int i_out_ver = 0;
		for(i_out_ver = 0; i_out_ver < length ; i_out_ver++)
		{
			printf("\n");
			i_out_hor = 0;
			for(; i_out_hor < length+1 ; i_out_hor++)
			{
				printf("%f", lin_var[i_out_ver][i_out_hor]);
				printf("\t");
			}
		}
	}

	printf("\nSie haben das Programm zur Durchführung des Gaußschen Algorithmus gewählt.");
	printf("\nDie Koeffizienten werden von links nach rechts eingelesen.");
	printf("\nWobei die jeweilige Spalte die Variablennummer wiedergibt\n\n");

	//***********************************************************************************//
	//Bestimmen der Anzahl zu berechnender Variablen
	printf("\nBitte geben sie die Anzahl der zu berechnenden Variablen an\n");
	fflush(stdout);
	scanf("%d",&length);
	//***********************************************************************************//
	//Einlesen des Linearen Gleichungssystems
	//***********************************************************************************//

	for (i_ver = 0; i_ver < length ; i_ver++) //äußere Schleife zum Einlesen
	{
		Zeile = i_ver;
		printf("\n\nSie befinden sich in der %i. Zeile\n\n\n",i_ver+1);

		for (i_hor = 0; i_hor < length+1 ; i_hor++)	//innere Schleife um die Zeile einzulesen
		{
			printf("Bitte geben Sie den %i. Koeffizienten ein\t",i_hor+1);
			fflush(stdout);
			scanf("%lf",&lin_var[Zeile][i_hor]);
		}
	}
	//printf("Die Anzahl der Variablen %i",length);
	//printf("\n\n");

	//***********************************************************************************//
	//Prüfen nach dem Eingeben des Systems
	printf("\nIhr eingegebenes Gleichungssystem\n");
	array_out(length);
	printf("\n\n");
	//***********************************************************************************//
	//Erste Prüfung auf Lösbarkeit des Systems
	//***********************************************************************************//
	Zeile = 0;
	Spalte = 0;

	check_array_before_inverted (length);
	check_array_spalten (length);

	//***********************************************************************************//
	//Testfeld für das Zeilentauschen
	//check_array_before (Spalte, Zeile, length);
	//***********************************************************************************//
	//Einlesen der Koeffizienten beendet
	//Beginn der Berechnung
	//***********************************************************************************//
	int i_cancel = 0;
	int cancel = 0;
	for (; i_cancel < length ; i_cancel++)
	{
		if (lin_var[i_cancel][i_cancel] == 0)
		{
			cancel = 1;
		}
	}

	if (cancel == 0)
	{
		errase_downstairs(Spalte, Zeile, length);
		Zeile = 0;
		Spalte = 0;
		errase_upstairs(Spalte, Zeile, length);
		printf("\nDas umgeformte Array zur Berechnung der Variablen\n");
		array_out(length);

		//***********************************************************************************//
		//Berechnen und ausgeben der Variablen-Werte
		//***********************************************************************************//
		printf("\n\n\nDas result_array \n\n");
		int i_out_hor_result = 0;
		int i_result_array = 0;
		for (; i_result_array < length; i_result_array++)
		{
			result_array[i_result_array] = lin_var[i_result_array][length]/lin_var[i_result_array][i_result_array];
		}
		for(; i_out_hor_result < length ; i_out_hor_result++)
		{
			printf("Die %i. Variable ist",i_out_hor_result+1);
			printf("   %f", result_array[i_out_hor_result]);
			printf("\n");
		}
	}
	if (cancel == 1)
	{
		printf("\n\nGleichungssystem nicht lösbar!\n");
	}
	return(0);
}
