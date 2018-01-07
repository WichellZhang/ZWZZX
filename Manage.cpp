#include"Manage.h"
#include<string>
#include<fstream> 
#include<iostream>
using namespace std;



Manage::Manage() {

}

Manage::~Manage() {

}


void Manage::print() {
	cout << "路由号" << endl;
	for (int a = 0; a<numNodes; a++)
	{
		cout << vexs[a] << "	";
		for (int b = 0; b<numNodes; b++)
		{
			cout << arc[a][b] << "	";
		}
		cout << endl;
	}
}
void Manage::readtxt()
{

ifstream OpenFiled("1.txt");
int i=0,j=0;
string str;
while(!OpenFiled.eof())
{
	getline(OpenFiled,str);
	j++;
}
numNodes=j-1;
OpenFiled.close();
ifstream OpenFile("1.txt");
while(!OpenFile.eof())
{
OpenFile>>vexs[i];
for(int j=0;j<numNodes;j++)
OpenFile>>arc[i][j];
i++;
}

cout<<"路由号"<<endl;
for(int a=0;a<numNodes;a++)
{	cout<<vexs[a]<<"	";
	for(int b=0;b<numNodes;b++)
	{
		cout<<arc[a][b]<<"	";
	}
	cout<<endl;
}
OpenFile.close();

}

int Manage::Num(int b)
{
	for(int i=0;i<numNodes;i++)
	{
		if(vexs[i]==b)
		return i;
	}
}


void Manage::delNode(int a)
{	
	int i,j;

  int m=Num(a);
	  
  
  for (i=m+1;i<numNodes;i++)
{  vexs[i-1]=vexs[i];
   for (j=0;j<numNodes;j++)
    arc[i-1][j]=arc[i][j];
} 

for (i=m+1;i<numNodes;i++)
{ 
	for (j=0;j<numNodes;j++)
	arc[j][i-1]=arc[j][i];
}	


	numNodes=numNodes-1;

ofstream Open("1.txt");

for(i=0;i<numNodes;i++)
{ 
Open<<vexs[i]<<"	";
for(int j=0;j<numNodes;j++)
{Open<<arc[i][j]<<"		";
} 
 Open<<endl;
} 


Open.close(); 
readtxt();
} 

void Manage::delSide(int a,int b)
{	int m=Num(a);
	int n=Num(b);
	arc[m][n]=9;
	arc[n][m]=9;
	
		
ofstream OpenFile("1.txt");
int i=0;
for(i;i<numNodes;i++)
{ 
OpenFile<<vexs[i]<<"	";
for(int j=0;j<numNodes;j++)
{OpenFile<<arc[i][j]<<"		";
}
 OpenFile<<endl;
} 


OpenFile.close();
readtxt();
}

void Manage::shortest(int a)
{
	int v = Num(a);
	int n = numNodes;
	int max = 9;
	int *dist = new int[n];
	int *path = new int[n];
	bool *s = new bool[n];
	int i, j, k,u,m,l,d,e,min;
	for (i = 0; i < n; i++)
	{
		dist[i] = arc[v][i];
		s[i] = false;
		if (i != v && dist[i] < max)
			path[i] = v;
		else path[i] = -1;
    }
	s[v] = true;
	dist[v] = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = max;
		u = v;
		for (j = 0; j < n; j++)
		{
			if (s[j] == false && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		s[u] = true;
		for (k = 0; k < n; k++)
		{
			m = arc[u][k];
			if (s[k] == false && m < max && dist[u] + m < dist[k])
			{
				dist[k] = dist[u] + m;
				path[k] = u;
			}
		}
	}
	cout << "路由器" << a << "的路由表为下" << endl;
	for (i = 0; i < n; i++)
	{
		if (i != v)
		{
			j = i;
			while (j != v)
			{
				l = j;
				j = path[j];
			}
	
			cout << "到路由器" << vexs[i] << "的最短路径为" << dist[i] << "   " << "下一跳为路由器" << vexs[l] << endl;
		}
	}


}


