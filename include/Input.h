#ifndef __INPUT_H__
#define __INPUT_H__

namespace Inputs
{
    enum BUTTON_PRESSED{
        NONE = 0,
        UP,
        DOWN,
        MENU,
        BACK
    };

    extern BUTTON_PRESSED lastButton;
    extern BUTTON_PRESSED newButton;

    void update();

    void resetInput();

} // namespace Inputs



#endif