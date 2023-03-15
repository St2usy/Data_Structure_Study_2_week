#include <ctime>
#include "BankSimulator.h"

int main() {
	srand((unsigned int)time(NULL)); // 난수생성을위함
	BankSimulator sim;
	sim.readSimulationParameters();
	sim.run();
	sim.printStat();

	return 0;
}