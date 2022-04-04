#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
char s[102][102];
//位向量 
int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={-1,1,-1,0,1,-1,0,1};
int n,m;
void BFS(int i,int j)
{
	pair <int, int> id;
	queue <pair <int, int> > a;
	id.first = i;
	id.second = j;
	a.push(id);

	while(!a.empty()){
		id = a.front();
		a.pop();
		
		for(int i = 0 ; i <8; i++){
			if(id.first + dx[i] >= 0 && id.second + dy[i] >= 0 && id.first + dx[i] < n && id.second + dy[i] < m && s[id.first][id.second] == '@'){
				a.push(make_pair(id.first + dx[i], id.second + dy[i]));
			}
		}
		s[id.first][id.second] = '*';
	}
	return;

}
int main()
{
	int c;
	while(~scanf ("%d %d",&n,&m)&&n&&m)
	{
		c=0;
		for (int i=0;i<n;i++)
		{	
			cin >> s[i];//輸入圖 
		}
		//每一個頂點的遍歷。 
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='@')
				//發現油田時，數量++ 
				{
					c++;
					BFS(i,j);//BFS把整塊油田變成 *,下次就不會被計算到了. 
				}
			}
		}
		printf ("%d\n",c);
	}
	return 0;
} 