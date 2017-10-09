/*************************************************************************
    > File Name: Abstraction.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月29日 星期四 11时09分04秒
 ************************************************************************/

#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_
class AbstractionImp;

class Abstraction{
	public:
		virtual ~Abstraction();
		virtual void Operation()=0;
	protected:
		Abstraction();
	private:
};

class RefinedAbstraction:public Abstraction{
	public:
		RefinedAbstraction(AbstractionImp* imp);
		~RefinedAbstraction();
		void Operation();
	protected:
	private:
		AbstractionImp* _imp;
};
#endif
