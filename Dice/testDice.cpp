#include "Die.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	Die SixSided(6);
	Die TwelveSided(12);
	int sixArray[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int twelveArray[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int counter = 0; counter < 1000000; counter++)
	{
		SixSided.roll();
		TwelveSided.roll();
		for (int index = 1; index < 7; index++)
		{
			if (SixSided.getValue() == index)
			{
				sixArray[index]++;
			}
		}
		for (int index = 1; index < 13; index++)
		{
			if (TwelveSided.getValue() == index)
			{
				twelveArray[index]++;
			}
		}
	}
	cout << "Stats for Six Sided Die: " << endl;
	for (int counter = 1; counter < 7; counter++)
	{
		cout << "Side " << counter << ": " << fixed << setprecision(2) << (sixArray[counter] / 10000.0) << "%" << endl;
	}
	cout << "\nStats for the Twelve Sided Die: " << endl;
	for (int counter = 1; counter < 13; counter++)
	{
		cout << "Side " << counter << ": " << fixed << setprecision(2) << (twelveArray[counter] / 10000.0) << "%" << endl;
	}

	cout << endl; system("pause"); return 0;
}