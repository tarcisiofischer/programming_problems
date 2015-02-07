#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

namespace {
	static const int max_size = 100 * 50;
}

template<unsigned int MAX_SIZE>
class BigNum
{
public:

	BigNum(const std::string &value)
	{
		unsigned int i = value.size() - 1;
		for (const char &c : value) {
			_value[i] = c - 48;
			--i;
		}
		_size = value.size();
	}

	BigNum operator+(const BigNum& other)
	{
		auto lower_size = std::min(_size, other._size);
		auto higher_size = std::max(_size, other._size);
		std::stringstream result_stream;
		auto remainder = 0;
		int i = 0;
		for (i = 0; i < lower_size; ++i) {
			auto partial_sum = _value[i] + other._value[i] + remainder;
			result_stream << partial_sum % 10;
			remainder = partial_sum / 10;
		}

		const auto &k = (_size > other._size) ? *this : other;
		for (; i < higher_size; ++i) {
			auto partial_sum = k._value[i] + remainder;
			result_stream << partial_sum % 10;
			remainder = partial_sum / 10;
		}

		if (remainder > 0) {
			result_stream << remainder;
			++i;
		}

		auto result = result_stream.str();
		std::reverse(std::begin(result), std::end(result));
		return BigNum(result);
	}

	friend std::ostream &operator<<(std::ostream &out, const BigNum<MAX_SIZE> &bignum)
	{
		for (auto i = bignum._size - 1; i >= 0; --i) {
			out << static_cast<char>(bignum._value[i] + 48);
		}
		return out;
	}

private:
	char _value[MAX_SIZE];
	int _size;
};

int main()
{
	std::string line;
	BigNum<max_size> total("0");
	while (std::getline(std::cin, line))
	{
		BigNum<max_size> next_value(line);
		total = total + next_value;
	}
	std::cout << total << "\n";
	return 0;
}
