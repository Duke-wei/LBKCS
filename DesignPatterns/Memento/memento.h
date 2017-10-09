/*************************************************************************
    > File Name: memento.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月09日 星期一 10时30分36秒
 ************************************************************************/

#ifndef _MEMENTO_H_
#define _MEMENTO_H_
#include <string>
using namespace std;
class Memento;
class Originator{
	public:
		typedef string State;
		Originator();
		~Originator();
		Originator(const State& std);
		Memento* CreateMemento();
		void SetMemento(Memento* men);
		void RestoreToMemento(Memento* mt);
		State GetState();
		void SetState(const State& std);
		void PrintState();
	protected:
	private:
		State _sdt;
		Memento* _mt;
};
class Memento{
	public:
	protected:
	private:
		friend class Originator;
		typedef string State;
		Memento();
		Memento(const State& sdt);
		~Memento();
		void SetState(const State& sdt);
		State GetState();
	private:
		State _sdt;
};
#endif
