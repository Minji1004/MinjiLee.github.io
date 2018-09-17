#include <iostream>
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "ArrayTemplate.h"
#include "ArrayTemplate.cpp"
#include "Exception.h"
using namespace std;

namespace CREDIT_CLASS
{
	enum { CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 2 };
}

void AccountHandler::NewAccount()
{
	int choice;

	cout << "������ ���¸� �����Ͻʽÿ�. \n";
	cout << "1. ���뿹�ݰ��� \n";
	cout << "2. �ſ�ŷڰ��� \n";
	cout << "�Է�: ";
	cin >> choice; cout << endl;

	String name;
	int number;
	int money;

	cout << "�̸��� �Է��Ͻʽÿ�: \n";
	cin >> name;
	cout << "���¹�ȣ�� �Է��Ͻʽÿ�: \n";
	cin >> number;

	while(1){
		try{
			cout << "�Ա��� ���� �Է��Ͻʽÿ�: \n";
			cin >> money;
			if (money < 0)
			{
				DepositException expn(money);
				throw expn;
			}
			break;
		}
		catch(AccountException& expn){
			expn.ShowExceptionReason();
		}
	}

	if (choice == 1)
	{
		accountList[accountNum++] = new NormalAccount(name, number, money);
		return;
	}
	else if (choice == 2)
	{
		int creditClass;

		while(1)
		{ 
			int choice2;
			cout << "�ſ����� �������ֽʽÿ�: \n";
			cout << "1. A��� \n";
			cout << "2. B��� \n";
			cout << "3. C��� \n";
			cout << "�Է�: \n";
			cin >> choice2; cout << endl;
			
			try{
				switch (choice2)
				{
				case 1:
					creditClass = CREDIT_CLASS::CREDIT_A;
					break;
				case 2:
					creditClass = CREDIT_CLASS::CREDIT_B;
					break;
				case 3:
					creditClass = CREDIT_CLASS::CREDIT_C;
					break;
				default:
					throw - 1;
				}
				break;
			}
			catch (int)
			{
				cout << "�߸� �Է��ϼ̽��ϴ�.����� �ٽ� �Է����ֽʽÿ�. \n";
			}
		}
		accountList[accountNum++] = new HighCreditAccount(name, number, money, creditClass);
	}
	else
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. ó������ �ٽ� �������ֽʽÿ�. \n";
		return;
	}

}


int AccountHandler::Search() const
{
	int number;
	cout << "ã�� ���� ��ȣ�� �Է����ֽʽÿ�: ";
	cin >> number; cout << endl;

	int idx = 0;
	for (idx = 0; idx < accountNum; idx++)
	{
		if (accountList[idx]->getID() == number)
			return idx;
	}

	cout << "ã�� ����� ���°� �������� �ʽ��ϴ�. \n";
	return -1;
}

void AccountHandler::Deposit()
{
	int idx = Search();

	if (idx != -1)
	{
		int depositM;
		while(1){
			try{
				cout << "�Ա��� �ݾ��� �Է����ֽʽÿ�: \n";
				cin >> depositM;
				if(depositM <0){
					DepositException expn(depositM);
					throw expn;
				}
				break;
			}
			catch (AccountException& expn)
			{
				expn.ShowExceptionReason();
			}
		}
		accountList[idx]->addMoney(depositM);
		return;
	}
	else
		return;
}

void AccountHandler::Withdraw()
{
	int idx = Search();

	if (idx != -1)
	{
		int withdrawM;
		while (1) {
			try {
				cout << "����� �ݾ��� �Է����ֽʽÿ�: \n";
				cin >> withdrawM;
				if (withdrawM > accountList[idx]->getMoney() || withdrawM < 0)
				{
					WithdrawException expn(withdrawM);
					throw expn;
				}
				break;
			}
			catch (AccountException& expn)
			{
				expn.ShowExceptionReason();
			}
		}

		accountList[idx]->minMoney(withdrawM);

		return;
	}
	else
		return;
}

void  AccountHandler::ShowAll() const
{
	int idx = 0;
	for (idx = 0; idx < accountNum; idx++)
		accountList[idx]->show();

	return;
}

AccountHandler::~AccountHandler()
{
	for (int idx = 0; idx < accountNum; idx++)
		delete accountList[idx];
}