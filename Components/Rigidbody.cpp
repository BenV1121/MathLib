#include "Rigidbody.h"

void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	trans.position = trans.position + velocity * deltaTime;
}
