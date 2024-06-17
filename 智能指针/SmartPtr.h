#pragma once

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}


	// 像指针一样使用SmartPtr类
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}


private:
	T* _ptr;
};


//模拟shared_ptr类使用静态成员计数
template<class T>
class shared_ptr
{
public:
	// RAII
	shared_ptr(T* ptr)
		:_ptr(ptr)
	{
		_count = 1;
	}

	// sp2(sp1)
	shared_ptr(const shared_ptr<T>& sp)
	{
		_ptr = sp._ptr;
		++_count;
	}

	~shared_ptr()
	{
		if (--_count == 0)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}
	}

	int use_count()
	{
		return _count;
	}

	// 像指针一样
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	static int _count;
};

