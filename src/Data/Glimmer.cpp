#include "Glimmer.h"

//==============================================================================
Glimmer::Glimmer() {
  // Empty constructor
}

//==============================================================================
Glimmer::~Glimmer() {
  // Empty destructor
}

void Glimmer::prepare(const float &sampleRate, const int &samplesPerBlock,
                      const int &numChannels) {
  // Set values to member variables ===============
  mSampleRate = sampleRate;
  mSamplesPerBlock = samplesPerBlock;
  mNumChannels = numChannels;
}

AudioBuffer<float> Glimmer::panner(AudioBuffer<float> &buffer,
                                   const float *leftInput,
                                   const float *rightInput) {
  for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
    float rightSample = rightInput[sample];
    float gainFactor = 4;
    rightSample *= gainFactor;
    buffer.setSample(1, sample, rightSample);
  }

  return buffer;
}

void Glimmer::process(juce::AudioBuffer<float> &buffer) {
  // separate left and right channel inputs
  const float *leftInput = buffer.getReadPointer(0);
  const float *rightInput = buffer.getReadPointer(0);

  if (buffer.getNumChannels() == 2)
    rightInput = buffer.getReadPointer(1);
  else if (buffer.getNumChannels() > 2)
    return;

  buffer = panner(buffer, leftInput, rightInput);
}
