/*************************************************************************
    > File Name: Builder.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月27日 星期二 20时03分33秒
 ************************************************************************/

#ifndef _BUILDER_H_
#define _BUILDER_H_
#include<string>
using namespace std;
class Product;
class Builder{
	public:
		virtual ~Builder();
		virtual void BuilderA(const string& buildPara)=0;
		virtual void BuilderB(const string& buildPara)=0;
		virtual void BuilderC(const string& buildPara)=0;
		virtual Product* GetProduct()=0;
	protected:
		Builder();
	private:

};

class ConcreteBuilder:public Builder{
	public:
		ConcreteBuilder();
		~ConcreteBuilder();
		void BuildPartA(const string&buildPara);
		void BuildPartB(const string&buildPara);
		void BuildPartC(const string&buildPara);
		Product* GetProduct();
	protected:
	private:
};

#endif
