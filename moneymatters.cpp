#include<bits/stdc++.h>

using namespace std;
map<int,int> money;
map<int,vector<int>> connect;
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
			connect [b].push_back(a)
		}


		 
 ｝
