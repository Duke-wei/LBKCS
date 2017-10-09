/*************************************************************************
    > File Name: Abstraction.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月29日 星期四 11时26分42秒
 ************************************************************************/

#include "Abstraction.h"
#include "AbstractionImp.h"

#include <iostream>
using namespace std;

Abstraction::Abstraction(){

}

Abstraction::~Abstraction(){

}

RefinedAbstraction::RefinedAbstraction(AbstractionImp * imp){
	_imp = imp;
}

RefinedAbstraction::~RefinedAbstraction(){

}

void RefinedAbstraction::Operation(){
	_imp->Operation();
}
