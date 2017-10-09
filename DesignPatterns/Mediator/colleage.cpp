/*************************************************************************
    > File Name: colleage.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月10日 星期二 10时43分47秒
 ************************************************************************/
#include "mediator.h"
#include "colleage.h"
#include<iostream>
using namespace std;

Colleage::Colleage(){

}

Colleage::Colleage(Mediator* mdt){
	this->_mdt = mdt;
}

Colleage::~Colleage(){

}

ConcreteColleageA::ConcreteColleageA(){

}

ConcreteColleageA::~ConcreteColleageA(){

}

ConcreteColleageA::ConcreteColleageA(Mediator* mdt):Colleage(mdt){

}

string ConcreteColleageA::GetState(){
	return _sdt;
}

void ConcreteColleageA::SetState(const string& std){
	_sdt = std;
}

void ConcreteColleageA::Action(){
	_mdt->DoActionFromAtoB();
	cout<<"State of ConcreteColleageB:"<<" "<<this->GetState()<<endl;
}


ConcreteColleageB::ConcreteColleageB(){

}

ConcreteColleageB::~ConcreteColleageB(){

}

ConcreteColleageB::ConcreteColleageB(Mediator* mdt):Colleage(mdt){

}

string ConcreteColleageB::GetState(){
	return _sdt;
}

void ConcreteColleageB::SetState(const string& std){
	_sdt = std;
}

void ConcreteColleageB::Action(){
	_mdt->DoActionFromBtoA();
	cout<<"State of ConcreteColleageB:"<<" "<<this->GetState()<<endl;
}

