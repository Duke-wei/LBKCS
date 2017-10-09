/*************************************************************************
    > File Name: Factory.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月24日 星期六 22时18分38秒
 ************************************************************************/
#include "Factory.h"
#include "Product.h"
#include<iostream>
using namespace std;
Factory::Factory(){

}

Factory::~Factory(){

}

ConcreteFactory::ConcreteFactory(){
	cout<<"ConcreteFactory..."<<endl;
}

ConcreteFactory::~ConcreteFactory(){

}

Product* ConcreteFactory::CreateProduct(){
	return new ConcreteProduct();
}

