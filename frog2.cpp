#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>vc , int n,int k)
{
	vector<int>dp(n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=1e9;
		for(int j=i-1;j>=1 and i-j<=k;j--){
		dp[i]=min(dp[i],abs(vc[i]-vc[j])+dp[j]);
	}}
	return dp[n];
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>vc(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>vc[i];
	}
	cout<<solve(vc,n,k);
}
