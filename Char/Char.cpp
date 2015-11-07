#include "Char.hpp"


Char::Char() :count(0){
}


Char::Char(char * oth_char) {
	this->count = strlen(oth_char);
	this->p_char = new char[this->count+1];
	strcpy_s(this->p_char,this->count+1, oth_char);
	
}
Char::Char(const Char& oth_char) {
	this->count = oth_char.count;
	this->p_char = new char[this->count + 1];
	strcpy_s(this->p_char, this->count + 1, oth_char.p_char);
}
Char::~Char() {
	delete [] this->p_char;
}
int Char::length() const {
	return this->count;
}


void Char::operator=(Char&  oth_char) {
	this->count = oth_char.count;
	this->p_char = new char[this->count + 1];
	strcpy_s(this->p_char, this->count + 1, oth_char.p_char);
}
Char  Char::operator+(Char &oth_char) {
	int size = this->count + oth_char.count;
	char* temp = new char[size+1];

	strcpy_s(temp, size, this->p_char);
	strcat_s(temp,size+1, oth_char.p_char);
	Char k(temp);
	delete []temp;
	return k;

}


std::ostream& operator<<(std::ostream& os, const Char& oth_char) {
	return os << oth_char.p_char;
}