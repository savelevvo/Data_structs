#pragma once
#ifndef _STACK_H
#define _STACK_H

#include"Deque.h"

namespace mystruct
{
	template< typename T, typename C = deque<T> >
	class stack : private noiocmp
	{
	public:
		class empty_stack {};

		stack();
		~stack();

		/* Capacity */
		inline bool empty()const;
		inline size_t size()const;

		/* Modifiers */
		void push(T);
		T pop();

	private:
		C *st;

	};

	template< typename T, typename C = vector<T> >
	stack< T, C >::stack()
	{
		st = new C;
	}

	template< typename T, typename C = vector<T> >
	stack< T, C >::~stack()
	{
		st->~C();
	}

	/**
	* Returns whether the stack is empty: i.e. whether its size is zero.
	**/
	template< typename T, typename C = vector<T> >
	inline bool stack< T, C >::empty()const
	{
		return st->size() == 0;
	}

	/**
	* Returns the number of elements in the stack.
	**/
	template< typename T, typename C = vector<T> >
	inline size_t stack< T, C >::size()const
	{
		return st->size();
	}

	/**
	* Inserts a new element at the top of the stack. The content of this new element is initialized to a copy of _val.
	**/
	template< typename T, typename C = vector<T> >
	void stack< T, C >::push(T _val)
	{
		st->push_back(_val);
	}

	/**
	* Removes the element on top of the stack, effectively reducing its size by one.
	**/
	template< typename T, typename C = vector<T> >
	T stack< T, C >::pop()
	{
		if (st->size() == 0) throw empty_stack();
		return st->pop_back();
	}
}// namespace

#endif // !_STACK_H