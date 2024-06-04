
void circumference_of_a_circle()
{
    float radius = 0, PI = 3.1416, circumference = 0;
    printf("Enter radius: ");
    scanf("%f", &radius);

    circumference = 2 * PI * radius;
    printf("Circumference: %f", circumference);
}
