#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, discriminant, x1, x2;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    stringstream outputEquation;
    outputEquation << fixed << setprecision(1) << "Equation is: (" << a << ") x^2 + (" << b << ") x + (" << c << ") = 0\n";
    cout << outputEquation.str();
    discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant > 0)
    {
        cout << "There are 2 roots\n";
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << fixed << setprecision(1) << "x1 = " << x1 << endl;
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << fixed << setprecision(1) << "x2 = " << x2 << endl;
    }
    if (discriminant == 0)
    {
        cout << "There are 1 roots\n";
        x1 = -b / (2 * a);
        cout << fixed << setprecision(1) << "x1 = " << x1 << endl;
    }
    if (discriminant < 0)
    {
        cout << "There are 0 roots\n";
    }
    return 0;
}
