#include <iostream>
#include <string>
#include <iomanip>   //для форматирования вывода
#include <nlohmann/json.hpp>
#include <fstream>
#include <map>

using namespace std;

struct Packages
{
    string key_name;
    string version_release;
    string name;
    string version;
    string release;
    string arch;
    string disttag;
    string source;
    int epoch;
    int buildtime;

    Packages(string kname, string ver_rel) : key_name {kname} , version_release { ver_rel }
    {}

    bool operator <(const Packages& rhs) const
    {
        return this->key_name < rhs.key_name;
    }

};


int main(){

    std::ifstream file("body.json");    // открываем файл

    nlohmann::json j;                   // создаем json объект 
    j = nlohmann::json::parse(file);    // парсим его

     map<Packages, int> map_pack;


    auto it_j = j["packages"].begin();  // начало массива с пакетами
    auto eit_j = j["packages"].end();   // конец массива с пакетами



 
    for (; it_j != eit_j ; ++it_j)      // пока поработаем с 5 элементами
    {
        //cout << *(it+i) << endl;
        string name = (*(it_j))["name"].get<string>();
        string arch = (*(it_j))["arch"].get<string>();

        string version = (*(it_j))["version"].get<string>();
        string release = (*(it_j))["release"].get<string>();

        Packages p1{name+arch, version+release};
        
        p1.name = (*(it_j))["name"].get<string>();
        p1.epoch = (*(it_j))["epoch"].get<int>();
        p1.version = (*(it_j))["version"].get<string>();
        p1.release = (*(it_j))["release"].get<string>();
        p1.arch = (*(it_j))["arch"].get<string>();
        p1.disttag = (*(it_j))["disttag"].get<string>();
        p1.buildtime = (*(it_j))["buildtime"].get<int>();
        p1.source = (*(it_j))["source"].get<string>();

        map_pack[p1] += 1;
    }

    for (auto it = map_pack.begin() ; it != map_pack.end(); ++it)
        cout << it->first.key_name << '\t' << it->second << endl;


    return 0;
}