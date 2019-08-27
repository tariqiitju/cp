#include <bits/stdc++.h>
using namespace std;
string manacher(string &p)
{
	int n=(int)p.size();
	vector<int> v( 3+(n<<1),0);
	int c=0,r=0;
	string s="@";
	for(int i=0;p[i];i++)s+='#',s+=p[i];
	s+='#';
	int mxi,mx=0;
	for(int i=1;s[i];i++)
	{
		int mi=c-i+c;
		if(i<r)v[i]=min(v[mi], r-i);
		while(i+1+v[i]<SZ(s) && s[ i-1-v[i] ]==s[i+1+v[i]])v[i]++;
		if(i+v[i]>r)c=i,r=i+v[i];
		if(v[i]>mx)mx=v[i],mxi=i;
	}
	return p.substr((mxi-mx-1)/2, mx);
}
