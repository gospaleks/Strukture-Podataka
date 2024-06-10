#include "ScatterObject.h"



ScatterObject::ScatterObject():HashObject()
{
	status = 0;
}


ScatterObject::ScatterObject(const char* k, const char* i, const char* p, const char* a) :HashObject(k, i, p, a)
{
	status = 0;
}

ScatterObject::ScatterObject(ScatterObject const& obj):HashObject(obj)
{
	status = obj.status;
}

ScatterObject& ScatterObject::operator = (ScatterObject const& obj)
{
	if (this != &obj)
	{
		(HashObject&)(*this) = obj;
		status = obj.status;
	}
	return *this;
}

