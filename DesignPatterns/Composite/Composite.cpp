/*************************************************************************
    > File Name: Composite.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月01日 星期日 12时43分40秒
 ************************************************************************/

#include "Component.h"
#include "Composite.h"

#define NULL 0

Composite::Composite(){
	vector<Component*>::iterator itend = comVec.begin();
}

Composite::~Composite(){

}

void Composite::Operation(){
	vector<Component*>::iterator comIter = comVec.begin();
	for(;comIter!=comVec.end();comIter++){
		(*comIter)->Operation();
	}
}

void Composite::Add(Component* com){
	comVec.push_back(com);
}

void Composite::Remove(Component* com){
	comVec.erase(&com);
}

Component* Composite::GetChild(int index){
	return comVec[index];
}
