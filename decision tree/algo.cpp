//Dipak Agarwal
//16IE10035
//Assignment 2 decision tree


#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int c[9]={-999,-999,-999,-999,-999,-999,-999,-999,-999};
int z=0;
double entropy(int arr[1000])
{
	int pos=0;
	int neg=0;
	int i=0;
	
	while(arr[i]!=-999)
	{
		if(arr[i]==1)
		pos++;
		else
		neg++;
		i++;
	}
	double p1;
	p1=pos*1.0/(pos+neg);
	double p2;
	p2=neg*1.0/(pos+neg);
	//cout<<" p1="<<p1<<" p2="<<p2<<"pos="<<pos<<"neg="<<neg<<endl;
	
	if(p1==0||p2==0||(pos==0&&neg==0))
	return 0;
	double x=(-p1*log2(p1)-p2*log2(p2));
	return x;
}
void build(int arr[1000][9],int post,int final[1000])
{
	double min=1000.0;
	int pos=0;
	int neg=0;
	int a1[1000];
	int a2[1000];
	int index=-999;
	
	int l=0;
	
	for(int i=0;i<8;i++)
	{
	
		for(int j=0;j<1000;j++)
		{
			a1[j]=-999;
			a2[j]=-999;
		}
		for(int j=0;j<9;j++)
		if(c[j]==i)
		l++;
		if(l>0)
		{
			l=0;
			continue;
		}
		int j=0;pos=0;neg=0;
		while(arr[j][i]!=-999)
		{
			if(arr[j][i]==1)
			{
				a1[pos]=arr[j][8];
				pos++;
			}
			else
			{
				a2[neg]=arr[j][8];
				neg++;
			}
			j++;
		}
		
		
	/*	for(int i=0;i<24;i++)
		cout<<a1[i];
		cout<<endl;
		for(int i=0;i<24;i++)
		cout<<a2[i];
		cout<<endl;*/
		
		double E=(pos*entropy(a1)+neg*entropy(a2))/(pos+neg);
		//cout<<" E="<<E<<" min="<<min<<" pos="<<pos<<" neg="<<neg<<" ea1="<<entropy(a1)<<" ea2="<<entropy(a2)<<endl;
		
		if(E<min)
		{
			min=E;
			index=i;
		}
	}
	
		for(int i=0;i<1000;i++)
	{
		a1[i]=-999;
		a2[i]=-999;
	}
	
//	cout<<"/////////////////"<<endl;
	if(index==-999)
		return;
	final[post]=index;
	c[z]=index;
	z++;
	int arr1[1000][9];
	int arr2[1000][9];
	int a=0;
	int b=0;
	
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<9;j++)
		{
			arr1[i][j]=-999;
			arr2[i][j]=-999;
		}
	}
	pos=0;
	neg=0;
	for(int i=0;i<25;i++)
	{
		if(arr[i][index]==1)
		pos++;
		if(arr[i][index]==0)
		neg++;
	}
	for(int i=0;i<pos+neg;i++)
	{
		if(arr[i][index]==1)
		{
			a1[a]=arr[i][8];
			for(int j=0;j<9;j++)
			{
				arr1[a][j]=arr[i][j];
				
			}a++;
		}
		else
		{
			a2[b]=arr[i][8];
			for(int j=0;j<9;j++)
			{
				arr2[b][j]=arr[i][j];
			//	b++;
			}b++;
		}
	}
	
/*	//cout<<endl<<entropy(a1)<<" 5 "<<entropy(a2)<<endl<<endl;
	cout<<"	index pos neg		arr  "<<index<<"     "<<pos<<"     "<<neg<<endl<<endl;
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<9;j++)
		cout<<arr[i][j]<<"  ";
		cout<<endl;
	}
	
	cout<<"			arr1"<<endl<<endl;
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<9;j++)
		cout<<arr1[i][j]<<"  ";
		cout<<endl;
	}
	
	cout<<"			arr2"<<endl<<endl;
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<9;j++)
		cout<<arr2[i][j]<<"  ";
		cout<<endl;
	}
	*/
	
	if(entropy(a1)==0)
	{
		if(a1[pos-1]==0)
		final[2*post+1]=-8;
		else
		final[2*post+1]=-9;
	}
	else
	build(arr1,2*post+1,final);
	if(entropy(a2)==0)
	{
		if(a2[neg-1]==0)
		final[2*post+2]=-8;
		else
		final[2*post+2]=-9;
	}
	else
	build(arr2,2*post+2,final);
}

void result(int final[1000],int arr[8])
{
	int pos=0;
	while(final[pos] != (-8) || final[pos] !=(-9))
	{
		if(final[pos]==-999)
		return;
		if(arr[final[pos]]==1)
		pos=2*pos+1;
		else if(arr[final[pos]]==0)
		pos=2*pos+2;
		if(final[pos]== -8 ||final[pos]==-9)
		break;
	}
	if(final[pos]==-8)
	cout<<0<<endl;
	else
	cout<<1<<endl;
}


int main()
	{
		 std::ifstream file ("data2.csv", std::ifstream::in);		// and open for reading.
		string line;
		int final[1000];
		int arr[1000][9];
		for(int j=0;j<1000;j++)
		{
			final[j]=-999;
			for(int i=0;i<9;i++)
			arr[j][i]=-999;
		}
		cout<<"	Training set."<<endl<<endl;
		int j=0;
		while(getline(file,line)) // Copy the file
		{ // to standard
			int count=0;
			cout<<line<<endl;
			for(int i=0;i<17;i++)	//loop to find hypothesis
			{
				if(line[i]==',')
					continue;
				if(line[i]=='1')
					arr[j][count]=1;
				if(line[i]=='0')	
					arr[j][count]=0;
				count++;
			}
			j++;
		}
		build(arr,0,final);
		std::ifstream file1 ("test2.csv", std::ifstream::in);
		int x[4][8];
		cout<<endl;
		j=0;
		cout<<"	Test cases."<<endl<<endl;
		while(getline(file1,line)) // Copy the file
		{ // to standard
			int count=0;
			cout<<line<<endl;
			for(int i=0;i<15;i++)	//loop to find hypothesis
			{
				if(line[i]==',')
					continue;
				if(line[i]=='1')
					x[j][count]=1;
				if(line[i]=='0')	
					x[j][count]=0;
				count++;
			}
			j++;
		}
		int y[8];
		cout<<endl<<"	Final result"<<endl<<endl;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<8;j++)
			y[j]=x[i][j];
			result (final,y);
			
		}
		return 0;
	}
	
