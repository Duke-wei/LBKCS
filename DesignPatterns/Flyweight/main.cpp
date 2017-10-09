/*************************************************************************
    > File Name: main.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月02日 星期一 14时43分11秒
 ************************************************************************/
#include "Flyweight.h"
#include "FlyweightFactory.h"
#include<iostream>
using namespace std;

int main(){
	FlyweightFactory* fc = new FlyweightFactory();
	Flyweight* fw1 = fc->GetFlyweight("hello");
	Flyweight* fw2 = fc->GetFlyweight("world");
	Flyweight* fw3 = fc->GetFlyweight("hello");

	return 0;
}

