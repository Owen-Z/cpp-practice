#include <iostream>
#include <vector>

#include "practice/get_vector_info.h"

int main() {
    std::vector<int> vec{};
    int x = 0;

    while (std::cin >> x) {
        vec.push_back(x);
    }

    std::cout << "avg: " << vector_info::get_vec_avg(vec)
              << " max: " << vector_info::get_vec_max(vec)
              << " min: " << vector_info::get_vec_min(vec) << std::endl;
}
