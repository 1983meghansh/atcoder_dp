#include<bits/stdc++.h>
using namespace std;
int solve(int n,int arra[],int arrb[],int arrc[])
{
int dp[n+1][3];
dp[1][0]=arra[1];
dp[1][1]=arrb[1];
dp[1][2]=arrc[1];
for(int i=2;i<=n;i++)
{
	dp[i][0]=arra[i]+max(dp[i-1][1],dp[i-1][2]);
	dp[i][1]=arrb[i]+max(dp[i-1][0],dp[i-1][2]);
	dp[i][2]=arrc[i]+max(dp[i-1][1],dp[i-1][0]);
}
return max(dp[n][0],max(dp[n][1],dp[n][2]));
}

int main()
{
	int n;
	cin>>n;
	int arra[n],arrb[n],arrc[n];
	for(int i=1;i<=n;i++)
	{
		cin>>arra[i]>>arrb[i]>>arrc[i];
	}
	cout<<solve(n,arra,arrb,arrc);
}
