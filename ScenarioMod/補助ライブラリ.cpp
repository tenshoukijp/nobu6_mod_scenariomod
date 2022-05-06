/**
 * 0.5を足してから切り捨てることで小数点以下を四捨五入する
 * @param[in] x 四捨五入を行う浮動小数点数
 * @return 四捨五入の結果
 */
#include <math.h>
int round《整数化》(double a) {
    return round(a);
}

double round《二分の一吸着化》(double a) {
    double b = a * 2;
	b = round(b);
	return b/2;
}
