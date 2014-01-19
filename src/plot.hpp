#ifndef PLOT_HPP_
#define PLOT_HPP_

#include "plant.hpp"
#include "seed_types.hpp"

#include "bbox.hpp"
#include "image.hpp"

class Plot {
public:
	Plot() = delete;
	Plot(Image* const plotImage, Image* const plantImage);
	~Plot();

	void DrawTo(SDL_Surface* const);

	void OnClick(int x, int y, void* ptr);

	Image* GetPlotImage() { return &plotImage; }
	Image* GetPlantImage() { return &plantImage; }

	BBox* GetPlotBox() { return &plotBox; }
	BBox* GetPlantBox() { return &plantBox; }

private:
	Plant* plant = nullptr;

	Image plotImage;
	Image plantImage;

	BBox plotBox;
	BBox plantBox;
};

#endif
