//Dipak Agarwal
//16IE10035
//Assignment 3

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int a[9][2][2];
int y=0;
int n=0;
int main()
	{
		 std::ifstream file ("data3.csv", std::ifstream::in);		// and open for reading.
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
 		int c0=0,c1=0,c2=0,c3=0;
 		for(int i=0;i<9;i++)
 		{
 			for(int j=0;j<20;j++)
 			{
 				if(arr[j][i]==1 && arr[j][8]==1)
 				c0++;
 				if(arr[j][i]==1 && arr[j][8]==0)
 				c1++;
 				if(arr[j][i]==0 && arr[j][8]==1)
 				c2++;
 				if(arr[j][i]==0 && arr[j][8]==0)
 				c3++;
 				if(i==8)
 				{
 					if(arr[j][8]==1)
					 y++;
					 else
					 n++;
				 }
			 }
			 a[i][0][0]=c0;
			 a[i][0][1]=c1;
			 a[i][1][0]=c2;
			 a[i][1][1]=c3;
			 c0=0;
			 c1=0;
			 c2=0;
			 c3=0;
		 }
		std::ifstream file1 ("test3.csv", std::ifstream::in);
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
	//	cout<< y <<"    "<<n;
		double yes=0,no=0;
		yes=1.0*y/(y+n);
		no=1.0*n/(y+n);
		double py=1.0;
		double pn=1.0;
		cout<<endl<<"        "<<"Result"<<endl;
		for(int j=0;j<4;j++)
		{
			for(int i=0;i<8;i++)
			{
				if(x[j][i]==1)
				{
					py=1.0*((1+a[i][0][0])*(y+n)*py)/((y+2)*(a[i][0][0]+a[i][0][1]));
					pn=1.0*((1+a[i][0][1])*(y+n)*pn)/((n+2)*(a[i][0][0]+a[i][0][1]));
				}
				else
				{
					py=1.0*((1+a[i][1][0])*(y+n)*py)/((y+2)*(a[i][1][0]+a[i][1][1]));
					pn=1.0*((1+a[i][1][1])*(y+n)*pn)/((n+2)*(a[i][1][0]+a[i][1][1]));	
				}
			}
		//	cout<< py*yes << "   "<<pn*no<< endl;
			if(py*yes>=pn*no)
			cout<<1<<" ";
			else
			cout<<0<<" ";  
			py=1.0;
			pn=1.0;
		}
	//	cout<<a[0][0][0]<<" "<<a[0][0][1]<<" "<<a[0][1][0]<<" "<<a[0][1][1];
	}
		 

