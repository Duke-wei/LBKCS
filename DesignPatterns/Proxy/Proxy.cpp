/*************************************************************************
    > File Name: Proxy.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月04日 星期三 10时41分40秒
 ************************************************************************/

#include "Proxy.h"
#include<iostream>
using namespace std;
Subject::Subject(){

}
Subject::~Subject(){

}

ConcreteSubject::ConcreteSubject(){

}

ConcreteSubject::~ConcreteSubject(){

}

void ConcreteSubject::Request(){
	cout<<"ConcreteSubject...request..."<<endl;
}

Proxy::Proxy(){

}

Proxy::Proxy(Subject* sub){
	_sub = sub;
}
Proxy::~Proxy(){

}

void Proxy::Request(){
	cout<<"Proxy request ..."<<endl;
	_sub->Request();
}

