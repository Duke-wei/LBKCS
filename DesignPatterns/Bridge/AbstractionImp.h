/*************************************************************************
    > File Name: AbstractionImp.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月29日 星期四 11时12分24秒
 ************************************************************************/

#ifndef _ABSTRACTIONIMP_H_
#define _ABSTRACTIONIMP_H_

class AbstractionImp{
	public:
		virtual ~AbstractionImp();
		virtual void Operation()=0;
	protected:
		AbstractionImp();
	private:
};

class ConcreteAbstractionImpA:public AbstractionImp{
	public:
		ConcreteAbstractionImpA();
		~ConcreteAbstractionImpA();
		virtual void Operation();
	protected:
	private:
};

class ConcreteAbstractionImpB:public AbstractionImp{
	public:
		ConcreteAbstractionImpB();
		~ConcreteAbstractionImpB();
		virtual void Operation();
	protected:
	private:
};
#endif
