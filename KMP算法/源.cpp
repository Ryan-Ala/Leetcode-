#include<iostream>
#define MAX_LEN 100
using namespace std;


void Get_next_bit(const char* sub, int* next)
{
	int lensub = strlen(sub);
	next[0] = -1;
	next[1] = 0;
	int i = 2;  //��ǰ i ���±�
	int k = 0;  //ǰһ��� k
	while (i < lensub)
	{
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

void Get_Next(const char* t, int* next)
{
	//��ʼ��ǰһ�ַ�����ͬ�����±�0��ʼ��Ϊ -1 ���±� 1��ʼ��Ϊ 0
	next[0] = -1;
	next[1] = 0;

	int k;
	for (int j = 2; t[j] != '\0'; j++)
	{
		k = next[j - 1];
		if (k == -1)
		{
			next[j] = 0;
			continue;
		}
		else
		{
			while (k != -1 && t[j - 1] != t[k])   //���� k!=-1 ֻ�ܷ���ǰ�棬�����ں���ᵼ�����
			{
				k = next[k];
			}
			if (k == -1 || t[j - 1] == t[k])  
				next[j] = k + 1;
			else
				next[j] = 0;
		}
	}

}
// ��next����

void get_next(const char* t, int* next)
{

	// next[i]����ⷽ���ǣ��ҵ���t[0]~t[i-1]�Ĺ����ƥ��ǰ׺�ͺ�׺�ĳ���
	next[0] = -1;  //next����ĵ�һλԼ����ֵΪ -1
	next[1] = 0;   //next�����±� 1 ��ֵ�϶�Ϊ 0 

	//������λnext�����ֵ

	for (int i = 2; t[i] != '\0'; i++)   //�ַ���ֻҪû������һֱѭ��
	{
		int max_len = i - 1, len, j;     //max_lenΪ���ܵ����ͬǰ��׺��len����Ŀ����Կ�ʼ����һ�ݼ����������0
		for (len = max_len; len >= 1; len--)
		{
			for (j = 0; j < len; j++)
			{
				if (t[j] != t[j + i - len])  //ֻҪ���ڲ���ͬ���ַ������˳���ѭ��
				{
					break;
				}
			}
			if (j == len)  //˵���ҵ�����ͬǰ��׺,�ҳ���Ϊ len
			{
				next[i] = len;  //������Ϊ len ����ͬǰ��׺��¼����Ӧ�� next ����
				break;   //����ѭ���� len  ����Ҫ���Լ�
			}
		}
		if (len < 1)  // len С�� 1 ˵�����п��ܳ��ȵ���ͬǰ��׺��������ʧ���ˣ���ʱnext�����ӦֵΪ 0
		{
			next[i] = 0;
		}
	}
}

int KMP(const char* s,const char* t)   //s Ϊ��Ҫ�Ƚϵ��ַ�(�ϳ����ַ�)
{
	int next[MAX_LEN];
	Get_Next(t, next);
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			//���� next[x]Ϊ -1 �����
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	if (t[j] == '\0')  //˵��ƥ�䵽��󣬷���ƥ���ַ������±�
	{
		return i - strlen(t);  // i ��ѭ����������� 1 ���������������� +1 ;
	}
	else   //ƥ��ʧ��
		return -1;

}

int main()
{
	const char* s = "abcdabbcdabcdabd";
	const char* t = "abcdabd";
	cout << KMP(s, t);
	return 0;
}