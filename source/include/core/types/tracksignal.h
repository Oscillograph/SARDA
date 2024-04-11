#ifndef SARDELKA_TRACK_SIGNAL_H
#define SARDELKA_TRACK_SIGNAL_H

#include <include/core/proto-core.h>

namespace SARDELKA
{
	struct TrackSignal
	{
		std::vector<std::pair<double, double>> data;
	};
}

#endif
