bool isValid(char* s) {
    char fun(char p)
    {
        if (p == ')')
            return '(';
        if (p == ']')
            return '[';
        if (p == '}')
            return '{';
        return 0;
    }
    int sz = strlen(s), num = 0;
    char str[sz + 1];
    if (sz % 2 == 1)
        return 0;
    for (int i = 0; i < sz; i++)
    {

        char ch = fun(s[i]);
        if (ch)
        {
            num--;
            if (num < 0)
                return 0;
            if (num >= 0 && str[num] == ch)
            {
                if (num == 0 && i == sz - 1)
                {
                    return 1;
                }
                continue;

            }
            else
                return 0;

        }
        else
        {
            str[num++] = s[i];
        }
    }
    return 0;
}