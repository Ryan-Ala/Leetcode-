int maxDistance(int* colors, int colorsSize) {
    int max = 0, count = 0;
    for (int i = 0; i < colorsSize; i++)
    {
        int j = colorsSize - 1;
        while (i < j)
        {
            if (colors[i] != colors[j])
            {
                count = j - i;
                if (max < count)
                    max = count;
                if (max >= colorsSize - i)
                    return max;
                break;
            }
            while (i < j && colors[j] == colors[j - 1])
            {
                j--;
            }
            j--;
        }
    }
    return max;
}