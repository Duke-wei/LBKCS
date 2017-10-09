/*************************************************************************
    > File Name: Prototype.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月28日 星期三 13时16分56秒
 ************************************************************************/
#include "Prototype.h"
#include<iostream>
using namespace std;

Prototype::Prototype(){

}
Prototype::~Prototype(){

}
Prototype* Prototype::Clone() const {
	return 0;
}
ConcretePrototype::ConcretePrototype(){

}
ConcretePrototype::~ConcretePrototype(){

}
ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp){
	cout<<"ConcretePrototype copy..."<<endl;
}

Prototype* ConcretePrototype::Clone()const {
	return new ConcretePrototype(*this);
}
