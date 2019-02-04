#include <iostream>
using namespace std;

bool LeapYear(int n)
{
	return (n%4 == 0 && n % 100 != 0 || n % 400 == 0);
}

int Day(int n,int m)
{
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		return 31;
	if (n == 4 || n == 6 || n == 9 || n == 11 )
		return 30;
	if (n == 2)
	{
		if (LeapYear(m))
			return 29;
		return 28;
	}
}

int main()
{
	int count = 0;
	
	int od,om,oy;
	cout<<"Nhập ngày tháng năm sinh của bạn: ";
	cin>>od>>om>>oy;
	int d,m,y;
	cout<<"Nhập ngày tháng năm hiện tại của bạn: ";
	cin>>d>>m>>y;
	while(od != d || om != m || oy != y)
	{
		count++;
		od++;
		if(od > Day(om,oy))
		{
			od = 1;
			om++;
			if(om > 12)
			{
				om = 1;
				oy++;
			}
		}
	}
	cout<<"Bạn đã ăn hại: "<<count<<" ngày"<<endl;
	return 0;
}
