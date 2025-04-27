#include <cstdio>
#include <cstring>
#include <conio.h>
#include "UserData.h"

int UserData::nUserDataCounter = 0;

UserData::UserData(void)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}

UserData::UserData(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szPhone, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}

UserData::~UserData(void)
{
	nUserDataCounter--;
}

const char* UserData::getKey(void)
{
	return szName;
}

void UserData::printNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n",
		this,
		szName, szPhone,
		getNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}