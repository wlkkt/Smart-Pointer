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


	// ��ָ��һ��ʹ��SmartPtr��
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


//ģ��shared_ptr��ʹ�þ�̬��Ա����
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

	// ��ָ��һ��
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

	//��ʹ�������n1->next = n2֮��Ĳ���������Ϊ˫�����Ͳ�ͬ�����޷����ำֵ
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
	//��ListNode* n1 = new ListNode(10);
	//ListNode* n2 = new ListNode(20);
				   //|
				   //v
	std::shared_ptr<ListNode> n1 = ((new) ListNode(10);
	std::shared_ptr<ListNode> n2 = ((new) ListNode(20);

	//���м���ܳ������쳣    
		   //|
		   //v
	//���õ������쳣��

	n1->next = n2;
	n2->prev = n1;

	//��delete n1;
	//delete n2;//��ʱ����Ҫ������delete�ˣ�������ָ���ڲ���delete

	return 0;
}