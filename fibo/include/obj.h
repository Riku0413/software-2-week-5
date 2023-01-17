
struct matrix {
    long m[2][2];
};

struct matrix matrix_multiply(struct matrix a, struct matrix b);
struct matrix matrix_power_n(struct matrix a, int n);
long fibo(int n);