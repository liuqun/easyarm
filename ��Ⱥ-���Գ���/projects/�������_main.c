#include <math.h>

// 根据m,n值计算小车当前坐标x,y
// 公式推导步骤:略
void CalcCarPosition(float *x, float *y, float m, float n)
{
  float root;
  float denominator;
  
  root = sqrt((1-m*m)*(1-n*n)*(2-(m-n)*(m-n)));
  denominator = 2*(-1 + m*m + n*n);
  *x = 0.5 - (m*n + m*m*n*n)/denominator + (m*n*n*n + m*root)/denominator;
  *y = 0.5 - (m*n + m*m*n*n)/denominator + (m*m*m*n + n*root)/denominator;
}


main()
{
  // xy坐标
  float x;
  float y;
  
  // 小车收到主站提供的数据
  float m; // m := PA - PB  单位：米
  float n; // n := PA - PC  单位：米
  
  m = n = 0.0; // For debug only
  CalcCarPosition(&x, &y, m, n);
  
  m = 1.0; n = 1 - sqrt(2); // For debug only
  CalcCarPosition(&x, &y, m, n);
  
}