#ifndef SARDA_CONFIG_H
#define SARDA_CONFIG_H

#include <include/core/core.h>

namespace sarda
{
	// TODO: design configuration storage architecture
	struct GeneralConfiguration
	{
		double transmitPower = 1.0; // Watts
		double carrierFrequency = 10'000'000'000; // Hz
	};
	
	// 1. Get configuration of the radar: antennas, transmitter, receiver characteristics
	void GetConfig_Radar();
	// 2. Get configuration of the radar carrier: movement characteristics, stop-and-go, continuous movemenet
	void GetConfig_Carrier();
	// 3. Get configuration of the medium: propagation, delay, noises
	void GetConfig_Medium();
	// 4. Get configuration of the probing signal: waveform, frequencies, etc.
	void GetConfig_Signal();
	// 5. Get configuration of the transmitting process: carrier frequencies, time of silence
	void GetConfig_Transmitting();
	// 6. Get configuration of the recording process: analog-to-digital transformations
	void GetConfig_Recording();
	// 7. Get configuration of physical models to process: geometrical opticals, electro-magnetic computations
	void GetConfig_Physics();
}

#endif
