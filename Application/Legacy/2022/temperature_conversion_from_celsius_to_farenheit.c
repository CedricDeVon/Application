
void temperature_conversion_from_celsius_to_farenheit()
{
    /*
    Requirements:
    - Convert C to F, in degrees
    - Use the formula:
    - F = (9/5) * C + 32
    */

    int celsius = 0;
    float farenheit = 0;
    printf("Enter celsius: ");
    scanf("%d", &celsius);

    farenheit = 9 / 5 * celsius + 32;
    printf("%d celsius is equal to %.2f farenheit", celsius, farenheit);
}
