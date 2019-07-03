#include<iostream>
class Account
{
protected:
	int accId;
	char accName[20];
	double salary;
public:
	Account();
	Account(int , const char*, double);

	int getAccId();
	void setAccId(int);

	const char* getAccName();
	void setAccName(const char*);

	double getSalary();
	void setSalary(double);

	void accept();
	void display();
	~Account();
};

