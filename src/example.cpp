/* Copyright: (c) Kayne Ruse 2013
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
*/
#include "example.hpp"

#include <algorithm>

//-------------------------
//Public access members
//-------------------------

Example::Example() {
	imgPlantBasic.LoadSurface("rsc/plant_basic.bmp");
	imgPlantBasic.SetClipW(32);
	imgPlantBasic.SetClipH(32);
}

Example::~Example() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void Example::FrameStart() {
	//
}

void Example::Update(double delta) {
	for (auto& it : plantList) {
		it.Update(delta);
	}
}

void Example::FrameEnd() {
	//
}

void Example::Render(SDL_Surface* const screen) {
	for (auto& it : plantList) {
		//move this into Plant?
		imgPlantBasic.SetClipX(32*it.GetStage());
		imgPlantBasic.SetClipY(32*it.GetType());
		imgPlantBasic.DrawTo(screen, it.GetPos().x-16, it.GetPos().y-32);
	};
}

//-------------------------
//Event handlers
//-------------------------

void Example::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void Example::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	plantList.push_back({SeedType::BLUEFRUIT});
}

void Example::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void Example::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void Example::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
