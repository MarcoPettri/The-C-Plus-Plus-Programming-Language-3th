// Exercise 6.12
/*
		Modify the program from §6.6[3] to also compute the median.
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

	Pair& set_name(const std::string&);
	Pair& push_back(float);
	Pair& insert(const_it, const_it);

	const str& get_name() const;
	const array& get_values() const;
	array::size_type count() const;

	const_it cbegin() const;
	const_it cend()   const;

	float		 sum() const;
	float        mean() const;
	float		 median() const;

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


	Pair* all_users = new Pair();

	for (const Pair* user : users) {

		std::cout << '\n' << *user << '\n';

		all_users->insert(user->cbegin(), user->cend());
	}


	std::cout << "Total: " << all_users->sum()
		<< " ;Mean: " << all_users->mean()
		<< " ;Median: " << all_users->median() << std::endl;

	for (array::size_type i = 0, size = users.size(); i < size; ++i) {
		delete users[i];
	}

	delete all_users;

	return 0;

}


Pair& Pair::set_name(const std::string& nm) { name = nm; return *this; }
Pair& Pair::push_back(float val) { values.push_back(val); return *this; }
Pair& Pair::insert(const_it beg, const_it end) { values.insert(values.end(), beg, end); return *this; }

const str& Pair::get_name() const { return name; }
const array& Pair::get_values() const { return values; }
array::size_type Pair::count() const { return values.size(); }

const_it Pair::cbegin() const { return values.cbegin(); }
const_it Pair::cend() const { return values.cend(); }


float Pair::sum() const {

	float result = float();

	const_it cbeg = values.cbegin();
	const_it cend = values.cend();

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

float Pair::median() const {
	
	const_it begin = values.cbegin();
	const_it end = values.cend();

	if (begin == end) { return 0; }

	const_it middle = begin + (end - begin) / 2;

	// if size is odd
	if (this->values.size() % 2) {
		return *middle;
	}

	// if size is even
	return (*middle-- + *middle) / 2;
	
}

std::ostream& operator<<(std::ostream& out, const Pair& rhs) {

	out << "Name: " << rhs.name
		<< "\nValues: ";

	for (const_it it = rhs.values.cbegin(), cend = rhs.values.cend();
		it != cend;) {

		out << *it << (++it != cend ? ", " : "\n");
	}

	out << "Sum: " << rhs.sum()
		<< "\nMean: " << rhs.mean()
		<< "\nMedian: " << rhs.median();

	return out;
}