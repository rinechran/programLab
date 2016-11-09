#include "stdafx.h"
#include "Mshape.hpp"


//add Me

void Eun::ERect::mouseButtonDown(CPoint & point) {
	if (this->PtInRect(point)) {
		mMouseCheck = true;
		pPoint = new CPoint();
		*pPoint = point - this->TopLeft();
	}
}

void Eun::ERect::mouseButtonUp(CPoint & point) {
	mMouseCheck = false;
}

void Eun::ERect::mouseMove(CPoint & point) {
	if (mMouseCheck == true)
		MoveToXY(static_cast<CPoint>(point - *pPoint));
}
