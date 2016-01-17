#include<iostream>
#include<list>
#include"DLList.h"

using std::cout;
using std::endl;

// TODO:
//	push_back(); push_front();
//	pop_back(); pop_front();

int main()
{	
	DLList<int> dl1(10), dl2;
	
	//std::list<int> l2;
	
	dl1 = dl2;
	
	




	// 4.6MB(1.23s)
	//for (int i = 0; i < 100000; i++)
	//	l2.push_back(i*2);

	// 4.2MB(0.82s)
	//for (int i = 0; i < 100000; i++)
	//	l1.add(i * 2);

	return 0;
}