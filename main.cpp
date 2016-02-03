#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;
using mystruct::vector;

void getVectorInfo(const vector<int> &_v, bool display = true)
{
	cout << "Size: " << _v.size() << endl;
	cout << "Capacity: " << _v.capacity() << endl;
	if (display)
	{
		size_t vsize = _v.size();
		cout << "Vector: ";
		for (unsigned i = 0; i < vsize; i++)
			cout << _v[i] << " ";
		cout << endl;
	}
	cout << "------------------" << endl;
}

int main()
{	
	vector<int> v1;

	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}