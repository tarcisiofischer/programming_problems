#include <iostream>

int total;
int star[12];
const int total_clean_circles = 12;
int next_circle[total_clean_circles] = {1, 2, 3, 4, 6, 9, 11, 8, 5, 7, 10, 0};
int next_circle_index;
int next_possible_value[total_clean_circles] = {};

bool rule1() { return star[1] + star[2] + star[3] + star[4]  == 26; }
bool rule2() { return star[4] + star[6] + star[9] + star[11] == 26; }
bool rule3() { return star[1] + star[5] + star[8] + star[11] == 26; }
bool rule4() { return star[7] + star[8] + star[9] + star[10] == 26; }
bool rule5() { return star[0] + star[3] + star[6] + star[10] == 26; }
bool rule6() { return star[0] + star[2] + star[5] + star[7]  == 26; }

bool used_values[12];
int use_value(int value) {
	used_values[value] = true;
	return value;
}

void unuse_value(int value) {
	used_values[value] = false;
}

void solve() {
	if(next_circle_index == 4 && !rule1()) return;
	if(next_circle_index == 7 && !rule2()) return;
	if(next_circle_index == 9 && !rule3()) return;
	if(next_circle_index == 11 && !rule4()) return;
	if(rule1() && rule2() && rule3() && rule4() && rule5() && rule6()) {
		for(int i = 0; i < 12; i++)
			std::cout << star[i] << ", ";
		std::cout << std::endl;
		total++;
		return;
	}
	if(next_circle_index == total_clean_circles) return;

	for(int i = 1; i <= 12; i++) {
		if(used_values[i]) continue;
		star[next_circle[next_circle_index]] = use_value(i);
		next_circle_index++;
		solve();
		next_circle_index--;
		unuse_value(i);
	}
}

int main() {
	for(int i = 0; i < 12; i++) used_values[i] = false;
	total = 0;

	next_circle_index = 0;
	solve();

	std::cout << total << std::endl;
}

