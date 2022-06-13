#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

double real_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR) {
		return z.a;
	} else if (z.t == POLAR) {
		return z.a * cos(z.b);
	}
	return -1;
}

double img_part(struct complex_struct z)
{
	if (z.t == POLAR) {
		return z.b;
	} else if (z.t == POLAR) {
		return z.a * sin(z.b);
	}
	return -1;
}

double magnitude(struct complex_struct z)
{
	if (z.t == RECTANGULAR) {
		return sqrt(z.a * z.a + z.b * z.b);
	} else if (z.t == POLAR) {
		return z.a;
	}
	return -1;
}

double angle(struct complex_struct z)
{
	if (z.t == RECTANGULAR) {
		return atan2(z.b, z.a);
	} else if (z.t == POLAR) {
		return z.b;
	}
	return -1;
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r * cos(A);
	z.b = r * sin(A);
	return z;
}


struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	// 在进行加减法的时候，使用直角坐标将会好很多，所以，这里会将输入的坐标 z 转化为直角坐标系。
	// 也就是将其分为实部，和虚部。然后用 z1 的实部加上 z2 的实部，z1 的虚部加上 z2 的虚部。
	// 最后把已经计算完的结果，通过 make_from_real_img 再转变为 z。
	// 这里面就不要再思考底层的结构体是如何处理数据的了。无论 z 是怎么储存在结构体里的，当我使用
	// 的时候，都会将其转变为我所需要的。也就是这里的 real_part 和 img_part，这两个部分。
	// 所以，并不用在意底层结构体中是如何储存的，只需要知道 real_part 和 img_part 能够达成自身的
	// 目的就行了。
	return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
	printf("%0.1f", real_part(z));
	if (img_part(z) < 0) {
		printf("%0.1fi", img_part(z));
	} else if (img_part(z) > 0) {
		printf("+%0.1fi", img_part(z));
	}
}

int main() {
	struct complex_struct a = make_from_real_img(2, 5);
	struct complex_struct b = make_from_mag_ang(0, 2);
	struct complex_struct c = make_from_mag_ang(3, -2);

	print_complex(a);
	print_complex(b);
	print_complex(c);
}
