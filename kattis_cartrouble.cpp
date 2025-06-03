#include<bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int>> graph;
unordered_map<int,vector<int>> picture;
bool reach_0 [1000];
bool be_reach [1000];
bool visited_dfs[1000];
bool visited_dfs2[1000];
void dfs(int now)
{
    reach_0[now]=true;
    visited_dfs[now]=true;
    for(int i=0;i<graph[now].size();i++)
    {
        if(visited_dfs[graph[now][i]]==false)
        {
            dfs(graph[now][i]);
        }

    }
}
void dfs_2(int now)
{
    be_reach[now]=true;
    visited_dfs2[now]=true;
    for(int i=0;i<picture[now].size();i++)
    {
        if(visited_dfs2[picture[now][i]]==false)
        {
            dfs_2(picture[now][i]);
        }

    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ID,m;
        cin>>ID;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int road;
            cin>>road;
            graph[ID].push_back(road);
        }
    }

    // second check 0 or not
    dfs(0);

    // first check reach 0 or not
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            picture[graph[i][j]].push_back(i);
        }
    }

    dfs_2(0);

    //print first
    bool check=false;
    for(int i=0;i<n;i++)
    {
        if(be_reach[i]==false)
        {
            check=true;
            cout<<"TRAPPED "<<i<<endl;
        }
    }

    // print second
    for(int i=0;i<n;i++)
    {
        if(reach_0[i]==false)
        {
            check =true;
            cout<<"UNREACHABLE "<<i<<endl;
        }
    }


    if(check==false)
    {
        cout<<"NO PROBLEMS"<<endl;
    }
    return 0;
}
