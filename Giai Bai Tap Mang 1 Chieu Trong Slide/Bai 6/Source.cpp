#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

int KiemTraNguyenTo(int x)
{
	if(x < 2)
	{
		return 0; // không thỏa
	}
	else if(x > 2)
	{
		if(x % 2 == 0)
		{
			return 0; // không thỏa
		}
		for(int i = 3; i <= (int)sqrt((double)x); i += 2)
		{
			if(x % i == 0)
			{
				return 0; // không thỏa
			}
		}
	}
	return 1; // thỏa
}

void SuaNguyenToThanhSo0(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNguyenTo(a[i]) == 1)
		{
			a[i] = 0; // sửa lại
		}
	}
}

void ThemPhanTu(int a[], int &n, int vitrithem, int phantuthem)
{
	for(int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}

void XoaPhanTu(int a[], int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

void ChenVaoSauNguyenTo(int a[], int &n, int socanchen)
{
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNguyenTo(a[i]) == 1)
		{
			ThemPhanTu(a, n, i + 1, socanchen);
			i++; // để không xét lại phần tử vừa thêm vào
		}
	}
}

void XoaTatCaSoNguyenTo(int a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNguyenTo(a[i]) == 1)
		{
			XoaPhanTu(a, n, i);
			i--; // lui lai cap nhat vi tri
		}
	}
}

int main()
{
	int a[MAX], n;

	do{
		printf("\nNhap vao so luong phan tu cua mang: ");
		scanf("%d", &n);

		if(n < 0 || n > MAX)
		{
			printf("\nSo luong khong hop le. Xin kiem tra lai !");
		}
	}while (n < 0 || n > MAX);

	srand(time(0));

	// random mảng
	for(int i = 0; i < n; i++)
	{
		// stdlib.h & time.h
		// srand(time(0));
		// a + rand() % (b - a + 1)

		// random trong đoạn -20 --> 30
		
		a[i] = -20 + rand() % 51;
	}

	XuatMang(a, n);

	//SuaNguyenToThanhSo0(a, n);
	//printf("\nSua cac so nguyen to thanh so 0\n");
	//XuatMang(a, n);

	// chèn số 0 vào đằng sau tất cả số nguyên tố
	printf("\nMang sau khi chen la\n");
	ChenVaoSauNguyenTo(a, n, 0);
	XuatMang(a, n);

	printf("\nMang sau khi xoa tat ca so nguyen to la\n");
	XoaTatCaSoNguyenTo(a, n);
	XuatMang(a, n);
	

	getch();
	return 0;
}