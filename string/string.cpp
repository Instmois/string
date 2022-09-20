#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class String {
	char* buffer = NULL;
	unsigned int size = 0;
public:
	String() = default;
	String(const char* str) {
		if (str) {
			size = strlen(str);
			buffer = new char[size + 1];
			strcpy(buffer, str);
		}
	}
	String(const String& str) {
		if (str.size) {
			size = str.size;
			buffer = new char[size + 1];
			strcpy(buffer, str.buffer);
		}
	}
	~String() {
		delete[] buffer;
	}
	char& operator[](int i) {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}
	const char& operator[](int i) const {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}
	String& operator=(const String& str) {
		if (this == &str) {
			return *this;
		}
		if (buffer) delete[] buffer;
		size = str.size;
		buffer = new char[size + 1];
		strcpy(buffer, str.buffer);
		return *this;
	}
	String& operator+=(const String& str) {
		String temp = buffer;
		size += str.size;
		buffer = new char[size + 1];
		strcpy(buffer, temp.buffer);
		strcat(buffer, str.buffer);
		return *this;
	}
	String operator+(const String& str) {
		String temp;
		delete[] temp.buffer;
		int size1 = size;
		int size2 = str.size;
		int size3 = size1 + size2;
		temp = new char[size3 + 1];
		strcpy(temp.buffer, buffer);
		strcpy(temp.buffer + size1, str.buffer);
		return temp;
	}
	friend ostream& operator<<(ostream&, const String&);
};

ostream& operator<<(ostream& stream, const String& str) {
	if (str.buffer) stream << str.buffer << endl;
	else cout << "None" << endl;
	return stream;
}

int main() {

	String str = "Hello";
	String str2 = "Hi ";
	String str3 = "Marry";
	String str4 = " How are you?";
	cout << str;
	String str1 = NULL;
	cout << str1;
	String str_copy = str;
	cout << str_copy;
	cout << str[0] << endl;
	str[0] = 'X';
	cout << str;
	str = str2;
	cout << str;
	str += str3;
	cout << str;
	cout << str + str4;
	return 0;
}
