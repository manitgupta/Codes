#include<iostream>
#include<cstdio>

using namespace std;

void hanoi(int n, char frompeg, char topeg, char auxpeg, int &count)
{
	if (n==1)
	{
		printf("Move disk 1 from peg %c to peg %c \n",frompeg,topeg);
		count+=1; //Covers the steps of (n-1) disks.
		return;
	}
	hanoi(n-1,frompeg,auxpeg,topeg,count);
	count+=1; //Covers the step of moving nth disk.n
	cout<<"Move disk "<<n<<" from peg "<<frompeg<<" to peg "<<topeg<<endl;
	hanoi(n-1,auxpeg,topeg,frompeg,count);
}

int main()
{
	int count=0;
	hanoi(3,'A','C','B',count); //A = Source, B = Spare, C = Dest
	cout<<"No. of Steps:"<<count<<endl;
	return 0;

}

