#include <iostream>
#include <cstdlib>
#include "get_req.h"
#include "dser.h"
#include "cli.h"



void help_text()
{
    system("clear");
    cout << "\e[1;32mexport/branch_binary_packages/{branch} \e[0m" << '\n'
    << "(arch string ) Description: package architecture" << '\n'
    << "(branch*  string) Description: branch name" << "\n\n" << endl;
}

void binary_package(string &uri, string name_file, string position)
{
    system("clear");
    while (true)
    {
        cout << "Enter a \e[1;31m"<< position <<"\e[0m request to the site \e[1;34m https://rdb.altlinux.org/api/\e[0m " << '\n'
        << "? - for to call help" << '\n'
        << "0: exit"<< '\n'
        << "example: \e[1;32mexport/branch_binary_packages/p10?arch=i586\e[0m" << '\n'
        << "->: ";

        cin >> uri;

        if (uri == "0") exit(1);

        if (uri == "?")
        {
            help_text();
            continue; 
        }

        string query = url+uri;
        getRequest(name_file,  query);

        cout << "A file responses has been generated" << name_file<< ".json" << endl;
        return;
    }
}

int start()
{
    string uri;
    string query;

    cout << "Choose an actuin" << '\n'
    << "1: Run a regular get request" << '\n'
    << "2: Request for binary packages 2 branches"<< '\n'
    << "0: exit"<< '\n'
    << "->: ";

    int key;
    cin >> key;

    if (key == 0) return 1;

    if (key == 1 )
    {
        cout << "Enter a request to the site \e[1;34m https://rdb.altlinux.org/api/\e[0m " << '\n'
        << "example: \e[1;32merrata/errata_branches\e[0m" << '\n'
        << "->: ";

        cin >> uri;
        query = url+uri;
        getRequest("res",  query);
        cout << "A file responses has been generated res.json" << endl;
        return 1;
    }


    if (key == 2)
    {
        binary_package(uri, "first", "first");
        binary_package(uri, "second", "second");
    }

    if ((key != 2) and (key != 1))
    {
        cout << "Invalid value, close programm" << endl; 
        exit(1); 
    }

    map<Packages, int> map_pack;

// выполняем десериализацию
    Deserialization_File(map_pack, "FIRST");
    Deserialization_File(map_pack, "SECOND", 2);

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