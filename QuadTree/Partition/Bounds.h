#pragma once

// 사각형 영역을 표시하는 클래스
class Bounds
{
public:
	Bounds(int x, int y, int width = 1, int height = 1)
		: x(x), y(y), width(width), height(height)
	{
	}

	// Getter
	inline int X() const { return x; }
	inline int Y() const { return y; }
	inline int Width() const { return width; }
	inline int Height() const { return height; }

	inline int MaxX() const { return x + width; }
	inline int MaxY() const { return y + height; }

	// 겹침 판정 함수
	bool Intersects(const Bounds& other) const;

private:
	// 왼쪽 상단 지점을 기준으로 위치 표기
	int x = 0;
	int y = 0;

	// 너비/높이
	int width = 1;
	int height = 1;
};

