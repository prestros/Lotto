// Lottoprogramm
// Autor: Fabian Prestros
// Datum: 30.08.2020
#include <stdio.h>
#include <stdlib.h>

int lottoziehung(int a[6])
{
	int i, j, n = 0;

	for (i = 0; i <= 5; i++)
	{
		a[i] = erzeugen();	// Eine Lottozahl ziehen.

		// Prüfen, ob eine Lottozahl bereits gezogen wurde
		do
		{
			if (i > 0)
			{
				n = 0;
				for (j = 0; j < i; j++)	// Durchlauf der bereits gezogenen Lottozahlen
				{
					if (a[i] == a[j])	// Vergleichen, ob eine Lottozahl bereits gezogen wurde
						n++;	// Zählen, wie oft eine Lottozahl bereits gezogen wurde
				}
				if (n > 0)	// Wenn eine Lottozahl bereits gezogen wurde, den Zufallsgenerator erneut anwerfen
					a[i] = erzeugen();
			}
		} while (n > 0);	// So lange wiederholen, bis kein Lottozahl doppelt ist
	}
}

int erzeugen()
// Befüllen des Arrays a mit 6 Zufallszahlen
{
	int i, random_number = 0;
	
	random_number = rand();	// Generieren der Zufallszahl
	random_number = random_number % 46 + 1;	// Begrenzen der Zufallszahl auf Werte zwischen 1 und 45, allgemein gilt random_number = random_number % (max - min + 1) + min;
	return (random_number);
}

int eingabe(int a[6])
{
	int i, j, n = 0;

	for (i = 0; i <= 5; i++)
	{
		a[i] = einlesen(i);	// Abfragen der Lottotipps

		// Prüfen, ob ein Lottotipp schon einmal eingegeben wurde
		do
		{
			if (i > 0)
			{
				n = 0;
				for (j = 0; j < i; j++)	// Durchlauf der zuvor eingeben Lottotipps
				{
					if (a[i] == a[j])	// Vergleichen, ob ein Lottotipp bereits abgegeben wurde
						n++;	// Zählen, wie oft ein Lottotipp bereits abgegeben wurde
				}
				if (n > 0)	// Wenn ein Lottotipp bereits eingegeben wurde, diesen erneut abfragen
				{
					printf("Jede Zahl darf nur ur einmal vorkommen!\n");
					a[i] = einlesen(i);
				}
			}
		} while (n > 0);	// So lange wiederholen, bis kein Lottotipp doppelt ist
	}
}

int einlesen(int n)
{
	int num;		// Einzulesende Zahl
	int chk = 0;	// Rückgabewert zur Fehlermeldung

	do				// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%d. Lottotipp = ", n + 1);	// Abfragen der Tipps
		chk = scanf_s("%d", &num);
		while (getchar() != '\n');		// Tastaturpuffer leeren.
		if ((chk == 0) || (num < 1) || (num > 45))	// Fehlermeldung, wenn Zahl kleiner 1 oder größer 45 und Rückgabewert = 0 => scanf_s meldet, dass keine Zahl eingegeben wurde.
			printf("Bitte geben Sie eine Nat\x81rliche Zahl zwischem 1 und 45 ein!\n");
	} while ((chk == 0) || (num < 1) || (num > 45));	// Schleifendurchlauf, bis kein Fehler mehr vorliegt.
	return num;
}

void bubblesort(int a[6])
// Beispiel bubbleSort2 entsprechend https://de.wikipedia.org/wiki/Bubblesort
{
	int i, temp, getauscht;
	do
	{
		getauscht = 0;
		for (i = 0; i < 5; i++)
			if (a[i] > a[i + 1])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				getauscht = 1;
			}
	} while (getauscht != 0);
}

int ausgabe(int a[6])
// Ausgabe Zahlen in Arrays a
{
	int i;

	printf("\n");

	for (i = 0; i <= 5; i++)
		printf("%d. Lottozahl = %d\n", i + 1, a[i]);
}

int pruefen(int a[6], int b[6])
// Vergleichen der Arrays a und b, um die Anzahl n der gleichen Zahlen in beiden Arrays zu ermitteln
{
	int i, j, n = 0;

	for (i = 0; i <= 5; i++)
	{
		for(j = 0; j <= 5; j++)
		{
			if (a[j] == b[i])
				n++;
		}
	}

	
	return n;
}

int main()
{
	int  Lottotip[6], Lottozahlen[6], Richtige;
	
	srand(time(0));
	eingabe(Lottotip);
	lottoziehung(Lottozahlen);
	bubblesort(Lottozahlen);
	ausgabe(Lottozahlen);
	Richtige = pruefen(Lottotip, Lottozahlen);
	
	if (Richtige != 0)
		printf("Gl\x81 \bckwunsch! Sie haben im Lotto gewonnen. Sie haben %d richtige Zahlen erraten.\n", Richtige);
	else
		printf("Sie haben leider nicht im Lotto gewonnen.\n");
}