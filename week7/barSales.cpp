#include <iostream>
#include <iomanip>

static const int BARS_PER_CASE = 12;
static const int COST_PER_CASE = 5;
static const double PERCENT_TOWARDS_SG = 0.10;

void input(int *, double *);
void output(int, double);

int main() {
    int cases;
    double salePrice;    
    input(&cases, &salePrice);
    output(cases, salePrice);
    return 0;
}

void input(int * cases, double * salePrice) {
    std::cout << "Enter Number of Cases Sold: " << std::endl;
    std::cin >> *cases;

    std::cout << "Enter Price Per Bar" << std::endl;
    std::cin >> *salePrice;
}

void output(int cases, double salePrice) {
    double totalProfit, actualProfit;
    totalProfit = cases * BARS_PER_CASE * salePrice;
    totalProfit -= COST_PER_CASE * cases;    

    actualProfit = totalProfit * 0.9;

    std::cout << "Actual Proceeds $" << std::fixed << std::setprecision(2) << actualProfit << std::endl;    
}



