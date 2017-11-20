#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "StackNode.h"

using namespace std;


/*the class contains important information about a student
such as ID, major, year etc. in addition to storing sensitive data
about the student it also conatins 2 more fields. They are
number of absence and a stack to store the date of their absences.*/

class ListNode
{
	//constructor
	ListNode();
	~ListNode();
	//getters
	int getRecordNumber() const;
	long int getIDNumber() const;
	string getName() const;
	string getemail() const;
	string getUnits() const;
	string getMajor() const;
	string getLevel() const;

	//setters
	void setRecordNumber(int NewRecordNumber);
	void setIDNumber(long int newIDNumber);
	void setName(string NewName);
	void setemail(string newEmail);
	void setUnits(string newUnits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);

private:
	int RecordNumber;
	long int IDNumber;
	string Name;
	string email;
	string Units;
	string Major;
	string Level;
	int NumberAbsence;
	StackNode * DateAbsence;
	ListNode * pNext;
};