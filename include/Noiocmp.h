#pragma once
#ifndef _NOIOCMP_H
#define _NOIOCMP_H

#include<iostream>

class noiocmp
{
private:
	std::ostream & operator<< (std::ostream &)const;
	std::istream & operator>> (std::istream &);
	bool operator< (const noiocmp &)const;
	bool operator<=(const noiocmp &)const;
	bool operator> (const noiocmp &)const;
	bool operator>=(const noiocmp &)const;
	bool operator==(const noiocmp &)const;
	bool operator!=(const noiocmp &)const;
};
#endif // !_NOIOCMP_H
