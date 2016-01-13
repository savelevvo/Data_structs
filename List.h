#ifndef LIST_H
#define LIST_H

#include<iostream>
using std::cout;
using std::endl;

template<typename T>
struct data
{
	T value;
	data<T> *next;
};

template<typename T>
class List
{
public:
	List();
	List(const T &);
	List(const List<T> &);
	~List();
	void add(const T &);
	size_t size()const { return list_size; }
	void display()const;

	bool operator==(const List<T> &)const;
	bool operator!=(const List<T> &)const;
	List<T> & operator= (const List<T> &);

private:
	data<T> *first;
	data<T> *last;
	size_t list_size;
	void init(data<T> *, const T &);
	void copy(const List<T> &);
	bool is_empty()const { return (first == nullptr && last == nullptr); }
	
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
	list_size = 0;	
}

template<typename T>
List<T>::List(const T &_val)
{
	data<T> *node = new data<T>;
	init(node, _val);
	first = last = node;
}

template<typename T>
List<T>::List(const List<T> &rhs)
{
	copy(rhs);
}

template<typename T>
List<T>::~List()
{
	data<T> *current = new data<T>(*first);
	data<T> *tmp = new data<T>(*first);

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
void List<T>::add(const T &_val)
{
	data<T> *node = new data<T>;
	init(node, _val);
	if (!is_empty())
		last = last->next = node;
	else
		last = first = node;
}

template<typename T>
void List<T>::display()const
{
	data<T> *tmp = new data<T>;

	for (tmp = first; tmp != nullptr; tmp = tmp->next)
		cout << tmp->value << " ";
	cout << endl;

	delete tmp;	
}

template<typename T>
bool List<T>::operator== (const List<T> &rhs)const
{
	if (this == &rhs) return true;
	if (list_size != rhs.size()) return false;

	data<T> *ltmp = first;
	data<T> *rtmp = rhs.first;

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
bool List<T>::operator!= (const List<T> &rhs)const
{
	return !(*this == rhs);
}

template<typename T>
List<T> & List<T>::operator= (const List<T> &rhs)
{
	copy(rhs);
	return *this;
}

template<typename T>
void List<T>::init(data<T> *_node, const T &_val)
{
	_node->value = _val;
	_node->next = nullptr;
	list_size++;
}

template<typename T>
void List<T>::copy(const List<T> &_rhs)
{
	if (this == &_rhs || _rhs.is_empty())
		return;

	data<T> *tmp = new data<T>;

	for (tmp = _rhs.first; tmp != nullptr; tmp = tmp->next)
		add(tmp->value);

	delete tmp;
}

#endif // LIST_H
