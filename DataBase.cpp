#include "DataBase.h"
DataBase::DataBase()
{}

DataBase::DataBase(string c_OrdersFilePath, string c_OrderFilesFilePath, string c_ProductsFilePath)
	: OrdersFilePath(c_OrdersFilePath)
	, OrderItemsFilePath(c_OrderFilesFilePath)
	, ProductsFilePath(c_ProductsFilePath)
{	//cout << OrdersFilePath <<" "<<OrderItemsFilePath << " " << ProductsFilePath ;
}

void DataBase::MostProfitableProducts()
{

}

void DataBase::MostProfitableProduct(string Date)
{

}