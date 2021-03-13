#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DataBase
{

private:
	vector<string> ordersIDs;

protected:
	string OrdersFilePath;
	string OrderItemsFilePath;
	string ProductsFilePath;

public:
	DataBase();
	DataBase(string c_OrdersFilePath, string c_OrderItemsFilePath, string c_ProductsFilePath);
	void MostProfitableProducts();
	void MostProfitableProduct(string Date);
};

