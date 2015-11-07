
#pragma once
#include <iostream>
#include <cstring>

class Char {
public:
	Char();
	Char(char *);
	Char(const Char &);
	~Char();
	int length() const;
	void  operator=(Char&);
	Char operator+(Char&);
	friend Char& operator+( Char&, char*);
	friend std::ostream& operator<<(std::ostream&, const Char&);
	
private:
	char * p_char;
	int count;

};

std::ostream& operator<<(std::ostream&, const Char&);
