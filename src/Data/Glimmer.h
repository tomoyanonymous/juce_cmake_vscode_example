#pragma once

#include <JuceHeader.h>

class Glimmer {
public:
  Glimmer();
  ~Glimmer();
  void prepare(const float &sampleRate, const int &samplesPerBlock,
               const int &numChannels);
  void process(AudioBuffer<float> &buffer);
  AudioBuffer<float> panner(AudioBuffer<float> &buffer, const float *leftInput,
                            const float *rightInput);

private:
  // initialise member variables
  float mSampleRate = 44100.f;
  int mSamplesPerBlock = 512;
  int mNumChannels = 2;
};