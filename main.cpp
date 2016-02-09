#include<iostream>
#include"Deque.h"
#include<cstring>
using std::cout;
using std::endl;


int main()
{
	mystruct::deque<int> dd;

	char *r = "hello";
	cout << r[1] << endl;

	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}