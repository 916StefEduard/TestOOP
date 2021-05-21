#include <sstream>
#include "repository.h"
#include <fstream>
#include <algorithm>

using namespace std;
void repository::add(vegetable v){
    array.push_back(v);
}

const vector<vegetable> &repository::get_vegetables() const{
    return array;
}
std::vector<string> split_string(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

std::vector<vegetable> repository::get_vegetables_with_family(const string& family){
    std::vector<vegetable> v;
    for(auto &element:array){
        if(element.family==family){
            v.push_back(element);
        }
    }
    return v;
}

void repository::sort(vector<string> families){
    std::sort(families.begin(),families.end(),[](const string& element1,const string& element2){
        return element1<element2;
    });
}

void repository::load_data(){
      fstream file;
      vegetable v;
      int i;
      file.open("../data/data.txt");
      if(file.is_open()){
          string line;
          while(getline(file,line)){
           std::vector<string> strings=split_string(line,';');
           i=0;
           while(i<strings.size()){
                v.family=strings[0];
                v.name=strings[1];
                v.parts=strings[2];
               i++;
           }
           repository::add(v);
          }
          file.close();
      }
}
