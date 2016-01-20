#ifndef _QUEUE_H
#define _QUEUE_H

#include<iostream>

template<typename T>
class Queue
{
public:
	class EmptyQueue {};
	class InvalidRange {};
	
	Queue(int);
	Queue(const Queue<T> &);// todo
	~Queue();
	
	void push(const T &);
	T pop();
	size_t size()const { return sz; }
	
	bool operator==(const Queue<T> &)const; // todo
	bool operator!=(const Queue<T> &)const; // todo
	Queue<T> & operator= (const Queue<T> &);// todo

private:
	int sz;
	T *arr;
	int head;
	int tail;
	size_t count;

	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	bool operator< (const Queue<T> &)const;
	bool operator<=(const Queue<T> &)const;
	bool operator> (const Queue<T> &)const;
	bool operator>=(const Queue<T> &)const;
};

template<typename T>
Queue<T>::Queue(int size)
{
	tail = head = 0;
	count = 0;
	sz = size;
	arr = new T[sz];
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] arr;
}

template<typename T>
void Queue<T>::push(const T &val)
{
	arr[tail] = val;
	tail < sz - 1 ? tail++ : head = tail = 0;
	count++;
}

template<typename T>
T Queue<T>::pop()
{
	if (head >= sz) throw InvalidRange();
	if (0 == count) throw EmptyQueue();
	count--;
	return arr[head++];
}

template<typename T>
bool Queue<T>::operator==(const Queue<T> &rhs)const
{
	if (this == &rhs) return true;
	if (size() != rhs.size()) return false;

	bool eq = true;
	
	for (size_t i = 0; i < count; i++)
		if (arr[i] != rhs.arr[i]) { eq = false; break; }

	return eq;
}

template<typename T>
bool Queue<T>::operator!=(const Queue<T> &rhs)const
{
	return !(*this == rhs);
}

#endif // _QUEUE