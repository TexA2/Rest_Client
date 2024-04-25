#ifndef GET_REQ
#define GET_REQ

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

int createfile(FILE **bodyfile, const char *bodyfilename);

void getRequest(string file_name, string &query);

#endif