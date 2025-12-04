#include <stdio.h>

float area()
{
    printf("Enter the radius: ");
    float radius;
    scanf("%f", &radius);
    float area = 3.14 * radius * radius;

    return area;

}

int main()
{
    float Area = area();
    printf("Area is: %.4f\n", Area);

    return 0;
}