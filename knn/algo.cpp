//Dipak Agarwal
//16IE10035
//Assignment 4

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int a[9][2][2];
int y=0;
int n=0;
int main()
	{
		 std::ifstream file ("data4.csv", std::ifstream::in);		// and open for reading.
		string line;
		int arr[1000][9];
		for(int j=0;j<1000;j++)
		{
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
 		
		std::ifstream file1 ("test4.csv", std::ifstream::in);
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
		j=0;
		double dist=0.0;
		double x1[20][2];
		for(j=0;j<4;j++)
		{
			for(int i=0;i<20;i++)
			{
				for(int k=0;k<8;k++)
				{
				   dist=dist+(x[j][k]-arr[i][k]*0.1)*(x[j][k]-arr[i][k]*0.1);	
				}
				x1[i][0]=dist;
				x1[i][1]=i;
				dist=0;
			}
			int one=0;
			int zero=0;
			for(int i=0;i<5;i++)
			{
				int min=x1[i][0];int pos=i;
				for(int k=i+1;k<20;k++)
				{
					if(x1[k][0]<min)
					{
						min=x1[k][0];
						pos=k;
					}
				}
				double temp=x1[i][0];
				int temp1=x1[i][1];
				x1[i][0]=min;
				int f=x1[i][1]=x1[pos][1];
				x1[pos][0]=temp;
				x1[pos][1]=temp1;
				if(arr[f][8]==1)
				one++;
				else
				zero++;
			}
			one>zero?cout<<1:cout<<0;
			cout<<" ";
		}
	}
		 

