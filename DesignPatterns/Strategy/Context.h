/*************************************************************************
    > File Name: Context.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月06日 星期五 12时11分26秒
 ************************************************************************/

#ifndef _CONTEXT_H_
#define _CONTEXT_H_
class Strategy;
class Context{
	public:
		Context(Strategy* stg);
		~Context();
		void DoAction();
	protected:
	private:
		Strategy* _stg;
};
#endif
