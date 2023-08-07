bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0)
        return 1;
    if (flowerbedSize == 1 || flowerbedSize == 2)
    {
        if (flowerbedSize == 1)
        {
            if (flowerbed[0] == 0 && n == 1)
                return 1;
        }
        else
        {
            if (flowerbed[0] == 1 || flowerbed[1] == 1)
                return 0;
            else
            {
                if (n == 2)
                    return 0;
                return 1;
            }

        }
    }
    int count = 0;
    if (!flowerbed[0] && !flowerbed[1])
    {
        flowerbed[0] = 1;
        count++;
    }
    if (!flowerbed[flowerbedSize - 1] && !flowerbed[flowerbedSize - 2])
    {
        count++;
        flowerbed[flowerbedSize - 1] = 1;
    }
    for (int i = 1; i < flowerbedSize - 1; i++)
    {
        if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
        {
            flowerbed[i] = 1;
            count++;
        }
    }

    if (count < n)
        return 0;
    return 1;
}