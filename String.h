#pragma once
#ifndef _STRING_H
#define _STRING_H

#include<iostream>
#include<cstring>
#include"Vector.h"

namespace mystruct
{
	class string
	{
	public:
		string();
		string(const string &);
		string(const char*);
		~string();

		string & operator=(const string &);
		string & operator=(const char*);
		string & operator=(char);

		/* Capacity */
		inline size_t size()const;
		void resize(size_t);
		inline size_t length()const;
		inline size_t capacity()const;
		inline void reserve(size_t);
		inline void clear();
		inline bool empty()const;

		/* Element access */
		char & operator[](unsigned)const;
		char & at(unsigned)const;
		char & back()const;
		char & front()const;

		/* Modifiers */
		string & operator+=(const string &);
		string & operator+=(const char*);
		string & operator+=(char);
		string & append(const string &);
		string & append(const char*);
		void push_back(char);
		void pop_back();
		void swap(string &);

	private:
		vector<char> *s;

	};

	string operator+(const string &, const string &);
	bool operator== (const string &, const string &);
	bool operator!= (const string &, const string &);
	bool operator<  (const string &, const string &);
	bool operator<= (const string &, const string &);
	bool operator>  (const string &, const string &);
	bool operator>= (const string &, const string &);
	std::istream & operator>>(std::istream &, string &);
	std::ostream & operator<<(std::ostream &, const string &);


	string::string()
	{
		s = new vector<char>;
	}

	string::string(const string &rhs)
	{
		size_t rlen = rhs.length();
		s = new vector<char>(rlen);
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
	}

	string::string(const char *rhs)
	{
		size_t rlen = strlen(rhs);
		s = new vector<char>(rlen);
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
	}

	string::~string()
	{
		s->~vector();
	}

	string & string::operator=(const string &rhs)
	{
		if (this == &rhs) return *this;
		size_t rlen = rhs.size();
		reserve(rlen);
		clear();
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
		return *this;
	}

	string & string::operator=(const char* rhs)
	{
		size_t rlen = strlen(rhs);
		reserve(rlen);
		clear();
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
		return *this;
	}

	string & string::operator=(char rhs)
	{
		clear();		
		push_back(rhs);
		return *this;
	}

	inline size_t string::size()const
	{
		return s->size();
	}

	void string::resize(size_t _val)
	{
		s->resize(_val);
	}

	inline size_t string::length()const
	{
		return s->size();
	}

	inline size_t string::capacity()const
	{
		return s->capacity();
	}

	inline void string::reserve(size_t _val)
	{
		s->reserve(_val);
	}

	inline void string::clear()
	{
		s->clear();
	}

	inline bool string::empty()const
	{
		return s->empty();
	}

	char & string::operator[](unsigned _val)const
	{
		return (*s)[_val];
	}

	char & string::at(unsigned _val)const
	{
		return s->at(_val);
	}

	char & string::back()const
	{
		return s->back();
	}

	char & string::front()const
	{
		return s->front();
	}

	string & string::operator+=(const string &rhs)
	{

	}

	string & string::operator+=(const char* rhs)
	{

	}

	string & string::operator+=(char rhs)
	{

	}

	string & string::append(const string &_val)
	{

	}

	string & string::append(const char* _val)
	{

	}

	void string::push_back(char _val)
	{
		s->push_back(_val);
	}

	void string::pop_back()
	{
		s->pop_back();
	}

	void string::swap(string &rhs)
	{
		
	}

	string operator+(const string &lhs, const string &rhs){}
	bool operator== (const string &lhs, const string &rhs){}
	bool operator!= (const string &lhs, const string &rhs){}
	bool operator<  (const string &lhs, const string &rhs){}
	bool operator<= (const string &lhs, const string &rhs){}
	bool operator>  (const string &lhs, const string &rhs){}
	bool operator>= (const string &lhs, const string &rhs){}
	std::istream & operator>>(std::istream &lhs, string &rhs){}
	std::ostream & operator<<(std::ostream &lhs, const string &rhs){}

}// namespace

#endif // !_STRING_H
