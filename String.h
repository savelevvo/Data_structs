#pragma once
#ifndef _STRING_H
#define _STRING_H

#include<iostream>

namespace mystruct
{
	class string
	{
	public:
		string();
		string(const string &str);
		string(const char* s);
		~string();
		
		string & operator=(const string &);
		string & operator=(const char* s);
		string & operator=(char c);

		/* Capacity */
		inline size_t size()const;
		void resize(size_t);
		inline size_t length()const;
		inline size_t capacity()const;
		void reserve(size_t);
		inline void clear();
		inline bool empty()const;

		/* Element access */
		char & operator[](size_t);
		//const char & operator[] (size_t) const;
		char & at(size_t);
		//const char & at(size_t)const;
		char & back()const;
		char & front()const;

		/* Modifiers */
		string & operator+=(const string &);
		string & operator+=(const char* s);
		string & operator+=(char c);
		string & append(const string &);
		string & append(const char* s);
		void push_back(char);
		void pop_back();
		void swap(string &);

	private:
		char *s;
		int n;

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
}// namespace

#endif // !_STRING_H
