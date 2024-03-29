#pragma once
#include <iostream>
template <typename T>
class Set
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node(T val, Node* N = nullptr): value(val), next(N) {}
	};
	Node* head;
	size_t size;

public:
	Set();
	Set(const Set& S);
	Set(T* elements, size_t n);
	Set(T element);
	~Set();
	size_t size()const;
	Set<T>& operator=(const Set& S);
	Set<T>& add_element(T element);
	Set<T>& add_range(T* elements, size_t n);
	Set<T> set_union(const Set& S)const;
	Set<T> set_difference(const Set& S)const;
	Set<T> set_intersect(const Set& S)const;
	Set<T> set_sum_diff(const Set& S)const;
	bool is_valid(const T& x)const;
	Set<T>& remove(const T& x)const;
	void write_to(std::ostream& out)const;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& S);

template <typename T>
Set<T>::Set() : head(new Node(T ())), size(0) {}

template<typename T>
Set<T>::Set(const Set& S): size(S.size)
{
	head = new Node(S.head->value);
	Node* curr = S.head->next;
	Node* temp = head;
	while (curr != nullptr)
	{
		temp->next = new Node(curr->value);
		temp = temp->next;
		curr = curr->next;
	}
}

template<typename T>
Set<T>::Set(T* elements, size_t n): size(0)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (!is_valid(elements[i]))
		{
			add_element(elements[i]);
			++size;
		}
	}
}

template<typename T>
Set<T>::Set(T element)
{
	head = new Node(element);
	size = 1;
}

template<typename T>
Set<T>::~Set()
{
	while (head != nullptr)
	{
		Node* victom = head;
		head = head->next;
		delete victom;
	}
}

template<typename T>
inline Set<T>& Set<T>::add_element(T element)
{
	if (is_valid(element))
		throw exception("This element is already in the set...Add_element funktion run into problem...");
	else
	{
		if (head == nullptr || element < head->value)
		{
			head = new Node(element, head);
		}
		else
		{
			Node* curr = head;
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
			++size;
		}
	}
	return *this;
}

template<typename T>
Set<T> Set<T>::set_difference(const Set& S)const
{
	Set<T> result;
	Node* result_pointer = result.head;
	Node* this_pointer = head;
	Node* S_pointer = S.head;
	while (this_pointer != nullptr && S_pointer != nullptr)
	{
		if (this_pointer->value < S_pointer->value)
		{
			result_pointer->next = new Node(this_pointer->value);
			result_pointer = result_pointer->next;
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
	Node* this_pointer = head;
	Node* S_pointer = S.head;
	Node* result_pointer = result.head;
	while (this_pointer != nullptr && S_pointer != nullptr)
	{
		if (this_pointer->value < S_pointer->value)
		{
			result_pointer->next = new Node(this_pointer->value);
			result_pointer = result_pointer->next;
			this_pointer = this_pointer->next;
		}
		else if (S_pointer->value < this_pointer->value)
		{
			result_pointer->next = new Node(S_pointer->value);
			result_pointer = result_pointer->next;
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
	}
	while (S_pointer != nullptr)
	{
		result_pointer->next = new Node(S_pointer->value);
		S_pointer = S_pointer->next;
		result_pointer = result_pointer->next;
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
	Node* this_pointer = head;
	Node* S_pointer = S.head;
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
inline Set<T>& Set<T>::operator=(const Set& S){
	size = S.size;
	head = new Node(nullptr);
	this.set_union(S);
}

template<typename T>
inline Set<T> Set<T>::set_union(const Set& S) const{
	Set<T> unswer;
	Node* first = this->head;
	Node* second = S.head;
	Node* third = unswer.head;
	size_t ThisSize = S.size + this->size;

	for (size_t i = 0; i <= ThisSize; ++i) {
		if (first.Node->next == nullptr) {
			for (i <= ThisSize; ++i){

			}
		}
		else if (second.Node->next == nullptr) {
			for (i <= ThisSize; ++i){

			}
		}
		else if (first.Node->value == second.Node->vaue) {

		}
		else if (first.Node->value > second.Node->vaue) {

		}
		else {

		}
	}
}
template<typename T>
inline void Set<T>::write_to(std::ostream& out) const
{
	// check if works correctly
	Node* temp = head;
	while (temp != nullptr)
	{
		out << temp->value << ' ';
		temp = temp->next;
	}
}

template<typename T>
inline size_t Set<T>::size() const
{
	return size;
}

template<typename T>
inline Set<T>& Set<T>::remove(const T& x) const
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
			return *this;
		}
		prev = curr;
		curr = curr->next;
	}

	return *this;
}

template<typename T>
bool Set<T>::is_valid(const T& x)const
{
	Node* curr = head;
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
