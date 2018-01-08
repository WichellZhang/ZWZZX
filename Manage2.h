#pragma once
#include "Manage1.h"
class Manage :private MANAGE
{
public:
	void print();
	int Num(int b);
	void readtxt();
	void delNode(int m);//É¾³ýµã 
	void delSide(int m, int n); //É¾³ý±ß 
	void shortest(int v);
};