/*************************************************************************
    > File Name: Factory.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月24日 星期六 22时13分25秒
 ************************************************************************/

#ifndef _FACTORY_H_
#define _FACTORY_H_

class Product;

class Factory{
	public:
		virtual ~Factory()=0;
		virtual Product* CreateProduct()=0;
	protected:
		Factory();
	private:
};

class ConcreteFactory:public Factory{
	public:
		~ConcreteFactory();
		ConcreteFactory();
		Product* CreateProduct();
	protected:
	private:
};
#endif 
