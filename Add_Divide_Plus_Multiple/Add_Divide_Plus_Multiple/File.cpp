#include <stdio.h>

#define BU(a) ((~a)+1)
#define ABS(a) (a>0?a:BU(a))

int Add(int num1, int num2) {
	return num2 ? Add(num1^num2, (num1&num2) << 1) : num1;
}

int Minu(int num1, int num2) {
	//    int i;
	//    for (i=1;!(num2&i);i<<=1);
	//    for (i<<=1;i;i<<=1) num2^=i;
	return Add(num1, BU(num2));
}


int H_Multy(int num1, int num2) {
	int ans = 0;
	for (int i = 1; i; i <<= 1, num1 <<= 1) {
		if (num2&i) {
			ans = Add(ans, num1);
		}
	}
	return ans;
}

int Multy(int num1, int num2) {

	return (num1 ^ num2) < 0 ? BU(H_Multy(ABS(num1), ABS(num2))) : H_Multy(ABS(num1), ABS(num2));

}

enum _OP { _DIV, _MOD };

int H_DIV(int num1, int num2, _OP op) {
	if (!num2) {
		printf("Éµ±Æ");
		return 0;
	}
	int ans = 0;
	for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
		if ((num1 >> i) >= num2) {
			ans = Add(1 << i, ans);
			num1 = Minu(num1, num2 << i);
		}
	}
	switch (op) {
	case _DIV:
		return ans;
	case _MOD:
		return num1;
	}
}



int DIV(int num1, int num2) {
	int ans = H_DIV(ABS(num1), ABS(num2), _DIV);
	if ((num1^num2) >> (sizeof(int) * 8 - 1)) {
		return BU(ans);
	}
	else {
		return ans;
	}
}

int MOD(int num1, int num2) {
	int ans = H_DIV(ABS(num1), ABS(num2), _MOD);
	if ((num1^num2) >> (sizeof(int) * 8 - 1)) {
		return BU(ans);
	}
	else {
		return ans;
	}

}

int main() {
	printf("%d\n%d\n%d\n", 1 * 2, 1 * -2, -2 * -2);
	getchar();
}