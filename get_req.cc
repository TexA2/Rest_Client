#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include "get_req.h"

//using namespace std;
//const string url = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
// call-back функция для записи данных в файл
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}
 
int createfile(FILE **bodyfile, const char *bodyfilename)
//функция создает файл формата json с именем запрашиваемой ветки
{
 
  *bodyfile = fopen(bodyfilename, "wb");

  if(!(*bodyfile))
  {
    return -1;
  }

  return 1;
}

void getRequest(string file_name, string &query) 
{
  FILE *bodyfile;
  string filename = file_name + ".json";
  createfile (&bodyfile, filename.c_str());  

  CURL *curl;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  struct curl_slist *slist1 = NULL;                                   // Создаем список заголовков
  slist1 = curl_slist_append(slist1, "Accept: application/json");     // Заголовок котрый сообщает Серверу что, клиент хочет получить ответ в формате json
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);                 // Добавляем список заголовков в запрос  

  curl_easy_setopt(curl, CURLOPT_URL, query.c_str());                   // URL адрес для передачи в url засунум сразу нагрузку и получим uri
 
  curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);                        // включаем анимацию загрузки
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyfile);                  // bodyfile - название файла

  curl_easy_perform(curl);                                            // отправляем запрос

  fclose(bodyfile);                                                   // закрываем файл
  curl_easy_cleanup(curl);                                            // закрываем дескриптов CURL
}
