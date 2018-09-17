#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(const String name, int accountNumber, int money): name(name)
{
	this->accountNumber = accountNumber;
	this->money = money;
}

int Account::getID() const
{
	return accountNumber;
}

void Account::addMoney(int money)
{
	this->money += money;
	cout << "잔액은 " << this->money << "입니다. \n\n";
}

void Account::minMoney(int money)
{
	/*
	if (this->money < money)
	{
		cout << "잔액이 부족합니다. \n\n";
		return;
	}
	*/
	this->money -= money;
	cout << "잔액은 " << this->money << "입니다. \n\n";
}
int Account::getMoney() const
{
	return money;
}

void Account::show() const
{
	cout << "이름: " << name << endl;
	cout << "계좌번호: " << accountNumber << endl;
	cout << "잔액: " << money << endl << endl;

}

