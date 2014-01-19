#include "plot.hpp"

Plot::Plot(Image* const argPlotImage, Image* const argPlantImage) {
	plotImage.SetSurface(argPlotImage->GetSurface());
	plantImage.SetSurface(argPlantImage->GetSurface());
}

Plot::~Plot() {
	//
}

void Plot::DrawTo(SDL_Surface* const) {
	//
}

void Plot::OnClick(int x, int y, void* ptr) {
	//
}
