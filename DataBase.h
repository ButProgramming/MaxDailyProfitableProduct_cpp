#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
using namespace std;

class DataBase
{

private:
	vector<string> ordersIDs;
	string OrdersFilePath;
	string OrderItemsFilePath;
	string ProductsFilePath;	
	vector<string> ordersIDs(string);
	map<string, int> productOrdersCount(vector<string>&);

public:
	DataBase(string c_OrdersFilePath, string c_OrderItemsFilePath, string c_ProductsFilePath);
	void MostProfitableProducts();
	void MostProfitableProduct(string Date);
};

