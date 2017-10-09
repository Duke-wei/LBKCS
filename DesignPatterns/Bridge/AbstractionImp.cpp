/*************************************************************************
    > File Name: AbstractionImp.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月29日 星期四 11时20分47秒
 ************************************************************************/
#include "AbstractionImp.h"
#include<iostream>
using namespace std;

AbstractionImp::AbstractionImp(){

}

AbstractionImp::~AbstractionImp(){

}

void AbstractionImp::Operation(){
	cout<<"AbstractionImp...imp..."<<endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA(){

}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA(){

}

void ConcreteAbstractionImpA::Operation(){
	cout<<"ConcreteAbstractionImpA..."<<endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB(){

}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB(){

}

void ConcreteAbstractionImpB::Operation{
	cout<<"ConcreteAbstractionImpB..."<<endl;
}

