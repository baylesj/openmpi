#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "bst.h"

const int squares[] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };

/* Happy functions */
bool is_happy(uint32_t num)
{
	uint64_t ceil;
	uint32_t cur = num;
	uint32_t digit;
	bool happy = false;
	bool repeating = false;
	uint64_t mod;
	uint32_t rem = num;
	uint64_t sum = 1;
	struct BSTree *seen = newBSTree();

	while (!happy && !repeating) {
		mod = 10;
		sum = 0;

		ceil = cur * 10;
		while (mod <= ceil) {
			digit = (cur % mod) / (mod / 10);
			sum += squares[digit];
			rem -= digit;
			mod *= 10;
		}

		if (sum == 1) {
			happy = true;
		} else if (containsBSTree(seen, sum)) {
			repeating = true;
		} else {
			addBSTree(seen, sum);
			cur = sum;
		}
	}
	deleteBSTree(seen);
	return (happy);
}

