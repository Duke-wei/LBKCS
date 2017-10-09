/*************************************************************************
    > File Name: State.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月07日 星期六 11时09分32秒
 ************************************************************************/

#ifndef _STATE_H_
#define _STATE_H_
class Context;
class State{
	public:
		State();
		virtual ~State();
		virtual void OperationInterface(Context*)=0;
		virtual void OperationChangeState(Context*)=0;
	protected:
		bool ChangeState(Context* con,State* st);
	private:
		//bool ChangeState(Context* con,State* st);
};

class ConcreteStateA:public State{
	public:
		ConcreteStateA();
		virtual ~ConcreteStateA();
		virtual void OperationInterface(Context*);
		virtual void OperationChangeState(Context*);
	protected:
	private:
};
class ConcreteStateB:public State{
	public:
		ConcreteStateB();
		virtual ~ConcreteStateB();
		virtual void OperationInterface(Context*);
		virtual void OperationChangeState(Context*);
	protected:
	private:
};
#endif
