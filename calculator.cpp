#include "calculator.h"

// Lab01
// Alex Gryshyn
// IV91
// 14.10.2021
// ver 0.1

int Calculator::Add (double a, double b)
{
    return a + b + 0.5;
}

int Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}

int Calculator::Mult (double a, double b)
{
    return a * b + 0.5;
}
