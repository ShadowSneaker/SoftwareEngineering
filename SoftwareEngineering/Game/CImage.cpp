#include "CImage.h"

// the defualt constructor for the image
Image::Image()
{

}

// default Destructor
Image::~Image()
{

}


// function to get Default image Width
float Image::GetImageWidth()
{
	return 0.0f;
}

// function to get Default image Hieght
float Image::GetImageHieght()
{
	return 0.0f;
}

//basic getter to get the Images X
float Image::GetImageX()
{
	return ImagePosition[X];
}

//basic getter to get the Images Y
float Image::GetImageY()
{
	return ImagePosition[Y];
}

//basic setter to set the Images X position
void Image::SetImageX(float x)
{
	ImagePosition[X] = x;
}

//basic setter to set the Images Y position
void Image::SetImageY(float y)
{
	ImagePosition[Y] = y;
}