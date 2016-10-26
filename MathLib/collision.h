#pragma once
#include "vec2.h"
#include "Shapes.h"

struct CollisionData1D
{
	bool  result;
	float penentrationDepth; // how much overlap
	float collisionNormal;   // -1 or 1
	bool  result() const;
	float MTV() const;				 // penentrationDepth * collisionNormal
};

CollisionData1D collisionDetection1(float Amin, float Amax,
									float Bmin, float Bmax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal; // -1 or 1

	bool result() const;
};

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A,
						   const AABB &B);

/*
	5 minutes of buffer
	.2 seconds DT for logic frames

	5*6/2 = 1500 frames

	1500-9000
*/

//struct FrameData replayFrameData[9000];
//replayFrameData[1] = ;
	// Horizontal / Vertical Inputs (2 floats)
	// button commands ()