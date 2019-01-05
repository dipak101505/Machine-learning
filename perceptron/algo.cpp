//Dipak Agarwal
//16IE10035
//Assignment 6

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int y=0;
int n=0;
double sig(double a)
{
	a=a*(-1);
	return(1/(1+exp(a)));
}
int main()
	{
		std::ifstream file ("data6.csv", std::ifstream::in);		// and open for reading.
		string line;
		int arr[20][9];
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
 		cout<<endl<<endl;
 		
		std::ifstream file1 ("test6.csv", std::ifstream::in);
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
		cout<<endl<<endl;
		double wt[9];double c=0;
		double predict[20];
		for(int i=0;i<9;i++)
			wt[i]=0.5;
		for(int i=0;i<100;i++)
		{
			for(j=0;j<20;j++)
			{
				double h=wt[8];
				for(int k=0;k<8;k++)
				{
					h+=arr[j][k]*wt[k];
				}
				predict[j]=sig(h);
				
			}
			for(int k=0;k<8;k++)
			{
				double sum=0;
				for(int l=0;l<20;l++)
				{
					sum+=(arr[l][8]-predict[l])*predict[l]*(1-predict[l])*arr[l][k];
				}
				wt[k]+=0.1*sum;	
			}
			double sum=0;
			for(int l=0;l<20;l++)
				{
					sum+=(arr[l][8]-predict[l])*predict[l]*(1-predict[l]);
				}
				wt[8]+=0.1*sum;
			
		}
		
		double sum=0;
		for(int i=0;i<4;i++)
		{
			sum+=wt[8];
			for(j=0;j<8;j++)
			{
				if(x[i][j]==1)
				sum+=wt[j];	
			}
//			cout<<sig(sum)<<" ";
			if(sig(sum)>=0.5)
			cout<<1<<" ";
			else
			cout<<0<<" ";
			sum=0;
		}
	}
