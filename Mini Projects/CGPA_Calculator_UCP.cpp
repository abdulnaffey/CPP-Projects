#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct GPA 
{
	float CGPA;
	int pre_credits;
	float GP[40]={0.0};
	float marks[40]={0.0};
	int   credit[40]={0};
	string  grade[40] ;
	string courses[40];
};
void AssignGP(GPA& count,int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (count.marks[i] >= 86)
		{
			count.grade[i] = { "A" };			count.GP[i] = 4.0;
		}
		else if (count.marks[i] < 86 && count.marks[i] > 81)
		{
			count.grade[i] = { "A-" };			count.GP[i] = 3.67;
		}
		else if (count.marks[i] < 82 && count.marks[i] > 77)
		{
			count.grade[i] = { "B+" };			count.GP[i] = 3.33;
		}
		else if (count.marks[i] < 77 && count.marks[i] > 73)
		{
			count.grade[i] = { "B" };			count.GP[i] = 3.0;
		}
		else if (count.marks[i] < 74 && count.marks[i] > 69)
		{
			count.grade[i] = { "B-" };			count.GP[i] = 2.67;
		}
		else if (count.marks[i] < 70 && count.marks[i] > 65)
		{
			count.grade[i] = { "C+" };			count.GP[i] = 2.33;
		}
		else if (count.marks[i] < 66 && count.marks[i] > 61)
		{
			count.grade[i] = { "C" };			count.GP[i] = 2.00;
		}
		else if (count.marks[i] < 62 && count.marks[i] > 57)
		{
			count.grade[i] = { "C-" };			count.GP[i] = 1.67;
		}
		else if (count.marks[i] < 58 && count.marks[i] > 53)
		{
			count.grade[i] = { "D+" };			count.GP[i] = 1.33;
		}
		else if (count.marks[i] < 54 && count.marks[i] > 49)
		{
			count.grade[i] = { "D" };			count.GP[i] = 1.0;
		}
		else if (count.marks[i] < 49)
		{
			count.grade[i] = { "F" };			count.GP[i] = 0.0;
		}
	}
}
void Display(GPA& count, int counter)
{
	cout <<"\t\t\t\t" << "---------------------------------------\n";
	cout << "\t\t\t\t" << "| \t   COURSE NAME\tG.P\tGRADE |\n";
	for (int i = 0; i < counter; i++)
	{
		cout << "\t\t\t\t" << "| " << setw(20) << count.courses[i] << "\t" << count.GP[i] << "\t" << setw(2) << count.grade[i] << setw(7) << "| \n";
	}
	cout << "\t\t\t\t" << "---------------------------------------\n";
}
void CalculatingGPA(GPA& count, int counter)
{
	float gpa, sum = 0.0;
	int   credit_total = 0;
	for (int i = 0; i < counter; i++)
	{
		sum = sum + (count.GP[i] * count.credit[i]);
		credit_total = credit_total + count.credit[i];
	}
	if (count.CGPA != 0)
	{
		sum +=  count.CGPA * count.pre_credits;
		gpa = sum / (credit_total + count.pre_credits);
	}
	else
	{
		gpa = sum / credit_total;
	}
	cout << "\t\t\t\t" << "The GPA of the Student is : " << setprecision(3) << gpa;
}
int GettingInput(GPA& count, int counter)
{
	int x;
	system("cls");
	cout << "\t\t\t" << "\t\t\tWELLCOME TO UCP CGPA CALCULATOR\n"; 
	cout << "\t\t\t\t" << "Enter the previous CGPA if any otherwise 0 :"; cin >> count.CGPA;
	cout << "\t\t\t\t" << "Enter the Total Credits if any otherwise 0 :"; cin >> count.pre_credits;
	cout << "\t\t\t\t" << "Starting with getting the Course Name for all subjects \n\n\t\t\t\tNumber of courses must not be more than 9.\n";
	for (int i = 0; i < 40; i++)
	{
		
		if(i!=0)cout << "\t\t\t" << "\t\t\tWELLCOME TO UCP CGPA CALCULATOR\n";
		cout << "\t\t\t\t" << "Enter the Course name for course " << i + 1 << " (use \"_\" instead of \" \")" << " : "; cin>> count.courses[i]  ;
		cout << "\t\t\t\t" << "Enter the Credits this course carries : "; cin >> count.credit[i];
		while (count.credit[i] < 0 || count.credit[i] > 4)
		{
			cout << "\t\t\t\t" << "Wrong Input !!!!\n\t\t\t\tEnter Again....:"; cin >> count.credit[i];
		}
		cout << "\t\t\t\t" << "Enter the Obtained Marks in " << count.courses[i] << " : "; cin >> count.marks[i];
		while (count.marks[i] < 0 || count.marks[i] > 100)
		{
			cout << "\t\t\t\t" << "Wrong Input !!!!\n\t\t\t\tEnter Again....:"; cin >> count.marks[i];
		}
		if (i < 40)
		{
			cout << "\t\t\t\t" << "Do yo want to add another subject?\n\t\t\t\tPress 1 if Yes 0 if No : "; cin >> x;
			while (x < 0 || x > 1)
			{
				cout << "\t\t\t\t" << "Wrong Input !!!!\n\t\t\t\tEnter Again....:"; cin >> x;
			}
		}
		if (x == 0)
		{
			i = 40;
		}
		system("cls");
		counter++;
	}
	return counter;
}
int main()
{
	GPA count;
	int x = 0,counter=0;
	do 
	{	
		counter = GettingInput(count, counter);
		AssignGP(count, counter);
		Display(count, counter);
		CalculatingGPA(count, counter);
		cout  << "\n\t\t\t\tDo you want to find for another student ?\n\t\t\t\tIf yes the enter 1 otherwise 0 :";
		cin >> x;
		while (x < 0 || x>1)
		{
			cout << "\t\t\t\t" << "Wrong Input !!!!\n\t\t\t\tEnter Again....:"; cin >> x;
		}
	} while (x!=0);
	system("PAUSE");
} 


