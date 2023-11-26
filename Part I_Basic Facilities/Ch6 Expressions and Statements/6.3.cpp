// Exercise 6.3
/*
		Read a sequence of possibly whitespace-separated (name,value) pairs, where the name is a
		single whitespace-separated word and the value is an integer or a floating-point value. Compute
		and print the sum and mean for each name and the sum and mean for all names
	
*/


#include<iostream>
#include<vector>
#include<string>

typedef std::vector<float> array;
typedef std::vector<float>::const_iterator const_it;
typedef std::string str;

struct Pair
{
	friend std::ostream& operator<<(std::ostream&, const Pair&);
public:

	Pair&        set_name(const std::string&);
	Pair&		 push_back(float);

	const str&	 get_name() const;
	const array& get_values() const;
	array::size_type count() const;

	float		 sum() const;
	float        mean() const;

private:
	
	str     name;
	array   values;

};

int main() {

	std::vector<Pair*> users;
	str name;

	std::cout << "name(EOF to exit): ";
	while (std::cin >> name) {
		
		Pair* current_user = new Pair();
		current_user->set_name(name);

		float val;

		std::cout << "value(-1 to exit): ";

		while (std::cin >> val && val != -1) {
			current_user->push_back(val);
		}

		users.push_back(current_user);
		std::cout << "\nname(EOF to exit): ";
	}

	float total = float();

	std::cout << std::endl;
	for (const Pair* user : users) {
		std::cout << *user << "\n\n";

		total += user->sum();
	}
	std::cout << "Total: " << total
		<< "; Mean: " << (total / users.size() )<< std::endl;

	for (array::size_type i = 0, size = users.size(); i < size; ++i) {
		delete users[i];
	}

	return 0;
	
}


Pair& Pair::set_name(const std::string& nm) { name = nm; return *this; }
Pair& Pair::push_back(float val) { values.push_back(val); return *this; }

const str& Pair::get_name() const { return name; }
const array& Pair::get_values() const { return values; }
array::size_type Pair::count() const { return values.size(); }

float Pair::sum() const {
	
	float result = float();

	const_it cbeg = values.cbegin();
	const_it cend =  values.cend();

	while (cbeg != cend) { result += *cbeg++; }
	
	return result;
}

float Pair::mean() const {

	float total = float();
	int   nelem = values.size();

	const_it cbeg = values.cbegin();
	const_it cend = values.cend();

	while (cbeg != cend) { total += *cbeg++; }

	return total / nelem;

	
}

std::ostream& operator<<(std::ostream& out, const Pair& rhs) {

	out << "Name: " << rhs.name
		<< "\nValues: ";

	for (const_it it = rhs.values.cbegin(), cend = rhs.values.cend();
		it != cend;) {

		out << *it << (++it != cend ? ", " : "\n");
	}

	out << "Sum: " << rhs.sum()
		<< "\nMean: " << rhs.mean();

	return out;
}