#include <JuceHeader.h>

using namespace juce;

class KlangFalter : public AudioPluginInstance {
public:
  KlangFalter() {}

  void prepareToPlay (double sampleRate, int samplesPerBlock) override {}
  void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer) override {}

  const String getName() const override { return "KlangFalter"; }
  bool acceptsMidi() const override { return true; }
  bool producesMidi() const override { return false; }
  bool isMidiEffect() const override { return false; }
  int getNumPrograms() override { return 1; }
  int getCurrentProgram() override { return 0; }
  void setCurrentProgram (int index) override {}
  const String getProgramName (int index) override { return {}; }
  void changeProgramName (int index, const String& newName) override {}

private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KlangFalter)
};

static const EffectDescription desc = {
  "KlangFalter",
  "Simple Audio Convolution Plugin",
  "HiFi-LoFi",
  "https://hifi-lofi.com",
  0, 0, nullptr, 0,
  nullptr
};

AudioProcessor* createPluginFilter() { return new KlangFalter(); }

// This creates an instance of the KlangFalter plugin
// and starts it running.
START_PLUGIN_FACTORY (KlangFalter)

