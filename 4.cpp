#include<iostream>
#include <algorithm> 
#include<stdlib.h>
#include<string>
using namespace std;

const int BUFFER = 5000;
const int TEMPNUM = 20;
const int NUMLENGTH = 2000;
int main()
{
	char CData[BUFFER]{ '\0' };
	int  num[NUMLENGTH]{ 0 };
	int  Length[2]{ 0,0 };
	while (cin.getline(CData, BUFFER))
	{

		int k = 0; int l = 0;
		for (int i = 0; i < BUFFER; i++)
		{
			char* temp=new char[TEMPNUM]{ '\0' };

			if (CData[i] == '\0')//跳开始的空值。
				break;
			for (int j = 0; j < TEMPNUM; j++)
			{//temp作为一个分割输入的缓冲，每次都应当清除上一次内容。
				temp[j] = CData[i++];
				if (CData[i] == ',' || CData[i] == '\0')
				{//得加检测后面的空值。
					break;
				}
			}
			sscanf_s(temp, "%d", &num[k++]);//k虽然作为计算num的索引，但是最后总会等于num元素数量
			delete [] temp;
		}
		//排序
		sort(num, num + k);//此处k不用加1
		int maxLength = 1;
		for (int i = 0; i < k; i++)
		{
			int tempMaxLength = 1;
			//这个方法不行，跳过的范围内的后一部分数据很有可能是下一个连续的开始几个。
			//if (maxLength != 1)//加点速度。
			//{//首先检测是否越界。
			//	if (i + maxLength+1 >= k) break;//防止跳范围的时候越界
			//	if (num[i + maxLength] != num[i] + maxLength) //该范围内的差值不等于长度值
			//		i += maxLength + 1;//跳过这个范围 
			//}
			while (num[i] == num[i + 1] - 1)
			{
				tempMaxLength++;
				i++;
				if (i+1 >= k) break;//检测要放最后，防止进入下一次，而不是本次。
			}
			if (tempMaxLength > maxLength)
				maxLength = tempMaxLength;
		}
		cout << maxLength << endl;
	}
	return 0;
}