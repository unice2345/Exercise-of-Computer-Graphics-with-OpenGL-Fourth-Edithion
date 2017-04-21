/*
 * Triangle.cpp
 *
 *  Created on: 2017年4月17日
 *      Author: lcy
 */

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

class Point
{
public:
	Point(int _x, int _y): x(_x), y(_y) {}

	Point operator-(Point& rhs) {
		return Point(x-rhs.x, y-rhs.y);
	}

	float x;
	float y;
};

class Polygon
{
public:
	std::list<Point> points;
};

float cross(Point p0, Point p1)
{
	return p0.x * p1.y - p0.y * p1.x;
};

/// \brief 判断点是否在三角形内
/// \param p0 待判断的点
/// \param p1, p2, p3 三角形的顶点
/// \return 点是否在三角形内
bool isPointInTrangle(Point p0, Point p1, Point p2, Point p3)
{
	Point v1 = p1 - p0;
	Point v2 = p2 - p0;
	Point v3 = p3 - p0;

	float c1 = cross(v1, v2);
	float c2 = cross(v2, v3);
	float c3 = cross(v3, v1);

	return ((c1 > 0 && c2 > 0 && c3 >0) || (c1 < 0 && c2 < 0 && c3 <0));
}

std::vector<Polygon> trianglization(Polygon& poly)
{
	std::vector<Polygon> resultPolys;

	while(poly.points.size() > 3) {
		auto range_begin = poly.points.begin();
		auto range_end = poly.points.end();
		std::advance(range_begin, 1);
		std::advance(range_end, -1);
		for(;range_begin != range_end;) {
			auto iter0 = range_begin;
			auto iter1 = range_begin;
			auto iter2 = range_begin;
			std::advance(iter0, -1);
			std::advance(iter2, 1);

			Point v0((iter1->x) - (iter0->x), (iter1->y) - (iter0->y));
			Point v1((iter2->x) - (iter1->x), (iter2->y) - (iter1->y));

			if(cross(v0, v1) > 0) { // 凸点，删除
				Polygon p;
				p.points.push_back(*iter0);
				p.points.push_back(*iter1);
				p.points.push_back(*iter2);
				resultPolys.push_back(p);

				range_begin = poly.points.erase(range_begin);
			} else { // 凹点，跳过
				range_begin++;
			}
		}
	}

	resultPolys.push_back(poly);

	return resultPolys;
}

int main()
{
	Polygon p;
	p.points.emplace_back(0, 0);
	p.points.emplace_back(1, 0);
	p.points.emplace_back(2, 1);
	p.points.emplace_back(3, 0);
	p.points.emplace_back(3, 3);
	p.points.emplace_back(0, 3);

	std::vector<Polygon> resultPolygon = trianglization(p);

	for(const auto& poly: resultPolygon) {
		for(const auto& pnt: poly.points) {
			std::cout << "(" << pnt.x << ", " << pnt.y << ") ";
		}
		std::cout << std::endl;

	}
	/*
	Point p0(5, 5);
	Point p1(0, 0), p2(10, 0), p3(5, 10);
	Point p4(5, -5);

	if(isPointInTrangle(p0, p1, p2, p3) && !isPointInTrangle(p4, p1, p2, p3)) {
		std::cout << "Pass" << std::endl;
	} else {
		std::cout << "Fail" << std::endl;
	}
    */
}




