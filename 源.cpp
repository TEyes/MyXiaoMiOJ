#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm> 
using namespace std;

bool compare(int a, int b) { return a > b; }
int main()
{
	//0 1 0 1 2 3 2 5 9 3 9 25 24 25 24
	char CData[10000]{'\0'};
	char temp[10]{'\0'};
	int  num[200]{0};
	int  n=0;
	while (cin.getline(CData,10000))
	{
		
		int k = 0;
		for (int i = 0; i < 10000; i++)
		{
			if (CData[i] == '\0')
				break;
			for (int j = 0; j < 10; j++)
			{
				temp[j] = CData[i++];
				if (CData[i] == ' ')
					break;
			}
			num[k++] = stoi(temp, nullptr);
		}
		sort(num, num+50,compare);
		for (int i = 0; i < 50; i=i+2)
		{
			if (num[i] != num[i + 1])
			{
				n = num[i];
				break;
			}

		}
		cout << n<<endl;
	}
	return 0;
}