/*************************************************************************
    > File Name: subject.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月08日 星期日 10时08分22秒
 ************************************************************************/
#include "subject.h"
#include "observer.h"
#include <list>
#include <iostream>
using namespace std;
typedef string State;

Subject::Subject(){
	_obvs = new list<Observer*>;

}

Subject::~Subject(){

}

void Subject::Attach(Observer* obv){
	_obvs->push_front(obv);
}

void Subject::Detach(Observer* obv){
	if(obv != NULL)
		_obvs->remove(obv);
}

void Subject::Notify(){
	list<Observer*>::iterator it;
	it = _obvs->begin();
	for(;it!=_obvs->end();it++){
		(*it)->Update(this);
	}
}

ConcreteSubject::ConcreteSubject(){
	_st = '\0';
}
ConcreteSubject::~ConcreteSubject(){

}

State ConcreteSubject::GetState(){
	return _st;
}
void ConcreteSubject::SetState(const State& st){
	_st = st;
}
