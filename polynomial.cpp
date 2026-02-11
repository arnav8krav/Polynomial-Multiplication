#include <bits/stdc++.h>
using namespace std;

//standard import statements

/* 
This function takes in a vector to represent the coefficients of some polynomial, as well as some "multiplier"
This "multiplier" is actually supposed to be some K, when multiplying the polynomial by x - K
*/

void polynomialMultiplication(vector<double>& currentProduct, const double& multiplier){
    
    currentProduct.push_back(0); //simulates multiplication with only coefficients
    vector<double> copiedProduct = currentProduct;
    for (int i = 1; i < currentProduct.size(); i++){
        currentProduct[i] += (multiplier*copiedProduct[i-1]);
        }
    

}


int main(){
    int degree;
    cout << "Enter the number of roots of the polynomial (degree): "; cin >> degree;
// Rejects degrees that are less than 0 (decimals have been accounted for in the fact that the degree variable was defined to be an integer)
    while (degree < 0){
        cout << "Invalid degree. Enter the number of roots of the polynomial (degree): ";
        cin >> degree;
    }
    vector<double> polynomial = {1}; //starting polynomial that we will iteratively build upon to reach the final polynomial
    vector<double> roots; //stores a double (decimal) for roots
    double yIntercept;
    double leadingCoeff;
    double rootProduct = 1;

    for (int i = 0; i < degree; i++){
        double root;
        cout << "Enter a root: "; cin >> root;
        roots.push_back(root);
        double adjustedRoot = -1 * root;
        polynomialMultiplication(polynomial, adjustedRoot);
    }

/* 
basically, the y-intercept of some polynomial p(x) has y-coordinate p(0).
in standard form, p(x) = a(x-r_1)(x-r_2)...(x-r_n) for an n degree polynomial.
p(0) is therefore equal to a * (-1)^n * (product of the roots).
the -1 power is 1 is n is even and -1 if n is odd - the root product will be constant;
we case on the parity of the degree to find the unique polynomial with a given y-intercept
*/


    cout << "Enter the y-coordinate of the y-intercept: "; cin >> yIntercept;

    for (int i = 0; i < roots.size(); i++){
    rootProduct *= roots[i];
}
//edge case if 0 is a root of the polynomial
if (rootProduct == 0){
    if (yIntercept != 0){
        cout << "No polynomial exists with a zero root and nonzero y-intercept.\n";
        return 0;
    }
    // y-intercept is 0 → choose any valid leading coefficient
    leadingCoeff = 1;
}
else{
    if (degree % 2 == 0){
        leadingCoeff = yIntercept / rootProduct;
    }
    else{
        leadingCoeff = -yIntercept / rootProduct;
    }
}


    for (int i = 0; i < polynomial.size(); i++){
        polynomial[i] *= leadingCoeff;
    }
    
    for (int i = 0; i < polynomial.size(); i++){
        cout << polynomial[i] << "x^(" << degree-i << ") ";
        if (i != polynomial.size()-1){
            cout << "+ ";
        }
    }
    cout << "\n";

}

