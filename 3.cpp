#include<iostream>
#include <algorithm> 
#include<stdlib.h>
#include<string>
using namespace std;

const int BUFFER = 5000;
const int TEMPNUM = 1000;
int* BigNumSubtract(int a[], int b[], int aLength);
int* Aligning(int b[], const int aLength,const int bLength);
int main()
{	
	char CData[BUFFER]{ '\0' };
	char temp[TEMPNUM]{ '\0' };
	int  num[2][TEMPNUM]{ 0 };
	int  Length[2]{ 0,0 };
	while (cin.getline(CData, BUFFER))
	{

		int k = 0; int l = 0;
		for (int i = 0; i < BUFFER; i++)
		{
			if (CData[i] == '\0')//跳开始的空值。
				break;
			for (int j = 0; j < TEMPNUM; j++)
			{//temp作为一个分割输入的缓冲，每次都应当清除上一次内容。
				temp[j] = CData[i++];
				if (CData[i] == '-'||CData[i]=='\0')
				{//得加检测后面的空值。
					Length[l++] = j+1;//j为temp的索引，temp长度应当加1
					break;
				}
			}
			for (int i = 0; i < Length[k]; i++)//这里的Legnth限制了temp的长度，所以b的值没有错。
			{
				num[k][i] = (temp[i] + 2) % 10;
			}
			k++;
		}
		int* a = new int[Length[0]]{ 0 };
		for (int i = 0; i < Length[0]; i++)
		{
			a[i] = num[0][i];
		}
		int* b= Aligning(num[1], Length[0], Length[1]);//new alloaction 
		int* dif=BigNumSubtract(a, b, Length[0]);
		bool flag = true;
		for (int i = 0; i < Length[0]; i++)
		{

			if (dif[0] == 0&&flag)
			{
				flag = false;
				do
				{
					i++;
				} while (dif[i]==0);
			}
			cout << dif[i];
		}
		cout << endl;
	}
	return 0;
}

int* BigNumSubtract(int a[], int b[], int aLength)
{
	for (int i = 0; i < aLength; i++)
	{
		if(a[i]>=b[i])
		a[i] = a[i] - b[i];
		else
		{
			int j = i;
			do
			{
				j--;//低位为高
			} while (a[j]==0);//找到非零高位
			a[j] -= 1;	//借位
			for (j=j+1; j<i; j++)//i与j间的零高位补9
			{
				a[j] = 9;
			}
			a[i] += 10;
			a[i]= a[i] - b[i];
		}
	}
	return a;
}

int* Aligning(int b[], const int aLength,const int bLength)
{
	int* bigB = new int[aLength] {0};
	int j = 0;
	for (int i = aLength - bLength; i < aLength; i++)
	{
		bigB[i] = b[j++];
	}
	return bigB;
}
