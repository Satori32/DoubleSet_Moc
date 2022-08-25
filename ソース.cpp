#include <iostream>
#include <vector>
#include <map>

#include <string>
#include <cstdint>

//this is nearest to MultiSet library.

template <class K , class T>
class DoubleSet {
public:
	typedef std::map<K, std::vector<T>> DS;
	DoubleSet() {}
	DoubleSet(const std::initializer_list<std::pair<K,std::vector<T>>>& In):D(In.begin(),In.end()){}

	bool Empty() {
		return D.empty();
	}

	typename DS::iterator begin() {
		return D.begin();
	}
	typename DS::iterator end() {
		return D.end();
	}

	std::vector<T>& operator[](const K& In) {
		return D[In];
	}
	std::size_t Size() {
		return D.size();
	}

	bool Clear() {
		D.clear();
		return true;
	}

	bool Erase(typename DS::iterator it) {
		D.erase(it);
		return true;

	}

	DS& Find(const K& In) {
		return D.find(In);
	}
protected:
	std::map<K, std::vector<T>> D;
};

int main() {
	DoubleSet<std::string, std::uint32_t> X = { {"hoge",{1,2,3}} };

	X["MOge"].push_back('H');

	return 0;
}