#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > s(9,vector<int> (9,0));
bool valr(int r,int k)
{
    for(int j=0;j<9;j++)
    {
        if(s[r][j]==k)
            return false;
    }
    return true;
}
bool valc(int c,int k)
{
    for(int i=0;i<9;i++)
    {
        if(s[i][c]==k)
            return false;
    }
    return true;
}
bool valb(int r,int c,int k)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(s[r+i][c+j]==k)
                return false;
        }
    }
    return true;
}
bool issafe(int i,int j,int k)
{
    bool validrow = valr(i, k);
    bool validcol = valc(j, k);
    bool validbox = valb(i - i%3, j - j%3, k);
    return validrow && validbox && validcol;
}

bool solve(int i,int j)
{
    if(i==9)
        return true;
    if(j==9)
        return solve(i+1,0);
    if(s[i][j]!=0)
        return solve(i,j+1);
    for(int k=1;k<=9;k++)
    {
        if(issafe(i,j,k))
        {
            s[i][j] = k;
            if(solve(i,j+1))
                return true;
            s[i][j] = 0;
        }
    }
    return false;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	            cin>>s[i][j];
	    }
	}
	bool ans = solve(0,0);
	if(ans==false)
	    cout<<-1<<endl;
	else
	{
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	            cout<<s[i][j]<<" ";
	        cout<<endl;
	    }
	}
	return 0;
}