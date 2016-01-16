#include<iostream>
#include<list>
#include"SLList.h"

using std::cout;
using std::endl;

int main()
{	
	SLList<int> l1, l2;
	//std::list<int> l2;
	
	// 4.6MB(1.23s)
	//for (int i = 0; i < 100000; i++)
	//	l2.push_back(i*2);

	// 4.2MB(0.92s -> 0.82s)
	//for (int i = 0; i < 100000; i++)
	//	l1.add(i * 2);

	return 0;
}