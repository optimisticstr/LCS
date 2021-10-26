#include<iostream>
#include<string.h>
using namespace std;

char b[50][50];

//Proto
int LCSLength(char *s1, char *s2);
void printLCS(char s[], int i, int j);

int main()
{
	char s1[50], s2[50];
	cout<<"Enter 1st string: ";
	cin >> s1;
	cout<<"Enter 2nd string: ";
	cin >> s2;
	int len = LCSLength(s1, s2); //LCS length function call
    int m = strlen(s1);
	int n = strlen(s2); //strlen from string.h library
	cout << "The LCS is ";
    printLCS(s1, m, n); //print LCS function call
    cout<<" of length "<< len <<endl;
    return 0;
}

//Function definitions (LCS length)-------------------
int LCSLength(char *s1, char *s2){
    int m = strlen(s1);
	int n = strlen(s2);
	int c[m+1][n+1];
	for(int i=0; i <= m; i++)
	{
		c[i][0]=0;
	}
	for(int j = 0; j <= n; j++)
	{
		c[0][j] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				c[i][j] = 1+c[i-1][j-1];
				b[i][j] = 'd';
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 'l';
			}
		}
	}
	return c[m][n];
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

