#pragma once
#include "Manage1.h"
class Manage :private MANAGE
{
public:
	void print();
	int Num(int b);
	void readtxt();
	void delNode(int m);//ɾ���� 
	void delSide(int m, int n); //ɾ���� 
	void shortest(int v);
};