#include <iostream>
#include "get_req.h"
#include "dser.h"
#include "cli.h"


void Show_list_branch()
{
    cout << "1: sisyphus" << '\n' << "2: sisyphus_e2k" << '\n' << "3: sisyphus_mipsel" << '\n'
    << "4: sisyphus_riscv64" << '\n'  << "5: sisyphus_loongarch64" << '\n' << "6: p10" << '\n'
    << "7: p10_e2k" << '\n'  << "8: p9" << '\n'  << "9: p9_e2k" << '\n'  
    << "10: p9_mipsel" << '\n'  << "11: p8" << '\n'  << "12: c10f1" << '\n' 
    << "13: c9f2" << '\n'  << "14: c7" << endl;  
}   

void Show_list_arch()
{
    cout << "aarch64" << '\n' << "armh" << '\n' << "i586" << '\n'
    << "noarch" << '\n'  << "ppc64le" << '\n' << "x86_64" << '\n'
    << "x86_64-i586" << endl;  
}

void initialization_branch(const int &key, string &branch)
{
    switch(key)
    {
        case 1  : branch = "sisyphus"; break;
        case 2  : branch = "sisyphus_e2k"; break;
        case 3  : branch = "sisyphus_mipsel"; break;
        case 4  : branch = "sisyphus_riscv64"; break;
        case 5  : branch = "sisyphus_loongarch64"; break;
        case 6  : branch = "p10"; break;
        case 7  : branch = "p10_e2k"; break;
        case 8  : branch = "p9"; break;
        case 9  : branch = "p9_e2k"; break;
        case 10 : branch = "p9_mipsel"; break;
        case 11 : branch = "p8"; break;
        case 12 : branch = "c10f1"; break;
        case 13 : branch = "c9f2"; break;
        case 14 : branch = "c9f2"; break;
        case 0 :  cout << "Input name branch1: " ; cin >> branch; break;
        default:
            cout << "Invalid value, close programm" << endl;
            exit(1); 
    }
   
}

void initialization_arch(const int &key, string &arch)
{
    switch(key)
    {
        case 1  : Show_list_arch();
                  cout << "Input arch: "; 
                  cin >> arch; break;
        case 0  : break;
        default:
            cout << "Invalid value, close programm" << endl; 
            exit(1); 
    }  
}

int start(){

    bool run = true;
    int key1, key2;

    string firs_branch;
    string second_branch;

    Show_list_branch();
    cout << "0: manual input" << endl;
    cout << "Select the pair branches to search: ";

    cin >> key1 >> key2;

    initialization_branch(key1, firs_branch);
    initialization_branch(key2, second_branch);

    string first_arch  = "";
    string second_arch = "";

    cout << "Do you want to set the architecture for the first branch?" << '\n';
    cout << "1 - yes , 0 - no : ";
    cin >> key1;
    initialization_arch(key1,first_arch);

    cout << "Do you want to set the architecture for the second branch?" << '\n';
    cout << "1 - yes , 0 - no : ";
    cin >> key2;
    initialization_arch(key2,second_arch);

// Выполняем Get запрос
    getRequest(firs_branch, first_arch);
    getRequest(second_branch, second_arch);

    map<Packages, int> map_pack;

// выполняем десериализацию
    Deserialization_File(map_pack, firs_branch);
    Deserialization_File(map_pack, second_branch, 2);

// запрашиваем у пользователя какой ему нужен резлуьат
    cout << "Types of comparison of packages:" << '\n'
    << "1: all packages that are in the 1st, but not in the 2nd;" << '\n'
    << "2: all packages that are in the 2nd, but not in the 1st;" << '\n'
    << "3: all packages ,version-release that are most similar to the 1st and 2nd" << '\n'
    << "->: "; 
    
    int key_comp;
    cin >> key_comp;

    serialization_File(map_pack,key_comp);
 
    return 0;
}