#include <curl/curl.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  std::string *data = (std::string*)userdata;
  data->append((char*)ptr, size * nmemb);
  return size * nmemb;
}

int main() {
  CURL *curl;
  CURLcode res;
  std::string url = "ws://localhost:8080"; // ????? URL
  std::string response;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "Error: " << res << std::endl;
      std::cerr << "curl_easy_perform failed: " << curl_easy_strerror(res) << std::endl;
    } else {
      // ?? JSON
      std::cout << &response << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  return 0;
}
