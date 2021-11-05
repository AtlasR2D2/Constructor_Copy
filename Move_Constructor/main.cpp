#include <iostream>
#include <vector>

class Move {
private:
	//Raw Pointer
	int *data;
public:
	void set_data_value(int d) {*data=d;};
	int getdatavalue(){return *data;};
	//Constructor
	Move(int d);
	//Copy Constructor
	Move(const Move &source);
	//Move Constructor
	Move(Move &&source) noexcept;
	//Destructor
	~Move();
};

Move::Move(int d){
	data = new int;
	*data = d;
	std::cout << "Constructor for: " << d << std::endl;
};

Move::Move(const Move &source){
	data = new int;
	*data = *source.data;
	std::cout << "Deep copy of " << *source.data << std::endl;
};

// "Steal" source pointer
Move::Move(Move &&source) noexcept
	: data{source.data}{
		//Null out the source pointer
		source.data=nullptr;
		std::cout << "Move constructor - Moving resource " << *data << std::endl;
	};

Move::~Move(){
	if (data != nullptr) {
		std::cout << "Destructor freeing data for " << *data << std::endl;
	}
	else {
		std::cout << "Destructor freeing data for nullptr" << std::endl;	
	}
	delete data;
}

int main(){
	
	std::vector<Move> vec;
	std::cout << "This works" << std::endl;
	vec.push_back(Move{10});
	vec.push_back(Move{20});
	
	return 0;
}