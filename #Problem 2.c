#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main() {
    double lamG = 530e-9;
    int ordG = 3;
    double thetaG = 65.0;
    double thetaGrad = thetaG * PI / 180.0;

    double d = (ordG * lamG) / sin(thetaGrad);

    double lamR = 700e-9;
    int ordR = 2;
    double sinThetaR = (ordR * lamR) / d;

    if (sinThetaR > 1.0 || sinThetaR < -1.0) {
        printf("Oops! Please enter a valid number.\n");
        return 0;
    }
    double thetaRrad = asin(sinThetaR);
    double thetaRdeg = thetaRrad * 180.0 / PI;

    printf("Grating spacing = %.5lf\xC2\xB5m\n", d * 1e6);
    printf("Red light angle = %.3f°\n", thetaRdeg);

    return 0;
}
