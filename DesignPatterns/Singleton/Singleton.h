/*************************************************************************
    > File Name: Singleton.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月26日 星期一 22时11分49秒
 ************************************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton{
	public:
		static Singleton* Instance();
		~Singleton(){
			if(_instance != 0) delete _instance;
		}
	protected:
		Singleton();
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	private:
		static Singleton* _instance;
};
#endif
