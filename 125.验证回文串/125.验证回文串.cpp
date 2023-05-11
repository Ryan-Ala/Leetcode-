#include<iostream>
bool isPalindrome(char* s) {
    int sz = 0;
    char* start = s, * end;
    while (s[sz] != '\0')
        sz++;
    end = &s[sz - 1];
    while (start < end)
    {
        while (!((*start <= 'Z' && *start >= 'A') || (*start >= 'a' && *start <= 'z') || (*start >= '0' && *start <= '9')))
        {
            start++;
            if (*start == '\0')
                return 1;
        }
        while (!((*end <= 'Z' && *end >= 'A') || (*end >= 'a' && *end <= 'z') || (*end >= '0' && *end <= '9')))
            end--;
        if ((*start == *end) || (toupper(*start) == *end) || (tolower(*start) == *end))
        {
            start++;
            end--;
            continue;
        }
        else
            return 0;
    }
    return 1;
}