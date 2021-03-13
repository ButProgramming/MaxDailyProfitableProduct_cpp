#include "DataBase.h"

int main()
{
	/*DataBase db1("orders.csv", "order", "products");
	db1.MostProfitableProduct("2021-01-01");*/

	map<string, int> myMap;
	myMap["123"]=1;
	myMap["123"] = myMap["123"] + 2;
	cout << myMap["123"] << endl;;
	pair<string, int> myPair;
	for (auto it = myMap.begin(); it != myMap.end(); it++)
		cout << it->first << " " << it->second << endl;

}