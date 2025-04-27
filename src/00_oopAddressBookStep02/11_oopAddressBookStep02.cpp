#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int main()
{
	MyList DB(new UserData);
	UserInterface UI(DB);
	UI.run();
}
