#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(int size)
{
	m_canvasSize = size;
	m_canvasVector.resize(m_canvasSize);
	for (int i = 0; i < size; i++)
	{
		m_canvasVector[i].resize(m_canvasSize);
	}

	for (int i = 0; i < m_canvasSize; i++)
	{
		for (int k = 0; k < m_canvasSize; k++)
		{
			m_canvasVector[i][k] = ' ';
		}
	}

}

void CCanvas::DrawLine(int x0, int y0, int x1, int y1)
{
	if (abs(x0 - x1) > abs(y0 - y1))
	{
		for (int i = 0; i <= abs(x0 - x1); i++)
		{
			int currentX = std::min(x0, x1) + i;
			int y = y1 + ((currentX - x1)*(y0 - y1)) / (x0 - x1);
			m_canvasVector[std::min(x0, x1) + i][y] = '*';
		}
	}
	else
	{
		for (int i = 0; i <= abs(y0 - y1); i++)
		{
			int currentY = std::min(y0, y1) + i;
			int x = x1 + ((currentY - y1)*(x0 - x1)) / (y0 - y1);
			m_canvasVector[x][std::min(y0, y1) + i] = '*';
		}
	}
}

void CCanvas::OutputCanvas()
{
	for (size_t i = 0; i < m_canvasVector.size(); i++)
	{
		for (size_t k = 0; k < m_canvasVector[i].size(); k++)
		{
			std::cout << m_canvasVector[i][k];
		}
		std::cout << std::endl;
	}
}