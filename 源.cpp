//本程序用于计算GS法迭代
//V1.0 在原有基础上完善功能,有问题，系数矩阵的二维数组的实参无法传递给形参，待解决！	（2020/12/9）
//GS迭代需判断是否收敛，待解决！	（2020/12/20）
#include<iostream>
using namespace std;
double culculate(double xt[], double* bt[], double ft[],int k);
int n = 20;
const int N = 5;	//N元1次方程
int main()
{
	//定义变量
	double x[N];
	for(int i=0;i<N;i++)	//给x赋初值
	{
		x[i] = 0;
	}
	
	//输入系数矩阵
	double b[N][N];
	for(int i=0;i<N;i++)
	{
		for (int j = 0;j<N;j++)
		{
			cin >> b[i][j];
		}
	}

	//输入常数项
	double f[N];
	for (int i = 0; i < N; i++)
		cin >> f[i];

	//开始计算迭代
	for(int i=1;i<n;i++)	//迭代次数 i
	{
		for (int j = 0; j < N; j++)
		{
		x[0] = culculate(x,b,f,j);	//迭代格式
		cout << x[j] << '\t';
		}
		cout << endl;
	}
	
}

double culculate(double xt[], double* bt[], double ft[],int k)
{
	double outcome = 0;
	for (int i = 0; i < N; i++)
	{
		outcome -= bt[k][i]*xt[i];
	}
	outcome -= bt[k][k] * xt[k];
	outcome += ft[k];
	outcome /= bt[k][k];
	return outcome;
}
