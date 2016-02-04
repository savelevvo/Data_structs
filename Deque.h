#pragma once
#ifndef _DEQUE_H
#define _DQEUE_H

#include<iostream>
#include"Vector.h"

namespace mystruct
{
	template<typename T>
	class deque
	{
	public:
		class Emptydeque {};
		class out_of_range {};

		deque(int);
		deque(const deque<T> &);
		~deque();
		deque<T> & operator= (const deque<T> &);

		/* Capacity */
		inline size_t size()const;
		void resize(size_t, T = 0);
		inline bool empty()const;

		/* Element access */
		T & operator[](unsigned)const;
		T & at(unsigned)const;
		T & front()const;
		T & back()const;

		/* Modifiers */
		void push_back(T);
		void push_front(T);
		T & pop_back();
		T & pop_front();

	private:
		size_t sz;
		vector<T> *arr;
		int head;
		int tail;
		size_t count;

		std::ostream & operator<< (std::ostream &)const;
		std::istream & operator>> (std::istream &);
		bool operator< (const deque<T> &)const;
		bool operator<=(const deque<T> &)const;
		bool operator> (const deque<T> &)const;
		bool operator>=(const deque<T> &)const;
		bool operator==(const deque<T> &)const;
		bool operator!=(const deque<T> &)const;
	};

	template<typename T>
	deque<T>::deque(int size)
	{
		tail = head = 0;
		count = 0;
		sz = size;
		//arr = new T[sz];
	}

	template<typename T>
	deque<T>::deque(const deque<T> &rhs)
	{

	}

	template<typename T>
	deque<T>::~deque()
	{
		delete[] arr;
	}

	
	/**
	* Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
	**/
	template<typename T>
	deque<T> & deque<T>::operator= (const deque<T> &rhs)
	{

	}

	/**
	* Returns the number of elements in the deque container.
	**/
	template<typename T>
	inline size_t deque<T>::size()const
	{

	}

	/**
	* Resizes the container so that it contains _n elements.
	**/
	template<typename T>
	void deque<T>::resize(size_t _n, T _val = 0)
	{

	}

	/**
	*
	**/
	template<typename T>
	inline bool deque<T>::empty()const
	{

	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::operator[](unsigned _val)const
	{
		
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::at(unsigned _val)const
	{
	
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::front()const
	{
	
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::back()const
	{

	}

	/**
	*
	**/
	template<typename T>
	void deque<T>::push_back(T _val)
	{
		arr[tail] = _val;
		tail < sz - 1 ? tail++ : head = tail = 0;
		count++;
	}

	/**
	*
	**/
	template<typename T>
	void deque<T>::push_front(T _val)
	{
	
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::pop_back()
	{
		if (head >= sz) throw InvalidRange();
		if (0 == count) throw Emptydeque();
		count--;
		return arr[head++];
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::pop_front()
	{
	
	}
}// namespace

#endif // !_DEQUE_H