#ifndef GET_REQ
#define GET_REQ

using namespace std;

const string url = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

int createfile(FILE **bodyfile, const char *bodyfilename);

void getRequest(string branch, string arch = "");

#endif