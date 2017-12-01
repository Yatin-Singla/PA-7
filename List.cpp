#include "List.h"
using std::cout;
using std::cin;

MasterList::MasterList()
{
	/*ifstream infile;
	infile.open("classList.csv");
	char Line[100] = {'\0'};
	infile.getline(Line, 100);*/
	//cout << Line << endl;
	Head = nullptr;
}

MasterList::~MasterList()
{
}

void MasterList::insert(ifstream &infile)
{
	ListNode * Node = new ListNode();
	char data[100] = { '\0' };
	infile.getline(data, 100);

	char recordNumber[4] = { '\0' };
	strcpy(recordNumber, strtok(data, ","));
	int RecordNumber = atoi (recordNumber);
	Node->setRecordNumber(RecordNumber);

	char IDNumber[10] = { '\0' };
	strcpy(IDNumber, strtok(NULL, ","));
	long int IDnumb = atoi(IDNumber);
	Node->setIDNumber(IDnumb);

	char name[50] = { '\0' };
	strcpy(name, strtok(NULL, ","));
	Node->setName(name);

	char email[50] = { '\0' };
	strcpy(email, strtok(NULL, ","));
	Node->setemail(string(email));

	char Units[5] = { '\0' };
	strcpy(Units, strtok(NULL, ","));
	Node->setUnits(Units);

	char Major[10] = { '\0' };
	strcpy(Major, strtok(NULL, ","));
	Node->setMajor(Major);

	char Level[15] = { '\0' };
	strcpy(Level, strtok(NULL, "\n"));
	Node->setLevel(Level);

	if (Head == nullptr)
	{
		Head = Node;
	}
	else
	{
		Node->pNext = Head;
		Head = Node;
	}

}

void MasterList::LoadMaster(ifstream &infile)
{
	//deconstructor
	Head->~ListNode();
	
	ListNode * Node = new ListNode();
	char data[100] = { '\0' };
	infile.getline(data, 100);

	char recordNumber[4] = { '\0' };
	strcpy(recordNumber, strtok(data, ","));
	int RecordNumber = atoi(recordNumber);
	Node->setRecordNumber(RecordNumber);

	char IDNumber[10] = { '\0' };
	strcpy(IDNumber, strtok(NULL, ","));
	long int IDnumb = atoi(IDNumber);
	Node->setIDNumber(IDnumb);

	char name[50] = { '\0' };
	strcpy(name, strtok(NULL, ","));
	Node->setName(name);

	char email[50] = { '\0' };
	strcpy(email, strtok(NULL, ","));
	Node->setemail(email);

	char Units[5] = { '\0' };
	strcpy(Units, strtok(NULL, ","));
	Node->setUnits(Units);

	char Major[10] = { '\0' };
	strcpy(Major, strtok(NULL, ","));
	Node->setMajor(Major);

	char Level[15] = { '\0' };
	strcpy(Level, strtok(NULL, ","));
	Node->setLevel(Level);

	//reusing a varible to store the number of absences.
	strcpy(recordNumber, strtok(data, "\n"));
	RecordNumber = atoi(recordNumber);
	Node->setAbsences(RecordNumber);



	Node->pNext = Head;
	Head = Node;
}

void MasterList::StoreList(ofstream &outfile)
{
	bool Empty = true;

	Empty = isEmpty();

	ListNode * pMem = Head;

	if (Empty == false)
	{
		do {
			outfile << pMem->getRecordNumber();
			outfile << " , ";
			outfile << pMem->getIDNumber();
			outfile << " , ";
			outfile << pMem->getName();
			outfile << " , ";
			outfile << pMem->getemail();
			outfile << " , ";
			outfile << pMem->getUnits();
			outfile << " , ";
			outfile << pMem->getMajor();
			outfile << " , ";
			outfile << pMem->getLevel();
			outfile << " , ";
			outfile << pMem->getAbsence();
			outfile << "\n";
			pMem = pMem->pNext;
		} while (pMem != nullptr);
	}
	else
	{
		cout << "MasterList is Empty!!\n";
	}
}

bool MasterList::isEmpty(void)
{
	if (Head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MasterList::RollCall(void)
{
	ListNode *pMem = Head;
	char Present = 'N';
	if (isEmpty() != true)
	{
		do
		{
			cout << "Is " << pMem->getName();
			cout << " present?\n";
			cout << "Please enter Y/N\n";
			cin >> Present;
			if(Present == 'Y')
			{ }
			//else means anything but 'Y' will call it
			else // Mark the date and mark the person absent
			{
				pMem->NumberAbsence += 1;

				time_t theTime = time(NULL);
				struct tm *Now = localtime(&theTime);
				ostringstream oss;
				oss<< Now->tm_mday <<"/"<< Now->tm_mon + 1<<"/"<< Now->tm_year + 1900;
				string Date = oss.str();
				StackNode * newDate = new StackNode(Date);
				Head->push(newDate);
			}
			pMem = pMem->getpNext();
		} while (pMem != nullptr);
	}
}

void MasterList::GenerateReport(void)
{
	int mastersChoice = 0;
	cout << "What kind of report does master wants dobby to present?\n";
	cout << "1. Generic Report.\n";
	cout << "2. Report of Defaultees.\n";
	cin >> mastersChoice;
	ListNode*pMem = Head;
	switch (mastersChoice)
	{
	case 1:
		while (pMem != nullptr)
		{
			cout << pMem->getName() << " - ";
			cout << pMem->peek() << "\n\n";
			pMem = pMem->getpNext();
		}
		break;
	case 2:
		cout << "Master please enter the minimum number of Absences to generate a report.\n";
		cin >> mastersChoice;
		pMem = Head;
		while (pMem != nullptr)
		{
			if (pMem->getAbsence() >= mastersChoice)
			{
				cout << pMem->getName() << " - ";
				cout << pMem->peek() << "\n\n";
			}
			pMem = pMem->getpNext();
		}

	}

}

void MasterList::editAbsences(void)
{
	int MastersChoice = 0;
	std::cout << "Cool you want to edit absences of a student.\n";
	std::cout << "Master wants to look for student based on:\n";
	cout << "1. Name or\n";
	cout << "2. Student ID\n";
	cin >> MastersChoice;
	string Name="";
	int StudentId = 0;

		//bases of finding the student
		//Name of the student
	ListNode *pMem = Head;
	if (MastersChoice == 1)
	{
		cout << "Please enter the name of the student.\n";
		cin >> Name;
		while (pMem->getName() != Name) // searching for the student
		{
			pMem = pMem->getpNext();
		}
	}
	else if (MastersChoice == 2)
	{
		cout << "Please enter the ID of the student.\n";
		cin >> StudentId;
		while (pMem->getIDNumber() != StudentId) // searching for the student
		{
			pMem = pMem->getpNext();
		}
	}
		
		//found the student		
		StackNode * date = pMem->DateAbsence;
		cout << "These are all the date the student was absent on which one would you like to edit.\n";
		
		while (date!=nullptr)//printing all the dates of absences
		{
			cout << date->getDate() << "\n";
			date = date->getpNext();
		}

		//asking for date of absence to edit
		cout << "Please enter the date in correct format to edit.\n";
		cin >> Name;//used for storing date
		date = pMem->DateAbsence;
		while (date->getDate() != Name)//finding the date
		{
			date = date->getpNext();
		}
		//date found
		cout << "What do you want to do?\n";
		cout << "1. Edit the date.\n";
		cout << "2. Remove the Absence.\n";
		int number = 0;
		switch (number)
		{
		case 1://edit the date
			cout << "Please enter the new date of Absence.\n";
			Head->removeDate(date);
			cin >> Name; //used for storing date
			date = new StackNode(Name);
			//rearranging the stack of absence
			Head->insertInOrder(date);
			break;
		case 2://remove absence
			Head->removeDate(date);
			Head->NumberAbsence -= 1;
			break;
		}
	}
