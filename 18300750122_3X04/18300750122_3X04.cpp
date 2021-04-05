//采用白盒测试法
#include <iostream>
#include <math.h>
using namespace std;
#include "C:\Users\kilorwong\source\repos\18300750122_3X04\18300750122_3X04\include\simple_test.h"
struct orderErr{};
struct norealsolution{};

void solution(double a, double b, double c) {
	if (a == 0)
	{
		throw orderErr{};
	}
	double delta;
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		throw norealsolution{};
	}
	cout << "x1=" << (sqrt(delta) - b) / a / 2 << "\tx2=" << (-sqrt(delta) - b) / a / 2 << endl;
}

int test_main()
{
	CHECK_THROW(solution(0, 1, 3), orderErr);       //覆盖范围line10——12
	CHECK_THROW(solution(1, 4, 5), norealsolution); //覆盖范围line14——19
	solution(1, 4, 4);
	solution(1, 4, 3);

	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
