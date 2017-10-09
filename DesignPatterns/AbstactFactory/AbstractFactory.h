/*************************************************************************
    > File Name: AbstractFactory.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月25日 星期日 16时30分25秒
 ************************************************************************/

#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_
class AbstractProductA;
class AbstractProductB;
class AbstractFactory{
	public:
		virtual ~AbstractFactory();
		virtual AbstractProductA* CreateProductA()=0;
		virtual AbstractProductB* CreateProductB()=0;
	protected:
		AbstractFactory();
	private:
};

class ConcreteFactory1:public AbstractFactory{
	public:
		ConcreteFactory1();
		~ConcreteFactory1();
		AbstractProductA* CreateProductA();
		AbstractProductB* CreateProductB();
	protected:
	private:
};
class ConcreteFactory2:public AbstractFactory{
	public:
		ConcreteFactory2();
		~ConcreteFactory2();
		AbstractProductA* CreateProductA();
		AbstractProductB* CreateProductB();
	protected:
	private:
};
#endif
