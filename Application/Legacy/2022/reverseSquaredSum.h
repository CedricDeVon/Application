#pragma once

void reverseSquaredSum()
{
	int testCaseCount = 0;
    std::cin >> testCaseCount;
    while (testCaseCount > 0)
    {
    	int size = 0;
    	std::cin >> size;
        int numbers[size];
        for (int index = 0; index < size; index += 1)
        {
            int number = 0;
            std::cin >> number;
            numbers[index] = number;
        }

        int answer = numbers[size - 1] * numbers[size - 1];
        bool isAllowedToSubtract = true;
        for (int currentIndex = size - 2; currentIndex >= 0; currentIndex -= 1)
        {
            if (isAllowedToSubtract)
            {
                answer -= numbers[currentIndex] * numbers[currentIndex];
                isAllowedToSubtract = false;
            }
            else
            {
                answer += numbers[currentIndex] * numbers[currentIndex];
                isAllowedToSubtract = true;
            }
        }
        std::cout << answer << '\n';
        testCaseCount -= 1;
    }
    
}