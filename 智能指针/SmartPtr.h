#pragma once

//template<class T>
//class SmartPtr
//{
//public:
//	// RAII
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//	}
//
//	
//	// 像指针一样使用SmartPtr类
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	void Printf()
//	{
//		SmartPtr<int> s1(new int(2));
//		SmartPtr s2(s1);
//		cout << get() << endl;
//	}
//
//	private:
//
//	SmartPtr(const SmartPtr& s)
//	{
//		cout << "SmartPtr(const SmartPtr& s)" << endl;
//	}
//
//	T* get()
//	{
//		return _ptr;
//	}
//
//T* _ptr;
//};
//
//
////模拟shared_ptr类使用静态成员计数
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
//
//	// sp2(sp1)
//	shared_ptr(const shared_ptr<T>& sp)
//	{
//		_ptr = sp._ptr;
//		++_count;
//	}
//
//	~shared_ptr()
//	{
//		if (--_count == 0)
//		{
//			cout << "delete:" << _ptr << endl;
//			delete _ptr;
//		}
//	}
//
//	int use_count()
//	{
//		return _count;
//	}
//
//	// 像指针一样
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//	static int _count;
//};
//
//
//struct ListNode
//{
//	int _val;
//
//	//④使得下面的n1->next = n2之类的操作不会因为双方类型不同导致无法互相赋值
//	//struct ListNode* _next;
//	//struct ListNode* _prev;
//			  //|
//			  //v
//	std::shared_ptr<ListNode> _next;
//	std::shared_ptr<ListNode> _prev;
//
//	ListNode(int val = 0)
//		:_val(val)
//	{}
//};
//
//// 不支持RAII，不参与资源管理
//template<class T>
//class weak_ptr
//{
//public:
//// RAII
//weak_ptr()
//	:_ptr(nullptr)
//{}
//
//weak_ptr(const shared_ptr<T>& sp)
//{
//	_ptr = sp.get();
//}
//
//weak_ptr<T>& operator=(const shared_ptr<T>& sp)
//{
//	_ptr = sp.get();
//	return *this;
//}
//
//// 像指针一样
//T& operator*()
//{
//	return *_ptr;
//}
//
//T* operator->()
//{
//	return _ptr;
//}
//
//private:
//T* _ptr;
//};


//#include <iostream>
//using namespace std;
//
//
//class Example {
//public:
//	Example() {};
//	//只声明不定义
//	Example(const Example& e);//拷贝构造
//	Example& operator=(const Example& e);//赋值重载
//};
//
//// 在类外部定义 拷贝构造 和 赋值重载
//Example::Example(const Example& e)
//{
//	cout << "Example(const Example& e)\n";
//}
//
//Example& Example::operator=(const Example& e)
//{
//	cout << "Example& Example::operator=(const Example& e)\n";
//	return *this;
//}



//Example::Example& operator= (const Example& e)
//{
//	cout << "Example(const Example& e)\n";
//}


class Example
{
public:
    //静态成员函数：可以直接通过类名调用，而不需要类的对象实例
    static Example* CreatObj()
    {
        return new Example;//在堆上new一个Example类型的匿名对象，并返回该对象的指针   
    }

private:

    Example() {};//默认构造函数
};