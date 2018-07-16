#include "stdafx.h"
#include "pointx.h"


pointx::pointx()
{
	x = y = 0;
}
pointx::~pointx()
{
}
pointx::pointx(_In_ int initX, _In_ int initY)
{
	x = initX;
	y = initY;
}
void pointx::Offset(_In_ int xOffset, _In_ int yOffset)
{
	x += xOffset;
	y += yOffset;
}