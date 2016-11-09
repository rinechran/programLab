#include "stdafx.h"
#include "Mshape.hpp"


//add Me

void EunMfc::ERect::mouseButtonDown(CPoint & point) {
	if (this->PtInRect(point)) {
		mMouseCheck = true;
		pPoint = new CPoint();
		*pPoint = point - this->TopLeft();
	}
}

void EunMfc::ERect::mouseButtonUp(CPoint & point) {
	mMouseCheck = false;
}

void EunMfc::ERect::mouseMove(CPoint & point) {
	if (mMouseCheck == true)
		MoveToXY(static_cast<CPoint>(point - *pPoint));
}
