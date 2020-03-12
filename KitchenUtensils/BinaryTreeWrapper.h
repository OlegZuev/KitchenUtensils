#pragma once
#include "BinaryTree.h"
#include "Stove.h"

template<class T>
class BinaryTreeWrapper {
public:
	BinaryTreeWrapper() = default;
	~BinaryTreeWrapper();
	BinaryTreeWrapper(BinaryTreeWrapper& other);
	BinaryTreeWrapper& operator=(BinaryTreeWrapper other);
	BinaryTreeWrapper(BinaryTreeWrapper&& other) noexcept;
	BinaryTreeWrapper& operator=(BinaryTreeWrapper&& other) noexcept;

	void add(T* new_element);
	void remove(int inventory_number);
	void forwardPrint();
	void backwardPrint();
	void symmetricPrint();
	bool exists(int inventory_number);

private:
	BinaryTree<T>* root{};

	friend void swap(BinaryTreeWrapper& lhs, BinaryTreeWrapper& rhs) noexcept;
};

template <class T>
BinaryTreeWrapper<T>::~BinaryTreeWrapper() {
	BinaryTree<T>::clear(root);
}

template <class T>
BinaryTreeWrapper<T>::BinaryTreeWrapper(BinaryTreeWrapper& other) : root(other.root) {}

template <class T>
BinaryTreeWrapper<T>& BinaryTreeWrapper<T>::operator=(BinaryTreeWrapper other) {
	swap(*this, other);

	return *this;
}

template <class T>
BinaryTreeWrapper<T>::BinaryTreeWrapper(BinaryTreeWrapper&& other) noexcept {
	swap(*this, other);
}

template <class T>
BinaryTreeWrapper<T>& BinaryTreeWrapper<T>::operator=(BinaryTreeWrapper&& other) noexcept {
	swap(*this, other);

	return *this;
}

template <class T>
void BinaryTreeWrapper<T>::add(T* new_element) {
	if (new_element == nullptr)
		throw std::invalid_argument("new_element can't be null");

	BinaryTree<T>::add(root, new_element);
}

template <class T>
void BinaryTreeWrapper<T>::remove(const int inventory_number) {
	if (inventory_number <= 0)
		throw std::invalid_argument("inventory_number should be greater than 0");

	auto dummy_utensil = new Stove(inventory_number, "");
	root = BinaryTree<T>::remove(root, dummy_utensil);
	delete dummy_utensil;
}

template <class T>
void BinaryTreeWrapper<T>::forwardPrint() {
	BinaryTree<T>::forwardPrint(root);
}

template <class T>
void BinaryTreeWrapper<T>::backwardPrint() {
	BinaryTree<T>::backwardPrint(root);
}

template <class T>
void BinaryTreeWrapper<T>::symmetricPrint() {
	BinaryTree<T>::symmetricPrint(root);
}

template<class T>
bool BinaryTreeWrapper<T>::exists(const int inventory_number) {
	auto dummy_utensil = new Stove(inventory_number, "");
	auto result = BinaryTree<T>::exists(root, dummy_utensil);
	delete dummy_utensil;
	return result;
}

template <class T>
void swap(BinaryTreeWrapper<T>& lhs, BinaryTreeWrapper<T>& rhs) noexcept {
	using std::swap;
	swap(lhs.root, rhs.root);
}