#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll N,W,w[200],v[200];
ll dp[105][100009];
ll soln(int id,int wt)
{
    if(id==N)    //base case when none of the items are left
    return 0;
    if(dp[id][wt]!=-1)
    return dp[id][wt];
    ll ans=soln(id+1,wt);   //case where we dont choose the item  
    if(w[id]+wt<=W)
    ans=max(ans,soln(id+1,wt+w[id])+v[id]);
    return dp[id][wt]=ans;
}

int main()
{
memset(dp,-1,sizeof(dp));
cin>>N>>W;
for(int i=0;i<N;i++)
{
    cin>>w[i]>>v[i];
}
cout<<soln(0,0)<<endl;
}
