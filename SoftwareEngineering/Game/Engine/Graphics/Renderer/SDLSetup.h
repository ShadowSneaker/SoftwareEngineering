#pragma once
#include <CopiriteMath/Datatypes/Vector.h>
#include <SDL_ttf.h>
#include <string>



// Determines what kind of window opens on startup.
enum class EWindowMode
{
	WindowPlayer,
	Windowed,
	Fullscreen,
	WindowBorderless
};


class CSDLSetup
{
	/// Properties

	// The main created window reference.
	SDL_Window* Window{ nullptr };

	// The main created renderer reference.
	SDL_Renderer* Renderer{ nullptr };

	// The currently used monitor info.
	SDL_DisplayMode DisplayMode{ SDL_DisplayMode{} };

public:
	// The type of window that should be created on startup.
	EWindowMode WindowMode{ EWindowMode::WindowPlayer };

	// The name of the window created.
	std::string WindowName;

	// The size of the window (in pixels).
	SVector2i WindowSize{ SVector2i{ 800, 600 } };



public:
	/// Constructors

	// Constructor, Default.
	CSDLSetup();

	// Destructor.
	~CSDLSetup();



	/// Functions

	// Initializes the SDL devices.
	// @return - Returns true if the devices were created successfully.
	bool Initialize();

	// Creates the window that pops up.
	// @return - Returns true if the window was created successfully.
	bool CreateDisplay();



	/// Getters

	// Returns the current monitor info.
	INLINE const SDL_DisplayMode GetDisplayMode() const { return DisplayMode; }

	// Returns the created window reference.
	INLINE SDL_Window* GetWindow() const { return Window; }

	// Returns the created renderer reference.
	INLINE SDL_Renderer* GetRenderer() const { return Renderer; }

	// Returns the window data to be used for the window size.
	uint32 GetWindowFlags() const;
};