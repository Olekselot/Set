#pragma once
#include <iostream>
#include <exception>
using namespace std;
template <typename T>
class Set
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node(T val, Node* N = nullptr) : value(val), next(N) {}
	};
	Node* head;
	size_t size;

public:
	Set();
	Set(const Set& S);
	Set(T* elements, size_t n);
	Set(T element);
	~Set();
	size_t size_of_set()const;
	Set<T>& operator=(const Set& S);
	Set<T>& add_element(T element);
	Set<T>& add_range(T* elements, size_t n);
	Set<T>& clear_set();
	Set<T> set_union(const Set& S)const;
	Set<T> set_difference(const Set& S)const;
	Set<T> set_intersect(const Set& S)const;
	Set<T> set_sum_diff(const Set& S)const;
	bool is_valid(const T& x)const;
	Set<T>& remove(const T& x);
	void write_to(std::ostream& out)const;

	//допоміжні функції для тестів
	bool sets_are_equal(const Set<T>& A);
	bool is_empty()const;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& S);

template<typename T>
bool Set<T>::sets_are_equal(const Set<T>& A)
{
	bool equalty = true;
	Node* this_ptr = head->next;
	Node* A_pointer = A.head->next;
	while (A_pointer != nullptr && this_ptr != nullptr)
	{
		if (A_pointer->value != this_ptr->value)
		{
			equalty = false;
			break;
		}
		A_pointer = A_pointer->next;
		this_ptr = this_ptr->next;
	}
	if (A_pointer != nullptr || this_ptr != nullptr)
		equalty = false;
	return equalty;
}

template<typename T>
bool Set<T>::is_empty()const
{
	if (head->next == nullptr)
		return true;
	else
		return false;
}

template <typename T>
Set<T>::Set() : head(new Node(T())), size(0) {}

template<typename T>
Set<T>::Set(const Set& S) : Set<T>(), size(S.size)
{
	S.head = S.head->next;
	if (S.head == nullptr)
		head = nullptr;
	else
	{
		head->next = new Node(S.head->value);
		Node* curr = S.head->next;
		Node* temp = head->next;
		while (curr != nullptr)
		{
			temp->next = new Node(curr->value);
			temp = temp->next;
			curr = curr->next;
		}
	}
}

template<typename T>
Set<T>::Set(T* elements, size_t n) : Set<T>(), size(0)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (!is_valid(elements[i]))
		{
			add_element(elements[i]);
		}
	}
}
template<typename T>
Set<T>::Set(T element) :Set<T>()
{
	head->next = new Node(element);
	size = 1;
}

template<typename T>
Set<T>::~Set()
{
	this->clear_set();
}

template<typename T>
inline Set<T>& Set<T>::add_element(T element)
{
	if (is_valid(element))
		throw exception("This element is already in the set...Add_element funktion run into problem...");
	else
	{
		if (head->next == nullptr || element < head->next->value)
		{
			head->next = new Node(element, head->next);
		}
		else
		{
			Node* curr = head->next;
			while (curr->next != nullptr && curr->next->value < element)
				curr = curr->next;
			curr->next = new Node(element, curr->next);
		}
		++size;
		return *this;
	}
}

template <typename T>
Set<T>& Set<T>::add_range(T* elements, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (!is_valid(elements[i]))
		{
			add_element(elements[i]);
		}
	}
	return *this;
}

template<typename T>
Set<T>& Set<T>::clear_set()
{
	Node* victom = head->next;
	while (victom != nullptr)
	{
		victom = victom->next;
		delete victom;
	}
	head->next = nullptr;
	this->size = 0;
	return *this;
}

template<typename T>
Set<T> Set<T>::set_difference(const Set& S)const
{
	Set<T> result;
	Node* result_pointer = result.head;
	Node* this_pointer = head->next;
	Node* S_pointer = S.head->next;
	while (this_pointer != nullptr && S_pointer != nullptr)
	{
		if (this_pointer->value < S_pointer->value)
		{
			result_pointer->next = new Node(this_pointer->value);
			result_pointer = result_pointer->next;
			++result.size;
			this_pointer = this_pointer->next;
		}
		else if (this_pointer->value == S_pointer->value)
		{
			this_pointer = this_pointer->next;
			S_pointer = S_pointer->next;
		}
		else if (S_pointer->value < this_pointer->value)
		{
			S_pointer = S_pointer->next;
		}
	}
	while (this_pointer != nullptr)
	{
		result_pointer->next = new Node(this_pointer->value);
		result_pointer = result_pointer->next;
		++result.size;
		this_pointer = this_pointer->next;
	}
	Node* victom = result.head;
	result.head = result.head->next;
	delete victom;
	return result;
}

template<typename T>
Set<T> Set<T>::set_sum_diff(const Set& S)const
{
	Set<T> result;
	Node* this_pointer = head->next;
	Node* S_pointer = S.head->next;
	Node* result_pointer = result.head;
	while (this_pointer != nullptr && S_pointer != nullptr)
	{
		if (this_pointer->value < S_pointer->value)
		{
			result_pointer->next = new Node(this_pointer->value);
			result_pointer = result_pointer->next;
			++result.size;
			this_pointer = this_pointer->next;
		}
		else if (S_pointer->value < this_pointer->value)
		{
			result_pointer->next = new Node(S_pointer->value);
			result_pointer = result_pointer->next;
			++result.size;
			S_pointer = S_pointer->next;
		}
		else if (this_pointer->value == S_pointer->value)
		{
			this_pointer = this_pointer->next;
			S_pointer = S_pointer->next;
		}
	}
	while (this_pointer != nullptr)
	{
		result_pointer->next = new Node(this_pointer->value);
		this_pointer = this_pointer->next;
		result_pointer = result_pointer->next;
		++result.size;
	}
	while (S_pointer != nullptr)
	{
		result_pointer->next = new Node(S_pointer->value);
		S_pointer = S_pointer->next;
		result_pointer = result_pointer->next;
		++result.size;
	}
	Node* victom = result.head;
	result.head = result.head->next;
	delete victom;
	return result;
}

template <typename T>
Set<T> Set<T>::set_intersect(const Set& S)const
{
	Set<T> result;
	Node* this_pointer = head->next;
	Node* S_pointer = S.head->next;
	Node* result_pointer = result.head;
	while (this_pointer != nullptr && S_pointer != nullptr)
	{
		if (this_pointer->value < S_pointer->value)
		{
			this_pointer = this_pointer->next;
		}
		else if (S_pointer->value < this_pointer->value)
		{
			S_pointer = S_pointer->next;
		}
		else if (this_pointer->value == S_pointer->value)
		{
			result_pointer->next = new Node(this_pointer->value);
			result_pointer = result_pointer->next;
			++result.size;
			this_pointer = this_pointer->next;
			S_pointer = S_pointer->next;
		}
	}
	Node* victom = result.head;
	result.head = result.head->next;
	delete victom;
	return result;
}
template<typename T>
Set<T>& Set<T>::operator=(const Set& S)
{
	if (this != &S)
	{
		this->clear_set();
		size = S.size;
		Node* curr = S.head;
		while (curr != nullptr)
		{
			this->add_element(curr->value);
			curr = curr->next;
		}
	}
	return *this;
}
template<typename T>
inline Set<T> Set<T>::set_union(const Set& S) const {
	Set<T> unswer;
	Node* first = this->head->next;
	Node* second = S.head->next;
	Node* third = unswer.head;
	while (first != nullptr && second != nullptr)
	{
		if (first->value < second->value) {
			third->next = new Node(first->value);
			first = first->next;
		}
		else if (first->value > second->value) {
			third->next = new Node(second->value);
			second = second->next;
		}
		else {
			third->next = new Node(first->value);
			first = first->next;
			second = second->next;
		}
		third = third->next;
		++unswer.size;
	}
	while(first != nullptr){
		third->next = new Node(first->value);
		first = first->next;
		third = third->next;
		++unswer.size;
	}
	while (second != nullptr) {
		third->next = new Node(second->value);
		second = second->next;
		third = third->next;
		++unswer.size;
	}
	return unswer;
}

template<typename T>
inline void Set<T>::write_to(std::ostream& out) const
{
	Node* temp = head->next;
	while (temp != nullptr)
	{
		out << temp->value << ' ';
		temp = temp->next;
	}
}

template<typename T>
inline size_t Set<T>::size_of_set() const
{
	return this->size;
}

template<typename T>
inline Set<T>& Set<T>::remove(const T& x)
{
	Node* curr = head;
	Node* prev = nullptr;

	while (curr != nullptr)
	{
		if (curr->value == x)
		{
			if (prev == nullptr)
			{
				head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			delete curr;
			--size;
			return *this;
		}
		prev = curr;
		curr = curr->next;
	}

	throw std::out_of_range("Element not found in set");
}

template<typename T>
bool Set<T>::is_valid(const T& x)const
{
	Node* curr = head->next;
	bool validness = false;
	while (curr != nullptr && curr->value <= x)
	{
		if (curr->value == x)
		{
			validness = true;
			break;
		}
		curr = curr->next;
	}
	return validness;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const Set<T>& S)
{
	S.write_to(out);
	return out;
}
