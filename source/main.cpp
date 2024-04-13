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
	
	SARDELKA::Vec3 Pt = {50.0, 1200.0, 0.0}; // the target position, meters
	SARDELKA::Vec3 S0 = {0.0, 0.0, 1000.0}; // carrier starting position, meters
	SARDELKA::Vec3 Vs = {25.0, 0.0, 0.0}; // carrier speed

	double a = (Vs.x * Vs.x - 3*SARDELKA::c * SARDELKA::c);
	double b = 2 * (Vs.x * S0.x - (Pt.x + Pt.y + Pt.z) * SARDELKA::c);
	double c = (S0.x * S0.x + S0.y* S0.y + S0.z * S0.z - (Pt.x * Pt.x + Pt.y * Pt.y + Pt.z * Pt.z));
	double D = (b * b - 4 * a * c);
	double t1 = (-b + std::sqrt(D)) / (2*a);
	double t2 = (-b - std::sqrt(D)) / (2*a);

	SARDELKA_CONSOLE_CYAN("D = ", D, ";\nt1 = ", t1, ";\nt2 = ", t2);
	SARDELKA_CONSOLE_CYAN("Or in meters:", ";\nx1 = ", t1 * Vs.x, ";\nx2 = ", t2 * Vs.x);
	
	SARDELKA_CONSOLE_LOG("Simulation complete.");
	
	// 10. Save the result.
	SARDELKA_CONSOLE_LOG("Save the results...");
	SARDELKA_CONSOLE_LOG("Save successful.");
	// [11. Show the result.] - optional
	
	
	return 0;
}
