/*************************************************************************
    > File Name: observer.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月08日 星期日 10时29分20秒
 ************************************************************************/

#include<iostream>
#include "subject.h"
#include "observer.h"
#include <string>
using namespace std;
Observer::Observer(){
	_st = '\0';
}

Observer::~Observer(){

}

ConcreteObserverA::ConcreteObserverA(Subject* sub){
	_sub = sub;
	_sub->Attach(this);
}
ConcreteObserverA::~ConcreteObserverA(){
	_sub->Detach(this);
	if(_sub != 0)
		delete _sub;
}

Subject* ConcreteObserverA::GetSubject(){
	return _sub;
}

void ConcreteObserverA::PrintInfo(){
	cout<<"ConcreteObserverA observer..."<<_sub->GetState()<<endl;
}

void ConcreteObserverA::Update(Subject* sub){
	_st = sub->GetState();
	PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject* sub){
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB(){
	_sub->Detach(this);
	if(_sub != 0)
		delete _sub;
}

Subject* ConcreteObserverB::GetSubject(){
	return _sub;
}

void ConcreteObserverB::PrintInfo(){
	cout<<"ConcreteObserverA observer..."<<_sub->GetState()<<endl;
}

void ConcreteObserverB::Update(Subject* sub){
	_st = sub->GetState();
	PrintInfo();
}
