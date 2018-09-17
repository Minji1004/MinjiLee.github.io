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

	cout << "개설할 계좌를 선택하십시오. \n";
	cout << "1. 보통예금계좌 \n";
	cout << "2. 신용신뢰계좌 \n";
	cout << "입력: ";
	cin >> choice; cout << endl;

	String name;
	int number;
	int money;

	cout << "이름을 입력하십시오: \n";
	cin >> name;
	cout << "계좌번호를 입력하십시오: \n";
	cin >> number;

	while(1){
		try{
			cout << "입금할 돈을 입력하십시오: \n";
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
			cout << "신용등급을 선택해주십시오: \n";
			cout << "1. A등급 \n";
			cout << "2. B등급 \n";
			cout << "3. C등급 \n";
			cout << "입력: \n";
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
				cout << "잘못 입력하셨습니다.등급을 다시 입력해주십시오. \n";
			}
		}
		accountList[accountNum++] = new HighCreditAccount(name, number, money, creditClass);
	}
	else
	{
		cout << "잘못 입력하셨습니다. 처음부터 다시 시작해주십시오. \n";
		return;
	}

}


int AccountHandler::Search() const
{
	int number;
	cout << "찾는 계좌 번호를 입력해주십시오: ";
	cin >> number; cout << endl;

	int idx = 0;
	for (idx = 0; idx < accountNum; idx++)
	{
		if (accountList[idx]->getID() == number)
			return idx;
	}

	cout << "찾는 사람의 계좌가 존재하지 않습니다. \n";
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
				cout << "입금할 금액을 입력해주십시오: \n";
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
				cout << "출금할 금액을 입력해주십시오: \n";
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