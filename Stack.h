#pragma once
#ifndef _STACK_H
#define _STACK_H

#include<iostream>

template<typename T>
class Stack
{
public:
	class EmptyStack{};
	Stack();
	Stack(const Stack<T> &);
	~Stack();

	void push(T);
	T pop();
	bool empty();
	size_t size();
	void swap(Stack<T> &);

private:
	T *sp;// stack pointer
	T *stack;
	size_t sz;
	size_t capacity;
	size_t lsz;// logical size

	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	Stack<T> & operator= (const Stack<T> &);
	bool operator==(const Stack<T> &)const;
	bool operator!=(const Stack<T> &)const;
	bool operator< (const Stack<T> &)const;
	bool operator<=(const Stack<T> &)const;
	bool operator> (const Stack<T> &)const;
	bool operator>=(const Stack<T> &)const;
};

template<typename T>
Stack<T>::Stack()
{
	lsz = 1;
	stack = new T[lsz];
	sp = stack;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &_val)
{

}

template<typename T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<typename T>
void Stack<T>::push(T _val)
{
	T *tmp = new T[lsz];
	
}

template<typename T>
T Stack<T>::pop()
{
	return *(--sp);
}

template<typename T>
bool Stack<T>::empty()
{
	return sz == 0;
}

template<typename T>
size_t Stack<T>::size()
{
	return sz;
}

template<typename T>
void Stack<T>::swap(Stack<T> &rhs)
{

}

#endif // _STACK_H