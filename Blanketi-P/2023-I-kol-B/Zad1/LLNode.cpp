#include "LLNode.h"

LLNode::LLNode()
{
	next = nullptr;
	info = 0;
}

LLNode::LLNode(int _info) : info(_info)
{
	next = nullptr;
}

LLNode::LLNode(int _info, LLNode* _next) : info(_info), next(_next)
{
}

LLNode::~LLNode()
{
}
