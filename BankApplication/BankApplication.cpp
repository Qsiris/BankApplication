#include <iostream>
#include <string>
using namespace std;

int user_choice;

// printing the interval of right anwser of user
void ErrorMessageNumberMustBeInInterval(int beginnig_of_interval, int ending_of_interval)
{
	cout << "You input wrong anwser!" << endl;
	cout << beginnig_of_interval << " < Your choice here < "<< ending_of_interval << endl;
}

void Greeting()
{
	cout << "Welcome to the bank's app called 'Eat money'!" << endl;
}

void ShowMainMenu()
{
	cout << "Input the choice:" << endl;
	cout << "1) Operations with bank account" << endl;
	cout << "2) Operations with debt card" << endl;
	cout << "3) Operatios with user account" << endl;
}

void ShowMainMenuWithGreeting()
{
	Greeting();
	ShowMainMenu();
}

void Navigation()
{
	ShowMainMenuWithGreeting();
	cin >> user_choice;
	if (user_choice > 3 || user_choice < 1)
	{
		while (true)
		{
			system("cls");
			ErrorMessageNumberMustBeInInterval(0, 4);
			ShowMainMenuWithGreeting();
			cin >> user_choice;
			if (user_choice < 4 || user_choice > 0)
			{
				break;
			}
		}
	}
}

// class of bank account
// using for identifying the user
// and contains bank account balance
class BankAccount
{
public:
	BankAccount();
	~BankAccount();

private:

	long long _bank_account_balance;
	// ID of user in this system
	// using for searching the user from database
	int _id;
};

BankAccount::BankAccount()
{
}

BankAccount::~BankAccount()
{
}

// class of debt bank card
// using for saving data of 
// debt card
class DebtBankCard
{
public:
	DebtBankCard();
	~DebtBankCard();

private:

	long _card_number;
	long long _card_banalce;
	int _pin;
	int _cvv2;
};

DebtBankCard::DebtBankCard()
{
}

DebtBankCard::~DebtBankCard()
{
}

// class of bank user account
// used to conduct transactions
// with a bank account, a user account
// in this system and a debit bank card account
class UserAccount
{
public:
	UserAccount();
	~UserAccount();
private:
	string _name_of_user;
	string _surname_of_user;
	string _patronymic_of_user;
	// bank account status
	// -1 - bankruptcy
	//  0 - zero balance on the card
	//  1 - positive balance
	// IMPORTANT!
	// this status applies to all types
	// of storage of funds. If in any place
	// of storage (card or bank account)
	// a person has 0 $, then he automatically 
	// receives the status 0, and if the balance 
	// is negative, then the status is -1
	int _status;
};

UserAccount::UserAccount()
{
}

UserAccount::~UserAccount()
{
}

int main()
{
	Navigation();
	return 0;
}