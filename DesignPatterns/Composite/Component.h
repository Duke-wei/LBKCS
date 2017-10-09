/*************************************************************************
    > File Name: Component.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月01日 星期日 12时35分06秒
 ************************************************************************/

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class Component{
	public:
		Component();
		virtual ~Component();
		virtual void Operation()=0;
		virtual void Add(const Component&);
		virtual void Remove(const Component&);
		virtual Component* GetChild(int);
	protected:
	private:
};
#endif
