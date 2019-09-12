#include<iostream>
#include<vector>

template <class T>
class myvector
{
	std::vector<T> v;
	int size1;
	int i;
public:
	myvector<T>()
	{
		size1 = 0;
		i=0;
	}
/*	myvector<T> v(int n)
	{
		size = n;
		v=std::vector<T> x(n,0);
		i=0;
	}
	myvector<T> v(int n,int x)
	{
		size = n;
		v=std::vector<T> y(n,x);
		i=0;
	}*/
	void push_front(T x)
	{	
		//std::cout<<"enteredhere";
		if(i==0 && size1==0)
		{
			size1++;
			//std::cout<<"entered"<<std::endl;
			v.push_back(x);
		}
		else
		{
		if(size1 == v.size())
		{//cout<<"entered1"
			std::vector<T> temp(2*v.size(),0);
			for(int j=v.size();j<2*v.size();j++)
			{
				temp[j] = v[j-v.size()];
			}

			temp[v.size()-1] = x;
			i = v.size()-1;
			v = temp;
			size1++;

		}
		else
		{//cout<<"entered2";
			i--;
			v[i]=x;
			size1++;
		}
	}

	}
	void push_back(T x)
	{
		v.push_back(x);
		size1++;
	}
	void pop_front()
	{	
		if(size1==0)
		{}
		else
		{i++;
		size1--;}
	}
	void pop_back()
	{	
		if(size1==0)
		{}
		else
		{v.pop_back();
		size1--;}
	}
	int size() const
	{
		return size1;
	}
	T & operator[](int a)
	{
		return v[i+a];
	}
};



