#include <stdio.h> //该文件包含pringtf()等函数

int mostWordsFound(const char** sentences, int sentencesSize) {
    int count = 0, i = 0, j = 0, num = 0;
    const char* a = NULL;
    while (i < sentencesSize)
    {
        a = sentences[i];
        j = 0;
        count = 0;
        while (*(a + j) != '\0')
        {
            if (*(a + j) == ' ')
                count++;
            j++;
        }
        if (count > num)
            num = count;
        i++;
    }
    return ++count;
}
int main()
{
    const char* arr[100] = { "w jrpihe zsyqn l dxchifbxlasaehj", "nmmfrwyl jscqyxk a xfibiooix xolyqfdspkliyejsnksfewbjom", "xnleojowaxwpyogyrayfgyuzhgtdzrsyococuqexggigtberizdzlyrdsfvryiynhg", "krpwiazoulcixkkeyogizvicdkbrsiiuhizhkxdpssynfzuigvcbovm", "rgmz rgztiup wqnvbucfqcyjivvoeedyxvjsmtqwpqpxmzdupfyfeewxegrlbjtsjkusyektigr", "o lgsbechr lqcgfiat pkqdutzrq iveyv iqzgvyddyoqqmqerbmkxlbtmdtkinlk", "hrvh efqvjilibdqxjlpmanmogiossjyxepotezo", "qstd zui nbbohtuk", "qsdrerdzjvhxjqchvuewevyzlkyydpeeblpc" };
    mostWordsFound(arr, 3);
}