/*************************************************************************
    > File Name: FlyweightFactory.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月02日 星期一 14时40分09秒
 ************************************************************************/

#include "FlyweightFactory.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

FlyweightFactory::FlyweightFactory(){

}

FlyweightFactory::~FlyweightFactory(){

}

Flyweight* FlyweightFactory::GetFlyweight(const string& key){
	vector<Flyweight*>::iterator it = _fly.begin();
	for(;it!=_fly.end();++it){
		if((*it)->GetIntrinsicState()==key){
			cout<<"already creted "<<endl;
			return *it;
		}
	}
	Flyweight* fn = new ConcreteFlyweight(key);
	_fly.push_back(fn);
	return fn;
}
