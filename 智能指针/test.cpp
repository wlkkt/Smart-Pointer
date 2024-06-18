#include<iostream>
#include <memory>
using namespace std;

#include "SmartPtr.h"


int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");

	return a / b;
}

void Func()
{
	//����һ��int* ���͵�����ָ��
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(new int);


	*sp1 += 10;//��ָ��һ������*
	
	SmartPtr<pair<string, int>> sp3(new pair<string, int>);//����ָ��sp3ָ�����һ��pair���͵���������
	sp3->first = "apple";
	sp3->second = 1;//�ȼ���sp3.operator->()->second = 1;
		
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
//		throw invalid_argument("��0����");
//	return a / b;
//}
//
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ�
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�
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
