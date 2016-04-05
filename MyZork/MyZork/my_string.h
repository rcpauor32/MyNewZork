#ifndef __MY_STRING_H__
#define	__MY_STRING_H__

class String {
public:
	char* string;
	unsigned int capacity;

	String(unsigned int mem);
	String(char* c_str1);
	String(String &str);
	virtual ~String();

public:
	int size();
	int length();
	bool empty();
	void clear();
	char* c_str();
	bool strcmp(char* input, char* compared);

	bool String::operator==(char* str1) {
		int equal = true;
		for (int i = 0; i < sizeof(string) && equal; i++) {
			if (string[i] != str1[i])
				equal = false;
		}
	
		return equal;
	}

	void String::operator=(char* str1) {
		delete[] this->string;
		capacity = sizeof(str1) + 1;
		string = new char[capacity + 1];
		for (int i = 0; i < capacity; i++) {
			string[i] = str1[i];
		}

	}

};

#endif