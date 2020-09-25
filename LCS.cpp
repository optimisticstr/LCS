//here the code begins
#include<iostream>
#include<string.h>
using namespace std;

char b[50][50]; //Global 2D char arr

//Protos
int LCSLength(char *s1, char *s2);
void printLCS(char s[], int i, int j);

int main()
{
	char s1[50], s2[50];
	cout<<"Enter 1st string: ";
	cin >> s1;
	cout<<"Enter 2nd string: ";
	cin >> s2;
	int len = LCSLength(s1, s2);
    int m = strlen(s1);
	int n = strlen(s2);
	cout << "The LCS is ";
    printLCS(s1, m, n);
    cout<<" of length "<< len <<endl;
    return 0;
}
//Function definitions (printLCS)-------------------
void printLCS(char s[], int i, int j)
{
	if(i==0 || j==0)
	{
		return;
	}
	if(b[i][j] == 'd')
	{
		printLCS(s, i-1, j-1);
		cout << s[i-1]; //printing LCS characters
	}
	else if(b[i][j] == 'u')
	{
		printLCS(s, i-1, j);
	}
	else
	{
		printLCS(s, i, j-1);
	}
}

