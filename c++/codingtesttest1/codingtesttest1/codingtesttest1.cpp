#include<stdio.h>
#include <iostream>

using namespace std;
float makesquare(int n);

/* [Notice for C/C++]
 * - 기본 제공되는 뼈대 코드는 입출력의 이해를 돕기위해 제공되었습니다.
 * - 뼈대코드의 활용은 선택사항이며 코드를 직접 작성하여도 무관합니다.
 *
 * - 데이터의 입력과 출력은 stdin과 stdout을 통하고 scanf와 printf를 사용하세요
 * - 별도의 병렬 처리나 시스템콜, 네트워크/파일접근 등을 하지 마세요
 * - main은 int형으로 선언한 후 return 0를 항상 하는 것을 권유합니다
 * - 지역변수 배열 크기에 의한 Stack Overflow 에러에 주의하세요
 * - (C++) cin/cout보다 scanf/printf를 사용하기를 권장합니다. (입출력 성능에 의한 이유)
 */


int main()
{   //프로그램의 시작부 
	int number;
	cin >> number;
	makesquare(number);

	cout << makesquare;
	return 0;
}

float makesquare(int n)
{
	int xarray[20], yarray[20];
	int ax, ay, i(0), j(0), maxvalue(0), xvalue, yvalue;
	for (; n > 0; n--)
	{
		cin >> ax;
		cin >> ay;
		xarray[i] = ax;
		yarray[i] = ay;
		for (int j = 0; j < i; j++)
		{
			xvalue = xarray[i] - xarray[j];
			yvalue = yarray[i] - yarray[j];
			if ((xvalue == yvalue) && xvalue > maxvalue)
			{
				maxvalue = xvalue;
			}
		}
		i++;
	}

	return maxvalue * maxvalue;
}