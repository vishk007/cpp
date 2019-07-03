#include"account.h"
#include<conio.h>
#include<fstream>
using namespace std;
class FileOperations {

public:
	static void WriteData()
	{
		char wish;
		fstream fs;
		Account a;
		fs.open("AccountData.dat", ios::out | ios::app);
		do 
		{
			a.accept();
			fs.write((char*)&a, 1 * sizeof(Account));
			cout << "Do you want to add another data?";
			cin >> wish;
		} while (wish=='y' || wish == 'Y');
		fs.close();
	}

	static void ReadData()
	{
		fstream fs;
		Account a;
		fs.open("AccountData.dat", ios::in | ios::app);
		while (fs.read((char*)&a, 1 * sizeof(Account)))
		{
				a.display();
		}
		fs.close();

	}


	//static bool SearchData(char * nm)
	static bool SearchData(int id)
	{
		fstream fs;
		Account a;
		fs.open("AccountData.dat", ios::in | ios::app);
		while (fs.read((char*)&a, 1 * sizeof(Account)))
		{
			//if(strcmp(a.getAccName,nm)==1)
			if (a.getAccId()== id) 
			{
				a.display();
				fs.close();
					return true;
			}
		}
		fs.close();
		return false;
	}

	static bool UpdateData(int id,double sal )
	{
		fstream fs;
		Account a;
		//char name[10];
		//cout << "Enter the name to update:: ";
		//cin >> name;
		//cout << "Enter the Id to update:: ";
		//cin >> id;
		//cout << "Enter the salary to update:: ";
		//cin >> sal;
		fs.open("AccountData.dat", ios::in | ios::out);
		while (fs.read((char*)&a, 1 * sizeof(Account)))
		{
			if (a.getAccId() == id)
			{
				a.getSalary();
				a.setSalary(sal);

				//a.accept();
				//fs.open("AccountData.dat", ios::out | ios::app);
				fs.write((char*)&a, 1 * sizeof(Account));
				fs.close();

				return true;
			}
		}

		

		fs.close();
		return false;
	}


};

int main() 
{
	bool res;
	int choice=0;
	char wish;
	do 
	{
		cout << "MENU::\n1.Accept Data \n2.Display Data \n3.Search Data \n4.Update Data \n5.Exit";
			cout << "\nEnter your choice";
			cin >> choice;
		switch (choice)
		{
		case 1:
			FileOperations::WriteData();
			break;
		case 2:
			FileOperations::ReadData();
			break;
		case 3:
			int id;
			//char name[10];
			cout << "Enter the account id you Want Serach";
			cin >> id;
			res=FileOperations::SearchData(id);
			if (res) 
			{
				cout << "\n data found";
			}
			else 
			{
				cout << "\n data not found";
			}
				break;
		case 4:
			
			double sal;
			cout << "Enter the Id to update:: ";
			cin >> id;
			//char name[10];
			cout << "Enter the salary to update:: ";
			cin >> sal;
			FileOperations::UpdateData(id,sal);
			break;
		case 5:
			exit(0);
		}
		cout << "\nDo you want to perform another operation?";
		cin >> wish;
	}while (wish == 'y' || wish == 'Y');

	_getch();
	return 0;
}