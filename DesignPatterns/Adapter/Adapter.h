/*************************************************************************
    > File Name: Adapter.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月30日 星期五 10时29分08秒
 ************************************************************************/

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

class Target{
	public:
		Target();
		virtual ~Target();
		virtual void Request();
	protected:
	private:
};

class Adaptee{
	public:
		Adaptee();
		~Adaptee();
		void SpecificRequest();
	protected:
	private:
};

class Adapter:public Target{
	public:
		Adapter(Adaptee* ade);
		~Adapter();
		void Request();
	protected:
	private:
		Adaptee* _ade;
};
#endif
