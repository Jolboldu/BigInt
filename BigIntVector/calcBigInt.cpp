#include <iostream>
#include <sstream>
#include <string>

#include "BigInt.h"

using namespace std;

bool parseExpr(const string& line, BigInt& r1, char& op, BigInt& r2);
void computeAndShow(const BigInt& r1, char op, const BigInt& r2);
void showResult(const BigInt& r);

int main()
{
    cout << boolalpha;
    
    string line;
    while (getline(cin, line))
    {
        BigInt r1;
        char op;
        BigInt r2;
        
        try
        {
            if (not parseExpr(line, r1, op, r2))
            {
                cout << "Incorrect expression: " << line << endl;
            }
            else
            {
                computeAndShow(r1, op, r2);
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}

bool parseExpr(const string& line, BigInt& r1, char& op, BigInt& r2)
{
    const string operations = "+-*:<>=#";

    istringstream sinp(line);
    if (!(sinp >> r1))
    {
        return false;
    }
    if (!(sinp >> op) or operations.find(op) == string::npos)
    {
        return false;
    }
    if (!(sinp >> r2 >> ws) or not sinp.eof())
    {
        return false;
    }
    
    return true;
}

void computeAndShow(const BigInt& r1, char op, const BigInt& r2)
{
    switch (op)
    {
        case '+':
            showResult(r1 + r2);
            break;
        case '-':
            showResult(r1 - r2);
            break;
        case '*':
            showResult(r1 * r2);
            break;
        case ':':
            showResult(r1 / r2);
            break;
        case '=':
            cout << (r1 == r2) << endl;
            break;
        case '#':
            cout << (r1 != r2) << endl;
            break;
        case '<':
            cout << (r1 < r2) << endl;
            break;
        case '>':
            cout << (r1 > r2) << endl;
            break;
        default:
            throw runtime_error("Something wrong!!!");
    }
}

void showResult(const BigInt& r)
{
    cout << "Result: " << r;
}