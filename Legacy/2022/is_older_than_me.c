
void is_older_than_me()
{
    int my_age = 0, your_age = 0;
    char your_name[16];

    printf("Enter my age: ");
    scanf("%d", &my_age);

    printf("Enter your name and age: ");
    scanf("%s %d", &your_name, &your_age);

    if (your_age < my_age)
    {
        printf("%s is younger than me.");
    }
    else if (your_age == my_age)
    {
        printf("%s is the same age as me.");
    }
    else if (your_age > my_age)
    {
        printf("%s is older than me.");
    }
}
