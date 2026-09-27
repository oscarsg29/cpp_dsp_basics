#include "dsp/test_runner.h"

#include <cstdio>

int main() {
    const int failures = dsp_run_tests(
        [](const char* name, int passed, void*) {
            std::printf("%s %s\n", passed ? "PASS" : "FAIL", name);
        },
        nullptr);
    std::printf("%s: %d failure(s)\n", failures == 0 ? "PASS" : "FAIL", failures);
    return failures == 0 ? 0 : 1;
}
