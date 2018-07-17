#include "stdafx.h"
#include "rectx.h"
//#include <atltypes.h>

rectx::rectx()
{
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}


rectx::~rectx()
{
}

/*
// from left, top, right, and bottom
inline rectx::rectx(_In_ int l, _In_ int t, _In_ int r, _In_ int b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}
// copy constructor
inline rectx::rectx(_In_ const RECT& srcRect)
{
	//::CopyRect(this, &srcRect);
	memcpy(this, &srcRect, sizeof(RECT));
	 
}

// from a pointer to another rect
inline rectx::rectx(_In_ LPCRECT lpSrcRect) throw()
{
	//::CopyRect(this, lpSrcRect);
	memcpy(this, &lpSrcRect, sizeof(RECT));
}
// from a point and size
inline rectx::rectx(_In_ POINT point, _In_ SIZE size) throw()
{
	right = (left = point.x) + size.cx;
	bottom = (top = point.y) + size.cy;
}
// from two points
inline rectx::rectx(_In_ POINT topLeft, _In_ POINT bottomRight) throw()
{
	left = topLeft.x;
	top = topLeft.y;
	right = bottomRight.x;
	bottom = bottomRight.y;
}


//inline int rectx::Widthx()
//{
//	return right - left;
//}

inline int rectx::Height() const throw()
{
	return bottom - top;
}

inline CSize rectx::Size() const throw()
{
	return CSize(right - left, bottom - top);
}

inline CPoint& rectx::TopLeft() throw()
{
	return *((CPoint*)this);
}

inline CPoint& rectx::BottomRight() throw()
{
	return *((CPoint*)this + 1);
}
// const reference to the top-left point
inline const CPoint& rectx::TopLeft() const throw()
{
	return *((CPoint*)this);
}
// const reference to the bottom-right point
inline const CPoint& rectx::BottomRight() const throw()
{
	return *((CPoint*)this + 1);
}

inline CPoint rectx::CenterPoint() const throw()
{
	return CPoint((left + right) / 2, (top + bottom) / 2);
}

inline void CRect::SwapLeftRight() throw()
{
	SwapLeftRight(LPRECT(this));
}

inline void WINAPI CRect::SwapLeftRight(_Inout_ LPRECT lpRect) throw()
{
	LONG temp = lpRect->left;
	lpRect->left = lpRect->right;
	lpRect->right = temp;
}
*/