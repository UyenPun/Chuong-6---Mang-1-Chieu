#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

int main()
{
	int a[MAX];
	int n;

	do{
		printf("\nNhap vao so luong phan tu cua mang: ");
		scanf("%d", &n);

		if(n < 0 || n > MAX)
		{
			printf("\nSo luong khong hop le. Xin kiem tra lai !");
		}
	}while (n < 0 || n > MAX);

	NhapMang(a, n);
	XuatMang(a, n);

	getch();
	return 0;
}