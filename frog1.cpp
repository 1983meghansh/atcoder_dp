#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>vc , int n)
{
	vector<int>dp(n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		int option1=abs(vc[i-1]-vc[i])+dp[i-1];
		int option2=(i==2)?	1e9:abs(vc[i-2]-vc[i])+dp[i-2];
		dp[i]=min(option1,option2);
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	vector<int>vc(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>vc[i];
	}
	cout<<solve(vc,n);
}
