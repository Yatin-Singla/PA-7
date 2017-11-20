#include "ListNode.h"
#include "StackNode.h"

ListNode::ListNode()
{
	RecordNumber = 0;
	IDNumber = 0;
	Name = "";
	email = "";
	Units = "";
	Major = "";
	Level = "";
	NumberAbsence = 0;
	DateAbsence = nullptr;
	pNext = nullptr;
}
ListNode::~ListNode()
{
	DateAbsence->~StackNode();
}

//getters
int ListNode::getRecordNumber() const
{
	return RecordNumber;
}
long int ListNode::getIDNumber() const 
{
	return IDNumber;
}
string ListNode::getName() const
{
	return Name;
}
string ListNode::getemail() const
{
	return email;
}
string ListNode::getUnits() const
{
	return Units;
}
string ListNode::getMajor() const
{
	return Major;
}
string ListNode::getLevel() const
{
	return Level;
}

//setters
void ListNode::setRecordNumber(int NewRecordNumber)
{
	RecordNumber = NewRecordNumber;
}
void ListNode::setIDNumber(long int newIDNumber)
{
	IDNumber = newIDNumber;
}
void ListNode::setName(string newName)
{
	Name = newName;
}
void ListNode::setemail(string newEmail)
{
	email = newEmail;
}
void ListNode::setUnits(string newUnits)
{
	Units = newUnits;
}
void ListNode::setMajor(string newMajor)
{
	Major = newMajor;
}
void ListNode::setLevel(string newLevel)
{
	Level = newLevel;
}

