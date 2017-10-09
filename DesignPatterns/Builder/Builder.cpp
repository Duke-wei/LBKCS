/*************************************************************************
    > File Name: Builder.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月27日 星期二 20时07分27秒
 ************************************************************************/

#include<iostream>
#include "Builder.h"
#include "Product.h"
using namespace std;

Builder::Builder(){

}
Builder::~Builder(){

}

ConcreteBuilder::ConcreteBuilder(){

}

ConcreteBuilder::~ConcreteBuilder(){

}
void ConcreteBuilder::BuildPartA(const string& buildPara){
	cout<<"Step1:BuildPartA..."<<buildPara<<endl;
}

void ConcreteBuilder::BuildPartB(const string& buildPara){
	cout<<"Step1:BuildPartB..."<<buildPara<<endl;
}
void ConcreteBuilder::BuildPartC(const string& buildPara){
	cout<<"Step1:BuildPartC..."<<buildPara<<endl;
}

Product* ConcreteBuilder::GetProduct(){
	BuilderA("pre-defined");
	BuilderB("pre-defined");
	BuilderC("pre-defined");
	return new Product();
}
