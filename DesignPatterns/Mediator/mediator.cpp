/*************************************************************************
    > File Name: mediator.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月10日 星期二 10时50分29秒
 ************************************************************************/
#include"mediator.h"
#include"colleage.h"
#include<iostream>
using namespace std;

Mediator::Mediator(){

}

Mediator::~Mediator(){

}

ConcreteMediator::ConcreteMediator(Colleage* clgA,Colleage* clgB){
	this->_clgA = clgA;
	this->_clgB = clgB;
}

void ConcreteMediator::DoActionFromAtoB(){
	_clgB->SetState(_clgA->GetState());
}
void ConcreteMediator::DoActionFromBtoA(){
	_clgA->SetState(_clgB->GetState());
}
void ConcreteMediator::SetConcreteColleageA(Colleage* clga){
	this->_clgA = clga;
}
void ConcreteMediator::SetConcreteColleageB(Colleage* clga){
	this->_clgB = clga;
}

Colleage* ConcreteMediator::GetConcreteColleageA(){
	return _clgA;
}
Colleage* ConcreteMediator::GetConcreteColleageB(){
	return _clgB;
}

void ConcreteMediator::IntroColleage(Colleage* cla,Colleage* clb){
	this->_clgA = cla;
	this->_clgB = clb;
}
