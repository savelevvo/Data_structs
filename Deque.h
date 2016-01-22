#pragma once
#ifndef _DEQUE_H
#define _DQEUE_H

#include<iostream>

template<typename T>
class Deque
{
public:
	class EmptyDeque {};
	class InvalidRange {};
	
	Deque(int);
	Deque(const Deque<T> &);// todo
	~Deque();
	
	void push(const T &);
	T pop();
	size_t size()const { return sz; }
	
	bool operator==(const Deque<T> &)const; // todo
	bool operator!=(const Deque<T> &)const; // todo
	Deque<T> & operator= (const Deque<T> &);// todo

private:
	int sz;
	T *arr;
	int head;
	int tail;
	size_t count;

	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	bool operator< (const Deque<T> &)const;
	bool operator<=(const Deque<T> &)const;
	bool operator> (const Deque<T> &)const;
	bool operator>=(const Deque<T> &)const;
};

template<typename T>
Deque<T>::Deque(int size)
{
	tail = head = 0;
	count = 0;
	sz = size;
	arr = new T[sz];
}

template<typename T>
Deque<T>::~Deque()
{
	delete[] arr;
}

template<typename T>
void Deque<T>::push(const T &val)
{
	arr[tail] = val;
	tail < sz - 1 ? tail++ : head = tail = 0;
	count++;
}

template<typename T>
T Deque<T>::pop()
{
	if (head >= sz) throw InvalidRange();
	if (0 == count) throw EmptyDeque();
	count--;
	return arr[head++];
}

template<typename T>
bool Deque<T>::operator==(const Deque<T> &rhs)const
{
	if (this == &rhs) return true;
	if (size() != rhs.size()) return false;

	bool eq = true;
	
	for (size_t i = 0; i < count; i++)
		if (arr[i] != rhs.arr[i]) { eq = false; break; }

	return eq;
}

template<typename T>
bool Deque<T>::operator!=(const Deque<T> &rhs)const
{
	return !(*this == rhs);
}

#endif // _DEQUE