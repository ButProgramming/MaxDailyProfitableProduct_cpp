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
	auto ab = productProfit(productOrdersCount(ordersIDs(date)));
	for (auto it = ab.begin(); it != ab.end(); it++)
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
					//cout << productOrdersCountMap[productID] << endl;
				}
			
			}
		}
		
	}

	return productOrdersCountMap;
}

map<string, int> DataBase::productProfit(map<string, int> productOrdersCount)
{
	map<string, int> productProfitMap;
	ifstream productsFile(ProductsFilePath);
	string line;
	int indexCommaFirst, indexCommaSecond, price;
	string productID, nameOfProduct, priceStr;
	while (getline(productsFile, line))
	{
		indexCommaFirst = line.find_first_of(',');
		indexCommaSecond = line.find_last_of(',');
		productID = line.substr(0, indexCommaFirst-0);
		nameOfProduct = line.substr(indexCommaFirst+1, (indexCommaSecond-1)-indexCommaFirst);
		priceStr = line.substr(indexCommaSecond + 1);
		for (auto it = productOrdersCount.begin(); it != productOrdersCount.end(); it++)
		{
			if (it->first == productID)
			{
				if (productProfitMap[nameOfProduct] == NULL)
				{
					price = stoi(priceStr);
					productProfitMap[nameOfProduct] = it->second * price;
				}
				else
				{
					price = stoi(priceStr);
					productProfitMap[nameOfProduct] = it->second * price;
				}
			}
		}
	}
	return productProfitMap;
}