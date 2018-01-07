#ifndef MANAGE_H
#define MANAGE_H
#include<iostream>
#include<string>
using namespace std;
#define Maxnum 9



class Manage
{
private:
	int vexs[Maxnum];
	int arc[Maxnum][Maxnum];
	int numNodes;
	int numEdges;
public:
	void print();
	int Num(int b);
	void readtxt();
	void delNode(int m);//É¾³ýµã 
	void delSide(int m,int n); //É¾³ý±ß 
	void shortest(int v);

};
#endif
