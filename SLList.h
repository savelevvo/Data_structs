#ifndef SLLIST_H
#define SLLIST_H

#include<iostream>
using std::cout;
using std::endl;

/********************
* Singly Linked List
********************/

template<typename T>
struct Node
{
	T value;
	Node<T> *next;
};

template<typename T>
class SLList
{
public:
	SLList();
	SLList(const T &);
	SLList(const SLList<T> &);
	~SLList();

	void push_back(const T &);
	void display()const;
	bool is_empty()const { return (first == nullptr && last == nullptr); }

	bool operator==(const SLList<T> &)const;
	bool operator!=(const SLList<T> &)const;
	SLList<T> & operator= (const SLList<T> &);

private:
	Node<T> *first;
	Node<T> *last;
	Node<T> *create_node(const T &);
	
	void copy(const SLList<T> &);

	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	bool operator< (const SLList<T> &)const;
	bool operator<=(const SLList<T> &)const;
	bool operator> (const SLList<T> &)const;
	bool operator>=(const SLList<T> &)const;
};

template<typename T>
SLList<T>::SLList()
{
	first = last = nullptr; 
}

template<typename T>
SLList<T>::SLList(const T &_val)
{
	first = last = create_node(_val);
}

template<typename T>
SLList<T>::SLList(const SLList<T> &rhs)
{
	copy(rhs);
}

template<typename T>
SLList<T>::~SLList()
{
	if (is_empty()) return;

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
void SLList<T>::push_back(const T &_val)
{
	if (!is_empty())
		last = last->next = create_node(_val);
	else
		last = first = create_node(_val);
}

template<typename T>
void SLList<T>::display()const
{
	Node<T> *tmp = new Node<T>;

	for (tmp = first; tmp != nullptr; tmp = tmp->next)
		cout << tmp->value << " ";
	cout << endl;

	delete tmp;
}

template<typename T>
bool SLList<T>::operator== (const SLList<T> &rhs)const
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
bool SLList<T>::operator!= (const SLList<T> &rhs)const
{
	return !(*this == rhs);
}

template<typename T>
SLList<T> & SLList<T>::operator= (const SLList<T> &rhs)
{
	last = first = nullptr;
	copy(rhs);
	return *this;
}

template<typename T>
Node<T> *SLList<T>::create_node(const T &_val)
{
	Node<T> *_node = new Node<T>;
	_node->value = _val;
	_node->next = nullptr;
	return _node;
}

template<typename T>
void SLList<T>::copy(const SLList<T> &rhs)
{
	if (this == &rhs || rhs.is_empty())
		return;

	Node<T> *tmp = new Node<T>;
	
	for (tmp = rhs.first; tmp != nullptr; tmp = tmp->next)
		push_back(tmp->value);// ???

	delete tmp;
}

#endif // SLLIST_H
