#include "UIBuilder.h"

UIBoxBuilder::UIBoxBuilder(SDL_Renderer* renderer, int windowWidth, int windowHeight) : renderer(renderer), windowWidth(windowWidth), windowHeight(windowHeight) {
}

UIBoxBuilder& UIBoxBuilder::withPosition(float x, float y) {
	this->x = x;
	this->y = y;
	return *this;
}


UIBoxBuilder& UIBoxBuilder::withDimensions(float width, float height) {
	this->width = width;
	this->height = height;
	return *this;
}


UIBoxBuilder& UIBoxBuilder::withColour(SDL_Color colour) {
	this->colour = colour;
	return *this;
}

UIBoxBuilder& UIBoxBuilder::withImage(CImage image) {
	this->image = image;
	return *this;
}

UIBoxBuilder& UIBoxBuilder::withAnchor(Anchor anchor) {
	this->anchor = anchor;
	return *this;
}

UIBoxBuilder& UIBoxBuilder::withParent(UIElement* parent) {
	this->parent = parent;
	return *this;
}

UIBox* UIBoxBuilder::build() {
	UIBox* box = new UIBox(renderer, windowWidth, windowHeight);
	box->setParent(parent);
	box->setAnchor(anchor);
	box->setElementSize(width, height);
	box->setPosition(x, y);
	box->setColour(colour);
	box->setImage(image);
	reset();
	return box;
}

void UIBoxBuilder::reset() {
	x = y = width = height = 0;
	colour = { 0,0,0 };
	anchor = TOP_LEFT;
	parent = nullptr;

}

UILabelBuilder::UILabelBuilder(SDL_Renderer* renderer, int windowWidth, int windowHeight) : renderer(renderer), windowWidth(windowWidth), windowHeight(windowHeight) {
}

UILabelBuilder& UILabelBuilder::withPosition(float x, float y) {
	this->x = x;
	this->y = y;
	return *this;
}

UILabelBuilder& UILabelBuilder::withDimensions(float width, float height) {
	this->width = width;
	this->height = height;
	return *this;
}

UILabelBuilder& UILabelBuilder::withMaxLength(Uint32 length) {
	this->maxLength = length;
	return *this;
}

UILabelBuilder& UILabelBuilder::withColour(SDL_Color colour) {
	this->colour = colour;
	return *this;
}

UILabelBuilder& UILabelBuilder::withAnchor(Anchor anchor) {
	this->anchor = anchor;
	return *this;
}

UILabelBuilder& UILabelBuilder::withParent(UIElement* parent) {
	this->parent = parent;
	return *this;
}

UILabelBuilder& UILabelBuilder::withFont(const char* path, int size) {
	this->fontPath = path;
	this->fontSize = size;
	return *this;
}

UILabelBuilder& UILabelBuilder::withText(std::string text) {
	this->text = text;
	return *this;
}

Label* UILabelBuilder::build() {
	Label* label = new Label(renderer, windowWidth, windowHeight);
	label->setColour(colour);
	label->setText(text);
	label->setElementSize(width, height);
	label->setMaxLength(maxLength);
	label->setAnchor(anchor);
	label->setFont(fontPath, fontSize);
	label->calculateDimensions();
	label->setParent(parent);
	label->setPosition(x, y);
	label->setFont(fontPath, fontSize);
	reset();
	return label;
}

void UILabelBuilder::reset() {
	x = y = width = height = maxLength = fontSize = 0;
	colour = { 0,0,0 };
	anchor = TOP_LEFT;
	parent = nullptr;
	fontPath = "";
	text = "";
}
