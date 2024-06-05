#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#pragma once

#define LOG_DURATION(nameOfCode) LogDuration logDuration(nameOfCode)

class LogDuration{
public:
    LogDuration(string nameOfCode) : start(steady_clock::now()), nameOfCode_(nameOfCode) {}

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cout << "Duration of execution " << nameOfCode_ << ": " << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    }
private:
    steady_clock::time_point start;
    string nameOfCode_;

};