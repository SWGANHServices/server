// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#pragma once

#include "boundary_layer.h"

namespace swganh
{
namespace tre
{

	/**
		Boundary circle class. It is used to restrict the extent of any of its parent's
		layers.
	*/
	class BoundaryCircle : public BoundaryLayer
	{
	public:

		virtual void Deserialize(swganh::ByteBuffer& buffer);
		virtual bool IsContained(float px, float pz);
		virtual float Process(float px, float pz);
		
	protected:
		float x,z;
		float rad;
	};

}
}
