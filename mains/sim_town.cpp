
#include <sim/building.h>
#include <sim/dyn_array.h>
#include <sim/rock.h>


int main(int arg, char** argv) {
	std::cout << "Initialization... " << std::endl;
	DynArray<Building> street;
	std::cout << "Welcome to SimTown! Please Enter IDs (-99 to finish)" << std::endl;
	int id = -1;
	std::cin >> id;
	while (id != -99) {
		Building tmp(id,0);
		street.push_back(tmp);
		std::cin >> id;
	}
	for (int i = 0; i < street.size(); ++i) {
		std::cout << street[i] << std::endl;
	}
	if (street.size() >= 2) {
		street[0].swap_rock(street[1], 2, 4);
	}
	std::cout << "End of program" << std::endl;

	return 0;
}

