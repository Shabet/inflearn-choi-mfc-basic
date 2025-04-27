#pragma once

class MyNode
{
	friend class MyList;

public:
	MyNode(void) = default;
	virtual ~MyNode(void) = default;

	MyNode* getNext(void) const {
		return pNext;
	}

	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

private:
	MyNode *pNext = nullptr;
};