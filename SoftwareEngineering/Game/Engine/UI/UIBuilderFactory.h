#pragma once
#include "../Graphics/Renderer/Renderer.h"
#include "UIBuilder.h"
#include <string>

class BuilderFactory {
private:
	CRenderer* renderer;
public:
	BuilderFactory(CRenderer* renderer);
	template<class T>
	inline Builder<T> *getBuilder(std::string type) {
		int width = renderer->GetWindowSize().GetX(), height = renderer->GetWindowSize().GetY();
		SDL_Renderer* renderer = this->renderer->GetSDLRenderer();
		if (type == "Box") {
			return (Builder<T>*)new UIBoxBuilder(renderer, width, height);
		}
		else if (type == "Label") {
			return (Builder<T>*)new UILabelBuilder(renderer, width, height);
		}
		return nullptr;
	}
};