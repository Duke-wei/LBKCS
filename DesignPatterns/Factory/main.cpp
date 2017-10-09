/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月24日 星期六 22时20分50秒
 ************************************************************************/

#include "Factory.h"
#include "Product.h"
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
	Factory* fc = new ConcreteFactory();
	Product* p = fc->CreateProduct();
	return 0;
}

