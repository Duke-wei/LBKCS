/*************************************************************************
    > File Name: colleage.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月10日 星期二 10时27分49秒
 ************************************************************************/

#ifndef _COLLEAGE_H_
#define _COLLEAGE_H_
#include<string>
using namespace std;
class Mediator;
class Colleage{
	public:
		virtual ~Colleage();
		virtual void Action()=0;
		virtual void SetState(const string& sdt) = 0;
		virtual string GetState()=0;
	protected:
		Colleage();
		Colleage(Mediator* mdt);
		Mediator* _mdt;
	private:
};
class ConcreteColleageA:public Colleage{
	public:
		ConcreteColleageA();
		ConcreteColleageA(Mediator* mdt);
		~ConcreteColleageA();
		void Action();
		void SetState(const string& sdt);
		string GetState();
	protected:
	private:
		string _sdt;
};
class ConcreteColleageB:public Colleage{
	public:
		ConcreteColleageB();
		ConcreteColleageB(Mediator* mdt);
		~ConcreteColleageB();
		void Action();
		void SetState(const string& sdt);
		string GetState();
	protected:
	private:
		string _sdt;
};
#endif
