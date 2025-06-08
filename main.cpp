// #include "iostream-bridge.h"
#include "fstream-bridge.h"

//#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream log("log.txt");
    log << "Hello World!" << endl;
    return 0;
}
