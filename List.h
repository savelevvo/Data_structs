#pragma once
#ifndef _LIST_H
#define _LIST_H

#include<iostream>

template<typename T>
struct Node
{
	T value;
	Node<T> *prev;
	Node<T> *next;
};

template<typename T>
class List
{
public:
	class EmptyList{};
	List();
	List(const T &);
	List(const List<T> &);
	~List();

	void push_back(const T &);
	void push_front(const T &);
	T & pop_back();
	T & pop_front();
	void display()const;
	bool empty()const { return (first == nullptr && last == nullptr); }
		
	bool operator==(const List<T> &)const;
	bool operator!=(const List<T> &)const;
	List<T> & operator= (const List<T> &);

private:
	Node<T> *first;
	Node<T> *last;
	Node<T> *create_node(const T &, Node<T> * = nullptr, Node<T> * = nullptr);
	
	void copy(const List<T> &);

	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	bool operator< (const List<T> &)const;
	bool operator<=(const List<T> &)const;
	bool operator> (const List<T> &)const;
	bool operator>=(const List<T> &)const;
};

template<typename T>
List<T>::List()
{
	first = last = nullptr; 
}

template<typename T>
List<T>::List(const T &_val)
{
	first = last = create_node(_val, last);
}

template<typename T>
List<T>::List(const List<T> &rhs)
{
	copy(rhs);
}

template<typename T>
List<T>::~List()
{
	if (empty()) return;

	Node<T> *current = new Node<T>(*first);
	Node<T> *tmp = new Node<T>(*first);

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
void List<T>::push_back(const T &_val)
{
	if (!empty())
		last = last->next = create_node(_val, last);
	else
		last = first = create_node(_val, last);
}

template<typename T>
void List<T>::push_front(const T &_val)
{
	if (!empty())
		first = first->prev = create_node(_val, nullptr, first);
	else
		last = first = create_node(_val, last);
}

template<typename T>
T & List<T>::pop_back()
{
	if (empty()) throw EmptyList();
	
	Node<T> *tmp = new Node<T>(*last);

	if (first->next == nullptr && last->prev == nullptr)// There is only one node
	{	
		delete last;
		first = last = nullptr;
		return tmp->value;
	}
	else// Several nodes
	{
		delete last;
		last = tmp->prev;
		last->next = nullptr;
		return tmp->value;
	}	
}

template<typename T>
T & List<T>::pop_front()
{
	if (empty()) throw EmptyList();

	Node<T> *tmp = new Node<T>(*first);

	if (first->next == nullptr && last->prev == nullptr)// There is only one node
	{
		delete first;
		first = last = nullptr;
		return tmp->value;
	}
	else// Several nodes
	{
		delete first;
		first = tmp->next;
		first->prev = nullptr;
		return tmp->value;
	}
}

template<typename T>
void List<T>::display()const
{
	Node<T> *tmp = new Node<T>;

	for (tmp = first; tmp != nullptr; tmp = tmp->next)
		std::cout << tmp->value << " ";
	std::cout << std::endl;

	delete tmp;
}

template<typename T>
bool List<T>::operator== (const List<T> &rhs)const
{
	if (this == &rhs) return true;

	Node<T> *ltmp = first;
	Node<T> *rtmp = rhs.first;

	bool eq = true;

	while (ltmp != nullptr)
	{
		if (ltmp->value == rtmp->value)
		{
			if (ltmp->next == nullptr && rtmp->next != nullptr) { eq = false; break; }
			if (rtmp->next == nullptr && ltmp->next != nullptr) { eq = false; break; }
			ltmp = ltmp->next;
			rtmp = rtmp->next;
		}
		else
		{
			eq = false;
			break;
		}
	}

	return eq;
}

template<typename T>
bool List<T>::operator!= (const List<T> &rhs)const
{
	return !(*this == rhs);
}

template<typename T>
List<T> & List<T>::operator= (const List<T> &rhs)
{
	last = first = nullptr;
	copy(rhs);
	return *this;
}

template<typename T>
Node<T> *List<T>::create_node(const T &_val, Node<T> *_prev = nullptr, Node<T> *_next = nullptr)
{
	Node<T> *_node = new Node<T>;
	_node->value = _val;
	_node->prev = _prev;
	_node->next = _next;
	return _node;
}

template<typename T>
void List<T>::copy(const List<T> &rhs)
{
	if (this == &rhs || rhs.empty())
		return;

	Node<T> *tmp = new Node<T>;
	
	for (tmp = rhs.first; tmp != nullptr; tmp = tmp->next)
		push_back(tmp->value);

	delete tmp;
}

#endif // _LIST_H
