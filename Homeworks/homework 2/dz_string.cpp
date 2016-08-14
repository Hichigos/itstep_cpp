#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String
{
	int len = 0;
	int size = 0;
	char* str = nullptr;
	static int def_inc;

public:
	String(char* _str) :len(strlen(_str)), size(len > def_inc ? len + 1 : def_inc), str(new char[size])
	{
		strcpy_s(str, len + 1, _str);
	}

	String(const String& obj) : String(obj.str)
	{ }

	~String()
	{
		delete[] str;
	}

	void insert(char ch, int index)
	{
		if (index > len)
		{
			cerr << "Error:index > length!" << endl;
			index = len;
		}

		if (size < len + 2)
		{
			char* str_ = new char[size + def_inc];
			strcpy_s(str_, size, str);
			delete[] str;
			size += def_inc;
			str = str_;
		}

		for (int i = len; i >= index; --i)
			str[i + 1] = str[i];

		str[index] = ch;
		++len;
	}

	void insert(char* str2, int index)
	{
		for (int i = 0, l = strlen(str2); i < l; ++i)
			insert(str2[i], index++);
	}

	void remove(int index)
	{
		if (index > len)
		{
			cerr << "Error:index > length!" << endl;
			index = len;
		}

		for (int i = index + 1; i <= len; ++i)
			str[i - 1] = str[i];
		--len;
	}

	void remove(int index, int count)
	{
		if (index < len)
		{
			if ((index + count) > len)
				count = len - index;

			for (int i = index; i + count <= len; ++i)
				str[i] = str[i + count];

			len -= count;
		}
		else
			cerr << "Error: using index = size\n";
	}

	void append(char ch)
	{
		insert(ch, len);
	}

	void append(const String& str2)
	{
		for (int i = 0; i < str2.len; ++i)
			insert(str2.str[i], len);
	}

	char* search_substring(const char *str_)
	{
		if (strstr(str, str_) == nullptr) return "Substring not found";
		else return strstr(str, str_);
	}

	char* search_symbol(const char ch)
	{
		if (strchr(str, ch) == nullptr) return "Symbol not found";
		else return strchr(str, ch);
	}

	const String& operator+=(const String& str2)
	{

		append(str2);
		return *this;

	}

	String operator+(const String& str2)
	{
		String s(str);
		s += str2.str;
		return s;
	}

	bool operator>(const char* const str2)
	{
		return strcmp(str, str2) > 0;
	}

	bool operator<(const char* const str2)
	{
		return strcmp(str, str2) < 0;
	}

	bool operator==(const char* const str2)
	{
		return strcmp(str, str2) == 0;
	}

	bool operator!=(const char* const str2)
	{
		return !operator==(str2);
	}

	const String& operator=(const String& str2)
	{
		if (this != &str2) {
			len = str2.len;
			size = len > def_inc ? len + 1 : def_inc;
			delete[] str;
			str = new char[size];
			strcpy_s(str, size, str2.str);
		}
		return *this;
	}

	char& operator[](int index)
	{
		if (abs(index >= (len + 1)))
			index = len + 1;
		if (index < 0)
			index = len + index;
		return str[index];
	}

	operator const char* const() const
	{
		return str;
	}

	int to_value()
	{
		return strtol(str, nullptr, 10);
	}

	friend ostream& operator<<(ostream& out, const String& str2);

	friend istream& operator>>(istream& in, String& str2);

};

ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.str << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, String& obj)
{
	char* buff=new char[256];
	in >> buff;
	delete obj.str;
	obj.str = buff;
	return in;
}

int String::def_inc = 16;

int main()
{
	char key;
	String obj1("Hello Big World");
	String obj2("I will stay in here");
	String obj3("123");
	cout << "Menu: \n"
		<< "a.Assign\n"
		<< "b.Concatenation\n"
		<< "s.Enter a string\n"
		<< "d.Output string\n"
		<< "e.Compare\n"
		<< "f.Convert in value\n"
		<< "h.Search a symbol\n"
		<< "i.Search a substring\n"
		<< "n.Consult the index\n" << endl;
	cin >> key;
	switch (key)
	{
	case 'a':
		obj1 = obj2;
		cout << obj1;
		break;
	case 'b':
		obj1 += obj2;
		cout << obj1;
		break;
	case 's':
		cin >> obj2;
		cout << obj2;
		break;
	case 'd':
		cout << obj1;
		break;
	case 'e':
		if (obj1 == obj2) cout << "The string 1 equal string 2" << endl;
		if (obj1 > obj2) cout << "String 1 larger,than string 2" << endl;
		else cout << "String 2 larger,than string 1" << endl;
		break;
	case 'f':
		cout << obj3.to_value();
		break;
	case 'h':
		cout << obj1.search_symbol('g');
		break;
	case 'i':
		cout << obj1.search_substring("Big");
		break;
	case 'n':
		cout << obj1[6];
		break;
	}
	return 0;
}