#ifndef DLLIST_H
#define DLLIST_H

#include "SLList.h"

template<typename T>
struct Node
{
	T value;
	Node<T> *next;
	Node<T> *prev;
};

template<typename T>
class DLList :	public SLList<T>
{
public:
	DLList(const T &);
	DLList(const DLList<T> &);
	void add(const T &);
	
	DLList<T> & operator= (const DLList<T> &);

private:
	
};

#endif // DLLIST_H
