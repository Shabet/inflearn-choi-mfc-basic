#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

UserInterface::UserInterface(MyList &rList)
	: list(rList)
{
}

UserInterface::~UserInterface(void)
{
}

void UserInterface::add(void)
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");
	gets_s(szPhone, sizeof(szPhone));

	UserData* pNewData = new UserData(szName, szPhone);
	list.addNewNode(pNewData);
}

int UserInterface::printUI(void)
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf_s("%d%*c", &nInput);

	return nInput;
}

void UserInterface::search(void)
{
	char szName[32] = { 0 };
	UserData *pNode = NULL;

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	pNode = static_cast<UserData*>(list.findNode(szName));

	if (pNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->getName(), pNode->getPhone(),
			pNode->getNext());
	}

	else
		puts("ERROR: 데이터를 찾을 수 없습니다.");

	_getch();
}

void UserInterface::remove(void)
{
	char szName[32] = { 0 };

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	if (list.removeNode(szName))
		puts("삭제완료.");
	else
		puts("ERROR: 삭제할 데이터를 찾을 수 없습니다.");
	_getch();
}

int UserInterface::run(void)
{
	int nMenu = 0;
	while ((nMenu = printUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:    //Add
			add();
			break;

		case 2:    //Search
			search();
			break;

		case 3:    //Print all
			list.printAll();
			break;

		case 4:    //Remove
			remove();
			break;
		}
	}

	return nMenu;
}