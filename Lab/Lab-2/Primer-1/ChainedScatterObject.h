#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(const char* k, const char* i, const char* p, const char* a): ScatterObject(k,i,p,a) { next = -1; }
	ChainedScatterObject(const char* k, const char* i, const char* p, const char* a, int n) : ScatterObject(k,i,p,a) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

