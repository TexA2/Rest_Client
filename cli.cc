#include <iostream>
#include <cstdlib>
#include "get_req.h"
#include "dser.h"
#include "cli.h"



void help_text()
{
    system("clear");
   cout << "\e[1;32mdependencies/binary_package_dependencies/{pkghash} \e[0m" << '\n'
   << "(pkghash* integer) Description: package hash" << "\n\n"

    << "\e[1;32mexport/branch_binary_packages/{branch} \e[0m" << '\n'
    << "(arch string ) Description: package architecture" << '\n'
    << "(branch*  string) Description: branch name" << "\n\n"

    << "\e[1;32msite/binary_package_archs_and_versions \e[0m" << '\n'
    << "(branch* string) Description: branch name" << '\n'
    << "(name* string) Description: binary package name" << "\n\n"

    << "\e[1;32msite/binary_package_scripts/{pkghash} \e[0m" << '\n'
    << "(pkghash* integer)" << "\n\n"

    << "\e[1;32msite/pkghash_by_binary_name \e[0m" << '\n'
    << "(arch*   string ) Description: package arch" << '\n'
    << "(name*   string ) Description: package name" << '\n'
    << "(branch* string)  Description: name of packageset"  << '\n' << endl;

}

void binary_package(string &uri, string name_file)
{
    system("clear");
    while (true)
    {
        cout << "Enter  request " << '\n'
        << "? - for to call help" << '\n'
        << "0: exit"<< '\n'
        << "example: \e[1;32mexport/branch_binary_packages/p10\e[0m" << '\n'
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
    << "2: Request for binary packages"<< '\n'
    << "0: exit"<< '\n'
    << "->: ";

    int key;
    cin >> key;

    if (key == 0) return 1;

    if (key == 1 )
    {
        cout << "Enter a request to the site https://rdb.altlinux.org/api/ " << '\n'
        << "example: \e[1;32merrata/errata_branches\e[0m" << '\n'
        << "->: ";

        cin >> uri;
        query = url+uri;
        getRequest("res",  query);
        cout << "A file responses has been generated res.json" << endl;
        return 1;
    }


// работаем с бинарными пакетами
    if (key == 2)
    {
        binary_package(uri, "first");
        binary_package(uri, "second");
        exit(1); // убрать ведь дальше пойдет обратка пакетов и их сравнение
    }

/*
// если работаем с бинарными пакетами 

    map<Packages, int> map_pack;

// выполняем десериализацию
    Deserialization_File(map_pack, "first");
    Deserialization_File(map_pack, "second", 2);

// запрашиваем у пользователя какой ему нужен резлуьат
    cout << "Types of comparison of packages:" << '\n'
    << "1: all packages that are in the 1st, but not in the 2nd;" << '\n'
    << "2: all packages that are in the 2nd, but not in the 1st;" << '\n'
    << "3: all packages ,version-release that are most similar to the 1st and 2nd" << '\n'
    << "->: "; 
    
    int key_comp;
    cin >> key_comp;

    serialization_File(map_pack,key_comp);
 */
    return 0;
}