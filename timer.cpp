#include <iostream>
#include <chrono>
#include <unistd.h>

class Timer {
public:
    using clock_t = std::chrono::steady_clock;
    using timepoint_t = clock_t::time_point;
public:
    Timer() : m_begin(clock_t::now()), duration(0) {
    }

    ~Timer() {
        this->stop();
        std::cout << duration << " milliseconds" << std::endl;
    }

    void stop() {
        auto end = clock_t::now();
        duration += std::chrono::duration_cast<std::chrono::milliseconds> (end - m_begin).count();
    }

    void go() {
        m_begin = clock_t::now();
    }
private:
    timepoint_t m_begin;
    int duration;
};

int main() {
    Timer t;
    sleep(5);
    t.stop();
    sleep(1);
    t.go();
    sleep(3);
    return 0;
}
