//���������ڼ���GS������
//V1.0 ��ԭ�л��������ƹ���,�����⣬ϵ������Ķ�ά�����ʵ���޷����ݸ��βΣ��������	��2020/12/9��
//GS�������ж��Ƿ��������������	��2020/12/20��
#include<iostream>
using namespace std;
double culculate(double xt[], double* bt[], double ft[],int k);
int n = 20;
const int N = 5;	//NԪ1�η���
int main()
{
	//�������
	double x[N];
	for(int i=0;i<N;i++)	//��x����ֵ
	{
		x[i] = 0;
	}
	
	//����ϵ������
	double b[N][N];
	for(int i=0;i<N;i++)
	{
		for (int j = 0;j<N;j++)
		{
			cin >> b[i][j];
		}
	}

	//���볣����
	double f[N];
	for (int i = 0; i < N; i++)
		cin >> f[i];

	//��ʼ�������
	for(int i=1;i<n;i++)	//�������� i
	{
		for (int j = 0; j < N; j++)
		{
		x[0] = culculate(x,b,f,j);	//������ʽ
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
