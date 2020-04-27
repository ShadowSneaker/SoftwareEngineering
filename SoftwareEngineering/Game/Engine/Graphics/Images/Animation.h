#pragma once
#include "Image.h"



class CAnimation :public CImage
{
private:
	/// Properties

	// The current cell that is being displayed to the screen.
	SDL_Rect Cell;

	// The total amount of images per row/column.
	SVector2i CellSize{ 1 };

	// The total amount of frames in this animation.
	uint TotalFrames{ 0 };

	// The current timer before the next frame is displayed.
	float Timer{ 0.0f };

	// The offset of time when this animation was resumed.
	float PauseTime{ 0.0f };

protected:
	// Determines if the animation is playing.
	bool Playing{ true };

	// Determines what way the animtion will be playing in.
	bool Reversed{ false };

public:
	// How long it takes to reach the next frame.
	float Speed{ 1.0f };

	// If true, loops the animation infinitly, if false, plays through the animation once and stops on the last frame.
	bool Loop{ true };

	// The current frame this animation is on.
	uint FrameIndex{ 0 };



public:
	/// Constructors

	// Constructor, Default.
	CAnimation();

	// Destructor.
	~CAnimation();



	/// Overridables

	// Updates the animation.
	virtual void Update() override;

	// Gets the frame point of an image.
	virtual SDL_Rect GetCell() const override;

	// Sets image based off of file path.
	// @param Path - the filepath for the image being used.
	virtual void SetImage(const std::string& Path) override;



	/// Functions

	// Resumes the animation from its current frame index.
	void Play();

	// Pauses the animation on its current frame index.
	void Stop();

	// Resumes the animation backwards from the current frame index.
	void Reverse();

	// Plays the animation starting at frame index 0.
	void PlayFromStart();

	// Plays the animation in reverse, starting from the last frame index.
	void ReverseFromEnd();

	// a function to test what frame the animation is on
	void AnimationTestFunction();


	/// Setters

	// Sets how manay frame there are in the animation.
	// @param Rows - The amount of frames there are in the Y axis.
	// @param Columns - The amount of frames there are in the X axis.
	void SetCellCount(const uint& Rows, const uint& Columns);

	// Sets how many frames are in the animation.
	// @param InCells - The amount of frames there are in the X and Y axis'.
	void SetCellCount(const SVector2i& InCells);



	/// Getters

	// Returns true if the animtion is currently playing.
	INLINE bool IsPlaying() const { return Playing; }

	// Returns true if the animation is currently playing in reverse.
	INLINE bool IsReversed() const { return Reversed; }

	// Returns how large each cell is (in pixels).
	INLINE SVector2i GetCellSize() const { return SVector2i{ Cell.w, Cell.h }; }

	// Returns the position of the center of the displayed cell.
	INLINE const SVector2i GetCellCenter() const { return (GetCellSize() * Transform.GetWorldScale()) / 2.0f; };
};