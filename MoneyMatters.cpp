#include<bits/stdc++.h>

using namespace std;
map<int,int> money;
map<int,vector<int>> connect;
bool visited[10001];
book flag =false;
int moneyadd=0;
void dfs(int people)
{
  visited[people]=true;
  moneyadd+=money[people];
  for(int i=0;i<connect[people].size();i++)
  {
	  if(visited[connect[people][i]]==false) 
		{
      dfs(connect[people][i]);
		}
  }
		  
}
int main（）
｛
    int people ;
    cin>>people;
    int friend;
    cin>>friend;
    for(int i=1 ;i<=people;i++)
    {
	int k;
	cin>>k;
	money[i]=k;
    }
    for(int i=0 i<friend; i++)
    {
	int a,b;
	cin>>a>>b;
	connect[a].push_back(b);
	connect [b].push_back(a);
     }
    for(int i=0;i<10001;i++)
    {
     	if(visited[i]==false) 
	    dfs(i);
			if(moneyadd!=0)
			{
				flag =true;
				break;
			} 
    }

     if(flag ==true)
     {
			 cout<<"impossible"<<endl;
		 }
			else if(flag ==false) 
      {
				cout<<"possible"<<endl;
			}

		 
 ｝
