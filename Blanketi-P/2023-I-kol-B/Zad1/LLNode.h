#pragma once

class LLNode
{
public:
	int info;
	LLNode* next;

	LLNode();
	LLNode(int _info);
	LLNode(int _info, LLNode* _next);
	~LLNode();
};

