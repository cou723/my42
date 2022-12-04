#include <stdio.h>
//再帰関数 関数=function => func
int func(int n) {
    if (n == 0) {
		return 0;
	}
    return n + func(n - 1);
}

int main() {
    for (int n = 0; n < 10; ++n) {
        printf("%dまでの和 = %d\n", n, func(n));
    }
	func(0);// = 0
	func(1);// = 1
	func(2);// = 3
}
//元のfunction
int func(int n) {
    if (n == 0) {
		return 0;
	}
    return n + func(n - 1);
}
//いじくるほう
int func(int n = 2) {
    if (2 == 0) {
		return 0;
	}
    return 2 + 1;
}
int func(int n = 1) {
    if (1 == 0) {
		return 0;
	}
    return 1 + 0;
}
int func(int n = 0) {
    if (0 == 0) {
		return 0;
	}
    return n + func(n - 1);
}
