#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;
using mystruct::vector;

int main()
{	
	vector<int> v1;

	cout << "Size: " << v1.size() << endl;
	cout << "Capacity: " << v1.capacity() << endl;

	size_t vsize = v1.size();
	for (unsigned i = 0; i < vsize; i++)
		cout << v1[i] << " ";
	cout << endl;
	
	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}