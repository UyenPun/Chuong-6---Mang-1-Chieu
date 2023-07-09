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

void TachSoNguyenTo(int a[], int n, int b[], int &m)
{
	m = 0;
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNguyenTo(a[i]) == 1)
		{
			b[m++] = a[i];
		}
	}
}

void TachThanh2MangAmDuong(int a[], int n, int b[], int &m, int c[], int &k)
{
	m = k = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0)
		{
			b[m++] = a[i];
		}
		else
		{
			c[k++] = a[i];
		}
	}
}

void HoanVi(int &a, int &b)
{
	/*int temp = a;
	a = b;
	b = temp;*/

	b = a + b; // cho đại
	a = b - a; // a = b
	b = b - a; // b = a
}

// sắp xếp Interchange Sort
void InterchangeSort(int a[], int n, char phanbiet)
{
	// a - b - c - d

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(phanbiet == 't') // tăng dần
			{
				if(a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			else if(phanbiet == 'g') // giảm dần
			{
				if(a[i] < a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}

void SapXepAmDuong(int a[], int n, int b[], int m, int c[], int k)
{
	// mảng dương giảm dần (không có số 0)
	InterchangeSort(b, m, 'g');

	// mảng âm tăng dần (có số 0)
	InterchangeSort(c, k, 't');
	// m = 3, k = 2
	
	int i;
	for(i = 0; i < m; i++)
	{
		a[i] = b[i];
	}

	for(int j = 0; j < k; j++)
	{
		a[i++] = c[j];
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

	printf("\nMang b chua cac so nguyen to co trong mang a la\n");
	int b[MAX], m;

	TachSoNguyenTo(a, n, b, m);
	XuatMang(b, m);

	int c[MAX], k;

	printf("\nTach thanh 2 mang am duong la\n");
	TachThanh2MangAmDuong(a, n, b, m, c, k);
	
	printf("\nSo duong la\n");
	XuatMang(b, m);

	printf("\nSO am la\n");
	XuatMang(c, k);

	printf("\nSap xep mang tang dan\n");
	InterchangeSort(a, n, 't');
	XuatMang(a, n);

	printf("\nDuong giam am tang 0 dung cuoi\n");
	SapXepAmDuong(a, n, b, m, c, k);
	XuatMang(a, n);

	getch();
	return 0;
}