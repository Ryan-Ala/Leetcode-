#include <iostream>
using namespace std;
int main() {
    int n, num;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> num;
    for (int i = 0; i < n;)
    {
        int k = 0;
        if (num == a[i])
        {
            k++;
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            a[n - k] = '\0';
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i] << " ";
    }
}


#include <stdio.h>
int main()
{
    int n = 0;
    int arr[50] = { 0 };
    int del = 0;
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &del);//Ҫɾ����Ԫ��
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != del)
        {
            arr[j++] = arr[i];  //�������Ԫ����ǰ�ƶ�������j��¼�޸ĺ�����鳤��
        }
    }
    for (i = 0; i < j; i++)  //ֻ��ӡj��ǰ��Ԫ��
    {
        printf("%d ", arr[i]);  
    }
    return 0;
}