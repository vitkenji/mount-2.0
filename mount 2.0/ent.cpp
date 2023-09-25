#include "ent.h"

Ent::Ent(Math::CoordinateF position, Math::CoordinateF size): position(position), size(size)
{

}

Ent::~Ent(){}

void Ent::setPosition(Math::CoordinateF position)
{
	this->position = position;
}

void Ent::setSize(Math::CoordinateF size)
{
	this->size = size;
}

Math::CoordinateF Ent::getPosition() const
{
	return this->position;
}

Math::CoordinateF Ent::getSize() const
{
	return this->size;

}