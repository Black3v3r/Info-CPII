/**********************************************************/
/* Développé par : LABARRE Florian – fushia_1			  */
/* Source : exo2.c – TP n°5 - le 05/05/2014 			  */
/* Description : Manipulation de tableaux 2D		      */
/**********************************************************/

/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* fonction main : fonction principale du programme */
int main(int argc, char const *argv[])
{
	system("clear"); // Efacer la console (Linux)
	system("cls"); // Effacer la console (Windows)
	srand(time(NULL));
	/* variables locales */
	int i = 0;
	int j = 0;
	int k = 0;
	int menu = 0;
	int mat1[3][3];
	int mat2[3][3];
	int matResult[3][3];
	int vect[3][1];
	int vectResult[3][1];

	/* instructions */
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			mat1[i][j] = rand()%6;
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	printf("Voulez-vous ?\n");
	printf("1. Multiplier la matrice par un vecteur\n");
	printf("2. Additionner la matrice à une autre matrice\n");
	printf("3. Multiplier la matrice par une autre matrice\n");
	scanf("%d", &menu);
	clear;
	switch(menu)
	{
		case 1:
			for (i = 0; i < 3; i++)
			{
				vect[i][0] = rand()%6;
			}
			for (i = 0; i < 3; ++i)
			{
				vectResult[i][0] = 0;
				for (j = 0; j < 3; ++j)
				{
					vectResult[i][0] += mat1[i][j] * vect[j][0];
				}
			}
			for (i = 0; i < 3; i++)
			{
				printf("%d\n", vectResult[i][0]);
			}
			break;
		case 2:
			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					mat2[i][j] = rand()%6;
					matResult[i][j] = mat1[i][j] + mat2[i][j];
				}
			}
			printf("mat2: \n");
			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					printf("%2d", mat2[i][j]);
				}
				printf("\n");
			}
			printf("Somme: \n");
			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					printf("%2d", matResult[i][j]);
				}
				printf("\n");
			}
			break;
		case 3:
			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					mat2[i][j] = rand()%6;
				}
			}

			for (i=0; i < 3; ++i)
			{
				for (j=0; j < 3; ++j)
				{
					matResult[i][j]=0;
					for (k=0; k < 3; ++k)
						matResult[i][j] += mat1[i][k]*mat2[k][j];
				}
			}

			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					printf("%2d", mat1[i][j]);	
				}
				if (i != (3 / 2))
					printf("     ");
				else
					printf("  x  ");
				for (j = 0; j < 3; ++j)
				{
					printf("%2d", mat2[i][j]);
				}
				if (i != (3 / 2))
					printf("     ");
				else
					printf("  =  ");
				for (j = 0; j < 3; ++j)
				{
					printf("%3d", matResult[i][j]);
				}
				printf("\n");
			}
			break;
		default:
			printf("Erreur, valeur incorrecte\n");
	}
	return 0;
}