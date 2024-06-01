
void hour_hand_from_now()
{
    int previous_hour = 9, following_hours = 3;
    int next_hour = (previous_hour + following_hours) % 12;
    if (next_hour == 0)
    {
        next_hour = 12;
    }

    printf("Current hour: %d, Hours fron now: %d, Predicted hour: %d", previous_hour, following_hours, next_hour);
}
