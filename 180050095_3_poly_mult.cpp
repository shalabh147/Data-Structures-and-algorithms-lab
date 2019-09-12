#include<iostream>
#include<vector>
using namespace std;


void naivemultiply(vector<int>::iterator i,vector<int>::iterator j,vector<int>::iterator k,long long int n)
{
	for(long long int x=0;x<n;x++)
	{
		for(long long int y=0;y<n;y++)
		{
			*(k+x+y)+=*(i+x)*(*(j+y));
		}
	}
}
void multiply(vector<int>::iterator i,vector<int>::iterator j,vector<int>::iterator k,long long int n)
{
	if(n<=16)
		{naivemultiply(i,j,k,n);}
	else
	{
		multiply(i,j,k,n/2);
		multiply(i+n/2,j+n/2,k+n,n/2);
		vector<int> R(n);
		vector<int> P(n/2);
		vector<int> Q(n/2);

		for(long long int x=0;x<n/2;x++)
		{
			P[x]=*(i+x)+*(i+x+n/2);
			Q[x]=*(j+x)+*(j+x+n/2);
		}
		multiply(P.begin(),Q.begin(),R.begin(),n/2);

		for(long long int x=0;x<n;x++)
		{
			R[x]=R[x]-*(k+x)-*(k+x+n);
		}

		for(long long int x=0;x<n;x++)
		{
			*(k+n/2+x)+=R[x];
		}
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int n;
	cin>>n;

	vector<int>coeff_P(n);
	vector<int>coeff_Q(n);

	for(long long int i=0;i<n;i++)
	{
		cin>>coeff_P[i];
	}

	for(long long int i=0;i<n;i++)
	{
		cin>>coeff_Q[i];
	}

	vector<int> coeff_R(2*n);
	multiply(coeff_P.begin(),coeff_Q.begin(),coeff_R.begin(),n);
	//cout<<coeff_R.size()<<endl;
	for(long long int i=0;i<coeff_R.size()-1;i++)
	{
		cout<<coeff_R[i]<<" ";
	}

	cout<<endl;

}