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
	/*for (string i : ordersIDs(date))
		cout << i << endl;*/
	auto  map = productOrdersCount(ordersIDs(date));
	for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

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

map<string, int> DataBase::productOrdersCount(vector<string> ordersIDsVector)
{
	map<string, int> productOrdersCountMap;
	ifstream orderItemsFile(OrderItemsFilePath);
	string line;
	int indexCommaFirst, indexCommaSecond, count;
	string orderID, productID, countStr;
	while (getline(orderItemsFile, line))
	{
		indexCommaFirst = line.find_first_of(',');
		indexCommaSecond = line.find_last_of(',');
		//cout << indexCommaFirst << " " << indexCommaSecond<<endl;
		orderID = line.substr(0, indexCommaFirst);
		productID = line.substr(indexCommaFirst + 1, (indexCommaSecond - 1) - indexCommaFirst);
		countStr = line.substr(indexCommaSecond+1);
		for (string id : ordersIDsVector)
		{
			if (id == orderID)
			{
				if (productOrdersCountMap[productID] == NULL)
				{
					count = stoi(countStr);
					productOrdersCountMap[productID] = count;
					
				}
				else
				{
					count = stoi(countStr);
					productOrdersCountMap[productID] += count;
					cout << productOrdersCountMap[productID] << endl;
				}
			
			}
		}
		
	}

	return productOrdersCountMap;
}