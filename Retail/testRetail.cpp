#include "RetailItem.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

void loadItems(vector<RetailItem> &object);

int main()
{
	double total = 0;
	vector<RetailItem> object;
	loadItems(object);

	// Calculates the total value for entire inventory
	for (int counter = 0; counter < object.size() - 1; counter++)
	{
		total += object[counter].getStockValue();
	}

	// Prints a detailed report of what is in inventory
	cout << "\t Description \t Price \t On Hand \t Value\n";
	for (int counter = 0; counter < object.size() - 1; counter++)
	{
		cout << setw(25) << left << object[counter].getDescription() << object[counter].getPrice() << setw(8) << right << object[counter].getUnitsOnHand() <<
			setw(16) << object[counter].getStockValue() << endl;
	}
	cout << "\nTotal Inventory Value: " << setprecision(2) << fixed << total << endl;

	return 0;
}

void loadItems(vector<RetailItem> &object)
{
	string temp;
	string description;
	string tempUnits;
	string tempPrice;
	double price;
	int unitsOnHand;
	RetailItem buffer("null", 0, 0);
	
	ifstream data;
	data.open("RetailData.csv");
	if (!data)	// Checks to see if file was opened or not
	{
		cout << "Could not open RetailData.csv\n";
		exit(EXIT_FAILURE);
	}
	else
	{	// Runs loop which continually sets the values of the buffer object and then back adds the object to the Vector object, until eof
		data.seekg(0);
		while (!data.eof())
		{
			getline(data, description, ',');
			getline(data, tempUnits, ',');
			getline(data, tempPrice, '\n');
			unitsOnHand = stoi(tempUnits);
			price = stod(tempPrice);
			buffer.setDescription(description);
			buffer.setUnitsOnHand(unitsOnHand);
			buffer.setPrice(price);
			object.push_back(buffer);
		}
	}
	data.close();
}