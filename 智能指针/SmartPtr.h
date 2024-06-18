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


struct ListNode
{
	int _val;

	//④使得下面的n1->next = n2之类的操作不会因为双方类型不同导致无法互相赋值
	//struct ListNode* _next;
	//struct ListNode* _prev;
			  //|
			  //v
	std::shared_ptr<ListNode> _next;
	std::shared_ptr<ListNode> _prev;

	ListNode(int val = 0)
		:_val(val)
	{}
};

int main()
{
	//①ListNode* n1 = new ListNode(10);
	//ListNode* n2 = new ListNode(20);
				   //|
				   //v
	std::shared_ptr<ListNode> n1 = ((new) ListNode(10);
	std::shared_ptr<ListNode> n2 = ((new) ListNode(20);

	//②中间可能出现抛异常    
		   //|
		   //v
	//不用担心抛异常了

	n1->next = n2;
	n2->prev = n1;

	//④delete n1;
	//delete n2;//此时不需要在这里delete了，在智能指针内部会delete

	return 0;
}