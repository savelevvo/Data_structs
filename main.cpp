#include<iostream>
#include<list>
#include"List.h"
#include"Queue.h"

using std::cout;
using std::endl;

int main()
{
	Queue<int> q1(2);
	Queue<int> q2(2);

	q1.push(10);
	q1.push(11);
	q2.push(10);
	q2.push(12);
	
	cout << (q1 == q1) << endl;
	//cout << q1.pop() << endl;
	
	List<int> l1;
	std::list<int> l2;

	// 4.6MB(1.23s)
	//for (int i = 0; i < 100000; i++)
	//	l2.push_back(i*2);


	// 4.2MB(0.92s)
	//for (int i = 0; i < 100000; i++)
	//	l1.add(i * 2);



	return 0;
}