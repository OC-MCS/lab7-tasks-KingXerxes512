#pragma once
#include <iostream>
#include "RetailItem.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

RetailItem::RetailItem(string description, int unitsOnHand, double price)
{
	setDescription(description);
	setUnitsOnHand(unitsOnHand);
	setPrice(price);
}

void RetailItem::setDescription(string input)
{
	description = input;
}

void RetailItem::setUnitsOnHand(int input)
{
	unitsOnHand = input;
}

void RetailItem::setPrice(double input)
{
	price = input;
}

string RetailItem::getDescription()
{
	return description;
}

int RetailItem::getUnitsOnHand()
{
	return unitsOnHand;
}

double RetailItem::getPrice()
{
	return price;
}

float RetailItem::getStockValue()
{
	return (unitsOnHand * price);
}

void RetailItem::loadItems()
{
	int counter = 0;
	string temp;
	vector<RetailItem> object;
	fstream data;
	data.open("Lab7 Data.csv");
	if (!data)
	{
		cout << "Could not open data file\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(data, temp, ','));
		{
			getline(data, description, ',');
			cin >> unitsOnHand;
			cin.ignore();
			cin >> price;
		}
	}
}