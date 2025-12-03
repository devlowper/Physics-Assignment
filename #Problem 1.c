#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main() {
    double lambda;
    int m;
    double a[3];
    double theta[3];
    int i, maxIndex = 0;

    printf("Enter wavelength (nm): ");
    scanf("%lf", &lambda);
    if(lambda < 380 || lambda > 750) {
        printf("Out of the range. Please enter a valid number.\n");
        return 0;
    }

    printf("Enter order m: ");
    scanf("%d", &m);

    for(i = 0; i < 3; i++) {
        printf("Enter slit width a%d (µm): ", i+1);
        scanf("%lf", &a[i]);

        double an = a[i] * 1000;
        double s = m * lambda / an;
        if(s > 1) s = 1;

        theta[i] = asin(s) * 180 / PI;
    }

    for(i = 1; i < 3; i++) {
        if(theta[i] > theta[maxIndex]) maxIndex = i;
    }

    printf("\n--- Results ---\n");

    printf("Wavelength Color : ");
    if(lambda >= 380 && lambda < 450) printf("Violet\n");
    else if(lambda < 485) printf("Blue\n");
    else if(lambda < 500) printf("Cyan\n");
    else if(lambda < 565) printf("Green\n");
    else if(lambda < 590) printf("Yellow\n");
    else if(lambda < 625) printf("Orange\n");
    else printf("Red\n");

    printf("Diffraction angles:\n");
    for(i = 0; i < 3; i++) {
        printf("Slit a%d: %.2lf degrees\n", i+1, theta[i]);
    }

    printf("\nSlit a%d bent the light MOST.\n", maxIndex+1);

    return 0;
}
