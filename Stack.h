#pragma once
#ifndef _STACK_H
#define _STACK_H

#include<iostream>
#include "Vector.h"
using mystruct::vector;

namespace mystruct
{
	template<typename T>
	class stack
	{
	public:
		class EmptyStack {};

		stack();
		~stack();

		/* Capacity */
		inline bool empty()const;
		inline size_t size()const;

		/* Modifiers */
		void push(T);
		T pop();

	private:
		vector<T> *st;
		size_t sz;

		std::ostream & operator<< (std::ostream &)const;
		std::istream & operator>> (std::istream &);
		stack<T> & operator= (const stack<T> &);
		bool operator==(const stack<T> &)const;
		bool operator!=(const stack<T> &)const;
		bool operator< (const stack<T> &)const;
		bool operator<=(const stack<T> &)const;
		bool operator> (const stack<T> &)const;
		bool operator>=(const stack<T> &)const;
	};

	template<typename T>
	stack<T>::stack()
	{
		sz = 0;
		st = new vector<T>;
	}

	template<typename T>
	stack<T>::~stack()
	{
		st->~vector();
	}

	/**
	* Returns whether the stack is empty: i.e. whether its size is zero.
	**/
	template<typename T>
	inline bool stack<T>::empty()const
	{
		return sz == 0;
	}

	/**
	* Returns the number of elements in the stack.
	**/
	template<typename T>
	inline size_t stack<T>::size()const
	{
		return sz;
	}

	/**
	* Inserts a new element at the top of the stack. The content of this new element is initialized to a copy of _val.
	**/
	template<typename T>
	void stack<T>::push(T _val)
	{
		st->push_back(_val);
		sz++;
	}

	/**
	* Removes the element on top of the stack, effectively reducing its size by one.
	**/
	template<typename T>
	T stack<T>::pop()
	{
		if (sz == 0) throw EmptyStack();
		sz--;
		return st->pop_back();
	}
}// namespace

#endif // !_STACK_H