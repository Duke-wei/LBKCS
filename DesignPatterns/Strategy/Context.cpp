/*************************************************************************
    > File Name: Context.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月06日 星期五 12时13分46秒
 ************************************************************************/
#include "Context.h"
#include "strategy.h"
#include<iostream>
using namespace std;
Context::Context(Strategy* stg){
	_stg = stg;
}

Context::~Context(){
	if(!_stg){
		delete _stg;
	}
}

void Context::DoAction(){
	_stg->AlgrithmInterface();
}
