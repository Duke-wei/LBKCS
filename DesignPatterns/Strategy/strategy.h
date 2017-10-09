/*************************************************************************
    > File Name: strategy.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月06日 星期五 11时18分52秒
 ************************************************************************/

#ifndef _STRATEGY_H_
#define _STRATEGY_H_
class Strategy{
	public:
		Strategy();
		virtual ~Strategy();
		virtual void AlgrithmInterface()=0;
	protected:
	private:
};

class ConcreteStrategyA:public Strategy{
	public:
		ConcreteStrategyA();
		virtual ~ConcreteStrategyA();
		void AlgrithmInterface();
	protected:
	private:
};

class ConcreteStrategyB:public Strategy{
	public:
		ConcreteStrategyB();
		virtual ~ConcreteStrategyB();
		void AlgrithmInterface();
	protected:
	private:
};
#endif
