#include <iostream>

int Resource(int procs , int need) // function which calculates the min resources required for the deadlock

{

int minimumResource = 0;

minimumResource = procs*(need-1)+1; // a condition for which the deacklock will never occurs

return minimumResource; // returns the remained minimum resources

}

int main() // main function

{

int procs = 2; // number of process

int need = 1; // resources need for each process

std::cout << "r: " << Resource(procs , need);

return 0;

}

