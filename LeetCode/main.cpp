#include <iostream>
#include <fstream>

#include "646.h"
#include "93.h"

//namespace list: Chirl | NanerLee | Sansan | Wcytem...
int main(int argc, char **argv)
{
#define REIOS 0  //输入重定向开关，1 重定向到根目录下"TestExample.txt"文件中;
    //                0 从控制台输入;   
#if REIOS  
    streambuf *backup = NULL;
    ifstream fin;
    fin.open("TestExample.txt");
    if (fin.is_open())
    {
        backup = cin.rdbuf();
        cin.rdbuf(fin.rdbuf());
    }
    else
        cerr << "<Warning:>"
        "\n\t The file \"TestExample.txt\" is not exist in current folder!" 
        "\n\t Please input your test example from the console!"<< endl;
#endif

    Chirl::Solution_646::test();  

#if REIOS
    if (fin.is_open())
    {
        cin.rdbuf(backup);
    }
#endif

#if _WIN32
    system("pause");
#endif    
    return 0;
}

