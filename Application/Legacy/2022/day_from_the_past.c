
void day_from_the_past(int days_ago)
/* TODO: REFACTOR CODE */
{
    int predicted_day = 5 - days_ago;
    if (predicted_day < 0)
    {
        if (predicted_day < -7)
        {
            predicted_day = 7 + abs(predicted_day);
        }
        else
        {
            predicted_day = 7 + predicted_day;
        }

        predicted_day = predicted_day % 7;
    }

    switch (predicted_day)
    {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    }
}