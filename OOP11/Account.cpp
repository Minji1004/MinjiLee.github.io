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
	cout << "�ܾ��� " << this->money << "�Դϴ�. \n\n";
}

void Account::minMoney(int money)
{
	/*
	if (this->money < money)
	{
		cout << "�ܾ��� �����մϴ�. \n\n";
		return;
	}
	*/
	this->money -= money;
	cout << "�ܾ��� " << this->money << "�Դϴ�. \n\n";
}
int Account::getMoney() const
{
	return money;
}

void Account::show() const
{
	cout << "�̸�: " << name << endl;
	cout << "���¹�ȣ: " << accountNumber << endl;
	cout << "�ܾ�: " << money << endl << endl;

}

