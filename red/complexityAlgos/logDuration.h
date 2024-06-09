#include <iostream>
#include <string>
#include <chrono>
#pragma once

using namespace std;

#define LOG_DURATION(nameOfCode) LogDuration logDuration(nameOfCode)

class LogDuration {
public:
    explicit LogDuration(const string& name = "")
        : name_(name)
    {
        start = std::chrono::steady_clock::now();
    }

    ~LogDuration() {
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start;
        cout << "Duration of execution " << name_ << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << endl;
    }
private:
    string name_;
    std::chrono::steady_clock::time_point start;
};