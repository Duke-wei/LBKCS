/*************************************************************************
    > File Name: Product.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月24日 星期六 22时08分04秒
 ************************************************************************/

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product{
	public:
		virtual ~Product()=0;
	protected:
		Product();
	private:
};

class ConcreteProduct:public Product{
	public:
		~ConcreteProduct();
		ConcreteProduct();
	protected:
	private:
};

#endif
