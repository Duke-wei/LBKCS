/*************************************************************************
    > File Name: Director.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月27日 星期二 20时14分12秒
 ************************************************************************/

#include "Director.h"
#include "Builder.h"

Director::Director(Builder* bld){
	_bld = bld;
}

Director::~Director(){

}

void Director::Construct(){
	_bld->BuilderA("user-defined");
	_bld->BuilderB("user-defined");
	_bld->BuilderC("user-defined");
}
