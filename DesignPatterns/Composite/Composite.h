/*************************************************************************
    > File Name: Composite.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月01日 星期日 12时37分28秒
 ************************************************************************/

#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "Component.h"
#include <vector>
using namespace std;

class Composite:public Component{
	public:
		Composite();
		~Composite();

		void Operation();
		void Add(Component* com);
		void Remove(Component* com);
		Component* GetChild(int index);
	protected:
	private:
		vector<Component*> comVec;
};
#endif
