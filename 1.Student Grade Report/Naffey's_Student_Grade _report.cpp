#include <iostream>
#include <string>
using namespace std;
int main()
{
	const int size = 100;
	int  choice2,counter = 0,del = 0, temp = 0, total_percent[size], roll[size], roll_find, marks_maths[size], marks_computer[size];
	bool choice = 1, check = 1;
	double help;
	char grade[size];
	string name[size], name_find, temp2;
	

	cout << "\t \t \t \t                        ASALAMUALAIKUM \t \t\ \t \n";

	for (int i = 0; choice == 1; i++)
	{
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "|";
		cout << endl;
		cout << "|                                                                                                                          |" << endl;
		cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
		cout << "|                                                                                                                          |" << endl;
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "| \n\n\n" << endl;
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "|";
		cout << endl;
		cout << "|                                                  WELLCOME TO ADMIN PANEL                                                 |" << endl;
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "|";
		cout << endl << endl;
		if ( counter == 0) cout << " Let's Start by entering the roll numbers and marks for the students.  \n";
		cout << " Enter the roll number for the student No. " << i + 1<< " : ";
		cin >> roll[i];
		cout << " Enter the name for the student No. " << i + 1 << " : ";
		cin.ignore();
		getline(cin,name[i]);
		cout << " Enter the Marks of Computer scince for the student No. " << i + 1 << " within 100  : ";
		cin >> marks_computer[i];
		while (marks_computer[i] > 100 || marks_computer[i] < 0)
		{
			cout << " Wrong Input ! \n Enter correctly : ";
			cin >> marks_computer[i];
		}
		
		cout << " Enter the Marks of Maths for the student No. " << i + 1 << " within 100  : ";
		cin >> marks_maths[i];
		while (marks_maths[i] > 100 || marks_maths[i] < 0)
		{
			cout << " Wrong Input ! \n Enter correctly : ";
			cin >> marks_maths[i];
		}
		
		total_percent[i] = (marks_computer[i] + marks_maths[i]) / 2;
		if (total_percent[i] <= 100 || total_percent[i] >= 91)
		{
			grade[i] = 'A';
			
		}
		else if (total_percent[i] <= 90 || total_percent[i] >= 75)
		{
			grade[i] = 'B';
			
		}
		else if (total_percent[i] < 75 || total_percent[i] >= 60)
		{
			grade[i] = 'C';
			
		}
		else if (total_percent[i] < 60 || total_percent[i] >= 50)
		{
			grade[i] = 'D';
			
		}
		else if (total_percent[i] < 50)
		{
			grade[i] = 'F';
			
		}

		counter++;
		
		cout << " Would you like to enter the data for another student ? \n if Yes the enter 1 otherwise enter 0 : ";
			cin >> choice;
			system("cls");
	}
	do {
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "|";
		cout << endl;
		cout << "|                                                                                                                          |" << endl;
		cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
		cout << "|                                                                                                                          |" << endl;
		cout << "|";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << "| \n\n\n" << endl;
		choice = 1;
		for (int i = 0; i < 122; i++) cout << "=";
		cout << endl;
		cout << " # |\t| NAME | \t\t | ROLL No. | \t | Computer marks | \t | Maths marks | \t | Percet % | \t | Grade | \n";
		for (int i = 0; i < 122; i++) cout << "-";
		cout << endl << endl;
		for (int i = 0; i < counter; i++)
			cout << " " << i << " |\t| " << name[i] << " | \t | " << roll[i] << " | \t | " << marks_computer[i] << " | \t\t | " << marks_maths[i] << " | \t\t | " << total_percent[i] << " | \t | " << grade[i] << " | \n";
		for (int i = 0; i < 122; i++) cout << "=";
		cout << endl;
		cout << " Do you like to perform any other advance operation ? \n if Yes the enter 1 and i'll show you the options otherwise enter 0 : ";
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			cout << "|";
			for (int i = 0; i < 122; i++) cout << "-";
			cout << "|";
			cout << endl;
			cout << "|                                                                                                                          |" << endl;
			cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
			cout << "|                                                                                                                          |" << endl;
			cout << "|";
			for (int i = 0; i < 122; i++) cout << "-";
			cout << "| \n\n\n" << endl;
			choice = 1;
			for (int i = 0; i < 122; i++) cout << "=";
			cout << endl;
			cout << " # |\t| NAME | \t\t | ROLL No. | \t | Computer marks | \t | Maths marks | \t | Percet % | \t | Grade | \n";
			for (int i = 0; i < 122; i++) cout << "-";
			cout << endl << endl;
			for (int i = 0; i < counter; i++)
				cout << " " << i << " |\t| " << name[i] << " | \t | " << roll[i] << " | \t | " << marks_computer[i] << " | \t\t | " << marks_maths[i] << " | \t\t | " << total_percent[i] << " | \t | " << grade[i] << " | \n";
			for (int i = 0; i < 122; i++) cout << "=";
			cout << endl <<endl;
			cout << " 1.	Press 1 to update Roll Number of a particular Student. \n";
			cout << " 2.	Press 2 to update marks of a particular student for CS. \n";
			cout << " 3.	Press 3 to update marks of CS for all students who are already enrolled.\n";
			cout << " 4.	Press 4 to update marks for Mathematics. \n";
			cout << " 5.	Press 5 to update marks of Mathematics for all students who are already enrolled. \n";
			cout << " 6.	Press 6 to sort the data on the basis of generated percentages.\n";
			cout << " 7.	Press 7 to delete the record of a particular student. \n";
			cout << " 8.     Press 8 if you want to exit. \n";
			cout << " Enter your choice : ";
			cin >> choice2;
			while (choice2 < 0 || choice2 > 9)
			{
				cout << " Wrong Input ! \n Enter correctly : ";
				cin >> choice2;
			}
			switch (choice2)
			{
				system("cls");
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "|";
				cout << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "| \n\n\n" << endl;

			case 1:
				system("cls");
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "|";
				cout << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "| \n\n\n" << endl;
				cout << " Would you like to search by Roll No. or Name ?\n Press 1 for Roll no. and 0 for Name  ";
				cin >> choice;
				if (choice == 0)
				{
					cout << " Enter the name of the student whose roll number you want to update : ";
					do {
						cin.ignore();
						getline(cin, name_find);
						for (int i = 0; i < counter; i++)
						{
							if (name_find == name[i])
							{
								cout << " Ok ! Enter the correct roll number : ";
								cin >> roll[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Name found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Roll no. is updated of the particular student. \n";
					break;
				}
				else
				{
					cout << " Enter the Previous Roll No. of the student whose roll number you want to update : ";
					do {
						cin >> roll_find;
						for (int i = 0; i < counter; i++)
						{
							if (roll_find == roll[i])
							{
								cout << " Ok ! Enter the correct roll number : ";
								cin >> roll[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Roll no. found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Roll no. is updated of the particular student. \n";
					break;
				}
			case 2:
				system("cls");
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "|";
				cout << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "| \n\n\n" << endl;
				cout << " Would you like to search by Roll No. or Name ?\n Press 1 for Roll no. and 0 for Name  ";
				cin >> choice;
				if (choice == 0)
				{
					cout << " Enter the name of the student whose Computer science Marks you want to update : ";
					do {
						cin.ignore();
						getline(cin, name_find);
						for (int i = 0; i < counter; i++)
						{
							if (name_find == name[i])
							{
								cout << " Ok ! Enter the correct marks for computer science : ";
								cin >> marks_computer[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Name found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Marks are updated of the particular student. \n";
					break;
				}
				else
				{
					cout << " Enter the Roll No. of the student whose Computer science Marks you want to update : ";
					do {
						cin >> roll_find;
						for (int i = 0; i < counter; i++)
						{
							if (roll_find == roll[i])
							{
								cout << " Ok ! Enter the correct marks for computer science : ";
								cin >> marks_computer[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Roll No. found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Marks are updated of the particular student. \n";
					break;
				}
			case 3:
				system("cls");
				cout << " Ok ! Let's update the marks of computer science of all students already enrolled. \n";
				for (int i = 0; i < counter; i++)
				{
					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "|";
					cout << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "| \n\n\n" << endl;
					cout << " Enter to update the marks of computer science for the student No. " << i + 1 << " : ";
					cin >> marks_computer[i];
					system("cls");
				}
				system("cls");
				cout << " Great ! All done with updating. \n";
				break;
			case 4:
				system("cls");
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "|";
				cout << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
				cout << "|                                                                                                                          |" << endl;
				cout << "|";
				for (int i = 0; i < 122; i++) cout << "-";
				cout << "| \n\n\n" << endl;
				cout << " Would you like to search by Roll No. or Name ?\n Press 1 for Roll no. and 0 for Name  ";
				cin >> choice;
				if (choice == 0)
				{
					cout << " Enter the name of the student whose Maths Marks you want to update : ";
					do {
						cin.ignore();
						getline(cin, name_find);
						for (int i = 0; i < counter; i++)
						{
							if (name_find == name[i])
							{
								cout << " Ok ! Enter the correct marks for maths : ";
								cin >> marks_computer[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Name found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Marks are updated of the particular student. \n";
					break;
				}
				else
				{
					cout << " Enter the Roll No. of the student whose Maths Marks you want to update : ";
					do {
						cin >> roll_find;
						for (int i = 0; i < counter; i++)
						{
							if (roll_find == roll[i])
							{
								cout << " Ok ! Enter the correct marks for maths : ";
								cin >> marks_computer[i];
								check = 0;
							}
							else if (i == 99)
							{
								cout << " No such Roll No. found ! \n Enter again carefully. : ";
								check = 0;
							}

						}
					} while (check == 1);
					check = 0;
					system("cls");
					cout << " Great ! All done. \n The Marks are updated of the particular student. \n";
					break;
				}
			case 5:
				system("cls");
				cout << " Ok ! Let's update the marks of maths of all students already enrolled. \n";
				
				for (int i = 0; i < counter; i++)
				{
					
					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "|";
					cout << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "| \n\n\n" << endl;
					cout << " Enter to update the marks of Maths for the student No. " << i + 1 << " : ";
					cin >> marks_maths[i];
					system("cls");
				}
				system("cls");
				cout << " Great ! All done with updating. \n";
				break;
			case 6:
				for (int i = 0; i < counter - 1; i++)
				{
					for (int j = i + 1; j < counter; j++)
					{
						if (total_percent[i] > total_percent[j])
						{
							temp = total_percent[i];
							total_percent[i] = total_percent[j];
							total_percent[j] = temp;

							temp = marks_maths[i];
							marks_maths[i] = marks_maths[j];
							marks_maths[j] = temp;

							temp = roll[i];
							roll[i] = roll[j];
							roll[j] = temp;

							temp = grade[i];
							grade[i] = grade[j];
							grade[j] = temp;

							temp = marks_computer[i];
							marks_computer[i] = marks_computer[j];
							marks_computer[j] = temp;

							temp2 = name[i];
							name[i] = name[j];
							name[j] = temp2;
						}
					}
				}
				system("cls");
				cout << " Great ! All done. \n All the data is sorted in ascending order of the percentage of the students. \n";
				break;
			case 7:
				system("cls");

					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "|";
					cout << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|                                                   A D M I N   P A N E L                                                  |" << endl;
					cout << "|                                                                                                                          |" << endl;
					cout << "|";
					for (int i = 0; i < 122; i++) cout << "-";
					cout << "| \n\n\n" << endl;
					cout << " Would you like to search by Roll No. or Name ?\n Press 1 for Roll no. and 0 for Name  ";
					cin >> choice;
					if (choice == 0)
					{
						cout << " Enter the name of the student whose record you ant to delete. \n";
						do {
							cin.ignore();
							getline(cin, name_find);
							for (int i = 0; i < counter; i++)
							{
								if (name_find == name[i])
								{
									cout << "ok";
									del += i;
									check = 0;
									break;
								}
								else if (i == 99)
								{
									cout << " No such Name found ! \n Enter again carefully. : ";
									check = 0;
									break;
								}
							}
						} while (check == 1);

						for (int i = del; i < counter; i++)  name[i] = name[i + 1];
						for (int i = del; i < counter; i++)  roll[i] = roll[i + 1];
						for (int i = del; i < counter; i++)  marks_computer[i] = marks_computer[i + 1];
						for (int i = del; i < counter; i++)  marks_maths[i] = marks_maths[i + 1];
						for (int i = del; i < counter; i++)	 total_percent[i] = total_percent[i + 1];
						for (int i = del; i < counter; i++)	 grade[i] = grade[i + 1];




						counter--;
						system("cls");
						cout << " Done ! \n";

						break;
					}
					else
					{
						cout << " Enter the Roll No. of the student whose record you ant to delete. \n";
						do {
							cin >> roll_find;
							for (int i = 0; i < counter; i++)
							{
								if (roll_find == roll[i])
								{
									cout << "ok";
									del += i;
									check = 0;
									break;
								}
								else if (i == 99)
								{
									cout << " No such Roll No. found ! \n Enter again carefully. : ";
									check = 0;
									break;
								}
							}
						} while (check == 1);

						for (int i = del; i < counter; i++)  name[i] = name[i + 1];
						for (int i = del; i < counter; i++)  roll[i] = roll[i + 1];
						for (int i = del; i < counter; i++)  marks_computer[i] = marks_computer[i + 1];
						for (int i = del; i < counter; i++)  marks_maths[i] = marks_maths[i + 1];
						for (int i = del; i < counter; i++)	 total_percent[i] = total_percent[i + 1];
						for (int i = del; i < counter; i++)	 grade[i] = grade[i + 1];




						counter--;
						system("cls");
						cout << " Done ! \n";

						break;
					}
			default:

				break;

			}
		}
		else choice2 = 8;
		
	} while (choice2 != 8);
	cout << " That's all for today \n Allah hafiz \n";

	system("PAUSE");
	return 0;
 }