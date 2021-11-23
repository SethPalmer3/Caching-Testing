#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}

struct ColorPoint** create2DArray(int n) {
	// Array to hold a pointer to the beginning of each row
	struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i) {
		// Array to hold each row
		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
		for (int j = 0; j < n; ++j) {
			// Init the ColorPoint struct
			points[i][j].a = rand() + 1;
			points[i][j].r = rand() + 1;
			points[i][j].g = rand() + 1;
			points[i][j].b = rand() + 1;
		}
	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n) {
	for (int i = 0; i < n; ++i) {
		free(points[i]);
	}
	free(points);
}



int main(void) {
	int n = 2048;
	int iterations = 1;
	long sum = 0.0;
	struct ColorPoint **point = create2DArray(n);

	/*Profile function f*/
	clock_t start = clock();
	//F is the slow function
	for (int i = 0; i < iterations; ++i)
	{
		sum = f(point, n);
		//This function is about 5 times slower because it has to
		//fetch the structs every time it wasnts to add add its values to the sum
	}
	clock_t end = clock();
	printf ("Total time = %f seconds\n",((double) (end - start)) / CLOCKS_PER_SEC);

	/*Profile function G*/
	start = clock();
	//G is te faster function
	for (int i = 0; i < iterations; ++i)
	{
		sum = g(point, n);
		//This function is faster because it can store adjecent data
		//points in one block or even just one cache level so a good 
		//chunck of some of the ColorPoints are already in the cache
		//ready to be retrieved
	}
	end = clock();
	printf ("Total time = %f seconds\n",((double) (end - start)) / CLOCKS_PER_SEC);
	printf("%ld\n", sum);

  free2DArray(point, n);
  return 0;
}