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
		void push_back(const char*);
		void push_back(char);
		void pop_back();
		void swap(string &);

	private:
		vector<char> *s;

	};

	string operator+(const string &, const string &);
	bool operator== (const string &, const string &);
	bool operator== (const char* lhs, const string& rhs);
	bool operator== (const string& lhs, const char* rhs);
	bool operator!= (const string &, const string &);
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

	/**
	* Assigns a new value to the string, replacing its current contents.
	*/
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

	/**
	* Returns the length of the string, in terms of bytes.
	* This is the number of actual bytes that conform the contents of the string, which is not necessarily equal to its storage capacity.
	* Both string::size and string::length are synonyms and return the same value.
	*/
	inline size_t string::size()const
	{
		return s->size();
	}

	/**
	* Resizes the string to a length of _val characters.
	* If _val < string length, the current value is shortened to its first _val character, removing the characters beyond.
	* If _val > string length, the current content is extended by inserting at the end as many characters as needed to reach a size of _val.
	*/
	void string::resize(size_t _val)
	{
		s->resize(_val);
	}

	/**
	* Returns the length of the string, in terms of bytes.
	* This is the number of actual bytes that conform the contents of the string, which is not necessarily equal to its storage capacity.
	* Both string::size and string::length are synonyms and return the exact same value.
	*/
	inline size_t string::length()const
	{
		return s->size();
	}

	/**
	* Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
	* This capacity is not necessarily equal to the string length.
	*/
	inline size_t string::capacity()const
	{
		return s->capacity();
	}

	/**
	* Requests that the string capacity be adapted to a planned change in size to a length of up to _val characters.
	* If _val > string capacity, the function causes the container to increase its capacity to _val characters (or greater).
	* This function has no effect on the string length and cannot alter its content.
	*/
	inline void string::reserve(size_t _val)
	{
		s->reserve(_val);
	}

	/**
	* Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
	*/
	inline void string::clear()
	{
		s->clear();
	}

	/**
	*  Returns whether the string is empty (i.e. whether its length is 0).
	* This function does not modify the value of the string in any way.
	*/
	inline bool string::empty()const
	{
		return s->empty();
	}

	/**
	* Returns a reference to the character at position _val in the string.
	*/
	char & string::operator[](unsigned _val)const
	{
		return (*s)[_val];
	}

	/**
	* Returns a reference to the character at position _val in the string.
	* The function automatically checks whether _val is the valid position of a character in the string (i.e., whether pos is less than the string length), throwing an out_of_range exception if it is not.
	*/
	char & string::at(unsigned _val)const
	{
		return s->at(_val);
	}

	/**
	* Returns a reference to the last character of the string.
	* This function shall not be called on empty strings.
	*/
	char & string::back()const
	{
		return s->back();
	}

	/**
	* Returns a reference to the first character of the string.
	* This function shall not be called on empty strings.
	*/
	char & string::front()const
	{
		return s->front();
	}

	/**
	* Extends the string by appending additional characters at the end of its current value.
	*/
	string & string::operator+=(const string &rhs)
	{
		size_t rlen = rhs.size();
		reserve(s->size() + rlen);
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
		return *this;
	}

	string & string::operator+=(const char* rhs)
	{
		size_t rlen = strlen(rhs);
		reserve(s->size() + rlen);
		for (size_t i = 0; i < rlen; i++)
			push_back(rhs[i]);
		return *this;
	}

	string & string::operator+=(char rhs)
	{
		push_back(rhs);
		return *this;
	}

	/**
	* Appends character c to the end of the string, increasing its length by one.
	*/
	void string::push_back(const char* _val)
	{
		s->push_back(*_val);
	}

	void string::push_back(char _val)
	{
		s->push_back(_val);
	}

	/**
	* Erases the last character of the string, effectively reducing its length by one.
	*/
	void string::pop_back()
	{
		s->pop_back();
	}

	/**
	* Exchanges the content of the container by the content of rhs, which is another string object. Lengths may differ.
	*/
	void string::swap(string &rhs)
	{
		string *tmp = new string;
		*tmp = *this;
		*this = rhs;
		rhs = *tmp;
		delete tmp;
	}
	
	string operator+(const string &lhs, const string &rhs)
	{
		string tmp;
		tmp.reserve(lhs.size() + rhs.size());

		tmp = lhs;
		tmp += rhs;

		return tmp;
	}
	
	/**
	* Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
	*/
	bool operator== (const string &lhs, const string &rhs)
	{
		if (lhs.size() != rhs.size()) return false;
		size_t len = lhs.size();
		for (size_t i = 0; i < len; i++)
			if (lhs[i] != rhs[i]) return false;
		return true;
	}

	bool operator== (const char* lhs, const string& rhs)
	{
		if (strlen(lhs) != rhs.size()) return false;
		size_t len = rhs.size();
		for (size_t i = 0; i < len; i++)
			if (lhs[i] != rhs[i]) return false;
		return true;
	}

	bool operator== (const string& lhs, const char* rhs)
	{
		if (lhs.size() != strlen(rhs)) return false;
		size_t len = lhs.size();
		for (size_t i = 0; i < len; i++)
			if (lhs[i] != rhs[i]) return false;
		return true;
	}
	
	bool operator!= (const string &lhs, const string &rhs)
	{
		return !(lhs == rhs);
	}

	/**
	* Extracts a string from the input stream is, storing the sequence in str, which is overwritten (the previous value of str is replaced).
	*/
	std::istream & operator>>(std::istream &is, string &str)
	{
		char buf[2048];
		is.getline(buf, sizeof buf);
		str = buf;
		return is;
	}
	
	/**
	* Inserts the sequence of characters that conforms value of str into os.
	*/
	std::ostream & operator<<(std::ostream &os, const string &str)
	{
		for (size_t i = 0; i < str.size(); i++)
			os << str[i];

		return os;
	}
}// namespace

#endif // !_STRING_H
