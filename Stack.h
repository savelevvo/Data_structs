#pragma once
#ifndef _STACK_H
#define _STACK_H

#include<iostream>

namespace mystruct
{
	template<typename T>
	class stack
	{
	public:
		class EmptyStack {};
		class FullStack{};
		stack(size_t);
		stack(const stack<T> &);
		~stack();

		inline bool empty()const;
		inline size_t size()const;

		void push(T);
		T pop();
		void swap(stack<T> &);

	private:
		T *sp;// stack pointer
		T *stack;
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
	stack<T>::stack(size_t _sz)
	{
		sz = _sz;
		stack = new T[_sz];
		sp = stack;
	}

	template<typename T>
	stack<T>::stack(const stack<T> &_val)
	{

	}

	template<typename T>
	stack<T>::~stack()
	{
		delete[] stack;
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
		stack[sp++] = _val;
		sz++;
	}

	/**
	* Removes the element on top of the stack, effectively reducing its size by one.
	**/
	template<typename T>
	T stack<T>::pop()
	{
		sz--;
		return *(--sp);
	}

	/**
	* Exchanges the contents of the container by those of rhs.
	**/
	template<typename T>
	void stack<T>::swap(stack<T> &rhs)
	{

	}
}// namespace

#endif // !_STACK_H