#include "Draw.h"
#include "Novice.h"
#include "calc.h"

void Draw::DrawBezier(const MyVector3& p0, const MyVector3& p1, const MyVector3& p2,
	const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color) {
	
	const int kDivisionNum = 32;

	MyVector3 bezier0 = {};
	MyVector3 bezier1 = {};

	float t0 = 0;
	float t1 = 0;

	for (int index = 0; index < kDivisionNum; index++) {
		t0 = float(index) / kDivisionNum;
		t1 = float(index + 1) / kDivisionNum;

		bezier0 = Calc::Bezier(p0, p1, p2, t0);
		bezier1 = Calc::Bezier(p0, p1, p2, t1);

		bezier0 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(bezier0, viewProjectionMatrix), viewportMatrix);
		bezier1 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(bezier1, viewProjectionMatrix), viewportMatrix);


		Novice::DrawLine(static_cast<int>(bezier0.x), static_cast<int>(bezier0.y), static_cast<int>(bezier1.x), static_cast<int>(bezier1.y), color);
	}
}
