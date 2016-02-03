#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;
using mystruct::vector;

void getVectorInfo(const vector<int> &_v)
{
	cout << "Size: " << _v.size() << endl;
	cout << "Capacity: " << _v.capacity() << endl;

	size_t vsize = _v.size();
	cout << "Vector: ";
	for (unsigned i = 0; i < vsize; i++)
		cout << _v[i] << " ";
	cout << endl << "------------------" << endl;
}

int main()
{	
	vector<int> v1, v2;
	v1.push_back(100);
	v2.push_back(9999); v2.push_back(8888);

	v1.swap(v2);
	//v1 = v2;
	getVectorInfo(v1);
	getVectorInfo(v2);
	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}