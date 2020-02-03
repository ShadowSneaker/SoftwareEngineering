#pragma once
#include <CopiriteMath/Datatypes/Vector.h>


// the basic class for the image
class Image
{
private:
	/// properties of the image

	///Coordinates

	//the vector that stores the Image positions
	//sets all positions to default 0
	STVector<2, float> ImagePosition = 0.0f;


	///Colour


	///Drawing



public:

	/// Constructors

	// basic constructor
	Image();

	//Destructor
	~Image();

	

	///Functions




	///Getters and Setters

	//Get the Image Width
	float GetImageWidth();

	//Get the Image Hieght
	float GetImageHieght();

	//Get the Images X Coordinate
	float GetImageX();

	//Get the Images Y Coordinate
	float GetImageY();

	// Set the Images X Coordinate
	void SetImageX(float x);

	//Set the Image Y Coordinate
	void SetImageY(float y);



};

