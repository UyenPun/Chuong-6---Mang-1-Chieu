/* 
a. Kiểm tra xem mảng có toàn số chẵn hay không ?

ý tưởng nhi đồng:
Đặt 1 biến đếm rồi kiểm tra tuần tự từng phần tử
nếu thằng nào là số chẵn thì tăng biến đếm lên,
đến cuối cùng kiểm tra nếu đếm == n => mảng toàn
chẵn.

ý tưởng hay hơn:
Chỉ cần trong quá dình duyệt mảng tìm ra số lẻ
đầu tiên thì lập tức kết luận ngay là mảng
này không thỏa
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
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

int KiemTraToanChan_CachThieuNhi(int a[], int n)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			dem++;
		}
	}
	if(dem == n)
	{
		return 1; // thỏa
	}
	return 0; // không thỏa

	// return dem == n;
}

int KiemTraToanChan_CachVaoDoi(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0) // lẻ
		{
			return 0; // không thỏa.
		}
	}
	return 1; // thỏa
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

int KiemTraMangToanNguyenTo(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNguyenTo(a[i]) == 0)
		{
			return 0; // không thỏa
		}
	}
	return 1; // thỏa
}

/* 
a[0] a[1] a[2] a[3] a[4]
tăng dần là khi:
a[0] <= a[1] <= a[2] <= a[3] <= a[4]
vậy thì chỉ cần tìm ra 1 cặp số nào phá vỡ điều
kiện trên => không thỏa tăng dần
tức là chỉ cần tìm ra nếu
a[0] > a[1] || a[1] > a[2] || a[2] > a[3] || a[3] > a[4]

*/

int KiemTraTangDan(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		if(a[i - 1] > a[i])
		{
			return 0; // không thỏa
		}
	}
	return 1; // thỏa
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

	int check1 = KiemTraToanChan_CachVaoDoi(a, n);
	if(check1 == 1)
	{
		printf("\nMang toan so chan");
	}
	else
	{
		printf("\nMang con ton tai phan tu le");
	}

	int check2 = KiemTraMangToanNguyenTo(a, n);
	if(check2 == 1)
	{
		printf("\nMang toan so nguyen to");
	}
	else
	{
		printf("\nMang con ton tai phan tu khong phai la nguyen to");
	}

	int check3 = KiemTraTangDan(a, n);
	if(check3 == 1)
	{
		printf("\nMang tang dan");
	}
	else
	{
		printf("\nMang khong phai tang dan");
	}

	getch();
	return 0;
}