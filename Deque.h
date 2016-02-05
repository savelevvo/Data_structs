#pragma once
#ifndef _DEQUE_H
#define _DQEUE_H

#include<iostream>
#include"Vector.h"
using mystruct::vector;

namespace mystruct
{
	template<typename T>
	class deque
	{
	public:
		class empty_deque {};
		class out_of_range {};

		deque();
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
		size_t count;
		unsigned head;
		unsigned tail;
		vector<T> *arr;

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
	deque<T>::deque()
	{
		tail = head = 0;
		count = 0;
		arr = new vector<T>;
		sz = 0;
	}

	template<typename T>
	deque<T>::deque(const deque<T> &rhs)
	{

	}

	template<typename T>
	deque<T>::~deque()
	{
		arr->~vector();
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
		return sz;
	}

	/**
	* Resizes the container so that it contains _n elements.
	**/
	template<typename T>
	void deque<T>::resize(size_t _n, T _val = 0)
	{

	}

	/**
	* Returns whether the deque container is empty (i.e. whether its size is 0).
	* This function does not modify the container in any way.
	**/
	template<typename T>
	inline bool deque<T>::empty()const
	{
		return sz == 0;
	}

	/**
	* Returns a reference to the element at position n in the deque container.
	* A similar member function, deque::at, has the same behavior as this operator function, except that deque::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range exception.
	**/
	template<typename T>
	T & deque<T>::operator[](unsigned _val)const
	{
		return arr[_val];
	}

	/**
	* Returns a reference to the element at position n in the deque container object.
	* The function automatically checks whether _val is within the bounds of valid elements in the container, throwing an out_of_range exception if it is not (i.e., if n is greater or equal than its size). This is in contrast with member operator[], that does not check against bounds.
	* Returns a reference to the element at position _val in the deque container object.

	**/
	template<typename T>
	T & deque<T>::at(unsigned _val)const
	{
		if (_val < 0 || _val > sz - 1) throw out_of_range();
		return arr[_val];
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::front()const
	{
		return arr[0];
	}

	/**
	*
	**/
	template<typename T>
	T & deque<T>::back()const
	{
		return arr[sz - 1];
	}

	/**
	*
	**/
	template<typename T>
	void deque<T>::push_back(T _val)
	{
		arr->push_back(_val);
		sz++;
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
		sz--;
		return arr->pop_back();
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