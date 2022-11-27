/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion.
	(c) Baco Alviter Erick Jesus 320105397.

	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.

******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{

	//Sustituya estas lineas por su código
	iNumElementos = 1;
	strcpy(szPalabras[0], "AquiVaElDiccionario");
	iEstadisticas[0] = 1; // la primer palabra aparece solo una vez.
}

/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int& iNumLista)							//Numero de elementos en la szListaFinal
{

	//Sustituya estas lineas por su código
	strcpy(szListaFinal[0], szPalabrasSugeridas[0]); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata

	iNumLista = 1;							//Una sola palabra candidata
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char* szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int& iNumSugeridas)						//Numero de elementos en la lista
{
	char palabra[50];
	char palabraTemp[100];
	int conta;
	int limite = 0;
	char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
	int conta2, conta3, conta4;
	char palabraEsp[100];



	//FILE* fp;
	//fopen_s(&fp, "candidatos.txt", "w");

	scanf_s("%s", palabra, 49);

	limite = 0;
	while (palabra[limite] != '\0')
	{
		strcpy_s(palabraTemp, palabra);

		conta = limite;
		while (palabraTemp[conta] != '\0')
		{
			palabraTemp[conta] = palabraTemp[conta + 1];
			conta++;
		}
		printf("%s", palabraTemp);
		printf("\n");

		limite++;
	}

	char temp;
	limite = 0;
	while (palabra[limite] != '\0')
	{
		strcpy_s(palabraTemp, palabra);

		temp = palabraTemp[limite];
		palabraTemp[limite] = palabraTemp[limite + 1];
		palabraTemp[limite + 1] = temp;

		printf("%s", palabraTemp);
		printf("\n");

		limite++;
	}

	conta2 = 0;
	while (palabra[conta2] != '\0')
	{
		strcpy_s(palabraTemp, palabra);

		limite = strlen(alfabeto);
		conta = 0;
		while (conta < limite)
		{
			palabraTemp[conta2] = alfabeto[conta];
			printf("%s", palabraTemp);
			printf("\n");
			conta++;
		}
		conta2++;
	}

	char c;


	conta = 0;
	conta2 = 0;

	limite = strlen(palabra);
	while (conta <= limite)
	{
		c = palabra[conta];
		palabraEsp[conta2] = ' ';
		conta2++;
		palabraEsp[conta2] = c;
		conta++;
		conta2++;
	}


	conta = 0;
	conta2 = 0;
	while (palabraEsp[conta] != '\0')
	{
		while (conta2 < 26)
		{
			palabraEsp[conta] = alfabeto[conta2];
			conta3 = 0;
			conta4 = 0;
			while (palabraTemp[conta4] != '\0')
			{
				if (palabraEsp[conta3] != ' ')
				{
					palabraTemp[conta4] = palabraEsp[conta3];
					conta4++;
				}
				conta3++;
			}
			conta2++;
			printf("%s", palabraTemp);
			printf("\n");

		}
		conta = conta + 2;
	}

	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}