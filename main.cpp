#include<iostream>
#include<list>
#include"list.h"
#include"Stack.h"

using std::cout;
using std::endl;

//  TODO:
//  List.h
//	  push_front();
//	  pop_back(); pop_front();
//  Stack.h
//    push(); pop();

int main()
{	
	Stack<int> st(3);
	st.push(10); st.push(20); st.push(30);
	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.pop() << endl;


	// 4.6MB(1.23s)
	//for (int i = 0; i < 100000; i++)
	//	l2.push_back(i*2);

	// 4.2MB(0.82s)
	//for (int i = 0; i < 100000; i++)
	//	l1.add(i * 2);

	return 0;
}