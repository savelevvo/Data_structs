#pragma once
#ifndef _DEQUE_H
#define _DQEUE_H

#include<iostream>
#include"Vector.h"
using mystruct::vector;

namespace mystruct
{
	template<typename T>
	class deque
	{
	public:
		class empty_deque {};
		class out_of_range {};

		deque();
		deque(const deque<T> &);
		~deque();
		deque<T> & operator= (const deque<T> &);

		/* Capacity */
		inline size_t size()const;
		void resize(size_t, T = 0);
		inline bool empty()const;

		/* Element access */
		T & operator[](unsigned)const;
		T & at(unsigned)const;
		T & front()const;
		T & back()const;

		/* Modifiers */
		void push_back(T);
		void push_front(T);
		T & pop_back();
		T & pop_front();
		void swap(deque<T> &);
		inline void clear();

	private:
		vector<T> *deq;

		std::ostream & operator<< (std::ostream &)const;
		std::istream & operator>> (std::istream &);
		bool operator< (const deque<T> &)const;
		bool operator<=(const deque<T> &)const;
		bool operator> (const deque<T> &)const;
		bool operator>=(const deque<T> &)const;
		bool operator==(const deque<T> &)const;
		bool operator!=(const deque<T> &)const;
	};

	template<typename T>
	deque<T>::deque()
	{
		deq = new vector<T>;
	}

	template<typename T>
	deque<T>::deque(const deque<T> &rhs)
	{
		deq = new vector<T>;
		size_t rsz = rhs.size();
		for (unsigned i = 0; i < rsz; i++)
			push_back(rhs[i]);
	}

	template<typename T>
	deque<T>::~deque()
	{
		deq->~vector();
	}
	
	/**
	* Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
	**/
	template<typename T>
	deque<T> & deque<T>::operator= (const deque<T> &rhs)
	{
		if (this == &rhs) return *this;
		
		deq->clear();
		unsigned rsz = rhs.size();
		for (unsigned i = 0; i < rsz; i++)
			push_back(rhs[i]);

		return *this;
	}

	/**
	* Returns the number of elements in the deque container.
	**/
	template<typename T>
	inline size_t deque<T>::size()const
	{
		return deq->size();
	}

	/**
	* Resizes the container so that it contains _n elements.
	**/
	template<typename T>
	void deque<T>::resize(size_t _n, T _val = 0)
	{
		deq->resize(_n, _val);
	}

	/**
	* Returns whether the deque container is empty (i.e. whether its size is 0).
	* This function does not modify the container in any way.
	**/
	template<typename T>
	inline bool deque<T>::empty()const
	{
		return deq->empty();
	}

	/**
	* Returns a reference to the element at position n in the deque container.
	* A similar member function, deque::at, has the same behavior as this operator function, except that deque::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range exception.
	**/
	template<typename T>
	T & deque<T>::operator[](unsigned _val)const
	{
		return (*deq)[_val];
	}

	/**
	* Returns a reference to the element at position n in the deque container object.
	* The function automatically checks whether _val is within the bounds of valid elements in the container, throwing an out_of_range exception if it is not (i.e., if n is greater or equal than its size). This is in contrast with member operator[], that does not check against bounds.
	* Returns a reference to the element at position _val in the deque container object.

	**/
	template<typename T>
	T & deque<T>::at(unsigned _val)const
	{
		if ( _val < 0 || _val > (deq->size() - 1) ) throw out_of_range();
		return (*deq)[_val];
	}

	/**
	* Returns a reference to the first element in the deque container.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & deque<T>::front()const
	{
		return (*deq)[0];
	}

	/**
	* Returns a reference to the last element in the container.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & deque<T>::back()const
	{
		return (*deq)[deq->size() - 1];
	}

	/**
	* Adds a new element at the end of the deque container, after its current last element. The content of _val is copied (or moved) to the new element.
	* This effectively increases the container size by one.
	**/
	template<typename T>
	void deque<T>::push_back(T _val)
	{
		deq->push_back(_val);
	}

	/**
	* Inserts a new element at the beginning of the deque container, right before its current first element. The content of _val is copied (or moved) to the inserted element.
	* This effectively increases the container size by one.
	**/
	template<typename T>
	void deque<T>::push_front(T _val)
	{
		size_t sz = deq->size();
		vector<T> *tmp = new vector<T>(sz + 1);
		tmp->push_back(_val);
		for (unsigned i = 0; i < sz; i++)
			tmp->push_back((*deq)[i]);
		deq->~vector();
		deq = tmp;
	}

	/**
	* Removes the last element in the deque container, effectively reducing the container size by one.
	* This destroys the removed element.
	**/
	template<typename T>
	T & deque<T>::pop_back()
	{
		if (deq->empty()) throw empty_deque();
		return deq->pop_back();
	}

	/**
	* Removes the first element in the deque container, effectively reducing its size by one.
	* This destroys the removed element.
	**/
	template<typename T>
	T & deque<T>::pop_front()
	{
		if (deq->empty()) throw empty_deque();
		T backup = (*deq)[0];
		size_t sz = deq->size();
		vector<T> *tmp = new vector<T>(sz - 1);
		for (unsigned i = 1; i < sz; i++)
			tmp->push_back((*deq)[i]);
		deq->~vector();
		deq = tmp;
		return backup;
	}

	/**
	* Exchanges the content of the container by the content of x, which is another deque object containing elements of the same type.
	* Sizes may differ.
	**/
	template<typename T>
	void deque<T>::swap(deque<T> &rhs)
	{
		deque<T> *tmp = new deque<T>;
		*tmp = *this;
		*this = rhs;
		rhs = *tmp;
		delete tmp;
	}

	/**
	* Removes all elements from the deque (which are destroyed), leaving the container with a size of 0.
	**/
	template<typename T>
	inline void deque<T>::clear()
	{
		deq->clear();
	}
}// namespace

#endif // !_DEQUE_H