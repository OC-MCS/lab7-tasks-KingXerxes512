#pragma once
#include <iostream>
#include <string>
#include "RetailItem.h"

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

double RetailItem::getStockValue()
{
	double stockValue = (unitsOnHand * price);
	return stockValue;
}