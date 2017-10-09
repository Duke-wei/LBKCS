/*************************************************************************
    > File Name: Proxy.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月04日 星期三 10时36分38秒
 ************************************************************************/

#ifndef _PROXY_H_
#define _PROXY_H_
class Subject{
	public:
		virtual ~Subject();
		virtual void Request()=0;
	protected:
		Subject();
	private:
};

class ConcreteSubject:public Subject{
	public:
		ConcreteSubject();
		~ConcreteSubject();
		void Request();
	protected:
	private:
};

class Proxy{
	public:
		Proxy();
		Proxy(Subject* sub);
		~Proxy();
		void Request();
	protected:
	private:
		Subject* _sub;
};
#endif
