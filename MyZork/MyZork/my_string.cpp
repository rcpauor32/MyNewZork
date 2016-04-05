#include "my_string.h"
#include <string.h>

String::String(unsigned int mem) {
	string = new char[mem];
}

String::String(char* str1) {
	this->capacity = sizeof(str1) + 1;
	this->string = new char[capacity];
	string = str1;
}

String::String(String& str){
	capacity = str.capacity;
	string = new char[capacity];
	string = str.string;
}

int String::size() {
	return sizeof(string);
}

int String::length() {
	return strlen(this->string);
}

bool String::empty() {
	if (string)
		return true;
	return false;
}

void String::clear() {
	delete[] string;
}

char* String::c_str() {
	return string;
}

bool strcmp(char* input, char* compared) {
	for (int i = 0; i < sizeof(input); i++) {
		if (input[i] != compared[i])
			return 0;
	}
	return 1;
}

String::~String() {
	delete[] string;
};