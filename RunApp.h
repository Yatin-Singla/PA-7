#include "List.h"
#include "Tester.h"


class Menu
{
public:
	//constructor
	Menu()
	{
		 StudentList = new MasterList();
	}
	void RunApp(void)
	{
		DisplayMenu();
	}

private:
	MasterList * StudentList;
	void DisplayMenu(void)
	{
		int optionSelected = 0;
		cout << "Please Select an option from the following.\n";
		cout << "1. Import Course List.\n";
		cout << "2. Load Master List.\n";
		cout << "3. Store Master List.\n";
		cout << "4. Mark Absences.\n";
		cout << "5. Bonus: Edit Absences.\n";
		cout << "6. Generate Report.\n";
		cout << "7. Exit.\n";
		cin >> optionSelected;
		char Line[100] = { '\0' };
		ifstream infile("classList.csv");
		ifstream ifile("master.txt");
		//trash line
		infile.getline(Line, 100);
		ofstream outfile("master.txt");

		switch (optionSelected)
		{
		case 1://Import Course List			
			do  {
				StudentList->insert(infile);
				} while (!infile.eof()/*infile.eof() != true*/);
				break;
		case 2:			
			do {
				StudentList->LoadMaster(ifile);
			} while (!ifile.eof()/*infile.eof() != true*/);
			break;
		case 3:
			StudentList->StoreList(outfile);
			break;
		case 4:
			StudentList->RollCall();
			break;
		case 5:
			StudentList->editAbsences();
			break;
		case 6:
			StudentList->GenerateReport();
			break;
		case 7:
			exit(0);
			break;
		}
		infile.close();
		ifile.close();
		outfile.close();
	}
	
};



