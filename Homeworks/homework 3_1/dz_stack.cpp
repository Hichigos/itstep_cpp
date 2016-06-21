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

int main()
{
	Stack<int> obj(32);
	int key = 0;
	cout << "Menu :\n"
		"1.Add 100 items , 10 remove and show the top item .\n"
		"2.Add 100 items , 101 remove and show the top item .\n"
		"3.Add 100 items , 99 remove and show the top item .\n";
	cin >> key;
	switch (key)
	{
	case 1:
		for (int i = 0; i < 100; ++i)
			obj.push(i);
		for (int i = 0; i < 10; ++i)
			obj.pop();
		cout << obj.top();
		break;
	case 2:
		for (int i = 0; i < 100; ++i)
			obj.push(i);
		for (int i = 0; i < 101; ++i)
			obj.pop();
		cout << obj.top();
		break;
	case 3:
		for (int i = 0; i < 100; ++i)
			obj.push(i);
		for (int i = 0; i < 99; ++i)
			obj.pop();
		cout << obj.top();
		break;

	default: cerr << "Wrong operation!" << endl;
	}
	return 0;
}