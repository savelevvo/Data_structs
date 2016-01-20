#include<iostream>
#include<list>
#include"List.h"

using std::cout;
using std::endl;

//  TODO:
//  List.h
//	  pop_back(); pop_front();
//  Stack.h
//    push(); pop();

int main()
{	
	List<int> list;
	list.push_back(10); list.push_back(11);
	list.push_back(12); list.push_back(13);
	
	list.push_front(9);	list.push_front(8);

	list.display();

	// 4.6MB(1.23s)
	//for (int i = 0; i < 100000; i++)
	//	l2.push_back(i*2);

	// 4.2MB(0.82s)
	//for (int i = 0; i < 100000; i++)
	//	l1.add(i * 2);

	return 0;
}