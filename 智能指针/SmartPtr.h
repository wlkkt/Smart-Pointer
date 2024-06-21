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
//	// ��ָ��һ��ʹ��SmartPtr��
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
////ģ��shared_ptr��ʹ�þ�̬��Ա����
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
//	// ��ָ��һ��
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
//	//��ʹ�������n1->next = n2֮��Ĳ���������Ϊ˫�����Ͳ�ͬ�����޷����ำֵ
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
//// ��֧��RAII����������Դ����
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
//// ��ָ��һ��
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
//	//ֻ����������
//	Example(const Example& e);//��������
//	Example& operator=(const Example& e);//��ֵ����
//};
//
//// �����ⲿ���� �������� �� ��ֵ����
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
    //��̬��Ա����������ֱ��ͨ���������ã�������Ҫ��Ķ���ʵ��
    static Example* CreatObj()
    {
        return new Example;//�ڶ���newһ��Example���͵��������󣬲����ظö����ָ��   
    }

private:

    Example() {};//Ĭ�Ϲ��캯��
};