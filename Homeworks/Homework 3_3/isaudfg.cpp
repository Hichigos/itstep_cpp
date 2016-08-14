#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

class String
{
	int len = 0;
	int size = 0;
	char* str = nullptr;
	static int def_inc;

public:
	String (int _size) : size(_size), str(new char[size])
	{}
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

	friend ostream& operator<<(ostream& out, const String& str2);

	friend istream& operator>>(istream& in, String& str2);

	void show_ascII_codes()
	{
		for (int i = 0; i < size; ++i)
			cout << (int)str[i] << " ";
		cout << endl;
	}
	void to_upper()
	{
		for (int i = 0; i < size; ++i)
			cout << (char)toupper(str[i]);
		cout << endl;
	}

	void to_lower()
	{
		for (int i = 0; i < size; ++i)
			cout << (char)tolower(str[i]);
		cout << endl;
	}

	char* get_str()  
	{
		return str;
	}

	int get_size() const
	{
		return size;
	}

	int to_integer()
	{
		return atoi(str);
	}

	double to_double()
	{
		return atof(str);
	}

};

class Queue
{
	int m_def_inc = 16;
	int m_capacity = m_def_inc;
	int m_size = 0;
	String m_arr{ m_capacity };
public:
	Queue() = default;
	explicit Queue(int increase)
		: m_def_inc(increase), m_capacity(m_def_inc), m_size(0)
	{}
	/*Queue(const Queue& obj) : m_def_inc(obj.m_def_inc), m_capacity(obj.m_capacity), m_size(obj.m_size)
	{
		for (int i = 0; i < size; ++i)
			m_arr[i] = obj.m_arr[i];
	}*/
	/*const Queue& operator=(const Queue& obj)
	{
		if (this != &obj)
		{
			m_def_inc = obj.m_def_inc;
			m_capacity = obj.m_capacity;
			m_size = obj.m_size;
			m_arr = obj.m_arr;
		}
		return *this;
	}*/
	void push(const char& data_)
	{
		//if (m_size == m_capacity) realloc(m_capacity + m_def_inc);
		m_arr.get_str()[m_size++] = data_;
	}
	void pop()
	{
		if (m_size) {
			//вызвать remove
			--m_size;
		}
		else cerr << "Queue is empty" << endl;
	}

	T first()
	{
		if (m_size)
			return m_arr[0];
		cerr << "Queue is empty" << endl;
		return T();
	}

	T last()
	{
		if (m_size)
			return m_arr[m_size];
		cerr << "Queue is empty" << endl;
		return T();
	}

	~Queue()
	{
	}
private:
	/*void realloc(int capacity)
	{
	T* new_arr = new T[capacity];
	for (int i = 0; i < m_capacity; ++i)
	new_arr[i] = m_arr[i];
	delete[] m_arr;
	m_arr = new_arr;
	m_capacity = capacity;
	}*/
};


ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.str << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& in, String& obj)
{
	char* buff = new char[256];
	in >> buff;
	delete obj.str;
	obj.str = buff;
	return in;
}

int String::def_inc = 16;

int main()
{
	String obj("12.3");
	cout << obj.to_double()+16;
}