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

			if (CData[i] == '\0')//����ʼ�Ŀ�ֵ��
				break;
			for (int j = 0; j < TEMPNUM; j++)
			{//temp��Ϊһ���ָ�����Ļ��壬ÿ�ζ�Ӧ�������һ�����ݡ�
				temp[j] = CData[i++];
				if (CData[i] == ',' || CData[i] == '\0')
				{//�üӼ�����Ŀ�ֵ��
					break;
				}
			}
			sscanf_s(temp, "%d", &num[k++]);//k��Ȼ��Ϊ����num����������������ܻ����numԪ������
			delete [] temp;
		}
		//����
		sort(num, num + k);//�˴�k���ü�1
		int maxLength = 1;
		for (int i = 0; i < k; i++)
		{
			int tempMaxLength = 1;
			//����������У������ķ�Χ�ڵĺ�һ�������ݺ��п�������һ�������Ŀ�ʼ������
			//if (maxLength != 1)//�ӵ��ٶȡ�
			//{//���ȼ���Ƿ�Խ�硣
			//	if (i + maxLength+1 >= k) break;//��ֹ����Χ��ʱ��Խ��
			//	if (num[i + maxLength] != num[i] + maxLength) //�÷�Χ�ڵĲ�ֵ�����ڳ���ֵ
			//		i += maxLength + 1;//���������Χ 
			//}
			while (num[i] == num[i + 1] - 1)
			{
				tempMaxLength++;
				i++;
				if (i+1 >= k) break;//���Ҫ����󣬷�ֹ������һ�Σ������Ǳ��Ρ�
			}
			if (tempMaxLength > maxLength)
				maxLength = tempMaxLength;
		}
		cout << maxLength << endl;
	}
	return 0;
}