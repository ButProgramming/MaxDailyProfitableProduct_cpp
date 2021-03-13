#include "DataBase.h"

int main()
{
	DataBase db1("orders.csv", "order_items.csv", "products.csv");
	db1.MostProfitableProducts();
}