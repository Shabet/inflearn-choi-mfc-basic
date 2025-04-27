#include <cstdio>
#include <cstring>
#include <conio.h>
#include "MyList.h"
#include "UserData.h"

MyList::MyList(MyNode *pHead)
{
	this->pHead = pHead;
}

MyList::~MyList(void)
{
	releaseList();
}

int MyList::addNewNode(MyNode *pNewNode)
{
	if (findNode(pNewNode->getKey()) != nullptr)
	{
		delete pNewNode;

		return 0;
	}

	pNewNode->pNext = pHead->pNext;
	pHead->pNext = pNewNode;

	return 1;
}

void MyList::printAll(void)
{
	MyNode *pTmp = pHead->pNext;

	while (pTmp != nullptr)
	{
		pTmp->printNode();
		pTmp = pTmp->pNext;
	}

	printf("UserData Counter : %d\n",
		UserData::getUserDataCounter() - 1);

	_getch();
}

MyNode* MyList::findNode(const char* pszKey)
{
	MyNode *pTmp = pHead->pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->getKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int MyList::removeNode(const char* pszKey)
{
	MyNode *pPrevNode = pHead;
	MyNode *pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->getKey(), pszKey) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

void MyList::releaseList(void)
{
	MyNode *pTmp = pHead;
	MyNode *pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	pHead = NULL;
}