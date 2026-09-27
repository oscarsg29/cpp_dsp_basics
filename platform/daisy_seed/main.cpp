#include "daisy_seed.h"
#include "dsp/test_runner.h"

int main() {
    daisy::DaisySeed seed;
    seed.Init();
    seed.StartLog(true);

    const int failures = dsp_run_tests(
        [](const char* name, int passed, void* context) {
            auto* board = static_cast<daisy::DaisySeed*>(context);
            board->PrintLine("%s %s", passed ? "PASS" : "FAIL", name);
        },
        &seed);
    seed.PrintLine("DSP tests: %d failure(s)", failures);
    seed.SetLed(failures != 0);
    while (true) {
        daisy::System::Delay(1000);
    }
}
