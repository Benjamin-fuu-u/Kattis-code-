#include<bits/stdc++.h>

using namespace std;
map<int,int> money;
map<int,vector<int>> connect;
bool visited[10001];
bool flag =false;
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
int main()
{
    int people ;
    cin>>people;
    int frien;
    cin>>frien;
    for(int i=0;i<people;i++)
    {
    	int k;
    	cin>>k;
	    money[i]=k;
    }
    for(int i=0 ;i<frien; i++)
    {
    	int a,b;
	    cin>>a>>b;
	    connect[a].push_back(b);
    	connect [b].push_back(a);
     }
    for(int i=0;i<people;i++)
    {
     	if(visited[i]==false) 
	    dfs(i);
			if(moneyadd!=0)
			{
				flag =true;
				break;
			} 
			moneyadd=0;
    }

     if(flag ==true)
     {
			 cout<<"IMPOSSIBLE"<<endl;
		 }
			else if(flag ==false) 
      {
				cout<<"POSSIBLE"<<endl;
			}

		 
}
