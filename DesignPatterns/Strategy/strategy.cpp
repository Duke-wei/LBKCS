/*************************************************************************
    > File Name: strategy.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月06日 星期五 11时21分59秒
 ************************************************************************/

#include "strategy.h"
#include <iostream>
using namespace std;
Strategy::Strategy(){

}

Strategy::~Strategy(){
	cout<<"~Strategy..."<<endl;
}

void Strategy::AlgrithmInterface(){

}

ConcreteStrategyA::ConcreteStrategyA(){

}

ConcreteStrategyA::~ConcreteStrategyA(){
	cout<<"~ConcreteStrategyA..."<<endl;
}

void ConcreteStrategyA::AlgrithmInterface(){
	cout<<"AlgrithmInterface...A"<<endl;
}


ConcreteStrategyB::ConcreteStrategyB(){

}

ConcreteStrategyB::~ConcreteStrategyB(){
	cout<<"~ConcreteStrategyA..."<<endl;
}

void ConcreteStrategyB::AlgrithmInterface(){
	cout<<"AlgrithmInterface...B"<<endl;
}

