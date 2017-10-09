/*************************************************************************
    > File Name: Director.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月27日 星期二 20时12分40秒
 ************************************************************************/

#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
class Builder;
class Director{
	public:
		Director(Builder* bld);
		~Director();
		void Construct();
	protected:
	private:
		Builder* _bld;
};
#endif
