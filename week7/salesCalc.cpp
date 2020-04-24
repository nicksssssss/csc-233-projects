#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

static const float EMPLOYEE_CUT = .07;
static const float FEDERAL_TAX_RATE = .18;
static const float RETIREMENT_CUT = .1;
static const float SOCIAL_SECURITY = .06;
int main()
{
string name;
float salesAmount, empPay;

cout << "Enter employee name and sales amount for the week in dollars.\n";
cin >> name >> salesAmount;
empPay = (salesAmount * EMPLOYEE_CUT) * (1 - FEDERAL_TAX_RATE) * (1 - RETIREMENT_CUT) * (1 - SOCIAL_SECURITY);
cout << endl << fixed << setprecision(2) << name << "'s pay: $" << empPay;
return 0;
}