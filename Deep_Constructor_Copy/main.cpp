#include <iostream>

using namespace std;

class Deep {
private:
	int *data;
public:
	void set_data_value(int d) { *data=d;};
	int get_data_value(){return *data;};
	// Constructor
	Deep(int d);
	// Copy Constructor
	Deep(const Deep &source);
	//Destructor
	~Deep();
	
};

Deep::Deep(int d){
	data = new int;
	*data = d;
};

Deep::Deep(const Deep &source)
: Deep{*source.data}
{
//		data = new int;
//		*data = *source.data;
	cout << "Copy constructor - Deep copy" << endl;
};

Deep::~Deep(){
	delete data;
	cout << "Destructor freeing data" << endl;
};

void display_Deep(Deep s){
	cout << s.get_data_value() << endl;
};

int main(){

	Deep obj1 {100};
	display_Deep(obj1);
	Deep obj2 {obj1};
	obj2.set_data_value(1000);
	display_Deep(obj2);
	// No crash occurs when destructor call attempt made.
	
	return 0;
};