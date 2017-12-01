#pragma once
#include "StackNode.h"

StackNode::StackNode(string newDate)
{
	Date = newDate;
	pNext = nullptr;
}
StackNode::StackNode(const StackNode &newNode)
{
	Date = newNode.getDate();
	pNext = newNode.getpNext();
}
StackNode::~StackNode()
{}
//getter
string StackNode::getDate() const
{
	return Date;
}
StackNode * StackNode::getpNext() const
{
	return pNext;
}
//setter
void StackNode::setDate(string newDate)
{
	Date = newDate;
}

void StackNode::setNext(StackNode *pMem)
{
	pNext = pMem;
}

