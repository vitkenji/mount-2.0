#pragma once
#include "std.h"

class Ent
{
protected:
	Math::CoordinateF position;
	Math::CoordinateF size;


public:
	Ent(Math::CoordinateF position, Math::CoordinateF size);
	void setPosition(Math::CoordinateF position);
	void setSize(Math::CoordinateF size);
	Math::CoordinateF getPosition() const;
	Math::CoordinateF getSize() const;

	virtual ~Ent();
	virtual void render() = 0;
	virtual void initialize() = 0;
	virtual void update(const float dt) = 0;

};