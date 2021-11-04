#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(char *in,char *opt,int i,int j)
{
	if(in[i]=='\0')
	{
		opt[j]='\0';
        cout<<opt<<" ";
		return;
	}
	//either pick a character
	opt[j]=in[i];
	generate_subsequence(in,opt,i+1,j+1);
	//or dont pick the character
	generate_subsequence(in,opt,i+1,j);
}

int main()
{
	char input[]="abc";
	char output[10];
 	generate_subsequence(input,output,0,0);
}
