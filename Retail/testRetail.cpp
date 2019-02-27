#include "RetailItem.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void loadItems(vector<RetailItem> &object);

int main()
{
	vector<RetailItem> object;
	loadItems(object);
	cout << (object[0]).getDescription() << endl;
	cout << (object[1]).getDescription() << endl;
	cout << (object[2]).getDescription() << endl;

	//cout << "\t Description \t Price \t On Hand \t Value\n";
	

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
	data.open("Lab7 Data.csv");
	if (!data)
	{
		cout << "Could not open data file\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		data.seekg(0);
		while (data.good())
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