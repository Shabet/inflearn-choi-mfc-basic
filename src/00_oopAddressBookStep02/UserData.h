#pragma once
#include "MyNode.h"

class UserData : public MyNode
{
public:
	UserData(void);
	UserData(const char* pszName, const char* pszPhone);
	~UserData(void);

	const char* getName(void) const {
		return szName;
	}
	const char*	getPhone(void) const {
		return szPhone;
	}
	static int getUserDataCounter(void) {
		return nUserDataCounter;
	}

protected:
	char szName[32];
	char szPhone[32];

	static int nUserDataCounter;

public:
	virtual const char* getKey(void);
	virtual void printNode(void);
};