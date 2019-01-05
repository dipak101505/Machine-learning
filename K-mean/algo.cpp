//Dipak Agarwal
//16IE10035
//Assignment 7

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int y=0;
int n=0;

int main()
	{
		std::ifstream file ("data7.csv", std::ifstream::in);		// and open for reading.
		string line;
		int arr[20][9];
	//	cout<<"	Training set."<<endl<<endl;
		int j=0;
		while(getline(file,line)) // Copy the file
		{ // to standard
			int count=0;
		//	cout<<line<<endl;
			for(int i=0;i<15;i++)	//loop to find hypothesis
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
 		//cout<<endl<<endl;
 		double mean[2][8];
		for(int i=0;i<8;i++)
		{
			mean[0][i]=arr[15][i];
			mean[1][i]=arr[0][i];
		}
		
		for(int i=0;i<10;i++)
		{
			double dist1=0;
			double dist2=0;
			int n=0;int m=0;
			for(int k=0;k<20;k++)
			{
				for(int l=0;l<8;l++)
				{
					dist1+=1.0*(mean[0][l]-arr[k][l])*(mean[0][l]-arr[k][l]);
					dist2+=1.0*(mean[1][l]-arr[k][l])*(mean[1][l]-arr[k][l]);
				}
				if(dist1<=dist2)
				{
				
				arr[k][8]=1;
				n++;
			}
				else
				{
				
				arr[k][8]=2;
				m++;
			}
			
				dist1=0;
				dist2=0;
			}
			mean[2][8]={0};
			for(int k=0;k<20;k++)
			{
				for(int l=0;l<8;l++)
				{
					if(arr[k][8]==1)
					{
						mean[0][l]+=arr[k][l];
					}
					if(arr[k][8]==2)
					{
						mean[1][l]+=arr[k][l];
					}
				}
			}
			for(int l=0;l<8;l++)
				{
						mean[0][l]/=n;
						mean[1][l]/=m;
				}
				
		}
		for(int i=0;i<20;i++)
		{
			cout<<arr[i][8]<<" ";
		}
	}
