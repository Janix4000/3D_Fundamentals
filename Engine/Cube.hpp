#pragma once
#include "Primitives.hpp"
#include "IndexedLineList.hpp"

class Cube {
public:
	Cube(float size) {
		int side = size * 0.5f;
		for (auto& z : {-1.f, 1.f})
		{
			for (auto& y : { -1.f, 1.f })
			{
				for (auto& x : { -1.f, 1.f })
				{
					vertices.emplace_back({ x * size, y * size, z * size });
				}
			}
		}
	}

	IndexedLineList getLines() const {
		return {
			vertices, {
			0,1, 1,3, 3,2, 2,0,
			6,7, 7,5, 5,4, 4,6,
			2,6, 3,7, 1,5, 0,4 }
		};
	}
private:
	Vertices_t vertices;
};