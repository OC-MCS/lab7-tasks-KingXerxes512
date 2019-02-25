#pragma once
#include <string>

using namespace std;

class RetailItem
{
private:
	string description;
	int unitsOnHand;
	double price;
public:
	RetailItem(string, int, double);
	void setDescription(string);
	void setUnitsOnHand(int);
	void setPrice(double);
	string getDescription();
	int getUnitsOnHand();
	double getPrice();
	float getStockValue();
	void loadItems();
};