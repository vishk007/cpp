#include "account.h"
#include<string.h>
#include<conio.h>
using namespace std;
Account::Account()
{
	this->accId = 0;
	strcpy(this->accName, "Unknown");
	this->salary = 0.0;
}

Account::Account(int accId, const char * accName, double salary)
{
	this->accId = accId;
	strcpy(this->accName, accName);
	this->salary = salary;
}

int Account::getAccId()
{
	return this->accId;
}

void Account::setAccId(int)
{
	this->accId = accId;
}

const char * Account::getAccName()
{
	return this->accName;
}

void Account::setAccName(const char *)
{
	//this->accName = accName;
	strcpy(this->accName,accName);
}

double Account::getSalary()
{
	return this->salary;
}

void Account::setSalary(double)
{
	this->salary = salary;
}

void Account::accept()
{
	cout << "Enter the details------" << endl;
	cout << "Enter the id::" << endl;
	cin >> this->accId;
	cout << "Enter the Name:" << endl;
	cin >> this->accName;
	cout << "Enter the Salary::" << endl;
	cin >> this->salary;
}

void Account::display()
{
	cout << "ID::" << this->accId << endl;
	cout << "NAME:"<< this->accName << endl;
	cout << "SALARY::" << this->salary << endl;
	cout << "-------------------"<<endl;

}

Account::~Account()
{
}
