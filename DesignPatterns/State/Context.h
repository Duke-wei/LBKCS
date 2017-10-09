/*************************************************************************
    > File Name: Context.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月07日 星期六 11时14分01秒
 ************************************************************************/

#ifndef _CONTEXT_H_
#define _CONTEXT_H_
class State;
class Context{
	public:
		Context();
		Context(State* state);
		~Context();
		void OprationInterface();
		void OperationChangState();
	protected:
	private:
		friend class State;
		bool ChangeState(State* state);
		State* _state;
};
#endif
