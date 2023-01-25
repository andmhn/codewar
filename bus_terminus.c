#include <stddef.h>
#include <stdio.h>

int bus_terminus(size_t nb_stops, const short bus_stops[nb_stops][2]) {
	int enters = 0;
	int reaches = 0;
	int terminus = 0;

	for (size_t i = 0; i < nb_stops; i++) {
		enters += bus_stops[i][0];
		reaches += bus_stops[i][1];
	}
	terminus = enters - reaches;
	return terminus;
}

void sample_test(int ans, size_t size, const short log[size][2]) {
	if (ans == bus_terminus(size, log))
		printf("Passed\n");
	else
		printf("Not Passed\n");
}

int main() {
	sample_test(5, 3, ((const short[][2]){{10, 0}, {3, 5}, {5, 8}}));
	sample_test(17, 6, ((const short[][2]){{3, 0}, {9, 1}, {4, 10}, {12, 2}, {6, 1}, {7, 10}}));
	sample_test( 21, 6, ((const short[][2]){{3, 0}, {9, 1}, {4, 8}, {12, 2}, {6, 1}, {7, 8}}));
	sample_test(0, 1, ((const short[][2]){{0, 0}}));
}
