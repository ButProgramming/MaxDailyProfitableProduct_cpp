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
	string OrdersFilePath;
	string OrderItemsFilePath;
	string ProductsFilePath;	
	vector<string> ordersIDs(string);
	map<string, int> productOrdersCount(vector<string>);
	map<string, int> productProfit(map<string, int>);

public:
	DataBase(string c_OrdersFilePath, string c_OrderItemsFilePath, string c_ProductsFilePath);
	void MostProfitableProducts();
	void MostProfitableProduct(string Date);
};

