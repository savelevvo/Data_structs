#pragma once
#ifndef _LIST_H
#define _LIST_H

#include<iostream>

namespace mystruct
{
	template<typename T>
	struct node
	{
		T value;
		node<T> *prev;
		node<T> *next;
	};

	template<typename T>
	class list
	{
	public:
		class EmptyList {};
		list();
		list(T);
		list(const list<T> &);
		~list();

		void push_back(T);
		void push_front(T);
		T & pop_back();
		T & pop_front();
		void display()const;
		bool empty()const { return (first == nullptr && last == nullptr); }

		bool operator==(const list<T> &)const;
		bool operator!=(const list<T> &)const;
		list<T> & operator= (const list<T> &);

	private:
		node<T> *first;
		node<T> *last;
		node<T> *create_node(T, node<T> * = nullptr, node<T> * = nullptr);
		void copy(const list<T> &);

		std::ostream & operator<< (std::ostream &)const;
		std::istream & operator>> (std::istream &);
		bool operator< (const list<T> &)const;
		bool operator<=(const list<T> &)const;
		bool operator> (const list<T> &)const;
		bool operator>=(const list<T> &)const;
	};

	template<typename T>
	list<T>::list()
	{
		first = last = nullptr;
	}

	template<typename T>
	list<T>::list(T _val)
	{
		first = last = create_node(_val, last);
	}

	template<typename T>
	list<T>::list(const list<T> &rhs)
	{
		copy(rhs);
	}

	template<typename T>
	list<T>::~list()
	{
		if (empty()) return;

		node<T> *current = new node<T>(*first);
		node<T> *tmp = new node<T>(*first);

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
	void list<T>::push_back(T _val)
	{
		if (!empty())
			last = last->next = create_node(_val, last);
		else
			last = first = create_node(_val, last);
	}

	template<typename T>
	void list<T>::push_front(T _val)
	{
		if (!empty())
			first = first->prev = create_node(_val, nullptr, first);
		else
			last = first = create_node(_val, last);
	}

	template<typename T>
	T & list<T>::pop_back()
	{
		if (empty()) throw EmptyList();

		node<T> *tmp = new node<T>(*last);

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
	T & list<T>::pop_front()
	{
		if (empty()) throw EmptyList();

		node<T> *tmp = new node<T>(*first);

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
	void list<T>::display()const
	{
		node<T> *tmp = new node<T>;

		for (tmp = first; tmp != nullptr; tmp = tmp->next)
			std::cout << tmp->value << " ";
		std::cout << std::endl;

		delete tmp;
	}

	template<typename T>
	bool list<T>::operator== (const list<T> &rhs)const
	{
		if (this == &rhs) return true;

		node<T> *ltmp = first;
		node<T> *rtmp = rhs.first;

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
	bool list<T>::operator!= (const list<T> &rhs)const
	{
		return !(*this == rhs);
	}

	template<typename T>
	list<T> & list<T>::operator= (const list<T> &rhs)
	{
		last = first = nullptr;
		copy(rhs);
		return *this;
	}

	template<typename T>
	node<T> *list<T>::create_node(T _val, node<T> *_prev = nullptr, node<T> *_next = nullptr)
	{
		node<T> *_node = new node<T>;
		_node->value = _val;
		_node->prev = _prev;
		_node->next = _next;
		return _node;
	}

	template<typename T>
	void list<T>::copy(const list<T> &rhs)
	{
		if (this == &rhs || rhs.empty())
			return;

		node<T> *tmp = new node<T>;

		for (tmp = rhs.first; tmp != nullptr; tmp = tmp->next)
			push_back(tmp->value);

		delete tmp;
	}
}// namespace

#endif // !_LIST_H
