//
// Created by alex on 7/5/15.
//

#ifndef ENGINE_SDL2_EVENTTYPE
#define ENGINE_SDL2_EVENTTYPE

#include <SDL_events.h>

namespace engine {
namespace sdl2 {
enum class Event_type {
    FirstEvent = SDL_FIRSTEVENT,
    QuitEvent = SDL_QUIT,
    AppTerminating = SDL_APP_TERMINATING,
    AppLowMemory = SDL_APP_LOWMEMORY,
    AppWillEnterBackground = SDL_APP_WILLENTERBACKGROUND,
    AppDidEnterBackground = SDL_APP_DIDENTERBACKGROUND,
    AppWillEnterForeground = SDL_APP_WILLENTERFOREGROUND,
    AppDidEnterForeground = SDL_APP_DIDENTERFOREGROUND,
    WindowStateEvent = SDL_WINDOWEVENT,
    SystemSpecificEvent = SDL_SYSWMEVENT,
    KeyPressedEvent = SDL_KEYDOWN,
    KeyReleasedEvent = SDL_KEYUP,
    TextEditingEvent = SDL_TEXTEDITING,
    TextInputEvent = SDL_TEXTINPUT,
    MouseMotionEvent = SDL_MOUSEMOTION,
    MouseButtonPressed = SDL_MOUSEBUTTONDOWN,
    MouseButtonReleased = SDL_MOUSEBUTTONUP,
    MouseWheelEvent = SDL_MOUSEWHEEL,
    JoystickAxisEvent = SDL_JOYAXISMOTION,
    JoystickBallMotion = SDL_JOYBALLMOTION,
    JoystickHatMotion = SDL_JOYHATMOTION,
    JoystickButtonPressed = SDL_JOYBUTTONDOWN,
    JoystickButtonReleased = SDL_JOYBUTTONUP,
    JoystickDeviceAdded = SDL_JOYDEVICEADDED,
    JoystickDeviceRemoved = SDL_JOYDEVICEREMOVED,
    ControllerAxisMotion = SDL_CONTROLLERAXISMOTION,
    ControllerButtonPressed = SDL_CONTROLLERBUTTONDOWN,
    ControllerButtonReleased = SDL_CONTROLLERBUTTONUP,
    ControllerDeviceAdded = SDL_CONTROLLERDEVICEADDED,
    ControllerDeviceRemoved = SDL_CONTROLLERDEVICEREMOVED,
    ControllerDeviceRemapped = SDL_CONTROLLERDEVICEREMAPPED,
    FingerDownEvent = SDL_FINGERDOWN,
    FingerUpEvent = SDL_FINGERUP,
    FingerMotionEvent = SDL_FINGERMOTION,
    DollarGestureEvent = SDL_DOLLARGESTURE,
    DollarRecordEvent = SDL_DOLLARRECORD,
    MultiGestureEvent = SDL_MULTIGESTURE,
    ClipboardUpdateEvent = SDL_CLIPBOARDUPDATE,
    FileDropEvent = SDL_DROPFILE,
    RenderTargetsReset = SDL_RENDER_TARGETS_RESET
};

inline Event_type from_SDL_event_type(Uint32 type)
{
    return static_cast<Event_type>(type);
}

}
}

#endif