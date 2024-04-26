#ifndef DSER
#define DSER

#include <map>

using namespace std;

struct Packages{
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


void Deserialization_File (map<Packages, int> &map_pack, string branch, int number = 1);
// map_pack -  ссылка на объект map<Packages, int>
// branch - название ветки (а точнее  json файла в которм хранится информация о ветке)
// number - номер запроса (1 - первый запрос т.е рабоать с первой веткой), 2- второй запрос т.е работать со второй веткой


void serialization_File(map<Packages, int> &map_pack);
// map_pack -  ссылка на объект map<Packages, int>
// status какую сортировку нам вывести :

#endif