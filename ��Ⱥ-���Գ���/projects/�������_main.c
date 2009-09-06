#include <math.h>

// ����m,nֵ����С����ǰ����x,y
// ��ʽ�Ƶ�����:��
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
  // xy����
  float x;
  float y;
  
  // С���յ���վ�ṩ������
  float m; // m := PA - PB  ��λ����
  float n; // n := PA - PC  ��λ����
  
  m = n = 0.0; // For debug only
  CalcCarPosition(&x, &y, m, n);
  
  m = 1.0; n = 1 - sqrt(2); // For debug only
  CalcCarPosition(&x, &y, m, n);
  
}