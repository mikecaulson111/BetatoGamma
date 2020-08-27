#include <iostream>
#include <iomanip>


using namespace std;

int columns;

int main()
{
	bool first = false; //change this to true if you eventually want to do vector change of basis, but that is a bit harder!
	int firstans;

	cout << "This is a program that will take in a beta matrix, and a gamma matrix, and give you the change of coordinates matrix." << endl;
	while(first)
	{
		cout << "Would you like to also input a vector and see what its representation is in gamma?" << endl;
		cout << "[1] Yes" << endl;
		cout << "[2] No" << endl;
		cin >> firstans;
		if(firstans > 2 || firstans < 1)
		{
			first = true;
		}
		else
		{
			first = false;
		}
	}
	cout << "This program only works for n x n matrices, how many rows(and thus cols) does your matrix have?" << endl;
	int rows, cols;
	cin >> rows;
	cols = rows;
	columns = cols * 2;
	double number1[rows][cols]; //This is Beta matrix
	double number[rows][columns]; //This is Gamma matrix
	cout << "Now for the numbers in your Beta(β) matrix:" << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << "For row " << i + 1 << " please enter the number in position " << j + 1 << endl;
			cin >> number1[i][j];
		}
	}
	cout << "And now for the Gamma(γ) matrix:" << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << "For row " << i + 1 << " please enter the number in position " << j + 1 << endl;
			cin >> number[i][j];
		}
		for(int j = cols;j<columns;j++)
				{
					int placer = j - cols;
					//cout << placer << endl;
					if(placer == i)
					{
						number[i][j] = 1;
					}
					else
					{
						number[i][j] = 0;
					}
				}
	}
	cout << "Here is your Beta matrix:" << endl;
	for(int i = 0; i < rows; i ++)
	{
		for(int j = 0;j<cols;j++)
		{
			if(j == cols - 1)
			{
				cout << "  " << number1[i][j] << endl;
			}
			else
			{
				cout << "  " << number1[i][j];
			}
		}
	}
	cout << "Your gamma matrix is: " << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(j == cols - 1)
			{
				cout << "  " << number[i][j] << endl;
			}
			else
			{
				cout << "  " << number[i][j];
			}
		}
	}
	if(firstans == 1)
	{
		double vector[rows];
	}
	//this is the matrix inversion of beta:
	int totnums[rows];
		for(int i = 0; i< rows; i++)
		{
			int counter1 = 0;
			for(int j = 0; j<cols; j++)
			{
				if(number[i][j] == 0)
				{
					counter1 = counter1 + 1;
				}
				else
				{
					break;
				}
			}
			totnums[i] = counter1;
		}
		int countere = 0;
		int counter2;
		bool truth = true;
		while(truth == true)
		{
			counter2 = 0;
			for(int i = 0; i<rows-1; i++)
			{
				if(totnums[i] > totnums[i+1])
				{
					counter2 = counter2 + 1;
					double temp1[cols];
					double temp2[cols];
					int temp3, temp4;
					for(int j = 0; j<cols;j++)
					{
						temp1[j] = number[i][j];
						temp2[j] = number[i+1][j];
						temp3 = totnums[i];
						temp4 = totnums[i+1];
					}
					for(int t = 0; t<cols;t++)
					{
						number[i][t] = temp2[t];
						number[i+1][t] = temp1[t];
						totnums[i] = temp4;
						totnums[i+1] = temp3;
					}

				}
			}
			if(counter2 > 0)
			{
				truth = true;
			}
			else
			{
				truth = false;
			}
			countere = countere+1;
		}
			int place;
				for(int i = 0; i<rows;i++)
				{
					for(int j = 0; j< cols; j++)
					{
						if(number[i][j] != 0)
						{
							place = j;
							break;
						}
					}
					int size = rows - 1;
					size = size - i;
					double tempop1[size][columns];
					double tempop2[columns];
					double tempop3[columns];
					for(int t = 0;t<size;t++)
					{
						for(int r = 0;r<columns;r++)
						{
							tempop1[t][r] = number[t+i+1][r];
						}
					}
					for(int t=0;t<columns;t++)
					{
						tempop2[t] = number[i][t];
					}
					double mult1,mult2,mult3;
					mult1 = tempop2[place];
					for(int y=0;y<size;y++)
					{
						mult2 = tempop1[y][place]; //This should be mult1(x) + mult2 = 0
						mult3 = -1 * mult2;
						mult3 = mult3 / mult1;
						for(int g = 0; g<columns;g++) // this might need to be from g=place, if this is the case you need to change parts above
						{
							tempop3[g] = tempop2[g] * mult3;
						}
						for(int v = 0; v<columns;v++)
						{
							tempop1[y][v] = tempop1[y][v] + tempop3[v];
						}
					}
					for(int g=0;g<size;g++)
					{
						for(int b=0;b<columns;b++)
						{
							number[g+i+1][b] = tempop1[g][b];
						}
					}
				}
			int place2;
			for(int i = 0; i < rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					if(number[i][j] != 0)
					{
						place2 = j;
						break;
					}
				}
				double temporar[columns];
				for(int h = 0; h < columns; h++)
				{
					temporar[h] = number[i][h];
				}
				double divisor = temporar[place2];
				if(divisor == 0)
				{
					break;
				}
				for(int u = 0; u < columns; u++)
				{
					double tnum = temporar[u];
					tnum = tnum / divisor;
					temporar[u] = tnum;
				}
				for(int t = 0; t<columns;t++)
				{
					number[i][t] = temporar[t];
				}
			}
			for(int i = 0; i <rows; i++)
					{
						for(int j = 0; j < columns; j++)
						{
							if(number[i][j] <0.00000000000000000000005 && number[i][j] > -0.00000000000000000000005)
							{
								number[i][j] = 0;
							}
						}
					}
			int place3;
				for(int i = rows-1;i>0;i--)
				{
					int counterer=0;
						for(int j = 0; j<cols;j++)
						{
							if(number[i][j] != 0)
							{
								place3 = j;
								break;
							}
							else
							{
								counterer = counterer + 1;
							}
						}
						if(counterer != cols)
						{
					double temparr1[i][columns];
					double temparr2[columns];
					for(int t=0; t<i;t++)
					{
						for(int h = 0; h < columns; h++)
						{
							temparr1[t][h] = number[t][h];
						}
					}
					for(int r = 0; r<columns;r++)
					{
						temparr2[r] = number[i][r];
					}
					for(int e=0;e<i;e++)
					{
						double temparr3[columns];
						double num1,num2,num3;
						num1 = temparr2[place3];
						num2 = temparr1[e][place3];
						num3 = -num2/num1;
						for(int r = 0; r<columns;r++)
						{
							temparr3[r] = num3 * temparr2[r];
						}
						for(int w = 0; w<columns; w++)
						{
							temparr1[e][w] = temparr1[e][w] + temparr3[w];
						}

					}
					for(int t=0;t<i;t++)
					{
						for(int a =0; a<columns;a++)
						{
							number[t][a]= temparr1[t][a];
						}
					}
						}
				}
				//That is the end of matrix inversion;
	//Now is the multiplication:
				double narr[rows][cols];
				for(int i = 0; i < rows; i++)
				{
					for(int j = 0; j < cols; j++)
					{
						narr[i][j] = number[i][j+cols];
					}
				}
//				for(int i = 0; i < rows; i++)
//					{
//						for(int j = 0; j<cols;j++)
//						{
//							if(j == cols-1)
//							{
//								cout << "  " << narr[i][j] << endl;
//							}
//							else
//							{
//								cout << "  " << narr[i][j] << "  ";
//							}
//						}
//					}
				//int counter22 = 0;
				//HERE

				double finalarr[rows][cols];//This is the final array that is the first array's rows and the second array's cols.
					for(int i = 0; i < rows; i++)
					{
						for(int j=0;j<cols;j++)
						{
							double temparr[cols];
							double total = 0;
							double temp = 0;
							for(int z=0;z<cols;z++)
							{
								temparr[z] = number1[z][j];
							}
							for(int t=0;t<cols;t++)
							{
								temp = 0;
								temp = temparr[t] * narr[i][t]; // This part does all of the matrix math!
								total = total + temp;
								//cout << total << endl;
							}
							finalarr[i][j] = total;
						}
					}


					cout << "Now here is your change of basis matrix(from beta to gamma): " << endl;
					for(int i = 0; i < rows; i++)
						{
							for(int j = 0; j<cols;j++)
							{
								if(j == cols-1)
								{
									cout << "  " << finalarr[i][j] << endl;
								}
								else
								{
									cout << "  " << finalarr[i][j] << "  ";
								}
							}
						}

					//This program works and is finished for the most part
}
