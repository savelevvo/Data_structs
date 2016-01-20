#ifndef _STACK_H
#define _STACK_H

#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class Stack
{
public:
	Stack(const size_t & = 1);
	~Stack();

	void push(const T &);
	T pop();

private:
	unsigned sp;
	T *stack;
};

template<typename T>
Stack<T>::Stack(const size_t &_sz = 1)
{
	sp = 0;
	stack = new T[_sz];
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<typename T>
void Stack<T>::push(const T &_val)
{
	stack[sp++] = _val;
}

template<typename T>
T Stack<T>::pop()
{
	return stack[--sp];
}

#endif // STACK_H