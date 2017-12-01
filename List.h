#pragma once
#include "ListNode.h"

/*this class is a master class to list node
Basically contains all the list node*/

class MasterList
{
public:
	MasterList();
	~MasterList();
	void insert(ifstream &infile);
	void LoadMaster(ifstream &infile);
	void StoreList(ofstream &outfile);
	bool isEmpty(void);
	void RollCall(void);
	void GenerateReport(void);
	void editAbsences(void);

private : 
	ListNode * Head;
};