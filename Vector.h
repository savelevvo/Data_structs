#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H

namespace mystruct
{
	template<typename T>
	class vector
	{
	public:
		class out_of_range {};
		vector(int = 1);
		~vector();
		vector<T> & operator=(const vector<T> &);

		inline size_t size()const;
		void resize(size_t);
		inline size_t capacity()const;
		inline bool empty()const;
		void reserve(size_t);

		T & operator[](unsigned);
		T & at(int);
		T & front();
		T & back();

		void push_back(const T &);
		T & pop_back();
		void swap(vector<T> &);

	private:
		size_t sz;
		size_t cap;
		T *arr;
	};

	template<typename T>
	vector<T>::vector(int _sz = 1)
	{
		sz = _sz;
		arr = new T[sz];
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
	 * Resizes the container so that it contains n elements.
	 * If _val < sz, the content is reduced to its first n elements, removing those beyond (and destroying them).
	 * If _val > sz, the content is expanded by inserting at the end as many elements as needed to reach a size of n. 
	**/
	template<typename T>
	void vector<T>::resize(size_t _val)
	{

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
	 * If _val > cap, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
	 * In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
	**/
	template<typename T>
	void vector<T>::reserve(size_t _val)
	{

	}

	/**
	 * Returns a reference to the element at position _val in the vector container.
	**/
	template<typename T>
	T & vector<T>::operator[](unsigned _val)
	{

	}

	/**
	* Returns a reference to the element at position n in the vector.
	* The function automatically checks whether _val is within the bounds of valid elements in the vector.
	* Throwing an out_of_range exception if it is not.
	**/
	template<typename T>
	T & vector<T>::at(int _val)
	{

	}

	/**
	* Returns a reference to the first element in the vector.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & vector<T>::front()
	{

	}

	/**
	* Returns a reference to the last element in the vector.
	* Calling this function on an empty container causes undefined behavior.
	**/
	template<typename T>
	T & vector<T>::back()
	{

	}

	/**
	* Adds a new element at the end of the vector, after its current last element.
	**/
	template<typename T>
	void vector<T>::push_back(const T &_val)
	{

	}

	/**
	* Removes the last element in the vector, effectively reducing the container size by one.
	* This destroys the removed element.
	**/
	template<typename T>
	T & vector<T>::pop_back()
	{

	}

	/**
	* Exchanges the content of the container by the content of rhs, which is another vector object of the same type.
	* Sizes may differ.
	**/
	template<typename T>
	void vector<T>::swap(vector<T> &rhs)
	{

	}

}// namespace

#endif // !_VECTOR_H