#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H

namespace mystruct
{
	template<typename T>
	class vector
	{
	public:
		class out_of_range {};
		vector(int = 1);
		~vector();
		vector<T> & operator=(const vector<T> &);

		size_t size()const { return sz; }
		void resize(size_t);// Change size 
		size_t capacity()const { return cap; }
		bool empty()const { return sz == 0; }
		void reserve(size_t);// Request a change in capacity 

		T & operator[](int);
		T & at(int);// signals if the requested position is out of range by throwing an out_of_range exception
		T & front();// first element
		T & back(); // last element

		void push_back(const T &);
		T & pop_back();
		void swap(vector<T> &);

	private:
		size_t sz;
		size_t cap;
		T *arr;
	};

	template<typename T>
	vector<T>::vector(int _sz = 1)
	{
		sz = _sz;
		arr = new T[sz];


	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] arr;
	}

	template<typename T>
	void vector<T>::push_back(const T &_val)
	{

	}
}// namespace

#endif // !_VECTOR_H