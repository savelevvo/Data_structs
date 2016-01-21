#include<iostream>
#include<list>
#include"List.h"

using std::cout;
using std::endl;

//  TODO:
//  Stack.h
//    push(); pop();

int main()
{	

	List<int> l1;
	//std::list<int> l2;



	l1.push_back(10); l1.push_back(11); l1.push_back(12);
	l1.push_front(13); l1.push_front(14); l1.push_front(15);

	l1.pop_back(); l1.pop_back();
	l1.pop_front(); l1.pop_front();

	//l1.display();


	
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}