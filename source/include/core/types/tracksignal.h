#ifndef SARDA_TRACK_SIGNAL_H
#define SARDA_TRACK_SIGNAL_H

#include <include/core/proto-core.h>

namespace sarda
{
	struct TrackSignal
	{
		std::vector<std::pair<double, double>> data;
	};
}

#endif
