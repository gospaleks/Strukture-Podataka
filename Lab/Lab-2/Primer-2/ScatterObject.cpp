#include "ScatterObject.h"



ScatterObject::ScatterObject():HashObject()
{
	status = 0;
}


ScatterObject::ScatterObject(const char* k, const char* _nazivModela, int _godinaProizvodnje) : HashObject(k, _nazivModela, _godinaProizvodnje)
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

