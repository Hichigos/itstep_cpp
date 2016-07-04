#include <iostream>

using namespace std;

template <class T>
class Stack
{
	int m_increase = 16;
	int m_capacity = m_increase;
	int m_size = 0;
	T* m_data = new T[m_capacity];
public:
	Stack() = default;

	explicit Stack(int increase)
		: m_increase(increase), m_capacity(m_increase), m_size(0), m_data(new T[m_capacity])
	{}

	Stack(const Stack&) = delete;

	void operator=(const Stack&) = delete;

	~Stack()
	{
		delete[] m_data;
	}

	void push(const T& data)
	{
		if (m_size == m_capacity)
			realloc(m_capacity + m_increase);
		m_data[m_size++] = data;
	}

	void pop()
	{
		if (m_size)
			--m_size;
		else
			std::cerr << "Error! Stack is empty!!!\n";
	}

	T top()
	{
		if (m_size)
			return m_data[m_size - 1];
		else
		{
			std::cerr << "Error! Stack is empty!!!\n";
			return T();
		}

	}

	int get_size()
	{
		return m_size;
	}

private:
	void realloc(int capacity)
	{
		T* new_data = new T[capacity];
		for (int i = 0; i < m_capacity; ++i)
			new_data[i] = m_data[i];

		delete[] m_data;
		m_data = new_data;
		m_capacity = capacity;
	}
};

class CharStack
{
	Stack<char> m_bracket;
public:
	explicit CharStack(int increase) : m_bracket(increase)
	{}

	CharStack(const CharStack&) = delete;

	void operator=(const CharStack&) = delete;

	void check_the_brackets(char* str)
	{
		for (unsigned int i = 0; i < strlen(str); ++i)
		{
			if ((str[i]== '{') || (str[i] == '(') || (str[i] == '['))
			{
				m_bracket.push(str[i]);
			}
			else if (str[i] == '}')
			{
				if (m_bracket.top() == '{')
					m_bracket.pop();
			}
			else if (str[i] == ')')
			{
				if (m_bracket.top() == '(')
					m_bracket.pop();
			}
			else if (str[i] == ']')
			{
				if (m_bracket.top() == '[')
					m_bracket.pop();
			}
		}
		if (m_bracket.get_size() == 0) cout << "all right!" << endl;
		else cout << "all bad! :(" << endl;
	}	

};

int main()
{
	CharStack obj(32);
	char* str = new char[32];
	cin >> str;
	obj.check_the_brackets(str);
	return 0;
}