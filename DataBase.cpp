#include "DataBase.h"

DataBase::DataBase(string c_OrdersFilePath, string c_OrderFilesFilePath, string c_ProductsFilePath)
	: OrdersFilePath(c_OrdersFilePath)
	, OrderItemsFilePath(c_OrderFilesFilePath)
	, ProductsFilePath(c_ProductsFilePath)
{	//cout << OrdersFilePath <<" "<<OrderItemsFilePath << " " << ProductsFilePath ;
}


void DataBase::MostProfitableProducts()
{

}

void DataBase::MostProfitableProduct(string date)
{
	for (string i : ordersIDs(date))
		cout << i << endl;

}

vector<string> DataBase::ordersIDs(string date)
{
	vector<string> ordersIDsVector;
	ordersIDsVector.reserve(100);
	ifstream ordersFile(OrdersFilePath);
	string line;
	int indexQuote, indexComma;
	while (getline(ordersFile, line))
	{
		indexQuote = line.find_first_of('"');
		indexComma = line.find_last_of(',');
		string id = line.substr(1, ((indexComma-1)-indexQuote));
		if (line.find(date) == string::npos)
			continue;
		ordersIDsVector.push_back(id);
	}
	return ordersIDsVector;
}

map<string, int> DataBase::productOrdersCount(vector<string>& ordersIDsVector)
{
	map<string, int> productOrdersCountMap;

	indexQuote = 


	return productOrdersCountMap;
}