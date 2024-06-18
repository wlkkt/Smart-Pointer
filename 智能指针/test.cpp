#include<iostream>
#include <memory>
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
