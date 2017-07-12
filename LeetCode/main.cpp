#include <iostream>
#include <fstream>

#include "524.h"
#include "93.h"

//namespace list: Chirl | NanerLee | Sansan | Wcytem...
int main(int argc, char **argv)
{
    //输入重定向;
    streambuf *backup;
    ifstream fin;
    fin.open("TestExample.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());

    Chirl::Solution_93::test();  

    cin.rdbuf(backup);
    return 0;
}

