#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "StackNode.h"
#include <ctime>

using namespace std;


/*the class contains important information about a student
such as ID, major, year etc. in addition to storing sensitive data
about the student it also conatins 2 more fields. They are
number of absence and a stack to store the date of their absences.*/

class ListNode
{
public:
	friend class MasterList;
	//constructor
	ListNode();
	//destructor
	~ListNode();
	//getters
	int getRecordNumber() const;
	long int getIDNumber() const;
	string getName() const;
	string getemail() const;
	string getUnits() const;
	string getMajor() const;
	string getLevel() const;
	int getAbsence() const;
	ListNode * getpNext() const ;

	//setters
	void setRecordNumber(int NewRecordNumber);
	void setIDNumber(long int newIDNumber);
	void setName(string NewName);
	void setemail(string newEmail);
	void setUnits(string newUnits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);
	void setAbsences(int Absences);
	
	//non convential member functions
	void push(StackNode *&Mem);
	void pop();
	string peek();
	bool isEmpty();
	void removeDate(StackNode *&date);
	void insertInOrder(StackNode *& date);

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