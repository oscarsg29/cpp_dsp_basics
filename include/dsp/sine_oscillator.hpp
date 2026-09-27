#ifndef DSP_SINE_OSCILLATOR_HPP
#define DSP_SINE_OSCILLATOR_HPP

#include <cmath>

namespace dsp {

class SineOscillator {
public:
    SineOscillator(float sample_rate, float frequency, float amplitude = 1.0f)
        : phase_(0.0f), phase_increment_(frequency / sample_rate), amplitude_(amplitude) {}

    float next() {
        constexpr float two_pi = 6.2831853071795864769f;
        const float sample = amplitude_ * std::sin(two_pi * phase_);
        phase_ += phase_increment_;
        if (phase_ >= 1.0f) {
            phase_ -= 1.0f;
        }
        return sample;
    }

    void reset() { phase_ = 0.0f; }

private:
    float phase_;
    float phase_increment_;
    float amplitude_;
};

}  // namespace dsp

#endif
