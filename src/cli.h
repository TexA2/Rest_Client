#ifndef CLI_CLIENT
#define CLI_CLIENT

using namespace std;

const string url = "https://rdb.altlinux.org/api/";

void Show_list_branch();
void Show_list_arch();
void initialization_branch(const int &key, string &branch);
void initialization_arch(const int &key, string &arch);
int start();



#endif
