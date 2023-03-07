#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void interactiveMode();
void noninteractiveMode(char *argv);

vector<double> validChecker();

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char *filename = argv[1];
        noninteractiveMode(filename);
    }
    else
    {
        interactiveMode();
    }
    return 0;
}

void interactiveMode()
{
    double a, b, c, discriminant, x1, x2;
    cin.exceptions(ifstream::failbit);
    vector<double> variables = validChecker();
    a = variables[0];
    b = variables[1];
    c = variables[2];
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
}

vector<double> validChecker()
{
    double a, b, c;
    bool validInput;
    vector<double> variables;
    do
    {
        try
        {
            validInput = true;
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
        }
        catch (ios_base::failure &fail)
        {
            validInput = false;
            cin.clear();
            string errorText;
            cin >> errorText;
            cout << "Error. Expected a valid real number, got " << errorText << " instead" << endl;
        }
    } while (!validInput);
    variables.push_back(a);
    variables.push_back(b);
    variables.push_back(c);
    return variables;
};

void noninteractiveMode(char *argv)
{
    fstream newfile;
    newfile.open(argv, ios::in);
    string readData;
    if (newfile.is_open())
    {
        getline(newfile, readData);
        newfile.close();
        cout << readData << endl;
        istringstream iss(readData);
        double a, b, c, discriminant, x1, x2;
        ;
        iss >> a >> b >> c;
        if (!iss.fail())
        {
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
        }
        cout << "invalid file format" << endl;
    }
    else
    {
        cout << "file does not exist" << endl;
    }
}