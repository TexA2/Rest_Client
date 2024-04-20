#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}
 
// https://rdb.altlinux.org/api/export/branch_binary_packages/
// p10
// p9
// sisyphus
// arch = aarch64

int createfile(FILE **bodyfile)
{
 /* open the body file */
  static const char *bodyfilename = "body.json";

  *bodyfile = fopen(bodyfilename, "wb");

  if(!(*bodyfile))
  {
    return -1;
  }

  return 1;
}



int main(void){

 /* open the body file */
  //static const char *bodyfilename = "body.out";                       // за место стастического именени у пользователя надо запрашивать какую он ветку хочет посмотреть
                                                                        // и результат сохранять в эту ветку
  FILE *bodyfile;

  createfile (&bodyfile);                                             // добавить обработчик ошибки -1;

  CURL *curl;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  struct curl_slist *slist1 = NULL;                                   // Создаем список заголовков
  slist1 = curl_slist_append(slist1, "Accept: application/json");     // Заголовок котрый сообщает Серверу что, клиент хочет получить ответ в формате json
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);                 // Добавляем список заголовков в запрос

  //string uri = "http://ip-api.com/json/24.48.0.1";
  string uri = "https://rdb.altlinux.org/api/export/branch_binary_packages/";
  string brach = "p9";
  string query = uri + brach;


  curl_easy_setopt(curl, CURLOPT_URL, query.c_str());                   // URL адрес для передачи в url засунум сразу нагрузку и получим uri
 
  curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);                        // включаем анимацию загрузки
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyfile);

  curl_easy_perform(curl);                                            // отправляем запрос
 
  fclose(bodyfile);                                                   // закрываем файл
  curl_easy_cleanup(curl);                                            // закрываем дескриптов CURL
 
  return 0;
}