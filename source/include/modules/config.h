#ifndef SARDELKA_CONFIG_H
#define SARDELKA_CONFIG_H

#include <include/core/core.h>
#include <include/types/math.h>

namespace SARDELKA
{
	enum class CarrierMovement : int 
	{
		StopAndGo			= 0,
		Continuous			= 1
	};
	
	struct AntennaConfiguration
	{
		std::vector<precision> DNA = {1.0};
		precision gain = 1.0f;
	};
	
	// TODO: design configuration storage architecture
	struct TransmitterConfiguration
	{
		precision transmitPower = 1.0; // Watts
		Vec3 position = {0.0, 0.0, 0.0};
		AntennaConfiguration antenna;
	};
	
	struct ReceiverConfiguration
	{
		precision detectionLevel = 0.1e-9; // Watts
		Vec3 position = {0.0, 0.0, 0.0};
		AntennaConfiguration antenna;
	};
	
	struct CarrierConfiguration
	{
		CarrierMovement m_MovementMode = CarrierMovement::StopAndGo;
		Vec3 position = {0.0, 0.0, 0.0};
		Vec3 speed = {0.0, 0.0, 0.0};
		Vec3 acceleration = {0.0, 0.0, 0.0};
	};
	
	struct RadarConfiguration
	{
		TransmitterConfiguration m_Transmitter;
		ReceiverConfiguration m_Receiver;
	};
	
	struct SignalConfiguration
	{
		precision carrierFrequency = 10e9; // Hz
		precision LFMBase = 0.1e9; // Hz
		precision LFMInterval = 1e-3; // seconds
		precision LFMSpeed = LFMBase / LFMInterval; // Hz / seconds
	};
	
	struct MediumConfiguration
	{
		precision propagationFactor1 = 1.0; // signal weakens by this factor while propagating the medium
		precision propagationFactor2 = 1.0; // signal weakens by this factor while propagating the medium
	};
	
	struct TransmittingConfiguration
	{
		precision silenceTime = 0.0f; // 0.0 means continuous wave 
	};
	
	struct RecordingConfiguration
	{
		precision slowTimeDelta = 10e-2; // seconds
		precision fastTimeDelta = 0.1e-6; // seconds
	};
	
	struct PhysicsConfiguration
	{
		bool optics = true;
	};
	
	struct GeneralConfiguration
	{
		RadarConfiguration m_Radar;
		CarrierConfiguration m_Carrier;
		MediumConfiguration m_Medium;
		SignalConfiguration m_Signal;
		TransmittingConfiguration m_Transmitting;
		RecordingConfiguration m_Recording;
		PhysicsConfiguration m_Physics;
	};
	
	GeneralConfiguration GlobalConfigurationStorage;
	
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
	// 8. Load scene objects
	void LoadSceneObjects();
}

#endif
