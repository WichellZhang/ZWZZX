#pragma once
#include<iostream>
#include<string>
using namespace std;
#define Maxnum 9
class MANAGE
{
public:
	int vexs[Maxnum];
	int arc[Maxnum][Maxnum];
	int numNodes;
	int numEdges;
};