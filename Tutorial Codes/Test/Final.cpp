#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void CalculatePay(vector<int>& times,vector<float>& standardpay,vector<float>& overtimepay)
{
	for (int i = 0; i < times.size(); ++i)
	{
		if(times[i] > 40)	//overtime has been done
		{
			standardpay.push_back(390);	//9.75*40 since standard pay would be fixed for 40 hour week if time > 40
			overtimepay.push_back((times[i]-40)*1.5);	//remaining time * 1.5	
			//Your assignment states the following: "overtime pay is time and a half.(*1.5)"
			//From what I understand overtimepay is 1.5 times the overtime hours. PLEASE CHECK THIS.
		}
		if(times[i] <= 40)	//means no overtime
		{
			standardpay.push_back(times[i]*9.75);	//calculate and store the standard pay.
			overtimepay.push_back(0);		//since overtime is now 0.
		}
	}
}

void PrintResult(vector<int>& times,vector<float>& standardpay,vector<float>& overtimepay)
{
	for (int i = 0; i < times.size(); ++i)
		{
			cout<<"Employee #"<<i+1<<" worked "<<times[i]<<" hours for $"<<std::fixed << std::setprecision(2)<<standardpay[i]<<" standard pay and $"<<overtimepay[i]<<" overtime totaling $"<<standardpay[i]+overtimepay[i]<<" pay for the week"<<endl;
		}
		//fixed and setpricison are used since we need all employees must line up on the decimal point.
}

int main()
{
	std::vector<int> times;		//Declare a vector of type int
	int x;					//temp variable for reading from file
	ifstream ifile;			
	ifile.open("Input.txt");	//open file in reading mode
	while(ifile >> x)		//read from file till "x" gets a valid value in it from file.
		times.push_back(x);	//store "x" in the vector "times".

	// for (int i = 0; i < times.size(); ++i)		//Boiler code to check if file is read properly.
	// {
	// 	cout<<times[i]<<" ";
	// }
	// cout<<endl;

	std::vector<float> standardpay;		//The two parallel vectors for standard and
	std::vector<float> overtimepay;		//overtime pay.
	
	CalculatePay(times,standardpay,overtimepay);
	////--------------THE CODE TILL NOW CALCULATES EVERYTHING THAT IS REQUIRED--------------
	////---------------BUT DOES NOT PRINT ANYTHING---------------------
	////--------------FINALLY YOU NEED TO PRINT THE ANSWER IN THE FORMAT SPECIFIED----------
	////--------------TO DO THIS, YOU NEED TO CALL THE "PrintResult" FUNCTION--------------
	////--------------I AM LEAVING THE CALLING PART AS AN EXERCISE FOR YOU TO PERFORM----------
	///-------------HINT: See the manner in which "CalculatePay" function is called----------
	
	//****insert function call here***.

	ifile.close();
	return 0;
}