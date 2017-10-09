/*************************************************************************
    > File Name: FlyweightFactory.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月02日 星期一 14时32分40秒
 ************************************************************************/

#ifndef _FLYWEIGHTFACTORY_H_
#define _FLYWEIGHTFACTORY_H_
#include "Flyweight.h"
#include <string>
#include <vector>
using namespace std;
class FlyweightFactory{
	public:
		FlyweightFactory();
		~FlyweightFactory();
		Flyweight* GetFlyweight(const string& key);
	protected:
	private:
		vector<Flyweight*> _fly;
};
#endif
