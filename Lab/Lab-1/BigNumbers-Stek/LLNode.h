#pragma once
template <class T>
class LLNode
{
public:
	T info;
	LLNode* next;

	LLNode() { next = nullptr; }
	LLNode(T el, LLNode* _next = nullptr) {
		info = el;
		next = _next;
	}

	~LLNode() { }
};

