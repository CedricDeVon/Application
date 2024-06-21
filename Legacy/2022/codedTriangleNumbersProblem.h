#pragma once

std::string getAllLinesOfTextFromAFile(std::string fileName)
{
    std::fstream file;
    std::string lineOfText;
    std::string linesOfText;
    file.open(fileName, std::ios::out | std::ios::in | std::ios_base::app);
    while (file)
    {
        std::getline(file, lineOfText);
        linesOfText.append(lineOfText);
    }
    file.close();
	return linesOfText;
}

bool isAnUppercasedAlphabeticalCharacter(char character)
{
	return character >= 65 && character <= 90;
}

bool isALowercasedAlphabeticalCharacter(char character)
{
	return character >= 97 && character <= 122;
}

bool isAnAlphabeticalCharacter(char character)
{
	return isAnUppercasedAlphabeticalCharacter(character) ||
		isALowercasedAlphabeticalCharacter(character);
}

unsigned int getValueOfAlphabeticalCharacter(char character)
{
	if (isAnUppercasedAlphabeticalCharacter(character))
	{
		return character - 64;
	}
	else if (isALowercasedAlphabeticalCharacter(character))
	{
		return character - 96;
	}
	else
	{
		return 0;
	}
}

bool isCharacterAComma(char character)
{
	return character == ',';
}

bool isATriangleNumber(unsigned int number)
{
	unsigned int sum = 0;
	unsigned int temporary = 1;
	while (sum < number)
	{
		sum += temporary;
		temporary += 1;
	}

	return sum == number;
}

unsigned int getTheSumOfValuesInAString(std::string word)
{
	unsigned int sum = 0;
	for (char character : word)
	{
		sum += getValueOfAlphabeticalCharacter(character);
	}
	return sum;
}

unsigned int codedTriangleNumbersProblem(std::string fileName)
{
	std::string linesOfText = getAllLinesOfTextFromAFile(fileName);
	unsigned int sumOfWord = 0;
	unsigned int totalTriangleNumbers = 0;
    for (int index = 0; index < linesOfText.length(); index += 1)
    {
    	char character = linesOfText[index];
		if (isAnAlphabeticalCharacter(character))
    	{
    		sumOfWord += getValueOfAlphabeticalCharacter(character);
    	}
		else if (isCharacterAComma(character) && isATriangleNumber(sumOfWord))
		{
			totalTriangleNumbers += 1;
		}
		if (isCharacterAComma(character))
		{
			sumOfWord = 0;
		}
    }

    return totalTriangleNumbers;
}

