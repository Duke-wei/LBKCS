/*************************************************************************
    > File Name: Template.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月05日 星期四 10时41分04秒
 ************************************************************************/

#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
class AbstractClass{
	public:
		virtual ~AbstractClass();
		void TemplateMethod();
	protected:
		virtual void PrimitiveOperation1()=0;
		virtual void PrimitiveOperation2()=0;
		AbstractClass();
	private:
};

class ConcreteClass1:public AbstractClass{
	public:
		ConcreteClass1();
		~ConcreteClass1();
		protected:
		void PrimitiveOperation1();
		void PrimitiveOperation2();
		private:
};

class ConcreteClass2:public AbstractClass{
	public:
		ConcreteClass2();
		~ConcreteClass2();
	protected:
		void PrimitiveOperation1();
		void PrimitiveOperation2();
	private:
};
#endif
