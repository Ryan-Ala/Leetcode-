#include<iostream>
#define MAX_LEN 100
using namespace std;


void Get_next_bit(const char* sub, int* next)
{
	int lensub = strlen(sub);
	next[0] = -1;
	next[1] = 0;
	int i = 2;  //当前 i 的下标
	int k = 0;  //前一项的 k
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
	//开始与前一种方法相同，将下标0初始化为 -1 ，下标 1初始化为 0
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
			while (k != -1 && t[j - 1] != t[k])   //这里 k!=-1 只能放在前面，若放在后面会导致溢出
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
// 求next数组

void get_next(const char* t, int* next)
{

	// next[i]的求解方法是，找到从t[0]~t[i-1]的公共最长匹配前缀和后缀的长度
	next[0] = -1;  //next数组的第一位约定赋值为 -1
	next[1] = 0;   //next数组下标 1 处值肯定为 0 

	//求其余位next数组的值

	for (int i = 2; t[i] != '\0'; i++)   //字符串只要没结束就一直循环
	{
		int max_len = i - 1, len, j;     //max_len为可能的最长相同前后缀，len从最长的可能性开始，逐一递减，但需大于0
		for (len = max_len; len >= 1; len--)
		{
			for (j = 0; j < len; j++)
			{
				if (t[j] != t[j + i - len])  //只要存在不相同的字符，就退出该循环
				{
					break;
				}
			}
			if (j == len)  //说明找到了相同前后缀,且长度为 len
			{
				next[i] = len;  //将长度为 len 的相同前后缀记录到对应的 next 数组
				break;   //跳出循环， len  不需要再自减
			}
		}
		if (len < 1)  // len 小于 1 说明所有可能长度的相同前后缀都尝试且失败了，此时next数组对应值为 0
		{
			next[i] = 0;
		}
	}
}

int KMP(const char* s,const char* t)   //s 为需要比较的字符(较长的字符)
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
			//处理 next[x]为 -1 的情况
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	if (t[j] == '\0')  //说明匹配到最后，返回匹配字符串的下标
	{
		return i - strlen(t);  // i 在循环最后还自增了 1 ，所以这里无需再 +1 ;
	}
	else   //匹配失败
		return -1;

}

int main()
{
	const char* s = "abcdabbcdabcdabd";
	const char* t = "abcdabd";
	cout << KMP(s, t);
	return 0;
}