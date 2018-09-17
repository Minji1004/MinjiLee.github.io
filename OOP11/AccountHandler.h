#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "ArrayTemplate.h"

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class AccountHandler
{
	BoundCheckTemplateArray<Account*> accountList;
	//Account * accountList[100];
	int accountNum;
public:
	AccountHandler() :accountNum(0){}
	void NewAccount();
	int Search() const;
	void Deposit();
	void Withdraw();
	void ShowAll() const;
	~AccountHandler();	
};

#endif // !__ACCOUNT_HANDLER_H__