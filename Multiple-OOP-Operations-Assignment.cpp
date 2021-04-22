/*
Create a class called SwimmingPool, this class contains the length, width and height, area in gallons. The area in gallons is calculated by the length * width * height * 0.133681. The class also has the rate (in gallons per minute) at which the water will the pool, and the rate (in gallons per minute) at which the water will drain from the pool. Add a constructor which initializes everything to zero. Create the following functions:
i. Gets the length, width, height
ii. Calculate the amount of water (in gallons) the pool contains using the length, width and
height.
iii. Input the amount of water to fill the pool, the input can be zero so the pool is empty.
iv. Determine the time required to fill and drain the pool.
Example: The pool has a length=12, width=15 and height=6 then the pool would contain 144.375 gallons of water: this is calculated by 12*15*6*0.133681. The pool will fill at a rate of 9 gallons per minute while it will drain at 3 gallons per minute.
Case I: 45 Gallons were added to the pool. Now the program will calculate the time in which that the pool will be filled and the time in which the pool will be drained. The pool will be filled in approximately 11 minutes and will drain in 15 minutes.
Case II: The pool was empty. The pool will be filled in approximately 16 minutes and will drain in 0 minute since it is already empty.
*/


/*
Muhammad Uzair
P16-6002
Assignment # 02
Question # 01
*/
#include <iostream>
#include <string>
using namespace std;

class SwimmingPool
{
	float poolLength, poolWidth, poolHeight;
	float poolGallons;
	int fillTime;
	int drainTime;

public:
	SwimmingPool()
	{
		poolLength = 0;
		poolWidth = 0;
		poolHeight = 0;
		poolGallons = 0;
		fillTime = 0;
		drainTime = 0;
	}

	void setValues(int x, int y, int z)
	{
		poolLength = x;
		poolWidth = y;
		poolHeight = z;
	}

	float amountOfWater()
	{
		poolGallons = poolLength * poolHeight * poolWidth * 0.133681;
		return poolGallons;
	}

	float waterFilled(int x)
	{
		return x;
	}

	void fillDrainTime(float x, int f, int d)
	{
		fillTime = (poolGallons - x) / f;
		int drainTime;
		drainTime = x / d;
		cout << "Time to fill the entire pool is: " << fillTime << endl;
		cout << "Time to drain the entire pool is: " << drainTime << endl;
	}
};

int main()
{
	SwimmingPool ob;
	float length, width, height;
	int gals;
	int fRate, dRate;

	cout << "Enter the Length of the pool" << endl;
	cin >> length;
	cout << "Enter the Width of the pool" << endl;
	cin >> width;
	cout << "Enter the Height of the pool" << endl;
	cin >> height;

	ob.setValues(length, width, height);
	ob.amountOfWater();

	cout << "Enter the amount of water that has been filled" << endl;
	cin >> gals;

	cout << "Enter Filling Rate" << endl;
	cin >> fRate;
	cout << "Enter Drain Rate: " << endl;
	cin >> dRate;
	ob.fillDrainTime(ob.waterFilled(gals), fRate, dRate);
	return 0;
}


/*
Q2: Create a class called ClockType which contains the seconds, minutes and hours. The user will input the time and select the format: 12 hours or 24 hours. After the user inputs the format and time, the program should display the time, increment the seconds, minutes and hours as a normal clock, and the program should increment the seconds at the same rate as a normal clock would. Create members functions for each task: input, display, increment second, increment minute and increment hour.
*/

/*MUhammad Uzair
P16-6002
Assignment 02
Question # 05*/
#include <iostream>
#include <string>
using namespace std;

class complex{
public:
complex(double, double);
void display()const;
complex add(complex)const;
complex sub(complex)const;

private:
double real;
double img;
};

complex::complex(double x = 0, double y = 0)
{
real = x;
img = y;
}

complex complex::add(complex usr)const
{
complex answer;
answer.real = real + usr.real;
answer.img = img + usr.img;
return answer;
}

complex complex::sub(complex usr)const
{
complex answer;
answer.real = real - usr.real;
answer.img = img - usr.img;
return answer;
}

void complex::display()const
{
cout << "(" << real << "," << img << ")" << endl;
}

int main()
{
double r, im, nr, nim;
cout << "Enter Real Part:\t";
cin >> r;
cout << "Enter Imaginary Part:\t";
cin >> im;
complex usr(r, im);
cout << "\n\n\nNow Enter Another Imaginary Number:\n";
cout << "Enter Real Part:\t";
cin >> nr;
cout << "Enter Imaginary Part:\t";
cin >> nim;
complex an(nr, nim);
complex addition = usr.add(an);
complex subtraction = usr.sub(an);
cout << "The First Imaginary Number:\t";
usr.display();
cout << "\nAdditon Of Imaginary Number = ";
addition.display();
cout << "\nSubtraction Of Imaginary Number = ";
subtraction.display();
return 0;
}


/*
Create a class called CalendarType which contains the date, month and year. The user would enter the day, month and year, the program should verify whether the date entered is correct or not, examples would be whether the date entered exists in the month such as 31 does not exist in April or the user entered 29th February 2005 and the year is not a leap year. The program would also tell us the day, example 15th March 2017 would be Wednesday. The oldest date the program can tell us the day of would be 1st January 1900 which would be Monday, you can use this to determine the day of any other date. Create member functions for each of the following task: input date, input month, input year, verify date entered and determine the day of the date entered.
*/



/*	Muhammad Uzair
P166002
Question # 03 */
#include<iostream>
#include<string>
using namespace std;
int leap = 0;
class CalanderType
{
	int day, month, year, day1, cheeckday;

public:
	CalanderType()//constructor
	{
		day = 0;
		month = 0;
		year = 0;
		day1 = 29;
		cheeckday = 0;
	}
	int inputday();
	void inputmonth();
	void inputyear();
	void printdate();
	int checkday();
};
void main()
{
	CalanderType c;
	c.inputday();
	c.printdate();
	c.checkday();
	system("pause");
}
int CalanderType::inputday()
{
	cout << "Enter the day of the date :";
	cin >> day;

	if (day <= 31 && day>0)
	{
		inputmonth();
	}
	else
		cout << "wrong date enter please enter day less then 31 " << endl;
	return 1;
}
void CalanderType::inputmonth()
{
again:
	cout << "Enter the month of the date: ";
	cin >> month;
	if (month <= 12 && month > 0)
	{
		if (day <= 31 && month == 1 || day <= 31 && month == 3 || day <= 31 && month == 5 || day <= 31 && month == 7 || day <= 31 && month == 8 || day <= 31 && month == 10 || day <= 31 && month == 12)
		{
			inputyear();
		}

		else if (day < 31 && month == 4 || day < 31 && month == 6 || day < 31 && month == 9 || day < 31 || month == 11 || day <= 29 && month == 2)
		{
			inputyear();
		}


		else
		{
			cout << "This month does not have this day " << endl;
			goto again;
		}
	}

	else
		cout << "wrong month enter please type correct " << endl;

}
void CalanderType::inputyear()
{
again:
	cout << "ENter the year of the date: ";
	cin >> year;
	if (year > 0)
	{
		if (year > 0)
		{
			if (year % 4 == 0)
				leap++;
		}
	}
	else
	{
		cout << "Please enter a positive value for year" << endl;
		goto again;
	}
}
void CalanderType::printdate()
{
	cout << day << ":" << month << ":" << year << endl;
	if (leap > 0)
		cout << "This is a leap year " << endl;

}
int CalanderType::checkday()
{
	int d = day, m = month, y = year;
	for (int i = 1; i <= year; i++)
	{
		for (int j = 1; j <= month; j++)
		{
			for (int k = d; k <= day; k++)
			{
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					day = 31;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11)
				{
					day = 30;
				}
				else if (month == 2)
				{
					day = 28;
				}
				k = k + 7;
			}
			m++;
		}
		y++;
	}
	switch (cheeckday)
	{
	case 1:
		cout << "This day will be Sunday" << endl;
		break;
	case 2:
		cout << "This day will be monday" << endl;
		break;
	case 3:
		cout << "This day will be Tuesday" << endl;
		break;
	case 4:
		cout << "This day will be Wednessday" << endl;
		break;
	case 5:
		cout << "This day will be thursday" << endl;
		break;
	case 6:
		cout << "This day will be Friday " << endl;
		break;
	case 7:
		cout << "This day will be Saturday" << endl;
		break;
	default:
		cout << "kuch b ";
		break;
	}

	return 0;
}

/*
Create class Matrix which add,subtract and multiply two matrices and store result in the third matrix. Your class had three data member int matrix_1[5][5], int matrix_2[5][5] and int matrix_3[5][5].simlary your program had member function getdata,add_matrix ,sub_matrix, multiply_matrix,show matrix which print result after of the resultant matrix.show ouput after each operation e.g addition,subtraction and multiplication.
File_1. 12345
6 7 8 9 10 11 12 13 14 15 15 16 17 18 11
12345
6 7 8 9 10
11 12 13 14 15
15 16 17 18 19
*/


/*	Muhammad Uzair
P16-6002
Question # 04*/
#include<iostream>
#include<fstream>
using namespace std;

class matrix
{
private:
	int matrix_1[4][5];
	int matrix_2[5][4];
	int matrix_3[5][5];
	int matrix_31[5][5];
	int matrix_32[5][5];
public:
	void getdata(int[][5], int[][4]);
	void addition();
	void subtruction();
	void multiplication();
	matrix();
	void Display();
	void displaymultiplication();
};
matrix::matrix() //constructer...
{
	for (int i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			matrix_1[i][j] = 0;
			matrix_2[i][j] = 0;
			matrix_3[i][j] = 0;
			matrix_31[i][j] = 0;
			matrix_32[i][j] = 0;
		}
	}
}
void matrix::getdata(int x[][5], int y[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix_1[i][j] = x[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <4; j++)
		{
			matrix_2[i][j] = y[i][j];
		}
	}
}
void matrix::addition()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			matrix_3[i][j] += (matrix_1[i][j] + matrix_2[i][j]);
			cout << " " << matrix_3[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void matrix::subtruction()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			matrix_31[i][j] += (matrix_2[i][j] - matrix_1[i][j]);
			cout << " " << matrix_31[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void matrix::multiplication()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k <4; k++)
			{
				matrix_32[i][j] += (matrix_1[i][k] * matrix_2[k][j]);
			}
		}
	}
}
void matrix::Display()
{
	addition();
	subtruction();
	multiplication();
	displaymultiplication();
}
void matrix::displaymultiplication()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << matrix_32[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	matrix mtx;
	int x[4][5], y[5][4];
	ifstream in("Text.txt");
	ifstream in1("Text1.txt");
	if (in.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				in >> x[i][j];
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			in1 >> y[i][j];
		}
	}
	mtx.getdata(x, y);
	mtx.Display();
	return 0;
}
