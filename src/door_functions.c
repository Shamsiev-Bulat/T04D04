#include <math.h>
#include <stdio.h>

double zier(double x);
double ber(double x);
double hyp(double);

int main() {
    double x, y1, y2, y3;
    int i;

    for (i = 0; i < 42; i++) {
        x = -M_PI + i * (2 * M_PI / 41.0);
        y1 = zier(x);
        y2 = ber(x);
        y3 = hyp(x);

        printf("%.7f | ", x);

        if (isnan(y1)) {
            printf("- | ");
        } else {
            printf("%.7f |", y1);
        }

        if (isnan(y2)) {
            printf("- | ");
        } else {
            printf("%.7f |", y2);
        }

        if (isnan(y3)) {
            printf("-\n");
        } else {
            printf("%.7f\n", y3);
        }
    }

    return 0;
}

double zier(double x) {
    if (x == 1 || x == -1) {
        return NAN;
    }
    return pow(1, 3) / (pow(1, 2) + pow(x, 2));
}

double ber(double x) {
    if (x == 0) {
        return NAN;
    }
    return sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));
}

double hyp(double x) {
    if (x == 0) {
        return NAN;
    }
    return 1.0 / pow(x, 2);
}
