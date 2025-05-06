#include <stdio.h>
#include <math.h>

double calculate_X(double a, double b);

int main() {
    double b = 2.5;
    double a_min = 0.0;
    double a_max = 5.0;
    double da = 0.5;
    double a;

    printf("Обчислення значення функції X = f(a)\n");
    printf("Параметри:\n");
    printf("b = %.2f\n", b);
    printf("a_min = %.2f\n", a_min);
    printf("a_max = %.2f\n", a_max);
    printf("Крок da = %.2f\n\n", da);
    printf("-------------------------------------\n");
    printf("|   a   |      X = f(a)     |\n");
    printf("-------------------------------------\n");

    for (a = a_min; a <= a_max; a += da) {
        double x_value = calculate_X(a, b);
        if (!isnan(x_value)) {
            printf("| %5.2f | %17.6f |\n", a, x_value);
        } else {
            printf("| %5.2f | Ділення на нуль! |\n", a);
        }
    }
    printf("-------------------------------------\n");

    return 0;
}

double calculate_X(double a, double b) {
    double result;

    if (a >= b) {
        result = a / exp(b + pow(a, 2));
    } else {
        double denominator = sin(a) + 1;
        if (fabs(denominator) < 1e-9) {
            return NAN;
        }
        result = (pow(a, 2) + a * b) / denominator;
    }
    return result;
}