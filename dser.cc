#include <iostream>
#include <string>
#include <iomanip>   //для форматирования вывода
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;

int main(){

    std::ifstream file("body.json");   

    nlohmann::json j;
    j = nlohmann::json::parse(file);

    auto it = j["packages"].crbegin();

    for (int i = 0 ; i < 5 ; ++i)
        cout << *(it+i) << endl;

    //cout << setw(2) << j["packages"] << endl;


    return 0;
}

/*
    std::ofstream file2("test.json");

    while(true)
    {
        char ch = file.get();
            if (ch ==  '[')
                break;
    }

    while(true)
    {
        char ch = file.get();
        if (ch != ']')
            file2 << ch;
        else
            break;
    }


    file.close();
    file2.close();

*/