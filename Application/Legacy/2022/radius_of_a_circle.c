
void radius_of_a_circle()
{
    float area = 0, PI = 3.141592, radius = 0;
    printf("Enter area: ");
    scanf("%f", &area);

    radius = sqrt(area / PI);
    printf("Radius: %f", radius);
}
