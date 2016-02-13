#include<iostream>
#include"include\String.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	mystruct::string s1("S1");
	mystruct::string s2("S2");
	s2 += "string";
	s2 += "0";
	s2 += s1;
	s2.push_back("_");
	s2.push_back((char)200);
	s2 = s2;


	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}