#include "stdafx.h"
#include <sac.h>

namespace EunMfc {
	class ERect : public CRect {
	public:
		//Constructors
		ERect() :
			CRect(), mMouseCheck(false) {}
		ERect(_In_ int l, _In_ int t, _In_ int r, _In_ int b) :
			CRect(l, t, r, b), mMouseCheck(false) {}
		ERect(_In_ const RECT& srcRect) :
			CRect(srcRect), mMouseCheck(false) {}
		ERect(_In_ LPCRECT lpSrcRect) :
			CRect(lpSrcRect), mMouseCheck(false) {}

		ERect(_In_ POINT point, _In_ SIZE size) : CRect(point, size), mMouseCheck(false) {}
		ERect(_In_ POINT topLeft, _In_ POINT bottomRight) :
			CRect(topLeft, bottomRight), mMouseCheck(false) {}

		//add Me
		void mouseButtonDown(CPoint &point);
		void mouseButtonUp(CPoint &point);
		void mouseMove(CPoint &point);

		//public template
		template <typename FN, typename ...ARGS>
		void mouseMove(CPoint &point, FN & fn, ARGS && ...args) {
			if (this->PtInRect(point) & fn(args...)) {
				mMouseCheck = true;
				pPoint = new CPoint();
				*pPoint = point - this->TopLeft();
			}
		}


	private:
		bool mMouseCheck;
		CPoint * pPoint;

	};

	class RGB {
	public:
		using RGBCOLOR = int;

		RGBCOLOR setColor(int r, int g, int b) {
			rgb = static_cast<RGBCOLOR>(RGB(r, g, b));
			return rgb;
		}

		template <typename T>
		RGBCOLOR setColor(T&& point) {
			rgb = point;
			return rgb;
		}

	private:
		RGBCOLOR rgb;

	};
}