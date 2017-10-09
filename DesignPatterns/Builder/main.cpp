/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月27日 星期二 20时16分42秒
 ************************************************************************/
#include "Builder.h"
#include "Product.h"
#include "Director.h"

#include<iostream>
using namespace std;

int main(){
	Director* d = new Director(new ConcreteBuilder());
	d->Construct();
	return 0;
}

