#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class ICanvas
{
public:
	virtual void DrawLine(int x0, int y0, int x1, int y1) = 0;
	virtual void OutputCanvas() = 0;
	virtual ~ICanvas() {}
};


class CCanvas : public ICanvas
{
public:
	CCanvas(int size);
	void DrawLine(int x0, int y0, int x1, int y1) override;
	void OutputCanvas();
private:
	int m_canvasSize;
	std::vector<std::vector<char>> m_canvasVector;
};
