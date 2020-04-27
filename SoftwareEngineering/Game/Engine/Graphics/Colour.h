#pragma once
#include <CopiriteMath/Datatypes/Vector.h>
#include <SDL.h>


struct SColour
{
	// The red value.
	uint8 R{ 255 };

	// The green value.
	uint8 G{ 255 };

	// The blue value.
	uint8 B{ 255 };

	// The alpha value.
	uint8 A{ 255 };



public:
	/// Constructors

	// Constructor, Default.
	INLINE SColour();

	// Constructor, Initiates this colour based off a SDL_Color.
	// @param Colour - The inputted SDL_Color to initalize this colour with.
	INLINE SColour(const SDL_Color& Colour);

	// Constructor, Initiates this colour based on individual values.
	// @param InR - The value used to initiate the red component.
	// @param InG - The value used to initiate the green component.
	// @param InB - The value used to initiate the blue component.
	// @param Alpha - The value used to initiate the alpha component.
	INLINE SColour(const uint8& InR, const uint8& InG, const uint8& InB, const uint8& Alpha = 255);

	// Constructor, Initiates all components based on a 4D vector.
	// @param Vector - The vector used to initiate all components.
	INLINE SColour(SVector4 Vector);

	// Constructor, Initiates all components based on a 3D vector and a float.
	// @prarm Vector - The vector used to initiate the red, green and blue components.
	// @prarm Alpha - The float used to initiate the alpha component.
	INLINE SColour(SVector Vector, uint8 Alpha = 1.0f);

	// Constructor, Initiates all components based on two 2D vectors.
	// @param V1 - The vector used to initiate the red and green components.
	// @param V2 - The vector used to initiate the blue and alpha components.
	INLINE SColour(SVector2 V1, SVector2 V2);

	// Constructor, Initiates all components based on a 2D vector and 2 floats.
	// @param Vector - The vector used to initiate the red and green components.
	// @param InB - The value used to initiate the blue component.
	// @param Alpha - The value used to initiate the alpha component.
	INLINE SColour(SVector2 Vector, uint8 InB, uint8 Alpha = 1.0f);



	/// Operators

	// Operator, Returns the result of this colour added by another colour.
	INLINE SColour operator+(const SColour& Other) const;

	// Operator, Returns the result of this colour added by a float value.
	INLINE SColour operator+(const uint8& Value) const;

	// Operator, Sets this colour to the result of this colour added by another colour.
	INLINE SColour operator+=(const SColour& Other);

	// Operator, Sets this colour to the result of this colour added by a float value.
	INLINE SColour operator+=(const uint8& Value);

	// Operator, Returns the result of this colour subtracted by another colour.
	INLINE SColour operator-(const SColour& Other) const;

	// Operator, Returns the result of this colour subtracted by a float value.
	INLINE SColour operator-(const uint8& Value) const;

	// Operator, Sets this colour to the result of this colour subtracted by another colour.
	INLINE SColour operator-=(const SColour& Other);

	// Operator, Sets this colour to the result of this colour subtracted by a float value.
	INLINE SColour operator-=(const uint8& Value);

	// Operator, Returns the result of this colour multiplied by another colour.
	INLINE SColour operator*(const SColour& Other) const;

	// Operator, Returns the result of this colour multiplied by a float value.
	INLINE SColour operator*(const uint8& Value) const;

	// Operator, Sets this colour to the result of this colour multiplied by another colour.
	INLINE SColour operator*=(const SColour& Other);

	// Operator, Sets this colour to the result of this colour multiplied by a float value.
	INLINE SColour operator*=(const uint8& Value);

	// Operator, Returns the result of this colour divided by another colour.
	INLINE SColour operator/(const SColour& Other) const;

	// Operator, Returns the result of this colour divided by a float value.
	INLINE SColour operator/(const uint8& Value) const;

	// Operator, Sets this colour to the result of this colour divided by another colour.
	INLINE SColour operator/=(const SColour& Other);

	// Operator, Sets this colour to the result of this colour divided by a float value.
	INLINE SColour operator/=(const uint8& Value);

	// Operator, Sets this colour to the values of an inputted colour.
	INLINE SColour operator=(const SColour& Other);

	// Operator, Sets all components of this colour to the inputted float value.
	INLINE SColour operator=(const uint8& Value);

	// Operator, Returns true if this colour's components are the same as the inputted colour's components.
	INLINE bool operator==(const SColour& Other) const;

	// Operator, Returns true if this colour's components are the same as an inputted float value.
	INLINE bool operator==(const uint8& Value) const;

	// Operator, Returns true if this colour's components are not the same as the inputted colour's components.
	INLINE bool operator!=(const SColour& Other) const;

	// Operator, Returns true if this colour's components are not the same as an inputted float value.
	INLINE bool operator!=(const uint8& Value) const;

	// Operator, Returns true if this colour's components are greater than the inputted colour's components.
	INLINE bool operator>(const SColour& Other) const;

	// Operator, Returns true if this colour's components are greater than the inputted float value.
	INLINE bool operator>(const uint8& Value) const;

	// Operator, Returns true if this colour's components are greater than or equal to the inputted colour's components.
	INLINE bool operator>=(const SColour& Other) const;

	// Operator, Returns true if this colour's components are greater than or equal to the inputted float value.
	INLINE bool operator>=(const uint8& Value) const;

	// Operator, Returns true if this colour's components are less than the inputted colour's components.
	INLINE bool operator<(const SColour& Other) const;

	// Operator, Returns true if this colour's components are less than the  inputted float value.
	INLINE bool operator<(const uint8& Value) const;

	// Operator, Returns true if this colour's components are less than or equal to the inputted colour's components.
	INLINE bool operator<=(const SColour& Other) const;

	// Operator, Returns true if thsi colour's components are less than or equal to the inputted float value.
	INLINE bool operator<=(const uint8& Value) const;



	/// Conversions

	INLINE SDL_Color ToSDLColor()
	{
		return SDL_Color{ R, G, B, A };
	}



	/// Statics

	// Returns the colour red.
	static INLINE SColour Red() { return SColour{ 255, 0, 0 }; }

	// Returns the colour green.
	static INLINE SColour Green() { return SColour{ 0, 255, 0 }; }

	// Returns the colour blue.
	static INLINE SColour Blue() { return SColour{ 0, 0, 255 }; }

	// Returns the colour purple.
	static INLINE SColour Purple() { return SColour{ 128, 0, 255 }; }

	// Returns the colour magenta.
	static INLINE SColour Magenta() { return SColour{ 255, 0, 255}; }

	// Returns the colour yellow.
	static INLINE SColour Yellow() { return SColour{ 255, 255, 0 }; }

	// Returns the colour black.
	static INLINE SColour Black() { return SColour{ 0, 0, 0 }; }

	// Returns the colour dark gray.
	static INLINE SColour DarkGray() { return SColour{ 51, 51, 51 }; }

	// Returns the colour gray.
	static INLINE SColour Gray() { return SColour{ 128, 128, 128 }; }

	// Returns the colour silver.
	static INLINE SColour Silver() { return SColour{ 230, 230, 230 }; }

	// Returns the colour white.
	static INLINE SColour White() { return SColour{ 255, 255, 255 }; }

	// Returns the colour cyan.
	static INLINE SColour Cyan() { return SColour{ 0, 255, 255 }; }

	// Returns the colour orange.
	static INLINE SColour Orange() { return SColour{ 255, 128, 0 }; }

	// Returns the colour pink.
	static INLINE SColour Pink() { return SColour{ 255, 204, 230 }; }

	// Returns the colour brown.
	static INLINE SColour Brown() { return SColour{ 102, 51, 0 }; }

	// Returns the colour lime.
	static INLINE SColour Lime() { return SColour{ 0, 255, 128 }; }

	// Returns the colour gold.
	static INLINE SColour Gold() { return SColour{ 204, 204, 0 }; }

	// Returns the colour clear.
	static INLINE SColour Clear() { return SColour{ 255, 255, 255, 128 }; }
};



INLINE SColour::SColour()
{}


INLINE SColour::SColour(const SDL_Color& Colour)
	:R{ Colour.r }, G{ Colour.g }, B{ Colour.b }, A{ Colour.a }
{}


INLINE SColour::SColour(const uint8& InR, const uint8& InG, const uint8& InB, const uint8& Alpha)
	:R{ InR }, G{ InG }, B{ InB }, A{ Alpha }
{}


INLINE SColour::SColour(SVector4 Vector)
	: R{ (uint8)Vector[0] }, G{ (uint8)Vector[1] }, B{ (uint8)Vector[2] }, A{ (uint8)Vector[3] }
{}


INLINE SColour::SColour(SVector Vector, uint8 Alpha)
	: R{ (uint8)Vector[0] }, G{ (uint8)Vector[1] }, B{ (uint8)Vector[2] }, A{ Alpha }
{}


INLINE SColour::SColour(SVector2 V1, SVector2 V2)
	: R{ (uint8)V1[0] }, G{ (uint8)V1[1] }, B{ (uint8)V2[0] }, A{ (uint8)V2[1] }
{}


INLINE SColour::SColour(SVector2 Vector, uint8 InB, uint8 Alpha)
	: R{ (uint8)Vector[0] }, G{ (uint8)Vector[1] }, B{ InB }, A{ Alpha }
{}


INLINE SColour SColour::operator+(const SColour& Other) const
{
	return SColour
	{
		uint8(R + Other.R),
		uint8(G + Other.G),
		uint8(B + Other.B),
		uint8(A + Other.A)
	};
}


INLINE SColour SColour::operator+(const uint8& Value) const
{
	return SColour
	{
		uint8(R + Value),
		uint8(G + Value),
		uint8(B + Value),
		uint8(A + Value)
	};
}


INLINE SColour SColour::operator+=(const SColour& Other)
{
	R += Other.R;
	G += Other.G;
	B += Other.B;
	A += Other.A;
	return *this;
}


INLINE SColour SColour::operator+=(const uint8& Value)
{
	R += Value;
	G += Value;
	B += Value;
	A += Value;
	return *this;
}


INLINE SColour SColour::operator-(const SColour& Other) const
{
	return SColour
	{
		uint8(R - Other.R),
		uint8(G - Other.G),
		uint8(B - Other.B),
		uint8(A - Other.A)
	};
}


INLINE SColour SColour::operator-(const uint8& Value) const
{
	return SColour
	{
		uint8(R - Value),
		uint8(G - Value),
		uint8(B - Value),
		uint8(A - Value)
	};
}


INLINE SColour SColour::operator-=(const SColour& Other)
{
	R -= Other.R;
	G -= Other.G;
	B -= Other.B;
	A -= Other.A;
	return *this;
}


INLINE SColour SColour::operator-=(const uint8& Value)
{
	R -= Value;
	G -= Value;
	B -= Value;
	A -= Value;
	return *this;
}


INLINE SColour SColour::operator*(const SColour& Other) const
{
	return SColour
	{
		uint8(R * Other.R),
		uint8(G * Other.G),
		uint8(B * Other.B),
		uint8(A * Other.A)
	};
}


INLINE SColour SColour::operator*(const uint8& Value) const
{
	return SColour
	{
		uint8(R * Value),
		uint8(G * Value),
		uint8(B * Value),
		uint8(A * Value)
	};
}


INLINE SColour SColour::operator*=(const SColour& Other)
{
	R *= Other.R;
	G *= Other.G;
	B *= Other.B;
	A *= Other.A;
	return *this;
}


INLINE SColour SColour::operator*=(const uint8& Value)
{
	R *= Value;
	G *= Value;
	B *= Value;
	A *= Value;
	return *this;
}


INLINE SColour SColour::operator/(const SColour& Other) const
{
	return SColour
	{
		uint8(R / Other.R),
		uint8(G / Other.G),
		uint8(B / Other.B),
		uint8(A / Other.A)
	};
}


INLINE SColour SColour::operator/(const uint8& Value) const
{
	return SColour
	{
		uint8(R / Value),
		uint8(G / Value),
		uint8(B / Value),
		uint8(A / Value)
	};
}


INLINE SColour SColour::operator/=(const SColour& Other)
{
	R /= Other.R;
	G /= Other.G;
	B /= Other.B;
	A /= Other.A;
	return *this;
}


INLINE SColour SColour::operator/=(const uint8& Value)
{
	R /= Value;
	G /= Value;
	B /= Value;
	A /= Value;
	return *this;
}


INLINE SColour SColour::operator=(const SColour& Other)
{
	R = Other.R;
	G = Other.G;
	B = Other.B;
	A = Other.A;
	return *this;
}


INLINE SColour SColour::operator=(const uint8& Value)
{
	R = Value;
	G = Value;
	B = Value;
	A = Value;
	return *this;
}


INLINE bool SColour::operator==(const SColour& Other) const
{
	return
	(
		R == Other.R &&
		G == Other.G &&
		B == Other.B &&
		A == Other.A
	);
}


INLINE bool SColour::operator==(const uint8& Value) const
{
	return
	(
		R == Value &&
		G == Value &&
		B == Value &&
		A == Value
	);
}


INLINE bool SColour::operator!=(const SColour& Other) const
{
	return
	(
		R != Other.R &&
		G != Other.G &&
		B != Other.B &&
		A != Other.A
	);
}


INLINE bool SColour::operator!=(const uint8& Value) const
{
	return
	(
		R != Value &&
		G != Value &&
		B != Value &&
		A != Value
	);
}


INLINE bool SColour::operator>(const SColour& Other) const
{
	return
	(
		R > Other.R &&
		G > Other.G &&
		B > Other.B &&
		A > Other.A
	);
}


INLINE bool SColour::operator>(const uint8& Value) const
{
	return
	(
		R > Value &&
		G > Value &&
		B > Value &&
		A > Value
	);
}


INLINE bool SColour::operator>=(const SColour& Other) const
{
	return
	(
		R >= Other.R &&
		G >= Other.G &&
		B >= Other.B &&
		A >= Other.A
	);
}


INLINE bool SColour::operator>=(const uint8& Value) const
{
	return
	(
		R >= Value &&
		G >= Value &&
		B >= Value &&
		A >= Value
	);
}


INLINE bool SColour::operator<(const SColour& Other) const
{
	return
	(
		R < Other.R &&
		G < Other.G &&
		B < Other.B &&
		A < Other.A
	);
}


INLINE bool SColour::operator<(const uint8& Value) const
{
	return
	(
		R < Value &&
		G < Value &&
		B < Value &&
		A < Value
	);
}


INLINE bool SColour::operator<=(const SColour& Other) const
{
	return
	(
		R <= Other.R &&
		G <= Other.G &&
		B <= Other.B &&
		A <= Other.A
	);
}


INLINE bool SColour::operator<=(const uint8& Value) const
{
	return
	(
		R <= Value &&
		G <= Value &&
		B <= Value &&
		A <= Value
	);
}