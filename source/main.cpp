#include <include/sardelka.h>

int main(int argc, char** argv) {
	SARDELKA_CONSOLE_CYAN("Hello, world!");
	
	// Current goal is to build a single module and then grow the app on top of it.
	// The module is a SAR TSS: track signal simulator.
	
	// The algorithm is this:
	SARDELKA_CONSOLE_LOG("Configuring system...");
	// 1. Get configuration of the radar: antennas, transmitter, receiver characteristics
	SARDELKA_CONSOLE_LOG("Load configuration: radar");
	// 2. Get configuration of the radar carrier: movement characteristics, stop-and-go, continuous movemenet
	SARDELKA_CONSOLE_LOG("Load configuration: radar carrier");
	// 3. Get configuration of the medium: propagation, delay, noises
	SARDELKA_CONSOLE_LOG("Load configuration: medium");
	// 4. Get configuration of the probing signal: waveform, frequencies, etc.
	SARDELKA_CONSOLE_LOG("Load configuration: signal");
	// 5. Get configuration of the transmitting process: carrier frequencies, time of silence
	SARDELKA_CONSOLE_LOG("Load configuration: transmission");
	// 6. Get configuration of the recording process: analog-to-digital transformations
	SARDELKA_CONSOLE_LOG("Load configuration: recording");
	// 7. Get configuration of physical models to process: geometrical opticals, electro-magnetic computations
	SARDELKA_CONSOLE_LOG("Load configuration: physics");
	// 8. Load scene objects
	SARDELKA_CONSOLE_LOG("Load scene objects");
	SARDELKA_CONSOLE_LOG("System configuration complete.");
	
	// 9. Simulate the recorded signal in one go (can be paralleled)
	SARDELKA_CONSOLE_LOG("Simulation...");
	SARDELKA::GlobalConfigurationStorage;
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
	
	SARDELKA_CONSOLE_RED("x: ", data.first, "; y: ", data.second);
	SARDELKA_CONSOLE_RED("cx: ", value->real(), "; cy: ", value->imag());
	SARDELKA_CONSOLE_RED("TS Matrix size is: ", ts->size());
	SARDELKA_CONSOLE_TEAL("Size of double is: ", sizeof(double));
	SARDELKA_CONSOLE_TEAL("Size of std::complex<double> is: ", sizeof(std::complex<double>));
	delete ts;
	
	SARDELKA_CONSOLE_LOG("Simulation complete.");
	
	// 10. Save the result.
	SARDELKA_CONSOLE_LOG("Save the results...");
	SARDELKA_CONSOLE_LOG("Save successful.");
	// [11. Show the result.] - optional
	
	
	return 0;
}
