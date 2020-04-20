#include "SampleUI.h"

SampleUI::SampleUI(CRenderer* renderer) : UIBase(renderer) {
	
	UIBoxBuilder builder = *(UIBoxBuilder*)factory->getBuilder<UIBox>("Box");

	UIBox* box = builder.withPosition(100, 30).withDimensions(100, 100).withColour({ 0xFF,0,0 }).build();
	UIBox* box2 = builder.withParent(box).withPosition(0, 0).withDimensions(10, 10).withColour({ 0, 0xFF, 0 }).withAnchor(Anchor::CENTRE).build();
	UIBox* box3 = builder.withPosition(0, 0).withDimensions(50, 80).withColour({ 0, 0, 0xFF }).withAnchor(Anchor::BOTTOM_LEFT).build();

	addElement(box);
	addElement(box2);
	addElement(box3);

	UILabelBuilder labelbuilder = *(UILabelBuilder*)factory->getBuilder<Label>("Label");

	Label* label = labelbuilder.withPosition(0, 0).withColour({ 0xFF, 0xFF, 0xFF }).withFont(FONT_ROBOTO, 18).withText("Test the length for clipping sdkjdhkasjdhsdkjhk").withParent(box).withMaxLength(100).withDimensions(100, 100).build();
	Label* label2 = labelbuilder.withPosition(0, 100).withColour({ 0xFF, 0, 0xFF }).withFont(FONT_ROBOTO, 16).withText("Test").withDimensions(100, 100).build();
	Label* label3 = labelbuilder.withPosition(0, 0).withColour({ 0xAA, 0xDF, 0xCC }).withFont(FONT_ROBOTO, 16).withText("+").withAnchor(CENTRE).withDimensions(10, 20).build();
	addElement(label);
	addElement(label2);
	addElement(label3);
}

void SampleUI::update() {

}
