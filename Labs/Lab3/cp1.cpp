#include <iostream>
#include <cmath>
using namespace std;

void compute_squares(unsigned int *a, unsigned int *b, unsigned int n) {
    for (int i=0; i < n; ++i) {
        
        // *(b+i) = *(a+i) * *(a+i) ;
        std::cout<<*(b+i)<<" ";
    }
}

int main() {
    unsigned int a[4] = {10000,200000,300000,10004};
    unsigned int b[4];
    compute_squares(a, b, 4);
}