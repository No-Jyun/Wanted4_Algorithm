#include <iostream>

// 선택 정렬 함수
void SelectionSort(int* array, int length)
{
	// 예외 처리
	if (length <= 1)
	{
		return;
	}

	for (int i = 0; i < length - 1; i++)
	{
		// 최소값
		int minIndex = i;

		// 현재 위치에서 끝까지 반복
		// 회차가 거듭될수록 오른쪽으로 위치를 옮겨가며 정렬
		for (int j = i + 1; j < length; j++)
		{
			// 비교
			if (array[minIndex] > array[j])
			{
				minIndex = j;
			}
		}

		// 회차 전에 저장해뒀던 인덱스가 바뀌었는지 확인
		if (minIndex != i)
		{
			std::swap<int>(array[minIndex], array[i]);
		}
	}
}

// 배열 항목 출력 함수
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i];

		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	
	// 배열 항목 개수 구하기
	int length = sizeof(array) / sizeof(array[0]);

	// 정렬 전 출력
	std::cout << "정렬 전 배열 : ";
	PrintArray(array, length);

	// 정렬
	SelectionSort(array, length);

	// 정렬 후 출력
	std::cout << "정렬 후 배열 : ";
	PrintArray(array, length);
}