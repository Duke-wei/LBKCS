/*************************************************************************
    > File Name: Facade.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月03日 星期二 11时15分23秒
 ************************************************************************/
#include "Facade.h"
#include<iostream>
using namespace std;

Subsystem1::Subsystem1(){

}

Subsystem1::~Subsystem1(){

}

void Subsystem1::Operation(){
	cout<<"Subsystem1 operation.."<<endl;
}

Subsystem2::Subsystem2(){

}

Subsystem2::~Subsystem2(){

}

Subsystem2::Operation(){
	cout<<"Subsystem2 Operation.."<<endl;
}

Facade::Facade(){
	this->_subs1 = new Subsystem1();
	this->_subs2 = new Subsystem2();
}

Facade::~Facade(){
	delete _subs1;
	delete _subs2;
}

void Facade::OperationWrapper(){
	this->_subs1->Operation();
	this->_subs2->Operation();
}

