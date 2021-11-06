#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n)
{
	//base case
	if(i==m and j==n)
	{
		soln[m][n]=1;
		//print the path
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<soln[i][j]<<" ";
			}
			cout<<"\n";
		}
		return true;
	}
	//rat should be inside grid
	if(i>m or j>n)
	{
		return false;
	}
	if(maze[i][j]=='x')
		return false;

	//assume soln exist through current cell
	soln[i][j]=1;

	bool rightSuccess=ratInMaze(maze,soln,i,j+1,m,n);
	bool downSuccess=ratInMaze(maze,soln,i+1,j,m,n);
	//backtracking
	soln[i][j]=0;
	if(rightSuccess or downSuccess)
	{
		return true;
	}
	return false;
}
int main()
{
	char maze[10][10]={
		"0000",
		"00x0",
		"000x",
		"0x00",
	};
	int soln[10][10]={0};
	int m=4,n=4;
	bool ans=ratInMaze(maze,soln,0,0,m-1,n-1);
	if(ans==false)
	{
		cout<<"path doesnt exist";
	}
	return 0;

}
