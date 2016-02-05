#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;
using mystruct::vector;

int main()
{	
	vector<float> fv;
	fv.push_back(9.9F); fv.push_back(11.3F); fv.push_back(21.2F);
	
	try {
		cout << fv.at(-11) << endl;
	}
	catch (vector<float>::out_of_range){
		cout << "Out Of Range Exception" << endl;
	}
	
	/* List testing */
	// 55.56MB(11.35s)
	//for (int i = 0; i < 1000000; i++)
	//	l2.push_back(i * 2);

	// 55.92MB(7.76s)
	//for (int i = 0; i < 1000000; i++)
	//	l1.push_back(i * 2);

	return 0;
}