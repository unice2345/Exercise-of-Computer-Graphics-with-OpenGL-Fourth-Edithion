/*
 * isConcave.cpp
 *
 *  Created on: 2017年4月12日
 *      Author: lcy
 */

#include <vector>
#include <iostream>

/// \brief 点类
class Point
{
public:
	Point(float _x = 0, float _y = 0) : x(_x), y(-y) {}

	float x;
	float y;
};

/// \brief 多边形类
class Polygon
{
public:
	Polygon() {}

	void addPoint(const Point& pnt){
		_points.push_back(pnt);
	}

	void addPoint(float x, float y){
		_points.emplace_back(x, y);
	}

	void clear() {
		_points.clear();
	}

	bool isConcave();

private:
	std::vector<Point> _points;
};

/// \brief 判断多边形是否为凹多边形
bool Polygon::isConcave()
{
	bool isFirstPnt = true, isFirstEdge = true, isFirstCrossProduct = true;
	Point lastPnt, lastEdge, currEdge;
	float lastCrossProduct, currCrossProduct;

	for(auto pnt: _points) {
		if(!isFirstPnt) {
			// 求edge
			currEdge = Point(pnt.x-lastPnt.x, pnt.y-lastPnt.y);
			if(!isFirstEdge) {
				// 求差积
				currCrossProduct = lastEdge.x * currEdge.y - currEdge.x * lastEdge.y;
				if(!isFirstCrossProduct) {
					if(currCrossProduct * lastCrossProduct < 0)
						return true;
				}

				lastCrossProduct = currCrossProduct;
				isFirstCrossProduct = false;
			}

			lastEdge = currEdge;
			isFirstEdge = false;
		}

		lastPnt = pnt;
		isFirstPnt = false;
	}

	return false;
}

int main()
{
	// 凸多边形
	Polygon poly0;
	poly0.addPoint(0, 0);
	poly0.addPoint(10, 0);
	poly0.addPoint(10, 10);
	poly0.addPoint(0, 10);

	// 凹多边形
	Polygon poly1;
	poly1.addPoint(0, 0);
	poly1.addPoint(10, 0);
	poly1.addPoint(20, 10);
	poly1.addPoint(10, 20);
	poly1.addPoint(10, 30);
	poly1.addPoint(0, 30);

	if(!poly0.isConcave() && poly1.isConcave())
		std::cout << "Test passed." << std::endl;
	else
		std::cout << "Test failed." << std::endl;
}


