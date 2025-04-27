#pragma once

class MyList;

class UserInterface
{
public:
	UserInterface(MyList &rList);
	~UserInterface(void);
	void add(void);
	void search(void);
	void remove(void);
	int printUI(void);
	int run(void);

protected:
	MyList	 &list;
};