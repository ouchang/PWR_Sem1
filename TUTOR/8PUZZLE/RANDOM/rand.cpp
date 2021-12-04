#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <random>
#include <cmath>
using namespace std;

int main() {
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch());

    unsigned int c1;

    
    cout << chrono::steady_clock::now().time_since_epoch().count() << endl;

    uint64_t timeSinceEpocSeconds = std::chrono::duration_cast<std::chrono::seconds>(
    std::chrono::system_clock::now().time_since_epoch()
).count();

    cout << timeSinceEpocSeconds << endl;

    uint64_t timeSinceEpocMiliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch()
).count();
    cout << timeSinceEpocMiliSeconds << endl;

uint64_t timeSinceEpocMicroSeconds = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::system_clock::now().time_since_epoch()
).count();
    cout << timeSinceEpocMicroSeconds << endl;

}
