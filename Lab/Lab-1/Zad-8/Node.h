#pragma once

template <class T>
class Node
{
public:
	int i, j;
	T el;
	Node<T>* kLink;
	Node<T>* vLink;

	Node(int _i, int _j, T _el);
};

template<class T>
inline Node<T>::Node(int _i, int _j, T _el)
{
	i = _i;
	j = _j;
	el = _el;
	kLink = nullptr;
	vLink = nullptr;
}
