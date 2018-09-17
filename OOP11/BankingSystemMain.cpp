#include <iostream>
#include <cstring>

#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "ArrayTemplate.h"
#include "ArrayTemplate.cpp"

using namespace std;

int main(void)
{
	AccountHandler handler;
	int choice;

	while (1)
	{
		showMenu();

		cout << "¼±ÅÃ: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			handler.NewAccount();
			cout << endl;
			break;
		case DEPOSIT:
			handler.Deposit();
			break;
		case WITHDRAW:
			handler.Withdraw();
			break;
		case INQUIRE:
			handler.ShowAll();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}

	return 0;
	
}