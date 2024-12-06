#include <iostream>
#include <vector>
#include <cmath>

#define TARGET_RESULT 200

void findExpression(std::vector<int>& arr, int number, int currentResult) {
    if (number < 0) {
        if (currentResult == TARGET_RESULT) {
            for (size_t i = 0; i < arr.size(); ++i) {
                std::cout << (arr[i] >= 0 ? '+' : '-') << std::abs(arr[i]);
            }
            std::cout << " = " << TARGET_RESULT << "\n";
        }
        return;
    }

    arr.push_back(number);
    findExpression(arr, number - 1, currentResult + number);

    arr.back() = -number;
    findExpression(arr, number - 1, currentResult - number);

    if (arr.size() > 1) {
        int last = arr.back();
        arr.pop_back();

        if (arr.back() > 0) {
            arr.back() = arr.back() * 10 + number;
        } else {
            arr.back() = arr.back() * 10 - number;
        }
        findExpression(arr, number - 1, currentResult - last + arr.back());

        arr.back() /= 10;
        arr.push_back(last);
    }

    arr.pop_back();
}

int main() {
    std::vector<int> arr;

    findExpression(arr, 9, 0);

    return 0;
}
