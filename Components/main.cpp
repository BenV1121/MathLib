#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

using namespace sfw;

void main()
{
	initContext();
	Transform trans(400, 300);

	// Different Constructor Syntaxes:
	int j = int(4);
	int k(4); // works in c-tor
	int l = { 4 };
	int n{ 4 }; // works in c-tor

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400, 300 };

	//trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 96,32 };

	vec2 basis = { 120,0 };
	float ang_vec = 0;

	while (stepContext())
	{
		ang_vec += getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 120;
		float proj = dot(basis, normal(incident));
		//trans.debugDraw();
		drawCircle(400 + proj, 300 + proj, 100);
		drawCircle(400 - proj, 300 + proj, 100);
		drawCircle(400 + proj, 300 - proj, 100);
		drawCircle(400 - proj, 300 - proj, 100);
		drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);
		drawLine(400, 300, 400 + incident.x, 300 + incident.y, BLUE);
		drawLine(400, 300, 400 + proj, 300, GREEN);

		trans.update();
	}
	
	termContext();
}