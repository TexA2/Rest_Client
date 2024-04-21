#include <iostream>
#include <string>
#include <iomanip>   //для форматирования вывода
#include <nlohmann/json.hpp>
#include <fstream>
#include <map>
#include "dser.h"


void Deserialization_File (map<Packages, int> &map_pack, string branch, int number)  
{
    ifstream file(branch + ".json");   // открываем файл
    nlohmann::json j;                       // создаем json объект 
    j = nlohmann::json::parse(file);        // парсим его

    auto it_j = j["packages"].begin();  // начало массива с пакетами 
    auto eit_j = j["packages"].end();   // конец массива с пакетами

    for (; it_j != eit_j ; ++it_j)    
    {
        string name = (*(it_j))["name"].get<string>();
        string arch = (*(it_j))["arch"].get<string>();

        string version = (*(it_j))["version"].get<string>();
        string release = (*(it_j))["release"].get<string>();

        Packages p1{name+"_"+arch, version+release};
        
        p1.name = (*(it_j))["name"].get<string>();
        p1.epoch = (*(it_j))["epoch"].get<int>();
        p1.version = (*(it_j))["version"].get<string>();
        p1.release = (*(it_j))["release"].get<string>();
        p1.arch = (*(it_j))["arch"].get<string>();
        p1.disttag = (*(it_j))["disttag"].get<string>();
        p1.buildtime = (*(it_j))["buildtime"].get<int>();
        p1.source = (*(it_j))["source"].get<string>();

        map_pack[p1] += number;

        auto res = map_pack.find(p1);

        if (res->second == 3)
        {
            if (res->first.version_release < p1.version_release) res->second++;
        }   
    }
    file.close();
}

void serialization_File(map<Packages, int> &map_pack, int status)
{
    ofstream file("res.json");
    nlohmann::json j;
    string str;

    for (auto it = map_pack.begin() ; it != map_pack.end(); ++it)
    {
       if (it->second == status) 
       {
            j["name"]= it->first.name;
            j["epoch"] = it->first.epoch;
            j["version"] = it->first.version;
            j["release"] = it->first.release;
            j["arch"] = it->first.arch;
            j["disttag"] = it->first.disttag;
            j["buildtime"] = it->first.buildtime;
            j["source"] = it->first.source;

            str = j.dump();

            file << str << '\n';

            cout << str << endl;
       }
    }

    cout << "A file responses has been generated res.json" << endl;
    file.close();
}