#include "Bounds.h"

bool Bounds::Intersects(const Bounds& other) const
{
    // 겹치지 않은 경우 먼저 판단

    // 다른 영역이 오른쪽으로 벗어난 경우 (나보다 오른쪽에 있는 경우)
    if (other.x > MaxX())
    {
        return false;
    }

    // 다른 영역이 왼쪽으로 벗어난 경우 (나보다 왼쪽에 있는 경우)
    if (other.MaxX() < x)
    {
        return false;
    }

    // 다른 영역이 아래쪽으로 벗어난 경우 (나보다 아래에 있는 경우)
    if (other.y > MaxY())
    {
        return false;
    }

    // 다른 영역이 위쪽으로 벗어난 경우 (나보다 위에 있는 경우)
    if (other.MaxY() < y)
    {
        return false;
    }

    // 겹침
    return true;
}
