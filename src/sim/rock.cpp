
#include <sim/rock.h>

int Rock::rock_counter_ = 0;

Rock::Rock() : rid_(rock_counter_) {
	std::cout << "   Welcome Rock ! :-)) " << rid_ << std::endl;
	rock_counter_++;
}	

Rock::~Rock() {
	std::cout << "   Bye Rock :-(( " << rid_ << std::endl;
}
	
std::ostream& operator<<( std::ostream& out, const Rock& rhs){
	out << "## " << rhs.rid_ << " ##"; 
	return out;
}

