#pragma once

#include <iostream>
using namespace std;

class BTNodeInt
{
public:
	int key;
	BTNodeInt* left, * right;

public:
	BTNodeInt()
		: key(), left(nullptr), right(nullptr) { }
	BTNodeInt(int el)
		: key(el), left(nullptr), right(nullptr) { }
	BTNodeInt(int el, BTNodeInt* lt, BTNodeInt* rt) 
		: key(el), left(lt), right(rt) { }
	bool isEQ(int el) const {
		if (key == el) return true;
		else return false;
	};
	void setKey(int el) { key = el; }
	int getKey() const { return key; }
	void visit() const { cout << key << " "; }
};

