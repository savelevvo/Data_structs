#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H

template<typename T>
class Vector
{
public:
	Vector();
	~Vector();

	size_t size() { return sz; }
	bool empty() { return sz == 0; }

	void push_back(const T &);
	T & pop_back();
	void swap(Vector<T> &);

private:
	size_t sz;
	size_t cap;
	T *arr;

};

template<typename T>
Vector<T>::Vector()
{
	sz = 1;
	arr = new T[sz];


}

template<typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

template<typename T>
void Vector<T>::push_back(const T &_val)
{

}

#endif