#pragma once
#include "UIBox.h"
#include "../../Label.h"

template <class T>
class Builder {
protected:
	SDL_Renderer* renderer;
	int windowWidth, windowHeight;
	float x{ 0 }, y{ 0 }, width{ 1 }, height{ 1 };
	Anchor anchor{ TOP_LEFT };
	UIElement* parent = nullptr;
public:
	T virtual *build() = 0;
	void virtual reset() = 0;
};

class UIBoxBuilder : public Builder<UIBox> {
private:
	SDL_Renderer* renderer;
	int windowWidth, windowHeight;
	SDL_Color colour{1, 1, 1};
	CImage image;
public:
	UIBoxBuilder(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	UIBoxBuilder& withPosition(float x, float y);
	UIBoxBuilder& withDimensions(float width, float height);
	UIBoxBuilder& withColour(SDL_Color colour);
	UIBoxBuilder& withImage(CImage image);
	UIBoxBuilder& withAnchor(Anchor anchor);
	UIBoxBuilder& withParent(UIElement* parent);
	UIBox *build() override;
	void reset() override;
};

class UILabelBuilder : public Builder<Label> {
private:
	SDL_Renderer* renderer;
	int maxLength;
	int windowWidth, windowHeight;
	const char* fontPath;
	int fontSize;
	SDL_Color colour{ 1,1,1 };
	std::string text;
public:
	UILabelBuilder(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	UILabelBuilder& withPosition(float x, float y);
	UILabelBuilder& withDimensions(float width, float height);
	UILabelBuilder& withMaxLength(Uint32 length);
	UILabelBuilder& withColour(SDL_Color colour);
	UILabelBuilder& withAnchor(Anchor anchor);
	UILabelBuilder& withParent(UIElement* parent);
	UILabelBuilder& withFont(const char* path, int size);
	UILabelBuilder& withText(std::string text);
	Label* build() override;
	void reset() override;
};


