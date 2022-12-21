                      /*          ABDUL NAFFEY's MATRIX MANIPULATOR
                                  REG No.             L1F21BSCS0516
                                  Sec.                         b-15       */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;
int* fillmenu( int*);
int* startmenu(int*);
int* advancemenu(int*);
void write(int**, int* , int* , string* );
int* writingchoice(int* );
void display(int**, int*, int*);
void after_change_display(int**, int*, int*);
void subtraction(int** , int* , int* , int**);
void add(int** , int* , int*, int** );
void row_column_swap(int*, int*);
int** transpose(int**, int*, int* );
void swap_with_next_in_column(int**, int, int, int);
void column_sorting(int**, int*, int* );
void swap_with_next_in_row(int**, int , int,int);
void row_sorting(int**, int* , int* );
void totalsum(int**, int*, int*,int*);
void totalproduct(int**, int*, int*, int*);
void row_ave(int** , int* , int* );
void col_ave(int**, int*, int*);
void ave(int**, int*, int*);
void readfile(int**, int*, int*, string*);
int main()
{
	
	int *ch;
	ch = new int;
	bool filecheck = 0;
	string* file_name;
	file_name = new string;
	//First of all we will display menu to get the choice wether user want to input by himself or to read from file.
	ch = startmenu(ch);
	switch (*ch)
	{
		case 1:
		{
			//IF user select to read from file
			
			
			
			//Asking user to provide name to read data from
			cout << "Enter File name with extension. :";
			cin >> *file_name;
			ifstream read;
			while (filecheck == 0)
			{
			
				read.open(*file_name);
				if (!read)
				{
					cout << "FILE NOT FOUND !\n";
					cout << "ENTER AGAIN !\n ";
					cout << "Enter File name with extension. :";
					cin >> *file_name;
				}
				else
				{
					int** arr;
					int* row;
					row = new int;
					*row = 0;
					int* col;
					col = new int;
					*col = 0;
					filecheck = 1;
					char help[30] = { '\0' };


					char* num_get;

					bool hehe = 0;
					//Reading size from the given file to generate  new 2D array of exact size 
					while (!read.eof())
					{
						//Attaing the size of Matrix in file
						read.getline(help, 30);

						*row = *row + 1;

						if (hehe == 0)
						{
							num_get = strtok(help, " ");
							while (num_get)
							{
								*col = *col + 1;
								num_get = strtok(NULL, " ");
							}hehe = 1;
						}

					}
					memset(&help[0], '\0', sizeof(help));
					read.close();
					//Asigning the size to a 2D array
					arr = new int* [*row];
					for (int i = 0; i < *row; i++)
					{
						*(arr + i) = new int[*col];
					}
					//Calling function to read the data from file and fill the 2D array
					readfile(arr, row, col, file_name);
					hehe = 0;
					while (hehe == 0)
					{
						//Displaying the data
						display(arr, row, col);
						//Displaying the Main Mein for operations and implementing operations
						ch = advancemenu(ch);
						switch (*ch)
						{
						case 1:
						{
							int* sum;
							sum = new int;
							*sum = 0;
							string* ok;
							ok = new string;
							totalsum(arr, row, col, sum);
							display(arr, row, col);
							cout << "   The SUM of Whole Matrix is : " << *sum << endl;
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete sum;
							sum = NULL;
							delete ok;
							ok = NULL;
							break;
						}
						case 2:
						{
							int* product;
							product = new int;
							*product = 1;
							string* ok;
							ok = new string;
							totalproduct(arr, row, col, product);
							display(arr, row, col);
							cout << "   The PRODUCT of Whole Matrix is : " << *product << endl;
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete product;
							product = NULL;
							delete ok;
							ok = NULL;
							break;
						}
						case 3:
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout << "   The AVERAGE of rows of Whole Matrix are : " << endl;
							row_ave(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;
						}
						case 4:
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout << "   The AVERAGE of Column of Whole Matrix are : " << endl;
							col_ave(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;
						}
						case 5:
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout << "   The AVERAGE of Whole Matrix is : ";
							ave(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;
						}
						case 6:
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout << "\t\t\t     After ROW-WISE sorting of Matrix  \n";
							row_sorting(arr, row, col);
							after_change_display(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;

						}
						case 7: 
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout << "\t\t\t     After COLUMN-WISE sorting of Matrix  \n";
							column_sorting(arr, row, col);
							after_change_display(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;
						}
						case 8:
						{
							string* ok;
							ok = new string;
							int** two;
							two = new int* [*row];
							for (int i = 0; i < *row; i++)
							{
								*(two + i) = new int[*col];
							}
							display(arr, row, col);
							cout << "To continue further you want ONE other MATRIX as well of SAME SIZE \n";
							ch = fillmenu(ch);
							switch (*ch)
							{
							case 1:
							{
								for (int i = 0; i < *row; i++)
								{
									for (int j = 0; j < *col; j++)
									{
										*(*(two + i) + j) = rand() % 100;
									}
								}
								break;
							}
							case 2:
							{
								cout << "Enter the values : \n";
								for (int i = 0; i < *row; i++)
								{
									for (int j = 0; j < *col; j++)
									{
										cout << "Row " << i + 1 << " Column " << j + 1 << " ";
										cin >> *(*(two + i) + j);
									}
								}

								break;
							}

							}
							system("CLS");
							cout << "\t\tFIRST : \n";
							after_change_display(arr, row, col);
							cout << "\t\tSECOND : \n";
							after_change_display(two, row, col);
							cout << "  Press Enter to See their SUM MATRIX : ";
							cin.ignore();
							getline(cin, *ok);
							system("CLS");
							cout << "\t\tFIRST : \n";
							after_change_display(arr, row, col);
							cout << "\t\tSECOND : \n";
							after_change_display(two, row, col);
							add(arr, row, col, two);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							for (int i = 0; i < *row; i++)
							{
								delete[]  two[i];
							}
							delete[] two;
							delete ok;
							ok = NULL;
							break;
						}
						case 9:
						{
							string* ok;
							ok = new string;
							int** two;
							two = new int* [*row];
							for (int i = 0; i < *row; i++)
							{
								*(two + i) = new int[*col];
							}
							display(arr, row, col);
							cout << "To continue further you want ONE other MATRIX as well of SAME SIZE \n";
							ch = fillmenu(ch);
							switch (*ch)
							{
							case 1:
							{
								for (int i = 0; i < *row; i++)
								{
									for (int j = 0; j < *col; j++)
									{
										*(*(two + i) + j) = rand() % 100;
									}
								}
								break;
							}
							case 2:
							{
								cout << "Enter the values : \n";
								for (int i = 0; i < *row; i++)
								{
									for (int j = 0; j < *col; j++)
									{
										cout << "Row " << i + 1 << " Column " << j + 1 << " ";
										cin >> *(*(two + i) + j);
									}
								}

								break;
							}

							}
							system("CLS");
							cout << "\t\tFIRST : \n";
							after_change_display(arr, row, col);
							cout << "\t\tSECOND : \n";
							after_change_display(two, row, col);
							cout << "  Press Enter to See their SUBTRACTION MATRIX : ";
							cin.ignore();
							getline(cin, *ok);
							system("CLS");
							cout << "\t\tFIRST : \n";
							after_change_display(arr, row, col);
							cout << "\t\tSECOND : \n";
							after_change_display(two, row, col);
							subtraction(arr, row, col, two);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							for (int i = 0; i < *row; i++)
							{
								delete[]  two[i];
							}
							delete[] two;
							delete ok;
							ok = NULL;
							break;
						}
						case 10:
						{
							string* ok;
							ok = new string;
							display(arr, row, col);
							cout <<setw(26*2) << " After TRANSPOSE of Matrix \n";
							arr = transpose(arr, row, col);
							after_change_display(arr, row, col);
							cout << "   Press Enter to continue : ";
							cin.ignore();
							getline(cin, *ok);
							delete ok;
							ok = NULL;
							break;
						}
						case 0:
						{
							hehe = 1;
							
							break;
						}
						}
					}
					int* batao;
					batao = new int;
					//Displaying the data
					display(arr, row, col);
					//Asking to Store data in file
					cout << "-> Enter 1. If you want to WRITE DATA in the file.\n";
					cout << "-> Enter 0. If you want to Simply End the Program.\n";
					cout << "   Enter your choice : ";
					cin >> *batao;
					while (*batao < 0 || *batao > 1)
					{
						cout << "   Wrong Input ! \n";
						cout << "   Enter Again : ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> *ch;
					}
					if (*batao == 1)
					{
						display(arr, row, col);
						ch = writingchoice(ch);
						switch (*ch)
						{
							case 1:
							{
								write(arr, row, col, file_name);
								break;
							}
							case 2:
							{
								cout << "Enter File name in which you want to save your data : ";
								cin >> *file_name;
								write(arr, row, col, file_name);
								break;
							}
							
						}
						cout << "Updated Data is been stored in file \n";
					}cout << "AllAH HAFIZ !\n";
					for (int i = 0; i < *row; i++)
					{
						delete[]  arr[i];
					}
					delete[] arr;

					delete row;
					row = NULL;

					

					delete col;
					col = NULL;

					delete batao;
					batao = NULL;
				}
			}
			

			
			delete file_name;
			file_name = NULL;
			
			break;
		}
		case 2:
		{            //IF user select to enter manually
			
			bool hehe = 0;
			int** arr;
			
			int *row;
			row = new int;
			int* col;                   //Asking for matrix size
			col = new int;
			cout << "Enter the size for rows : "; cin >> *row;
			while (*row < 1)
			{
				
					cout << "   Wrong Input ! \n";
					cout << "   Enter Again : ";
					cin >> *row;
				
			}
			arr = new int* [*row];
			cout << "Enter the size for coloumns : "; cin >> *col;
			while (*col < 1)
			{

				cout << "   Wrong Input ! \n";
				cout << "   Enter Again : ";
				cin >> *col;

			}
			for (int i = 0; i < *row; i++)
			{
				*(arr + i) = new int[*col];
			}
			ch = fillmenu(ch);
			switch (*ch)
			{
				case 1:
				{
					for  (int i = 0; i < *row; i++)
					{
						for (int j = 0; j <*col ; j++)
						{
							*(*(arr + i) + j) = rand() % 100;
						}
					}
					break;
				}
				case 2:
				{
					cout << "Enter the values : \n";
					for (int i = 0; i < *row; i++)
					{
						for (int j = 0; j < *col; j++)
						{
							cout << "Row " << i + 1<< " Column " << j + 1<<" ";
							cin >> *(*(arr + i) + j) ;
						}
					}

					break;
				}
					
			}
			hehe = 0;
			while (hehe == 0)
			{
				//calling menu and implementing functions
				display(arr, row, col);
				ch = advancemenu(ch);
				switch (*ch)
				{
				case 1:
				{
					int* sum;
					sum = new int;
					*sum = 0;
					string* ok;
					ok = new string;
					totalsum(arr, row, col, sum);
					display(arr, row, col);
					cout << "   The SUM of Whole Matrix is : " << *sum << endl;
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete sum;
					sum = NULL;
					delete ok;
					ok = NULL;
					break;
				}
				case 2:
				{
					int* product;
					product = new int;
					*product = 1;
					string* ok;
					ok = new string;
					totalproduct(arr, row, col, product);
					display(arr, row, col);
					cout << "   The PRODUCT of Whole Matrix is : " << *product << endl;
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete product;
					product = NULL;
					delete ok;
					ok = NULL;
					break;
				}
				case 3:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "   The AVERAGE of rows of Whole Matrix are : " << endl;
					row_ave(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;
				}
				case 4:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "   The AVERAGE of Column of Whole Matrix are : " << endl;
					col_ave(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;
				}
				case 5:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "   The AVERAGE of Whole Matrix is : ";
					ave(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;
				}
				case 6:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "\t\t\t     After ROW-WISE sorting of Matrix  \n";
					row_sorting(arr, row, col);
					after_change_display(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;

				}
				case 7:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "\t\t\t     After COLUMN-WISE sorting of Matrix  \n";
					column_sorting(arr, row, col);
					after_change_display(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;
				}
				case 8:
				{
					string* ok;
					ok = new string;
					string* okg;
					okg = new string;
					int** two;
					two = new int* [*row];
					for (int i = 0; i < *row; i++)
					{
						*(two + i) = new int[*col];
					}
					display(arr, row, col);
					cout << "To continue further you want ONE other MATRIX as well of SAME SIZE \n";
					ch = fillmenu(ch);
					switch (*ch)
					{
					case 1:
					{
						for (int i = 0; i < *row; i++)
						{
							for (int j = 0; j < *col; j++)
							{
								*(*(two + i) + j) = rand() % 100;
							}
						}
						break;
					}
					case 2:
					{
						cout << "Enter the values : \n";
						for (int i = 0; i < *row; i++)
						{
							for (int j = 0; j < *col; j++)
							{
								cout << "Row " << i + 1 << " Column " << j + 1 << " ";
								cin >> *(*(two + i) + j);
							}
						}

						break;
					}

					}
					system("CLS");
					cout << "\t\tFIRST : \n";
					after_change_display(arr, row, col);
					cout << "\t\tSECOND : \n";
					after_change_display(two, row, col);
					cout << "  Press Enter to See their SUM MATRIX : ";
					cin.ignore();
					getline(cin, *ok);
					system("CLS");
					cout << "\t\tFIRST : \n";
					after_change_display(arr, row, col);
					cout << "\t\tSECOND : \n";
					after_change_display(two, row, col);
					add(arr, row, col, two);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *okg);
					for (int i = 0; i < *row; i++)
					{
						delete[]  two[i];
					}
					delete[] two;
					delete ok;
					ok = NULL;
					delete okg;
					okg = NULL;
					break;
				}
				case 9:
				{
					string* ok;
					ok = new string;
					string* okg;
					okg = new string;
					int** two;
					two = new int* [*row];
					for (int i = 0; i < *row; i++)
					{
						*(two + i) = new int[*col];
					}
					display(arr, row, col);
					cout << "To continue further you want ONE other MATRIX as well of SAME SIZE \n";
					ch = fillmenu(ch);
					switch (*ch)
					{
					case 1:
					{
						for (int i = 0; i < *row; i++)
						{
							for (int j = 0; j < *col; j++)
							{
								*(*(two + i) + j) = rand() % 100;
							}
						}
						break;
					}
					case 2:
					{
						cout << "Enter the values : \n";
						for (int i = 0; i < *row; i++)
						{
							for (int j = 0; j < *col; j++)
							{
								cout << "Row " << i + 1 << " Column " << j + 1 << " ";
								cin >> *(*(two + i) + j);
							}
						}

						break;
					}

					}
					system("CLS");
					cout << "\t\tFIRST : \n";
					after_change_display(arr, row, col);
					cout << "\t\tSECOND : \n";
					after_change_display(two, row, col);
					cout << "  Press Enter to See their SUBTRACTION MATRIX : ";
					cin.ignore();
					getline(cin, *ok);
					system("CLS");
					cout << "\t\tFIRST : \n";
					after_change_display(arr, row, col);
					cout << "\t\tSECOND : \n";
					after_change_display(two, row, col);
					subtraction(arr, row, col, two);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *okg);
					for (int i = 0; i < *row; i++)
					{
						delete[]  two[i];
					}
					delete[] two;
					delete ok;
					ok = NULL;
					delete okg;
					okg = NULL;
					break;
				}
				case 10:
				{
					string* ok;
					ok = new string;
					display(arr, row, col);
					cout << "\t\t\t\t After TRANSPOSE of Matrix \n";
					arr = transpose(arr, row, col);
					after_change_display(arr, row, col);
					cout << "   Press Enter to continue : ";
					cin.ignore();
					getline(cin, *ok);
					delete ok;
					ok = NULL;
					break;
				}
				case 0:
				{
					hehe = 1;
					
					break;
				}
				}
			}
			display(arr, row, col);
			int* batao ;
			batao = new int;            //Storing data in file
			cout << "-> Enter 1. If you want to WRITE DATA in the file.\n";
			cout << "-> Enter 0. If you want to Simply End the Program.\n";
			cout << "   Enter your choice : ";
			cin >> *batao;
			while (*batao < 0 || *batao > 1)
			{
				cout << "   Wrong Input ! \n";
				cout << "   Enter Again : ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> *ch;
			}
			if (*batao == 1)
			{
				cout << "Enter File name in which you want to save your data : ";
				cin >> *file_name;
				write(arr, row, col, file_name);
				cout << "Updated Data is been stored in file \n";
			}
			cout << "AllAH HAFIZ !\n";
			for (int i = 0; i < *row; i++)
			{
				delete[]  arr[i];
			}
			delete[] arr;

			delete row;
			row = NULL;

			delete col;
			col = NULL;

			delete batao;
			batao = NULL;
			break;
		}
	}
	

	
	delete ch;
	ch = NULL;
	delete file_name;
	file_name = NULL;
	
	
	system("PAUSE");
	return 0;
}
void subtraction(int** old, int* row, int* col, int** navi)
{
	cout << endl; cout << "\t\tNEW : \n";
	cout << setw(59) << "AFTER SUBTRACTION OF BOTH MATRICES " << endl;
	cout << setw(25) << "\"" << *row << " X " << *col << "\" MATRIX " << endl;
	cout << setw(26);
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < *row; i++)
	{
		cout << setw(25);
		for (int j = 0; j < *col; j++)
		{
			cout << "|" << *(*(old + i) + j) - *(*(navi + i) + j) << "\t";
		}
		cout << "|" << endl;
	}
	cout << setw(26);
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << setw(56) << "THE ORIGINAL MATRIX IS UPDATED AFTER SUBTRACTION OF BOTH MATRICES " << endl;
}
void add(int** old, int* row, int* col,int** navi)
{
	cout << endl; cout << "\t\tNEW : \n";
	cout << setw(56) << "AFTER ADDITION OF BOTH MATRICES " << endl;
	cout << setw(25) << "\"" << *row << " X " << *col << "\" MATRIX " << endl;
	cout << setw(26);
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < *row; i++)
	{
		cout << setw(25);
		for (int j = 0; j < *col; j++)
		{
			*(*(old + i) + j) = *(*(old + i) + j) + *(*(navi + i) + j);
			cout << "|" << *(*(old + i) + j)  << "\t";
		}
		cout << "|" << endl;
	}
	cout << setw(26);
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << setw(56) << "THE ORIGINAL MATRIX IS UPDATED AFTER ADDITION OF BOTH MATRICES " << endl;
}
int** transpose(int** old, int* row, int* col)
{
	int** navi;
	navi = new int* [*col];
	for (int i = 0; i < *col; i++)
	{
		*(navi + i) = new int[*row];
	}
	for (int i = 0,x=0; x < *col; i++,x++)
	{
		for (int j = 0,y=0; j < *row;y++ ,j++)
		{
			*(*(navi + x) + y)=*(*(old + j) +i);
		
		}
		
	}

	for (int i = 0; i < *row; i++)
	{
		delete[]  old[i];
	}
	delete[] old;
	row_column_swap(row, col);
	return navi;
}
void row_column_swap(int* row, int* col)
{
	int* temp;
	temp = new int;
	*temp = *row;
	*row = *col;
	*col = *temp;
	delete temp;
	temp = NULL;
}
void column_sorting(int** old, int* row, int* col)
{
	for (int i = 0; i < *col; i++)
	{
		for (int j = 0; j < *row - 1; j++)
		{
			for (int k = j + 1; k < *row; k++)
			{
				if (*(*(old + j) + i) > *(*(old + k) + i))
				{
					swap_with_next_in_column(old, i, j, k);
				}
			}
		}
	}
}
void swap_with_next_in_column(int** old, int i, int j, int k)
{
	int* temp;
	temp = new int;
	*temp = *(*(old + j) + i);
	*(*(old + j) + i) = *(*(old + k) + i);
	*(*(old + k) + i) = *temp;
	delete temp;
	temp = NULL;

}
void row_sorting(int** old, int* row, int* col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col-1; j++)
		{
			for (int k = j+1; k < *col ; k++)
			{
				if (*(*(old + i) + j) > *(*(old + i) + k ))
				{
					swap_with_next_in_row(old, i,j, k);
				}
			}
		}
	}
}
void swap_with_next_in_row(int** old, int i,int j,int k)
{
	int *temp;
	temp = new int;
	*temp = *(*(old + i) + j);
	*(*(old + i) + j) = *(*(old + i) + k);
	*(*(old + i) + k) = *temp;
	delete temp;
	temp = NULL;

}
void ave(int** old, int* row, int* col)
{
	float* ave;
	ave = new float;
	*ave = 0;
	float* sum;
	sum = new float;
	*sum = 0;
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*sum = *sum + *(*(old + i) + j);
			*ave = *ave + 1;
		}
	}
	cout << *sum / *ave << endl;
	delete sum;
	sum = NULL;
	delete ave;
	ave = NULL;
}
void col_ave(int** old, int* row, int* col)
{
	float* ave;
	ave = new float;
	*ave = 0;
	float* sum;
	sum = new float;
	*sum = 0;
	for (int i = 0; i < *col; i++)
	{
		for (int j = 0; j < *row; j++)
		{
			*sum = *sum + *(*(old + j) + i);
			*ave = *ave + 1;
		}
		cout << "-> The AVERAGE for COLUMN " << i + 1 << " is " << *sum / *ave << endl;
		*sum = 0;
		*ave = 0;
	}
	delete sum;
	sum = NULL;
	delete ave;
	ave = NULL;
}
void row_ave(int** old, int* row, int* col)
{
	float* ave;
	ave = new float;
	*ave = 0;
	float* sum;
	sum = new float;
	*sum = 0;
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*sum = *sum + *(*(old + i) + j);
			*ave = *ave + 1;
		}
		cout << "-> The AVERAGE for Row " << i + 1 << " is " << *sum / *ave << endl;
		*sum = 0;
		*ave = 0;
	}
	delete sum;
	sum = NULL;
	delete ave;
	ave = NULL;
}
int* advancemenu(int *ch)
{
cout << "-> Enter 1.  To get the SUM of all values MATRIX.\n";
cout << "-> Enter 2.  To get the PRODUCT of all values MATRIX.\n";
cout << "-> Enter 3.  To get the ROW-WISE AVERAGE of all values MATRIX.\n";
cout << "-> Enter 4.  To get the COLUMN-WISE AVERAGE of all values MATRIX.\n";
cout << "-> Enter 5.  To get the AVERAGE of all values MATRIX.\n";
cout << "-> Enter 6.  To SORT all values matrix ROW-WISE.\n";
cout << "-> Enter 7.  To SORT all values matrix COLUMN-WISE.\n";
cout << "-> Enter 8.  To do ADDITION of two MATRICIES.\n";
cout << "-> Enter 9.  To do SUBTRACTION of two MATRICIES.\n";
cout << "-> Enter 10. To get TRANSPOSE of the MATRIX.\n";
cout << "-> Enter 0.  To EXIT THE PROGRAM.\n";
cout << "   Enter your choice : ";

cin >> *ch;
while (*ch < 0 || *ch > 10)
{
	cout << "Wrong Input ! \n";
	cout << "Enter Again : ";
	cin >> *ch;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
return ch;}
void readfile(int** arr, int* row, int* col,string* file_name)
{
	ifstream read;
	char* num_get;
	char help[30] = { '\0' };
	read.open(*file_name);
	for (int i = 0; i < *row; i++)
	{
		read.getline(help, 30);

		int j = 0;
		num_get = strtok(help, " ");
		while (num_get)
		{
			*(*(arr + i) + j++) = atoi(num_get);
			num_get = strtok(NULL, " ");
		}
		j = 0; memset(&help[0], '\0', sizeof(help));
	}
	read.close();
	
}
void totalsum(int** old, int* row, int* col, int* sum)
{

	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col ; j++)
		{
			*sum = *sum + *(*(old + i) + j);
		}

	}
}
void display(int**old, int*row, int*col)
{
	system("cls");
	
	
	
	cout << setw(25) << "\"" << *row << " X " << *col << "\" MATRIX : " << endl;
	
	cout << setw(26);
	
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "_";
	}cout << endl; cout << setw(25); cout << "|"; cout << setw(*col*8); cout << " |";
	
	cout << endl;
	for (int i = 0; i < *row; i++)
	{
		cout << setw(25); cout << "|";
		for (int j = 0; j < *col ; j++)
		{
			cout<< " " << *(*(old + i) + j) << "\t";
		}
		cout << "|" << endl;
	}
	
	//cout << setw(25); cout << "|"; cout << setw(40); cout << "|"; cout << endl;
	cout << setw(25); cout << "|";
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "_";
	}cout << "|";
	cout << endl;
	
}
void after_change_display(int** old, int* row, int* col)
{

	cout << setw(25) << "\"" << *row << " X " << *col << "\" MATRIX : " << endl;

	cout << setw(26);

	for (int i = 1; i < *col * 8; i++)
	{
		cout << "_";
	}cout << endl; cout << setw(25); cout << "|"; cout << setw(*col * 8); cout << " |";

	cout << endl;
	for (int i = 0; i < *row; i++)
	{
		cout << setw(25); cout << "|";
		for (int j = 0; j < *col; j++)
		{
			cout << " " << *(*(old + i) + j) << "\t";
		}
		cout << "|" << endl;
	}

	//cout << setw(25); cout << "|"; cout << setw(40); cout << "|"; cout << endl;
	cout << setw(25); cout << "|";
	for (int i = 1; i < *col * 8; i++)
	{
		cout << "_";
	}cout << "|";
	cout << endl;
}
int* fillmenu(int * ch)
{
	cout << "-> Enter 1. To FILL the MATRIX with RANDOM VALUES less than 100.\n";
	cout << "-> Enter 2. To FILL the MATRIX with CUSTOM VALUES.\n";
	cout << "   Enter your choice : ";

	cin >> *ch;
	while (*ch < 1 || *ch > 2)
	{
		cout << "   Wrong Input ! \n";
		cout << "   Enter Again : ";
		cin >> *ch;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return ch;
}
int* startmenu(int *ch)
{
	cout << "-> Enter 1. If you want to READ DATA from FILE.\n";
	cout << "-> Enter 2. To ENTER DATA MANUALLY.\n";
	cout << "   Enter your choice : ";
	cin >> *ch;
	while (*ch < 1 || *ch > 2)
	{	
		cout << "   Wrong Input ! \n";
		cout << "   Enter Again : ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> *ch;
	}
	return ch;
}
void totalproduct(int** old, int* row, int* col, int* product)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*product = *product * *(*(old + i) + j);
		}

	}
}
int* writingchoice(int* ch)
{
	
	cout << "-> Enter 1. If you want to WRITE DATA in the same file.\n";
	cout << "-> Enter 2. If you want to WRITE DATA in new file.\n";
	cout << "   Enter your choice : ";
	cin >> *ch;
	while (*ch < 1 || *ch > 2)
	{
		cout << "   Wrong Input ! \n";
		cout << "   Enter Again : ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> *ch;
	}
	return ch;
}
void write(int** old, int* row, int* col,string* file_name)
{
	ofstream write;
	write.open(*file_name);
	for (int i = 0; i < *row; i++)
	{
		if (i > 0)
		{
			write << endl;
		}
		for (int j = 0; j < *col; j++)
		{
			write << *(*(old + i) + j)<<" ";
		}
	}

}