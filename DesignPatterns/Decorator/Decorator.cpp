/*************************************************************************
    > File Name: Decorator.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月31日 星期六 11时08分04秒
 ************************************************************************/
#include "Decorator.h"
#include<iostream>
using namespace std;

Component::Component(){

}

Component::~Component(){

}

void Component::Operation(){

}

ConcreteComponent::ConcreteComponent(){

}

ConcreteComponent::~ConcreteComponent(){

}

void ConcreteComponent::Operation(){
	cout<<"ConcreteComponent operation..."<<endl;
}

Decorator::Decorator(Component* com){
	this->_com = com;
}

Decorator::~Decorator(){
	delete _com;
}

void Decorator::Operation(){

}

ConcreteDecorator::ConcreteDecorator(Component* com):Decorator(com){

}

ConcreteDecorator::~ConcreteDecorator(){

}

void ConcreteDecorator::AddedBehavior(){
	cout<<"ConcreteDecorator::AddedBehavior..."<<endl;
}

void ConcreteDecorator::Operation(){
	_com->Operation();
	this->AddedBehavior();
}

