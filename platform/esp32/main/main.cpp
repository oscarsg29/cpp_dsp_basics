#include "dsp/test_runner.h"

#include <cstdio>
#include <cstdlib>

extern "C" void app_main(void) {
    const int failures = dsp_run_tests(
        [](const char* name, int passed, void*) {
            std::printf("%s %s\n", passed ? "PASS" : "FAIL", name);
        },
        nullptr);
    std::printf("DSP tests: %d failure(s)\n", failures);
    if (failures != 0) {
        std::abort();
    }
}
