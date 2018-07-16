#pragma once
class pointx :
	public POINT
{
public:
	pointx(_In_ int initX, _In_ int initY);
	pointx();
	~pointx();

public:
	void Offset(_In_ int xOffset, _In_ int yOffset);
};

