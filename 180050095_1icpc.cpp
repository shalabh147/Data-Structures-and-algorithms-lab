#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;

	int arr[n];
	char ch[n];

	for(int i=0;i<n;i++)
	{
		cin>>ch[i];
		cin>>arr[i];
	}

	int v[100001]={0};

	int mini[100001]={1000000};

	bool occured[100001]={false};
	for(int i=0;i<n;i++)
	{
		occured[arr[i]]=true;
		if(ch[i]=='e')
		v[arr[i]]--;
		else
		v[arr[i]]++;

		mini[arr[i]]=min(mini[arr[i]],v[arr[i]]);


	}



	int no_of_true = 0;
    int mini_delete = 1000000;
	bool array[100001] = {false};

	int x[100001]={0};

	int maxi = 0;

	int index = 1;
	for(int i=1;i<100001;i++)
	{
		if((v[i]==0)&&(mini[i]>=0)&&(occured[i]==true))
			{array[i]=true;
				no_of_true++;
			}

	}
	maxi = no_of_true;

	//cout<<no_of_true<<endl;
    int initial_delete[100001]={0};
    int sumDelete = 0;
    for(int i=0;i<100001;i++)
    {
        if(occured[i]==true)
        {
            initial_delete[i] = 2*abs(mini[i])+v[i];
            sumDelete = sumDelete + initial_delete[i];
        }
    }

    cout<<sumDelete<<endl;
    mini_delete = sumDelete;
	for(int i=0;i<n;i++)
	{

		if(v[arr[i]]==0)
		{if(ch[i]=='e')
		x[arr[i]]--;
		else
		x[arr[i]]++;

		if(x[arr[i]]==mini[arr[i]])
		{

			if(array[arr[i]]==false)
				{array[arr[i]]=true;
					no_of_true ++;}
		}
		else
		{
			if(array[arr[i]]==true)
			{
				array[arr[i]]=false;
				no_of_true --;
			}
		}


		if(no_of_true > maxi)
		{
			maxi = no_of_true;
			index = i+2;
		}


		//cout<<no_of_true<<" "<<index<<endl;

	}




	}

	for(int i=0;i<n;i++)
    {
        if(ch[i]=='s')
        sumDelete=sumDelete+2;
        else
        sumDelete=sumDelete-2;

            if(sumDelete<mini_delete)
            mini_delete = sumDelete;

    }



	cout<<index<<" "<<maxi<<" "<<mini_delete<<endl;









}
