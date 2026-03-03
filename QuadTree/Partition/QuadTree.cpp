#include "QuadTree.h"

QuadTree::QuadTree(const Bounds& bounds)
{
	// 루트 노드 생성
	root = new Node(bounds);
}

QuadTree::~QuadTree()
{
	// 삭제
	SafeDelete(root);
}

void QuadTree::Insert(Node* node)
{
	// 예외 처리
	if (!node)
	{
		return;
	}

	root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
	// 예외 처리
	if (!queryNode)
	{
		return {};
	}

	// 겹침 가능성 있는 영역 확인
	std::vector<Node*> possibleNodes;
	root->Query(queryNode->GetBounds(), possibleNodes);

	// 실제 겹치는 노드들만 확인
	std::vector<Node*> intersects;
	for (Node* const node : possibleNodes)
	{
		for (Node* const point : node->Points())
		{
			if (point->GetBounds().Intersects(queryNode->GetBounds()))
			{
				intersects.emplace_back(point);
				continue;
			}
		}
	}

	// 결과 최종 반환
	return intersects;
}
