#ifndef COLOR_H
#define COLOR_H

#include <QObject>
#include "enum.h"

namespace Color {
    Q_NAMESPACE

    /* Here's one with Q_ENUM_NS (Qt 5.8 required!) */
    enum Primary {
        Red = 0xFF0000,
        Green = 0x00FF00,
        Blue = 0x0000FF
    };
    Q_ENUM_NS(Primary)
    /* Qt Creator auto completes the above enum
       and it compiles, but says "expected a declaration"
       on lines 16 and 17 */


    /* Here's one with better-enums from "enum.h" */
    BETTER_ENUM(Secondary, int,
                Cyan = 0x00FFFF,
                Magenta = 0xFF00FF,
                Yellow = 0xFFFF00)
    /* Qt Creator does not auto complete.
     * It compiles, but Qt Creator says
     * expected a declaration on line 24
     * or whatever line comes after BETTER_ENUMS(...
     * (even if BETTER_ENUM() is on one line)
     */

}

#endif // COLOR_H
