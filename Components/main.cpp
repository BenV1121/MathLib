#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include <cmath>

using namespace sfw;

void main()
{
	float W = 800, H = 800;
	initContext(W, H);
	/*
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
	*/
	while (stepContext())
	{
		/*
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
		*/

		float steps = 100;
		//i is the number of lines we draw.
		for (int i = 0; i < steps; ++i)
		{
			float x1 = i / steps;
			float x2 = (i + 1) / steps;
			float y1 = quadBezier(.5f, -1.f, 0, x1);
			float y2 = quadBezier(.5f, -1.f, 0, x2);

			x1 *= W;
			x2 *= W;

			y1 *= H;
			y2 *= H;

			drawLine(x1, y1, x2, y2);

		}
	}
	
	termContext();
}