#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

using lint = long long int;
//typedef unsigned long long int lint;

void cont(string &p);
void enterNum(lint &x,lint &y);
void orderNum(lint &x, lint &y, lint &a, lint &b);
lint countNum(lint &low, lint &high);
int power(lint tot);
void summary(int u,lint lo,lint hi, lint tot);

int main()
{
	string p;
	lint num1;
	lint num2;
	lint Num1;
	lint Num2;	
	lint s;

	while(p != "q")
	{		
		system("clear");
		enterNum(num1,num2);          	   //lets user enter their numbers
		orderNum(num1,num2,Num1,Num2);        //orders the inputted numbers so that Num1 > Num2
		s = countNum(Num2, Num1);             //cout the sum of all integers from Num2 to Num1
		int poww = power(s);

		cout<< "Total sum of integers from "<<Num2<<" to "<<Num1<< " = "<<s<<endl;

		if(poww>2){cout<<"Which is approximatley: "<<float(s/pow(10,poww))<<" X 10^"								   <<poww<<endl<<endl;}

		summary(2,Num2,Num1, s);
		cont(p);                       //asks user if they want to continue
	}
		
	system("clear");
	summary(1,Num2,Num1, s);
	cout<<endl<<"End of Intcount" <<endl;
		
	return 0;
}

//-----------------------------------------------------------------------------	


void cont(string &p)
{
	cout<<"enter \"q\" to quit or enter any other key to continue:"<<endl;
	cin>>p;
}

//-----------------------------------------------------------------------------

void enterNum(lint &x,lint &y)
{
	bool loop;         			   //to determine whether loop continues or not
	lint lim=numeric_limits<lint>::max()/100000;
	do{
		loop = false;
		
		cout<<"Enter two integers between 0 - "<<lim<<endl;
		cout<<"Enter first number:"<<endl;
		cin>>x;
		cout<<endl;
		
		cout<<"Enter second number:"<<endl;
		cin>>y;
		cout<<endl;
		system("clear");

		
		if(cin.fail() || x<0 || y<0 || x>lim || y>lim)		      //to catch errors
		{          
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Try again."<<endl;	
			loop = true;
		}
			
	}while(loop);
}

//--------------------------------------------------------------------------------

void orderNum(lint &x, lint &y, lint &a, lint &b)
{               
	(x>y)?(a=x):(b=x);
	(x>y)?(b=y):(a=y);	
}

//--------------------------------------------------------------------------------


lint countNum(lint &low, lint &high)
{                                             
	lint N=0;
	for (int i=low; i<=high; i++)
	{
		N+=i;
		cout<<i<<"\t\t"<<N<<"\n";
	}
	
	system("clear");
	return N;
}

//--------------------------------------------------------------------------------

int power(lint tot)
{
		int N=0;
		
		while(tot>=10)
		{
			tot=tot/10;
			N++;	
		}
		
		return N;
}

//--------------------------------------------------------------------------------

void summary(int u,lint lo,lint hi, lint tot)
{  
	static vector<string> su;
	
	if(u==2)
	{	
		string low = to_string(lo);
		string high= to_string(hi);
		string total=to_string(tot);

		string tt=" --> ";
		string hh=" = ";

		stringstream sum;
		sum << low << tt<< high<< hh<<total;
		string f=sum.str();
		
		su.push_back (f);
	}

	if(u==1)
	{
		cout<<"Summary"<<endl;
		
		for (int i=0; i<su.size();i++)
		{
		    cout << su[i] << endl;
		}
	}
}


