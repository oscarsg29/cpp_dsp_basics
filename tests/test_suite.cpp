#include "dsp/test_runner.h"
#include "dsp/sine_oscillator.hpp"

#include <cmath>

namespace {

bool near(float actual, float expected) {
    return std::fabs(actual - expected) < 0.0001f;
}

bool starts_at_zero_and_advances_one_cycle() {
    dsp::SineOscillator oscillator(4.0f, 1.0f);
    return near(oscillator.next(), 0.0f) &&
           near(oscillator.next(), 1.0f) &&
           near(oscillator.next(), 0.0f) &&
           near(oscillator.next(), -1.0f) &&
           near(oscillator.next(), 0.0f);
}

bool amplitude_scales_output() {
    dsp::SineOscillator oscillator(4.0f, 1.0f, 0.25f);
    oscillator.next();
    return near(oscillator.next(), 0.25f);
}

bool reset_restores_initial_phase() {
    dsp::SineOscillator oscillator(4.0f, 1.0f);
    oscillator.next();
    oscillator.next();
    oscillator.reset();
    return near(oscillator.next(), 0.0f) && near(oscillator.next(), 1.0f);
}

}  // namespace

extern "C" int dsp_run_tests(dsp_test_reporter report, void* context) {
    struct TestCase {
        const char* name;
        bool (*run)();
    };
    const TestCase tests[] = {
        {"sine completes one cycle", starts_at_zero_and_advances_one_cycle},
        {"amplitude scales output", amplitude_scales_output},
        {"reset restores phase", reset_restores_initial_phase},
    };

    int failures = 0;
    for (const auto& test : tests) {
        const bool passed = test.run();
        failures += !passed;
        if (report != nullptr) {
            report(test.name, passed ? 1 : 0, context);
        }
    }
    return failures;
}
