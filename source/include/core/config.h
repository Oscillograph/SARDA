#ifndef SARDA_CONFIG_H
#define SARDA_CONFIG_H

#include <include/core/core.h>

namespace sarda
{
	struct Vec3
	{
		double x = 0.0; // meters
		double y = 0.0; // meters
		double z = 0.0; // meters
	};
	
	enum class CarrierMovement : int 
	{
		StopAndGo			= 0,
		Continuous			= 1
	};
	
	// TODO: design configuration storage architecture
	struct TransmitterConfiguration
	{
		double transmitPower = 1.0; // Watts
		Vec3 position = {0.0, 0.0, 0.0};
	};
	
	struct ReceiverConfiguration
	{
		double detectionLevel = 0.0000000001; // Watts
		Vec3 position = {0.0, 0.0, 0.0};
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
		double carrierFrequency = 10000000000; // Hz
		double LFMBase = 100000000; // Hz
		double LFMInterval = 0.001; // seconds
		double LFMSpeed = LFMBase / LFMInterval; // Hz / seconds
	};
	
	struct MediumConfiguration
	{
		double propagationFactor1 = 1.0; // signal weakens by this factor while propagating the medium
		double propagationFactor2 = 1.0; // signal weakens by this factor while propagating the medium
	};
	
	struct TransmittingConfiguration
	{
		double silenceTime = 0.0f; // 0.0 means continuous wave 
	};
	
	struct RecordingConfiguration
	{
		double slowTimeDelta = 0.01; // seconds
		double fastTimeDelta = 0.0000001; // seconds
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
