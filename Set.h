#pragma once
#ifndef _SET_H
#define _SET_H

#include"Noiocmp.h"

namespace mystruct
{
	template<typename T>
	class set : private noiocmp
	{
	public:
		set();
		set(const set<T> &);
		~set();
		set<T> & operator=(const set<T> &);

		/* Capacity */
		inline bool empty()const;
		inline size_t size()const;

		/* Modifiers */
		void insert(T);
		void swap(set<T> &);
		void clear();

		/* Operations */
		T *find(T)const;
		size_t count(T)const;

	private:

	};
}// namespace
#endif // !_SET_H