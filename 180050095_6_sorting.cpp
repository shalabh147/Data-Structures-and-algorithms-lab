#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int M = 1000000;
/*int arr[M];
int index[M];
int weight[M];
int distance[M];*/
long long int D=0;
int main()
{

	int n;
	cin>>n;

	vector<long long int> arr(M);
	vector<long long int> index(M);
	vector<long long int> weight(M);
	vector<long long int> distance(M);
	//int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	//int index[n];

	for(int i=0;i<n;i++)
	{
		index[arr[i]] = i;
	}

	//int weight[n];
	//int distance[n];
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}

	for(int i=1;i<n;i++)
	{
		cin>>distance[i];
	}
	distance[0] = 0;
	for(int i=1;i<n;i++)
	{
		distance[i]=distance[i-1] + distance[i];
	}

	//int D=0;
	//for(int i=0;i<n;i++)
	//{
//		cout<<distance[i]<<" ";
//	}

	//cout<<endl;

	for(int i=0;i<n;i++)
	{
		D = D+weight[i]*abs(distance[arr[i]] - distance[i]);
	}
	vector<pair<int,int> > output;
	cout<<D<<endl;
	long long int q,present;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<i)
		{
			present = arr[i];

			stack<long long int> s;
			while(arr[present]<i)
			{
				s.push(present);
				present = arr[present];
			}
			s.push(present);
			q = i;
			while(s.size()>0)
			{
				swap(arr[q],arr[s.top()]);
				output.push_back(make_pair(q,s.top()));
				q = s.top();
				s.pop();
			}

		}
	}

	cout<<output.size()<<endl;
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i].first<<" "<<output[i].second<<endl;
	}
}