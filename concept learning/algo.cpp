#include <iostream>
#include <fstream>
using namespace std;
int main( int argc, char *argv[])
	{
		ifstream file(argv[1]); // Create a file stream
		// and open for reading.
		if( !file ) // Get status.
		{
			cerr << "An error occurred when opening the file "
			<< argv[1] << endl;
			return 2;
		}
		string line;
		int c=0;
		string comp;
		while(getline(file,line)) // Copy the file
		{ // to standard
			if(line[16]=='0')//ignoring where ever function is 0
				continue;
			if(c==0)	//storing the hypothesis in comp
			{
				c++;
				comp=line;
				continue;	
			}
			for(int i=0;i<15;i++)	//loop to find hypothesis
			{
				if(line[i]==',')
					continue;
				if(comp[i]=='1'&&line[i]=='1')
					continue;
				if(comp[i]=='0'&&line[i]=='0')	
					continue;
				comp[i]='D';
			}
		}
		cout<<"The desired hypothesis function has the coefficient as:"<<endl;
		int j=0;
		for(int i=0;i<15;i=i+2)		//loop to print result in desired format
		{
			if(comp[i]=='1'||comp[i]=='0')
			j++;
		}
		cout<<j<<',';
		
		for(int i=0;i<15;i=i+2)		//loop to print result in desired format
		{
			if(comp[i]=='1')
			{
				cout<<(i/2+1)<<',';
			}
			else if(comp[i]=='0')
			{
				cout<<(i/2+1)*-1<<',';
			}
		}
		cout<<"\b .";
		return 0;
	}
