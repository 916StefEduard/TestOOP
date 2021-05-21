#pragma once

#include <vector>
#include "../domain/domain.h"
using namespace std;

class repository{
private:
    std::vector<vegetable> array;
public:


    void add(vegetable v);
    [[nodiscard]] const vector<vegetable> &get_vegetables() const;
    void load_data();
    std::vector<vegetable> get_vegetables_with_family(const string& family);

    void sort(vector<string> families);
};