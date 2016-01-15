#ifndef SLLIST_H
#define SLLIST_H

#include<iostream>
using std::cout;
using std::endl;

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
	void add(const T &);
	size_t size()const { return list_size; }
	void display()const;

	bool operator==(const SLList<T> &)const;
	bool operator!=(const SLList<T> &)const;
	SLList<T> & operator= (const SLList<T> &);

private:
	Node<T> *first;
	Node<T> *last;
	size_t list_size;
	void init(Node<T> *, const T &);
	void copy(const SLList<T> &);
	bool is_empty()const { return (first == nullptr && last == nullptr); }
	
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
	list_size = 0;	
}

template<typename T>
SLList<T>::SLList(const T &_val)
{
	Node<T> *_node = new Node<T>;
	init(_node, _val);
	first = last = _node;
}

template<typename T>
SLList<T>::SLList(const SLList<T> &rhs)
{
	copy(rhs);
}

template<typename T>
SLList<T>::~SLList()
{
	Node<T> *current = new Node<T>(*first);
	Node<T> *tmp = new Node<T>(*first);

	while (tmp != nullptr)
	{
		tmp = (current->next == nullptr) ? nullptr : current->next;
		delete current;
		current = tmp;
	}

	delete tmp;
	delete current;
}

template<typename T>
void SLList<T>::add(const T &_val)
{
	Node<T> *_node = new Node<T>;
	init(_node, _val);
	if (!is_empty())
		last = last->next = _node;
	else
		last = first = _node;
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
	if (list_size != rhs.size()) return false;

	Node<T> *ltmp = first;
	Node<T> *rtmp = rhs.first;

	bool eq = true;

	while (ltmp != nullptr)
	{
		if (ltmp->value == rtmp->value)
		{
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
	copy(rhs);
	return *this;
}

template<typename T>
void SLList<T>::init(Node<T> *_node, const T &_val)
{
	_node->value = _val;
	_node->next = nullptr;
	list_size++;
}

template<typename T>
void SLList<T>::copy(const SLList<T> &_rhs)
{
	if (this == &_rhs || _rhs.is_empty())
		return;

	Node<T> *tmp = new Node<T>;

	for (tmp = _rhs.first; tmp != nullptr; tmp = tmp->next)
		add(tmp->value);

	delete tmp;
}

#endif // SLLIST_H
