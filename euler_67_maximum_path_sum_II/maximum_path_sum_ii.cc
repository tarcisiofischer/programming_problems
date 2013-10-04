#include <iostream>
#include <cstdlib>

class Triangle {
private:
	int* _triangle_structure;
	int _depth;
	bool _should_cleanup;

public:
	Triangle(int depth) : _depth(depth), _should_cleanup(true) {
		int structure_size = depth * (depth + 1) / 2;
		_triangle_structure = (int *)malloc(sizeof(int) * structure_size);
	}

	Triangle(int depth, int* triangle_structure)
	: _depth(depth), _triangle_structure(triangle_structure), _should_cleanup(false) {}
	
	~Triangle() {
		if(_should_cleanup) free(_triangle_structure);
	}
	
	int* get_row(int row_number) {
		int row_index = row_number * (row_number + 1) / 2;
		return &_triangle_structure[row_index - row_number];
	}

	int depth() {
		return _depth;
	}
};

inline int max(int a, int b) { return a > b ? a : b; }

Triangle* triangle_sum_aux(Triangle* partial_sum_triangle, Triangle* triangle, int row) {
	if(row == triangle->depth() + 1)
		return partial_sum_triangle;
	
	int column = 0;
	int max_column = row;
	int* sum_row = partial_sum_triangle->get_row(row);
	int* prev_row = partial_sum_triangle->get_row(row - 1);
	int* original_row = triangle->get_row(row);

	sum_row[column] = prev_row[column] + original_row[column];
	for(column = 1; column < max_column - 1; column++)
		sum_row[column] = max(prev_row[column - 1], prev_row[column]) + original_row[column];
	sum_row[column] = prev_row[column - 1] + original_row[column];

	return triangle_sum_aux(partial_sum_triangle, triangle, row + 1);
}

Triangle* triangle_sum(Triangle* triangle) {
	Triangle* partial_sum_triangle = new Triangle(triangle->depth());
	int* first_row = partial_sum_triangle->get_row(1);
	*first_row = *triangle->get_row(1);
	return triangle_sum_aux(partial_sum_triangle, triangle, 2);
}

int find_max(int* from, int size) {
	int max = *from;
	for(int* i = from + 1; i < from + size; i++)
		if(*i > max) max = *i;
	return max;
}

int max_path(Triangle* triangle) {
	Triangle* partial_sum_triangle = triangle_sum(triangle);
	int depth = partial_sum_triangle->depth();
	return find_max(partial_sum_triangle->get_row(depth), depth);
}

int main() {
	const int depth = 100;
	const int total_values = depth * (depth + 1) / 2;
	int values[total_values];
	
	for(int i = 0; std::cin >> values[i]; i++);
	Triangle triangle(depth, values);

	std::cout << max_path(&triangle) << std::endl;
	return 0;
}
