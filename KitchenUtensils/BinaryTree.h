#pragma once
#include <algorithm>

template<class T>
class BinaryTree {
public:
	BinaryTree();
	static void add(BinaryTree*& node, T* new_element);
	static BinaryTree<T>* remove(BinaryTree* node, T* element);
	static void forwardPrint(BinaryTree* node);
	static void backwardPrint(BinaryTree* node);
	static void symmetricPrint(BinaryTree* node);
	static void clear(BinaryTree* node);

private:
	BinaryTree* left;
	BinaryTree* right;
	T* current_element;
	unsigned char height;

	static void turnLeft(BinaryTree*& node);
	static void turnRight(BinaryTree*& node);
	static void updateHeight(BinaryTree* node);
	static unsigned char getHeight(BinaryTree* node);
	static int balanceFactor(BinaryTree* node);
	static BinaryTree<T>* balance(BinaryTree*& node);
	static BinaryTree* findMin(BinaryTree* node);
	static BinaryTree* detachMin(BinaryTree* node);
};


template <class T>
BinaryTree<T>::BinaryTree() {
	left = nullptr;
	right = nullptr;
	current_element = nullptr;
	height = 1;
}

template <class T>
void BinaryTree<T>::add(BinaryTree<T>*& node, T* new_element) {
	if (node == nullptr) {
		node = new BinaryTree;
		node->current_element = new_element;
	} else if (*new_element < *node->current_element) {
		add(node->left, new_element);
	} else if (*new_element > *node->current_element){
		add(node->right, new_element);
	} else {
		std::cout << "That element already exists: " << std::endl << *node->current_element << std::endl;
	}
	balance(node);
}

template <class T>
BinaryTree<T>* BinaryTree<T>::remove(BinaryTree* node, T* element) {
	if (node == nullptr)
		return nullptr;

	if (*element < *node->current_element)
		node->left = remove(node->left, element);
	else if (*element > *node->current_element)
		node->right = remove(node->right, element);
	else {
		auto left = node->left;
		auto right = node->right;
		delete node;
		if (right == nullptr)
			return left;

		auto right_min = findMin(right);
		right_min->right = detachMin(right);
		right_min->left = left;
		return balance(right_min);;
	}

	return balance(node);
}

template <class T>
void BinaryTree<T>::forwardPrint(BinaryTree* node) {
	if (node == nullptr)
		return;

	std::cout << *node->current_element << std::endl;
	symmetricPrint(node->left);
	symmetricPrint(node->right);
}

template <class T>
void BinaryTree<T>::backwardPrint(BinaryTree* node) {
	if (node == nullptr)
		return;

	symmetricPrint(node->left);
	symmetricPrint(node->right);
	std::cout << *node->current_element << std::endl;
}

template <class T>
void BinaryTree<T>::symmetricPrint(BinaryTree* node) {
	if (node == nullptr)
		return;

	symmetricPrint(node->left);
	std::cout << *node->current_element << std::endl;
	symmetricPrint(node->right);
}

template <class T>
void BinaryTree<T>::clear(BinaryTree* node) {
	if (node == nullptr)
		return;

	clear(node->left);
	clear(node->right);
	delete node;
}

template <class T>
void BinaryTree<T>::turnLeft(BinaryTree*& node) {
	auto temp = node->right;
	node->right = temp->left;
	temp->left = node;
	updateHeight(node);
	updateHeight(temp);
	node = temp;
}

template <class T>
void BinaryTree<T>::turnRight(BinaryTree*& node) {
	auto temp = node->left;
	node->left = temp->right;
	temp->right = node;
	updateHeight(node);
	updateHeight(temp);
	node = temp;
}

template <class T>
void BinaryTree<T>::updateHeight(BinaryTree* node) {
	auto left_height = getHeight(node->left);
	auto right_height = getHeight(node->right);
	node->height = std::max(left_height, right_height) + 1;
}

template <class T>
unsigned char BinaryTree<T>::getHeight(BinaryTree* node) {
	return node ? node->height : 0;
}

template <class T>
int BinaryTree<T>::balanceFactor(BinaryTree* node) {
	return getHeight(node->left) - getHeight(node->right);
}

template <class T>
BinaryTree<T>* BinaryTree<T>::balance(BinaryTree*& node) {
	updateHeight(node);
	if (balanceFactor(node) == -2) {
		if (balanceFactor(node->right) > 0)
			turnRight(node->right);
		turnLeft(node);
	} else if (balanceFactor(node) == 2) {
		if (balanceFactor(node->left) < 0)
			turnLeft(node->left);
		turnRight(node);
	}
	return node;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::findMin(BinaryTree* node) {
	return node->left ? findMin(node->left) : node;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::detachMin(BinaryTree* node) {
	if (node->left == nullptr)
		return node->right;

	node->left = detachMin(node->left);
	return balance(node);
}

