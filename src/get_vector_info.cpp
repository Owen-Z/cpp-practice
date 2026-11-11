#include <iostream>
#include <vector>

namespace vector_info {
int get_vec_min(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "Error: Vector is empty." << std::endl;
        return 0;
    }

    int min_value = vec[0];
    for (const int& num : vec) {
        if (num < min_value) {
            min_value = num;
        }
    }
    return min_value;
}

int get_vec_max(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "Error: Vector is empty." << std::endl;
        return 0;
    }

    int max_value = vec[0];
    for (const int& num : vec) {
        if (num > max_value) {
            max_value = num;
        }
    }
    return max_value;
}

double get_vec_avg(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "Error: Vector is empty." << std::endl;
        return 0;
    }

    double avg_val = 0;
    for (const int& num : vec) {
        avg_val += num;
    }
    return avg_val / static_cast<double>(vec.size());
}

}  // namespace vector_info