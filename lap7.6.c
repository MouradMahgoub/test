#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numerator;
    int denominator;

} Fraction;

Fraction add(Fraction num1, Fraction num2);
Fraction subtract(Fraction num1, Fraction num2);
Fraction multiply(Fraction num1, Fraction num2);
Fraction divide(Fraction num1, Fraction num2);

int main()
{
    Fraction num1, num2, result;
    char op;
    scanf("%d/%d\n", &num1.numerator, &num1.denominator);
    scanf("%c\n", &op);
    scanf("%d/%d", &num2.numerator, &num2.denominator);
    int n1 = num1.numerator, d1 = num1.denominator;
    int n2 = num2.numerator, d2 = num2.denominator;

    if(d1 == 0 || d2 == 0) printf("Error");

    switch(op)
    {
        case '+' :
            result = add(num1, num2);
            break;
        case '-' :
            result = subtract(num1, num2);
            break;
        case '*' :
            result = multiply(num1, num2);
            break;
        case '/' :
            result = divide(num1, num2);
            break;
        default :
            printf("Error");
            return 0;
    }

    int n3 = result.numerator, d3 = result.denominator;
    int gcd = GCD(n3, d3);
    n3 /= gcd;
    d3 /= gcd;

    printf("%d/%d %c %d/%d = %d/%d", n1, d1, op, n2, d2, n3, d3);
    return 0;
}

int GCD(int a, int b)
{
    if(a == 0) return a;
    if(b == 0) return b;
    if(a == b) return a;
    if(a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}

Fraction add(Fraction num1, Fraction num2)
{
    Fraction result;
    int n1 = num1.numerator, d1 = num1.denominator;
    int n2 = num2.numerator, d2 = num2.denominator;

    result.numerator = n1*d2 + n2*d1;
    result.denominator = d1*d2;

    return result;
}

Fraction subtract(Fraction num1, Fraction num2)
{
    Fraction result;
    int n1 = num1.numerator, d1 = num1.denominator;
    int n2 = num2.numerator, d2 = num2.denominator;

    result.numerator = n1*d2 - n2*d1;
    result.denominator = d1*d2;

    return result;
}

Fraction multiply(Fraction num1, Fraction num2)
{
    Fraction result;
    int n1 = num1.numerator, d1 = num1.denominator;
    int n2 = num2.numerator, d2 = num2.denominator;

    result.numerator = n1*n2;
    result.denominator = d1*d2;

    return result;
}

Fraction divide(Fraction num1, Fraction num2)
{
    Fraction result;
    int n1 = num1.numerator, d1 = num1.denominator;
    int n2 = num2.numerator, d2 = num2.denominator;

    result.numerator = n1*d2;
    result.denominator = n2*d1;

    return result;
}
//test