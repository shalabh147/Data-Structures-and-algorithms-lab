#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int facto(int n)
{
	if(n==1)
		return 1;
	else
		return n*facto(n-1);
}
int main()
{

	string s;
	long int q;
	cin>>s;
	cin>>q;
	vector<int> v;

	long int n;
	n=s.size();

	long int freq_smaller_than[n]={0};
	long int freq_equal_to[n];

	for(int i=0;i<n;i++)
	{
		freq_equal_to[i]=1;
	}
	

	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<s.size();j++)
		{
			if(s[j]<s[i])
				freq_smaller_than[i]++;
			else if(s[j]==s[i])
				freq_equal_to[i]++;

		}
	}

	/*	for(int i=0;i<s.size();i++)
	{
	
			
				cout<<freq_smaller_than[i]<<" ";
				cout<<freq_equal_to[i]<<" ";
				cout<<endl;

		
	}*/


	long int ans = 0;
	long int factor = 1;
	for(long int i=1;i<n;i++)
	{	//cout<<freq_equal_to[i]<<endl;
		factor = (factor * i)/freq_equal_to[n-i-1];
		//cout<<factor<<" "<<ans<<endl;
		ans = ans + factor*freq_smaller_than[n-i-1];

	}

	long int fact[n];
/*
	sort(s.begin(),s.end());
	string a;
	int x=0;
/*	v.push_back(0);
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[i-1])
			continue;
		else
			v.push_back(i);
	}

	while(q!=0)
	{
		int x=q/facto(s.size()-1);
		q=q%facto(s.size()-1);
		a.push_back(s[v[x]]);
		s.erase(s.begin()+v[x]);


	}
	a=a+s;

	int freq[26]={0};

	for(int i=0;i<s.size();i++)
	{
		freq[s[i]-'a']++;

	}

	for(int i=0;i<26;i++)
	{

	}

	for(int i=0;i<s.size();i++_)
	{

	}
*/
	cout<<ans<<endl;


	




}
  