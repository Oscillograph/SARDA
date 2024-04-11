#ifndef SARDELKA_TRACK_SIGNAL_TYPE_H
#define SARDELKA_TRACK_SIGNAL_TYPE_H

#include <include/core/proto-core.h>
#include <include/types/math.h>
#include <include/modules/config.h>

namespace SARDELKA
{
	// fwd
	struct TrackSignal
	{
		std::vector<std::complex<double>> data;
		
		TrackSignal(unsigned int size = 0, const std::complex<double>& value = {0, 0});
		~TrackSignal();
		
		void Generate(const std::vector<precision>& slowTime, precision fastTimeDelta, const GeneralConfiguration& config);
	};
	
	// implementation
	TrackSignal::TrackSignal(unsigned int size, const std::complex<double>& value)
	{
		data.resize(size);
		std::fill(data.begin(), data.end(), value);
	}
	
	TrackSignal::~TrackSignal()
	{}
	
	void Generate(const std::vector<precision>& slowTime, precision fastTimeDelta, const GeneralConfiguration& config)
	{}
}

#endif
