# Audio DSP learning roadmap

Work through the stages in order. Each stage should produce a small C++ component, focused tests, and an audible or measurable result. Treat the checkboxes as completion criteria, not a fixed schedule. Start with offline sample buffers; add real-time processing after the algorithms are correct.

## 1. Samples, signals, and waveforms

- [ ] Represent sample rate, frequency, phase, amplitude, time, and mono/stereo buffers with clear units and valid ranges.
- [ ] Generate sine, square, saw, triangle, impulse, step, and noise signals; write short WAV files for listening.
- [ ] Test waveform period, amplitude bounds, phase continuity, and behavior at zero frequency and the Nyquist limit.
- [ ] Compare naive oscillators with band-limited approaches to hear and measure aliasing.
- [ ] Build a simple Eurorack-style oscillator with frequency and waveform controls.

## 2. Audio building blocks

- [ ] Implement gain, mixing, clipping/saturation, delay lines, envelopes, and basic modulation.
- [ ] Explore decibels, headroom, sample-rate conversion basics, and the difference between sample-by-sample and block processing.
- [ ] Test silence, impulses, clipping limits, channel independence, and parameter changes during playback.
- [ ] Build a tremolo or delay guitar pedal and a simple VCA/envelope patch.

## 3. Linear systems and convolution

- [ ] Study linearity, time invariance, impulse response, causality, stability, and frequency response.
- [ ] Implement direct discrete convolution and verify it using impulses and short sequences.
- [ ] Connect convolution to delay, echo, reverb, and filtering; distinguish circular from linear convolution.
- [ ] Load an impulse response (IR) and make an offline guitar cabinet convolver.

## 4. Fourier analysis: FT, DTFT, DFT, and FFT

- [ ] Understand the Fourier transform (FT) and discrete-time Fourier transform (DTFT) as models for a signal's frequency content.
- [ ] Implement a small discrete Fourier transform (DFT) and inverse DFT; check reconstruction and Parseval's relation on test signals.
- [ ] Study sampling, spectral leakage, window functions, bin spacing, phase, and zero padding.
- [ ] Implement or integrate a fast Fourier transform (FFT) and inverse FFT; compare its output and runtime with the DFT.
- [ ] Plot or inspect spectra from an oscillator, guitar recording, and cabinet IR.

## 5. FIR filters and efficient convolution

- [ ] Design finite impulse response (FIR) low-pass, high-pass, and band-pass filters using windowed-sinc methods.
- [ ] Verify impulse response, passband/stopband behavior, phase, and latency.
- [ ] Implement overlap-add or overlap-save convolution, then partitioned convolution for longer cabinet/reverb IRs.
- [ ] Build a cabinet emulator with IR selection, bypass, and wet/dry control.

## 6. IIR filters and EQ

- [ ] Implement one-pole filters and biquad infinite impulse response (IIR) low-pass, high-pass, shelf, peak, and notch filters.
- [ ] Test stability, coefficient updates, frequency response, and behavior across sample rates and extreme parameters.
- [ ] Build a guitar tone stack or parametric EQ and compare measured responses with the intended curves.
- [ ] Explore feedback, resonance, and self-oscillation for a Eurorack-style filter.

## 7. Complete audio effects

- [ ] Combine gain staging, filtering, nonlinear distortion, oversampling, and cabinet convolution into a guitar effects chain.
- [ ] Build a modulation effect such as chorus, flanger, or phaser using delay or all-pass stages.
- [ ] Build a multiband or graphic EQ with repeatable presets and parameter smoothing.
- [ ] Add offline A/B renders and listening tests alongside numerical tests.

## 8. Real-time and advanced topics

- [ ] Introduce a real-time processing interface with prepare/reset/process operations and explicit sample-rate and block-size handling.
- [ ] Keep audio processing free of allocations, locks, file I/O, and unbounded work; measure CPU use and latency.
- [ ] Explore control-rate modulation, oversampling and anti-aliasing, nonlinear waveshaping, and feedback delay networks.
- [ ] Explore short-time Fourier transform (STFT), spectral effects, and time-frequency tradeoffs.
- [ ] Prototype a Eurorack voice, a guitar pedal, and a cabinet/EQ processor using the reusable components.

## Working approach

- [ ] For each component, write tests from observable audio behavior first, then implement and refactor.
- [ ] Run the shared tests on macOS first, then run them in ESP32 or Daisy Seed firmware, or in STM32 board firmware that links the portable test library; see [TESTING.md](TESTING.md).
- [ ] Keep signal generation, DSP algorithms, file I/O, and application wiring separate; use OO boundaries where they clarify responsibilities and dependencies.
- [ ] Record a short example, measurements, and known limitations when completing each stage.
