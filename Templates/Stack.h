#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
class Stack
{
private:
	struct element
	{
		T num;
		element* next_elem_ptr;

		T GetNum() { return num; }
		void SetNum(T _num) { num = _num; }
		element* GetNext_Ptr() { return next_elem_ptr; }
		void SetNext_Ptr(element* next_ptr) { next_elem_ptr = next_ptr; }
	};
	element* last_element;
	int const size_of_stack;
	int ammount_of_elements;

	float recursion_copy(element* ptr_on_elem);

public:
	Stack();
	Stack(const Stack<T>& other);
	~Stack();

	void push(T num);
	T pop();
	bool isempty();
	bool isfull();
	int get_size();

	Stack<T>& operator=(const Stack& other);

	T operator-();

	Stack<T>& operator+=(T add_num);

	template<class D>
	friend ostream& operator<<(ostream& out, const Stack<D>& A);
	template<class D>
	friend istream& operator>>(istream& in, Stack<D>& V);
};





template<class D>
ostream& operator<<(ostream& out, const Stack<D>& A)
{
	Stack<D> temp(A);
	while (!temp.isempty())
		out << " | " << temp.pop() << " | " << endl;
	out << " \\___/" << endl;
	return out;
}

template<class D>
istream& operator>>(istream& in, Stack<D>& V)
{
	while (!V.isempty())
		V.pop();
	D num;
	for (size_t i = 0; i < V.size_of_stack; i++)
	{
		in >> num;
		V.push(num);
	}
	return in;
}


template<class T>
Stack<T>::Stack() : size_of_stack(rand() % 10 + 5), last_element(nullptr), ammount_of_elements(0) {}

template<class T>
Stack<T>::Stack(const Stack& other) : size_of_stack(other.size_of_stack), ammount_of_elements(0)
{
	this->push(this->recursion_copy(other.last_element));
}

template<class T>
Stack<T>::~Stack()
{
	while (!this->isempty())
		this->pop();
}

template<class T>
void Stack<T>::push(T num)
{
	if (!isfull())
	{
		if (isempty())
		{
			last_element = new element;
			last_element->SetNext_Ptr(nullptr);
			last_element->SetNum(num);
			ammount_of_elements++;
		}
		else
		{
			element* temp = last_element;
			last_element = new element;
			last_element->SetNext_Ptr(temp);
			last_element->SetNum(num);
			ammount_of_elements++;
		}
	}
	else cout << "Стек полон, невозможно добавить новый элемент!\n";
}

template<class T>
T Stack<T>::pop()
{
	T number;
	if (!isempty())
	{
		number = last_element->GetNum();
		element* temp = last_element->GetNext_Ptr();
		delete last_element;
		last_element = temp;
		ammount_of_elements--;
	}
	else
		number = -1;
	return number;
}

template<class T>
bool Stack<T>::isempty()
{
	return !ammount_of_elements;
}

template<class T>
bool Stack<T>::isfull()
{
	return ammount_of_elements == size_of_stack;
}

template<class T>
inline int Stack<T>::get_size()
{
	return size_of_stack;
}

template<class T>
float Stack<T>::recursion_copy(element* ptr_on_elem)
{
	T chislo;
	if (ptr_on_elem->GetNext_Ptr() != nullptr)
	{
		chislo = recursion_copy(ptr_on_elem->GetNext_Ptr());
		if (!this->isfull()) this->push(chislo);
	}
	return ptr_on_elem->GetNum();
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	while (!this->isempty())
		this->pop();
	if (other.last_element != nullptr)
		this->push(this->recursion_copy(other.last_element));
	return *this;
}

template<class T>
T Stack<T>::operator-()
{
	return pop();
}

template<class T>
Stack<T>& Stack<T>::operator+=(T add_num)
{
	push(add_num);
	return *this;
}