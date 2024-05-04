#include "Glimmer.h"

//==============================================================================
Glimmer::Glimmer()
{
  // Empty constructor
}

//==============================================================================
Glimmer::~Glimmer()
{
  // Empty destructor
}

void Glimmer::prepare(const float &sampleRate, const int &samplesPerBlock,
                      const int &numChannels)
{
  // Set values to member variables ===============
  mSampleRate = sampleRate;
  mSamplesPerBlock = samplesPerBlock;
  mNumChannels = numChannels;
}

AudioBuffer<float> Glimmer::panner(AudioBuffer<float> &buffer,
                                   const float *leftInput,
                                   const float *rightInput)
{

  const int changeMarker = 44100;
  const int defaultGain = 0;

  for (int sample = 0; sample < buffer.getNumSamples(); sample++)
  {
    if (mSamplesCounter < changeMarker)
    {
      // reset gain of leftside
      float leftSample = leftInput[sample];
      leftSample = defaultGain;
      buffer.setSample(0, sample, leftSample);

      float rightSample = rightInput[sample];
      float gainFactor = 2;
      rightSample *= gainFactor;
      buffer.setSample(1, sample, rightSample);
    }
    else
    {
      // reset gain of rightside
      float rightSample = rightInput[sample];
      rightSample = defaultGain;
      buffer.setSample(1, sample, rightSample);

      // double gain of leftside
      float leftSample = leftInput[sample];
      float gainFactor = 2;
      leftSample *= gainFactor;
      buffer.setSample(0, sample, leftSample);
    }
    // when sample counter is greater than length of buffer x 2 reset sample
    // counter
    if (mSamplesCounter == changeMarker * 2)
    {
      mSamplesCounter = 0;
    }
    mSamplesCounter++;
  }
  return buffer;
}

void Glimmer::process(juce::AudioBuffer<float> &buffer)
{
  // separate left and right channel inputs
  const float *leftInput = buffer.getReadPointer(0);
  const float *rightInput = buffer.getReadPointer(0);

  if (buffer.getNumChannels() == 2)
    rightInput = buffer.getReadPointer(1);
  else if (buffer.getNumChannels() > 2)
    return;

  buffer = panner(buffer, leftInput, rightInput);
}
