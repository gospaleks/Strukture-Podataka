#pragma once
#include "HashObject.h"
class ScatterObject :
	public HashObject
{
	
public:
	int status; //0-slobodan, 1-obrisan, 2-zauzet
	ScatterObject();
	ScatterObject(const char* k, const char* i, const char* p, const char* a);
	ScatterObject(ScatterObject const& obj);
	ScatterObject& operator = (ScatterObject const& obj);
};

