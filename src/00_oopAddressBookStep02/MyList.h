#pragma once
#include "MyNode.h"

class MyNode;

class MyList
{
public:
	MyList(MyNode *pHead);
	~MyList(void);

	MyNode* findNode(const char* pszKey);
	int addNewNode(MyNode* pNewNode);
	void printAll(void);
	int removeNode(const char* pszKey);

protected:
	void releaseList(void);
	MyNode *pHead = nullptr;
};