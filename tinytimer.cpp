// MIT License
//
// Copyright (c) 2024 Cary Woods
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// Function to get the current timestamp as a string
string get_current_timestamp() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    char buffer[26];
    ctime_r(&now_time, buffer); // Use ctime_r for thread-safe timestamp conversion on Linux
    buffer[24] = '\0'; // Remove the newline character
    return string(buffer);
}

int main() {
    // Retrieve the hostname using gethostname() for better compatibility
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        cerr << "Error: Unable to retrieve hostname." << endl;
        return 1;
    }
    
    string log_file_name = string(hostname) + "_tiny_timer.log";
    ofstream log_file(log_file_name, ios::app);
    
    if (!log_file.is_open()) {
        cerr << "Error: Unable to open log file." << endl;
        return 1;
    }
    
    cout << "Tiny Timer is running. Writing to log file: " << log_file_name << endl;
    
    while (true) {
        // Get current timestamp and write to log file
        string timestamp = get_current_timestamp();
        log_file << "Timestamp: " << timestamp << endl;
        log_file.flush();
        
        // Wait for 5 minutes
        this_thread::sleep_for(chrono::minutes(5));
    }
    
    log_file.close();
    return 0;
}
