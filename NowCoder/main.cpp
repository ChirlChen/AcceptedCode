#include <iostream>
#include <fstream>

#include ".\CodingInterviews\16.h"
#include ".\CodingInterviews\2.h"
#include ".\2017ProgrammingTest\HighestScore.h"

int main(int argc, char **argv)
{
    //输入重定向;
    streambuf *backup;
    ifstream fin;
    fin.open("TestExample.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());

    Chirl::Solution_HighestScore::test();

    cin.rdbuf(backup);
    return 0;
}