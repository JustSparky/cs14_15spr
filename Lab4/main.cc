#include "lab4.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    cout << "Pre Order" << endl;
    coPrimePre(atoi(argv[1]));
    cout << "Post Order" << endl;
    coPrimePost(atoi(argv[1]));
    cout << "Sorted Order" << endl;
    coPrimeOrder(atoi(argv[1]));
}