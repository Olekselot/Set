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
	Set() :head(nullptr), size(0)
	{}
	Set(const Set& S) :head(S.head), size(S.size)
	{}
	Set(T* elements, size_t n)
	{
		head = new Node(elements[0]);
		size = 1;
		for (size_t i = 1; i < n; ++i)
		{
			add_element(elements[i]);
			++size;
		}
	}
	Set(T element)
	{}
	~Set()
	{}
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

template<typename T>
inline Set<T>::Set(): head(nullptr), size(0){}

template<typename T>
inline Set<T>::Set(const Set& S): head(S.head), size(S.size) {}

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
inline std::ostream& operator<<(std::ostream& out, const Set<T>& S)
{
	S.write_to(out);
	return out;
}
