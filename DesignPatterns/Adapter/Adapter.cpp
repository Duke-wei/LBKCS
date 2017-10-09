/*************************************************************************
    > File Name: Adapter.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月30日 星期五 10时31分52秒
 ************************************************************************/

#include<iostream>
#include "Adapter.h"

using namespace std;

Target::Target(){

}
Target::~Target(){

}

void Target::Request(){
	std::cout<<"Target::Request"<<std::endl;
}

Adaptee::Adaptee(){

}

Adaptee::~Adaptee(){
	
}

void Adaptee::SpecificRequest(){
	std::cout<<"Adaptee::SpecificRequest"<<std::endl;
}

Adapter::Adapter(Adaptee* ade){
	this->_ade = ade;
}

Adapter::~Adapter(){

}

void Adapter::Request(){
	_ade->SpecificRequest();
}
