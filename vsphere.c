#include <stdio.h>

#define Vsphere 4/3*3.14

int main()
{
    float radius, volume;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

    volume = Vsphere * radius*radius*radius;
    printf("Volume of the sphere is: %.2f\n", volume);

    return 0;

}