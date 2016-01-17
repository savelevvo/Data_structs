#ifndef DLLIST_H
#define DLLIST_H

#include "SLList.h"

/********************
 * Doubly Linked List
 ********************/

template<typename T>
struct DNode : public SNode<T>
{
	//T value;
	//DNode<T> *next;
	SNode<T> *prev;
};

template<typename T>
class DLList : public SLList<T>
{
public:
	DLList();
	DLList(const T &);
	DLList(const DLList<T> &);
	~DLList();

	void push_back(const T &);
	
	DLList<T> & operator= (const DLList<T> &);

private:
	DNode<T> *first;
	DNode<T> *last;

	DNode<T> *create_node(const T &);
	void copy(const DLList<T> &);
};

template<typename T>
DLList<T>::DLList()
{
	first = last = nullptr;
}

template<typename T>
DLList<T>::DLList(const T &_val)
{
	first = last = create_node(_val);
}

template<typename T>
DLList<T>::DLList(const DLList<T> &rhs)
{
	copy(rhs);
}

template<typename T>
DLList<T>::~DLList()
{
	if (is_empty()) return;

	DNode<T> *current = new DNode<T>(*first);
	DNode<T> *tmp = new DNode<T>(*first);

	while (tmp != nullptr)
	{
		tmp = current->next;
		delete current;
		current = tmp;
	}

	delete tmp;
	delete current;
}

template<typename T>
void DLList<T>::push_back(const T &_val)
{
	if (!is_empty())
		last = last->next = create_node(_val);// prev
	else
		last = first = create_node(_val);
}

template<typename T>
DLList<T> & DLList<T>::operator= (const DLList<T> &rhs)
{
	last = first = nullptr;
	copy(rhs);
	return *this;
}

template<typename T>
DNode<T> * DLList<T>::create_node(const T &_val)
{
	DNode<T> *_node = new DNode<T>;
	_node->value = _val;
	_node->next = nullptr;
	_node->prev = nullptr;
	return _node;
}

template<typename T>
void DLList<T>::copy(const DLList<T> &rhs)
{
	if (this == &rhs || rhs.is_empty())
		return;

	DNode<T> *tmp = new DNode<T>;

	for (tmp = rhs.first; tmp != nullptr; tmp = tmp->next)
		push_back(tmp->value);

	delete tmp;
}

#endif // DLLIST_H
