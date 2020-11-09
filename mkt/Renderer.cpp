#pragma once
#include "Renderer.hpp"
#include <iostream>
Renderer::Renderer()
{
	this->interger = 11;
}
void Renderer::printState()
{
	std::cout << interger;
}