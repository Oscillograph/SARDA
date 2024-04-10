#include <include/sarda.h>

int main(int argc, char** argv) {
	SARDA_CONSOLE_CYAN("Hello, world!");
	
	// Current goal is to build a single module and then grow the app on top of it.
	// The module is a SAR TSS: track signal simulator.
	
	// The algorithm is this:
	SARDA_CONSOLE_LOG("Configuring system...");
	// 1. Get configuration of the radar: antennas, transmitter, receiver characteristics
	SARDA_CONSOLE_LOG("Load configuration: radar");
	// 2. Get configuration of the radar carrier: movement characteristics, stop-and-go, continuous movemenet
	SARDA_CONSOLE_LOG("Load configuration: radar carrier");
	// 3. Get configuration of the medium: propagation, delay, noises
	SARDA_CONSOLE_LOG("Load configuration: medium");
	// 4. Get configuration of the probing signal: waveform, frequencies, etc.
	SARDA_CONSOLE_LOG("Load configuration: signal");
	// 5. Get configuration of the transmitting process: carrier frequencies, time of silence
	SARDA_CONSOLE_LOG("Load configuration: transmission");
	// 6. Get configuration of the recording process: analog-to-digital transformations
	SARDA_CONSOLE_LOG("Load configuration: recording");
	// 7. Get configuration of physical models to process: geometrical opticals, electro-magnetic computations
	SARDA_CONSOLE_LOG("Load configuration: physics");
	SARDA_CONSOLE_LOG("System configuration complete.");
	
	// 8. Simulate the recorded signal in one go (can be paralleled)
	SARDA_CONSOLE_LOG("Simulation...");
	std::pair<double, double> data;
	data.first = 0.0;
	data.second = 1.1;
	std::complex<double> hello;
	hello.real(data.first);
	hello.imag(data.second);
	
	arma::cx_mat* ts = new arma::cx_mat(1024, 65536);
//	ts->randu();
	std::complex<double>* value;
	value = &(ts->at(100, 200));
	
	SARDA_CONSOLE_RED("x: ", data.first, "; y: ", data.second);
	SARDA_CONSOLE_RED("cx: ", value->real(), "; cy: ", value->imag());
	SARDA_CONSOLE_RED("TS Matrix size is: ", ts->size());
	SARDA_CONSOLE_TEAL("Size of double is: ", sizeof(double));
	SARDA_CONSOLE_TEAL("Size of std::complex<double> is: ", sizeof(std::complex<double>));
	delete ts;
	
	SARDA_CONSOLE_LOG("Simulation complete.");
	
	// 9. Save the result.
	SARDA_CONSOLE_LOG("Save the results...");
	SARDA_CONSOLE_LOG("Save successful.");
	// [10. Show the result.] - optional
	
	
	return 0;
}
