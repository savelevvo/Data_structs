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
		class Emptystack {};
		stack();
		stack(const stack<T> &);
		~stack();

		void push(T);
		T pop();
		bool empty();
		size_t size();
		void swap(stack<T> &);

	private:
		T *sp;// stack pointer
		T *stack;
		size_t sz;
		size_t capacity;
		size_t lsz;// logical size

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
		lsz = 1;
		stack = new T[lsz];
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

	template<typename T>
	void stack<T>::push(T _val)
	{
		T *tmp = new T[lsz];

	}

	template<typename T>
	T stack<T>::pop()
	{
		return *(--sp);
	}

	template<typename T>
	bool stack<T>::empty()
	{
		return sz == 0;
	}

	template<typename T>
	size_t stack<T>::size()
	{
		return sz;
	}

	template<typename T>
	void stack<T>::swap(stack<T> &rhs)
	{

	}
}// namespace

#endif // !_STACK_H