#ifndef DSP_TEST_RUNNER_H
#define DSP_TEST_RUNNER_H

#ifdef __cplusplus
extern "C" {
#endif

// A zero return value means every test passed. The callback may be null.
typedef void (*dsp_test_reporter)(const char* name, int passed, void* context);
int dsp_run_tests(dsp_test_reporter report, void* context);

#ifdef __cplusplus
}
#endif

#endif
