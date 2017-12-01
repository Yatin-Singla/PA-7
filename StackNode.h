#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

/*stack node is data struct "stack" used to store the date of 
absences of each student*/

class StackNode
{
	//ListNode has been choosen as StackNode's friend because 
	//both classes pertain to single person, so this design concept
	// was implemented.
	friend class ListNode;
public:
	//constructor
	StackNode(string newDate = "");
	
	//copy constructor
	StackNode(const StackNode &newNode);
	
	//destructor
	~StackNode();

	//getter
	string getDate() const;
	StackNode * getpNext() const;

	//setter
	void setDate(string newDate);
	void setNext(StackNode *pMem);
	
private:
	string Date;
	StackNode * pNext;
};