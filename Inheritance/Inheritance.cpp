#include <iostream>
#include <cstring>
using namespace std;

// task 1
class Pet
{
public:
	int age;
	float size;
	float weight;
	string breed;
	string name;

	Pet(int a, float s, float w, string b, string n) : age{ a }, size{ s }, weight{ w }, breed{ b }, name{ n } {}
};

class Dog : public Pet
{
public:
	Dog(int a, float s, float w, string b, string n) : Pet(a, s, w, b, n) {};

	void speak() {
		cout << "Woof!" << endl;
	}
};

class Cat : public Pet
{
public:
	Cat(int a, float s, float w, string b, string n) : Pet(a, s, w, b, n) {};

	void speak() {
		cout << "Meow!" << endl;
	}
};

class Parrot : public Pet
{
public:
	Parrot(int a, float s, float w, string b, string n) : Pet(a, s, w, b, n) {};

	void speak() {
		cout << "Squawk!" << endl;
	}
};


// task 2
class String
{
public:
	char* Data;
	int lenght;

	String() : Data{ nullptr }, lenght{ 0 } {}

	String(const char* Cstring) {
		int lenghtC = strlen(Cstring);
		Data = new char[lenghtC + 1];
		for (int i = 0; i < lenghtC; i++)
		{
			Data[i] = Cstring[i];
		}
		Data[lenghtC] = '\0';
		lenght = lenghtC;
	}


	String(const String& str) {
		int len = strlen(str.Data);
		Data = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			Data[i] = str.Data[i];
		}
		Data[len] = '\0';
		lenght = len;
	}


	String& operator=(const String& str) {
		delete[] Data;
		int len = strlen(str.Data);
		Data = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			Data[i] = str.Data[i];
		}
		Data[len] = '\0';
		lenght = len;
		return *this;
	}


	int Getlenght() {
		return lenght;
	}

	void Clear() {
		delete[] Data;
		lenght = 0;
	}

	String operator+(const String& other) const {
		int totalLength = lenght + other.lenght;
		char* newData = new char[totalLength + 1];

		for (int i = 0; i < lenght; i++) {
			newData[i] = Data[i];
		}
		for (int i = 0; i < other.lenght; i++) {
			newData[lenght + i] = other.Data[i];
		}
		newData[totalLength] = '\0';

		String result(newData);
		delete[] newData;

		return result;
	}


	String& operator+=(const String& other) {
		int newLength = lenght + other.lenght;
		char* newData = new char[newLength + 1];

		for (int i = 0; i < lenght; ++i) {
			newData[i] = Data[i];
		}
		for (int i = 0; i < other.lenght; ++i) {
			newData[lenght + i] = other.Data[i];
		}

		newData[newLength] = '\0';

		delete[] Data;
		Data = newData;
		lenght = newLength;

		return *this;
	}

	bool operator==(const String& other) const {
		if (lenght != other.lenght) {
			return false;
		}
		for (int i = 0; i < lenght; ++i) {
			if (Data[i] != other.Data[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const String& other) const {
		return !(*this == other);
	}

	~String()
	{
		delete[] Data;
	}
};

class BitString : public String
{
public:
	BitString() : String() {};
	BitString(const char* Cstring) : String(Cstring) {};
	BitString(const BitString& str) : String(str) {};
	BitString& operator=(const BitString& str) {
		delete[] Data;
		lenght = strlen(str.Data);
		Data = new char[lenght + 1];
		for (int i = 0; i < lenght; i++) {
			Data[i] = str.Data[i];
		}
		Data[lenght] = '\0';
		lenght = 0;
		return *this;
	}
	~BitString()
	{
		delete[] Data;
		lenght=0;
	}
	BitString operator+(const BitString& other) const{
		int totalLength = lenght + other.lenght;
		char* newData = new char[totalLength + 1];

		for (int i = 0; i < lenght; i++) {
			newData[i] = Data[i];
		}
		for (int i = 0; i < other.lenght; i++) {
			newData[lenght + i] = other.Data[i];
		}
		newData[totalLength] = '\0';

		BitString result(newData);
		delete[] newData;

		return result;
	}
	BitString& operator+=(const BitString& other){
		int newLength = lenght + other.lenght;
		char* newData = new char[newLength + 1];

		for (int i = 0; i < lenght; ++i) {
			newData[i] = Data[i];
		}
		for (int i = 0; i < other.lenght; ++i) {
			newData[lenght + i] = other.Data[i];
		}

		newData[newLength] = '\0';

		delete[] Data;
		Data = newData;
		lenght = newLength;

		return *this;
	}
	bool operator==(const BitString& other) const{
		if (lenght != other.lenght) {
			return false;
		}
		for (int i = 0; i < lenght; ++i) {
			if (Data[i] != other.Data[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const BitString& other) const{
		return !(*this == other);
	}
};

int main()
{
	// task 1
	Dog dog1(4, 50, 20, "pitbull", "Bob");
	cout << dog1.name << endl;
	cout << dog1.age << endl;
	dog1.speak();
	Cat cat1(5, 30, 14, "Sphynx ", "Katie");
	cout << cat1.name << endl;
	cout << cat1.age << endl;
	cat1.speak();

	// task 2
	String str1("hello");
	String str2("world");
	String str3 = str1 + str2;

	cout << "str1: " << str1.Getlenght() << endl;
	cout << "str2: " << str2.Getlenght() << endl;
	cout << "str3: " << str3.Getlenght() << endl;

	str1 += str2;
	cout << "str1 after += str1: " << str1.Getlenght() << endl;

	if (str1 == str3) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	str1.Clear();
	cout << "str1 after clear: " << str1.Getlenght() << endl;

	return 0;
	// task 3

}