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
int ListNode::getAbsence() const
{
	return NumberAbsence;
}
ListNode * ListNode::getpNext() const
{
	return pNext;
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
void ListNode::setAbsences(int Absences)
{
	NumberAbsence = Absences;
}

void ListNode::push(StackNode *&Mem)
{
	if (DateAbsence != nullptr)
	{
		Mem->setNext(DateAbsence);
		DateAbsence = Mem;
	}
	else
	{
		DateAbsence = Mem;
	}
}
void ListNode::pop()
{
	if (DateAbsence != nullptr)
	{
		StackNode *pMem = DateAbsence;
		DateAbsence = DateAbsence->getpNext();
		delete pMem;
	}
	else{}
}
string ListNode::peek()
{
	if (DateAbsence == nullptr)
	{
		return "";
	}
	else { return DateAbsence->getDate(); }
}
bool ListNode::isEmpty()
{
	if (DateAbsence == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ListNode::removeDate(StackNode *&date)
{
	if (date != nullptr)
	{
		StackNode *&pMem = DateAbsence;
		if (pMem != nullptr)
		{
			while (pMem->getpNext() != date)
			{
				pMem = pMem->getpNext();
			}
			pMem->setNext(date->getpNext());
			delete date;
		}
	}
}
void ListNode::insertInOrder(StackNode *&date)
{
	StackNode *& pMem = DateAbsence;
	if (pMem != nullptr)
	{
		//finding the right node to add date in the stack
		while (pMem->getpNext()->getDate() < date->getDate())
		{
			pMem = pMem->getpNext();
		}
		date->setNext(pMem->getpNext());
		pMem->setNext(date);
	}
}