
float grade_equivalent(int grade_percentage)
{
    if (grade_percentage >= 99 && grade_percentage <= 100)
    {
        return 1.00;
    }
    else if (grade_percentage >= 96 && grade_percentage <= 98)
    {
        return 1.25;
    }
    else if (grade_percentage >= 93 && grade_percentage <= 95)
    {
        return 1.50;
    }
    else if (grade_percentage >= 90 && grade_percentage <= 92)
    {
        return 1.75;
    }
    else if (grade_percentage >= 87 && grade_percentage <= 89)
    {
        return 2.00;
    }
    else if (grade_percentage >= 84 && grade_percentage <= 86)
    {
        return 2.25;
    }
    else if (grade_percentage >= 81 && grade_percentage <= 83)
    {
        return 2.50;
    }
    else if (grade_percentage >= 78 && grade_percentage <= 80)
    {
        return 2.75;
    }
    else if (grade_percentage >= 75 && grade_percentage <= 77)
    {
        return 3.00;
    }
    else if (grade_percentage <= 74)
    {
        return 5.00;
    }
}
