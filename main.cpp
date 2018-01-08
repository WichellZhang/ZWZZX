#include"Manage2.h"


using namespace std;

int main()
{
	Manage G;
	int i, j, k;
	G.readtxt();
	G.print();
	while (1)
	{

		cout << "******************************" << endl;
		cout << "**********1.删除边************" << endl;
		cout << "********2.删除路由器**********" << endl;
		cout << "********3.生成路由表**********" << endl;
		cout << "************4.退出************" << endl;
		cout << "******************************" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			cout << "输入你想要删除的边的两路由器号" << endl;
			cin >> j >> k;
			G.delSide(j, k);
			break;
		}
		case 2:
		{
			cout << "输入你想要删除的路由器号" << endl;
			cin >> j;
			G.delNode(j);
			break;
		}
		case 3:
		{
			cout << "输入你想要生成的路由表的路由器号" << endl;
			cin >> j;
			G.shortest(j);
			break;
		}
		case 4:
		{
			exit(1);
			break;
		}

		}

	}
	return 0;
}
