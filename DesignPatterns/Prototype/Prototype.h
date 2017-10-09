/*************************************************************************
    > File Name: Prototype.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月28日 星期三 13时14分19秒
 ************************************************************************/

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_
class Prototype{
	public:
		virtual ~Prototype();
		virtual Prototype* Clone() const = 0;
	protected:
		Prototype();
	private:
};

class ConcretePrototype:public Prototype{
	public:
		ConcretePrototype();
		~ConcretePrototype();
		ConcretePrototype(const ConcretePrototype& cp);
		Prototype* Clone() const;
	protected:
	private:
};
#endif
