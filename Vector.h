#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>

namespace mystruct
{
	template<typename T>
	class vector
	{
	public:
		class out_of_range {};

		vector(size_t = 1);
		~vector();
		vector<T> & operator=(const vector<T> &);

		/* Capacity */
		inline size_t size()const;
		void resize(size_t, T = 0);
		inline size_t capacity()const;
		inline bool empty()const;
		void reserve(size_t);

		/* Element access */
		T & operator[](unsigned)const;
		T & at(unsigned)const;
		T & front()const;
		T & back()const;

		/* Modifiers */
		void push_back(T);
		T & pop_back();
		void swap(vector<T> &);
		inline void clear();
		
	private:
		T *arr;
		size_t sz;
		size_t cap;

		std::ostream & operator<< (std::ostream &)const;
		std::istream & operator>> (std::istream &);
		bool operator< (const vector<T> &)const;
		bool operator<=(const vector<T> &)const;
		bool operator> (const vector<T> &)const;
		bool operator>=(const vector<T> &)const;
		bool operator==(const vector<T> &)const;
		bool operator!=(const vector<T> &)const;

	};

	template<typename T>
	vector<T>::vector(size_t _cap = 1)
	{
		sz = 0;
		cap = _cap;
		arr = new T[cap];
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] arr;
	}

	/**
	 * Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
	**/
	template<typename T>
	vector<T> & vector<T>::operator=(const vector<T> &rhs)
	{
		if (this == &rhs) return *this;
		
		sz = 0;
		unsigned rsz = rhs.size();
		unsigned rcap = rhs.capacity();
		
		if (cap > rcap)
		{
			T *tmp = new T[rcap];
			delete[] arr;
			arr = tmp;
			cap = rcap;
		}
		
		for (unsigned i = 0; i < rsz; i++)
			push_back(rhs[i]);

		return *this;
	}

	/**
	* Returns the number of elements in the vector.
	* This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
	**/
	template<typename T>
	inline size_t vector<T>::size()const
	{ 
		return sz; 
	}

	/**
	 * Resizes the container so that it contains _n elements.
	 * If _n < sz, the content is reduced to its first n elements, removing those beyond (and destroying them).
	 * If _n > sz, the content is expanded by inserting at the end as many elements as needed to reach a size of _n. 
	**/
	template<typename T>
	void vector<T>::resize(size_t _n, T _val = 0)
	{
		if (_n < sz)
			sz = _n;
		else if (_n > sz)
			for (unsigned i = sz; i < _n; i++)
				push_back(_val);
		else
			return;
	}

	/**
	* Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
	* This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
	**/
	template<typename T>
	inline size_t vector<T>::capacity()const
	{ 
		return cap; 
	}

	/**
	* Returns whether the vector is empty (i.e. whether its size is 0).
	* This function does not modify the container in any way.
	**/
	template<typename T>
	inline bool vector<T>::empty()const
	{
		return sz == 0;
	}

	/**
	 * Requests that the vector capacity be at least enough to contain n elements.
	 * If _val > cap, the function causes the container to reallocate its storage increasing its capacity to _val (or greater).
	 * In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
	**/
	template<typename T>
	void vector<T>::reserve(size_t _val)
	{
		if (_val <= cap) return;
		T *tmp = new T[_val];
		for (unsigned i = 0; i < sz; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
		cap = _val;
	}

	/**
	 * Returns a reference to the element at position _val in the vector container.
	**/
	template<typename T>
	T & vector<T>::operator[](unsigned _val)const
	{
		return arr[_val];
	}

	/**
	* Returns a reference to the element at position n in the vector.
	* The function automatically checks whether _val is within the bounds of valid elements in the vector.
	* Throwing an out_of_range exception if it is not.
	**/
	template<typename T>
	T & vector<T>::at(unsigned _val)const
	{
		if (_val < 0 || _val > sz - 1) throw out_of_range();
		return arr[_val];
	}

	/**
	* Returns a reference to the first element in the vector.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & vector<T>::front()const
	{
		return arr[0];
	}

	/**
	* Returns a reference to the last element in the vector.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & vector<T>::back()const
	{
		return arr[sz-1];
	}

	/**
	* Adds a new element at the end of the vector, after its current last element.
	**/
	template<typename T>
	void vector<T>::push_back(T _val)
	{
		if (sz < cap)
			arr[sz++] = _val;
		else
		{
			cap *= 2;
			T *tmp = new T[cap];
			for (unsigned i = 0; i < sz; i++)
				tmp[i] = arr[i];
			delete[] arr;
			arr = tmp;
			arr[sz++] = _val;
		}
	}

	/**
	* Removes the last element in the vector, effectively reducing the container size by one.
	* Calling this function on an empty container causes undefined behavior.
	* This destroys the removed element.
	**/
	template<typename T>
	T & vector<T>::pop_back()
	{
		return arr[--sz];
	}

	/**
	* Exchanges the content of the container by the content of rhs, which is another vector object of the same type.
	* Sizes may differ.
	**/
	template<typename T>
	void vector<T>::swap(vector<T> &rhs)
	{
		vector<T> *tmp = new vector<T>;
		*tmp = *this;
		*this = rhs;
		rhs = *tmp;
		delete tmp;
	}

	/**
	* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
	**/
	template<typename T>
	inline void vector<T>::clear()
	{
		sz = 0;
	}
}// namespace

#endif // !_VECTOR_H