#include<iostream>
using namespace std;

#include "SmartPtr.h"


int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

void Func()
{
	//创建一个int* 类型的智能指针
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(new int);


	*sp1 += 10;//像指针一样可以*
	
	SmartPtr<pair<string, int>> sp3(new pair<string, int>);//智能指针sp3指向得是一个pair类型的匿名对象
	sp3->first = "apple";
	sp3->second = 1;//等价于sp3.operator->()->second = 1;
		
	cout << div() << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}


//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？
//	int* p1 = new int;
//	int* p2 = new int;
//	cout << div() << endl;
//	delete p1;
//	delete p2;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


	//template<class T>
	//class shared_ptr
	//{
	//public:
	//	// RAII
	//	shared_ptr(T* ptr)
	//		:_ptr(ptr)
	//	{
	//		_count = 1;
	//	}

	//	// sp2(sp1)
	//	shared_ptr(const shared_ptr<T>& sp)
	//	{
	//		_ptr = sp._ptr;
	//		++_count;
	//	}

	//	~shared_ptr()
	//	{
	//		if (--_count == 0)
	//		{
	//			cout << "delete:" << _ptr << endl;
	//			delete _ptr;
	//		}
	//	}

	//	int use_count()
	//	{
	//		return _count;
	//	}

	//	// 像指针一样
	//	T& operator*()
	//	{
	//		return *_ptr;
	//	}

	//	T* operator->()
	//	{
	//		return _ptr;
	//	}
	//private:
	//	T* _ptr;

	//	// 也不行
	//	static int _count;
	//};

	//template<class T>
	//int shared_ptr<T>::_count = 0;