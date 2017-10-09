/*************************************************************************
    > File Name: Flyweight.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月02日 星期一 14时34分39秒
 ************************************************************************/
#include "Flyweight.h"
#include<iostream>

using namespace std;

Flyweight::Flyweight(string intrinsicState){
	this->_intrinsicState = intrinsicState;
}

Flyweight::~Flyweight(){

}

void Flyweight::Operation(const string& extrinsicState){

}

string Flyweight::GetIntrinsicState(){
	return this->_intrinsicState;
}

ConcreteFlyweight::ConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState){
	cout<<"ConcreteFlyeweight Build..."<<intrinsicState<<endl;
}

ConcreteFlyweight::~ConcreteFlyweight(){

}

void ConcreteFlyweight::Operation(const string& extrinsicState){
	cout<<"ConcreteFlyweight:inside ["<<this->GetIntrinsicState()<<"] outside ["<<extrinsicState<<"]"<<endl;
}
