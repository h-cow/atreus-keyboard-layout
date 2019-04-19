#include "../../config.h"

// place overrides here
#define TAPPING_TERM 250

#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_MAX_SPEED         7
#define MOUSEKEY_TIME_TO_MAX       60
#define MOUSEKEY_WHEEL_MAX_SPEED   50
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40


#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL // comment this out for tap-to-select acceleration
// cursor speeds:
#define MK_C_OFFSET_SLOW     1 // pixels
#define MK_C_INTERVAL_SLOW 500 // milliseconds
#define MK_C_OFFSET_MED      4
#define MK_C_INTERVAL_MED   16
#define MK_C_OFFSET_FAST    12
#define MK_C_INTERVAL_FAST  16
// scroll wheel speeds:
#define MK_W_OFFSET_SLOW     1 // wheel clicks
#define MK_W_INTERVAL_SLOW 400 // milliseconds
#define MK_W_OFFSET_MED      1
#define MK_W_INTERVAL_MED  200
#define MK_W_OFFSET_FAST     1
#define MK_W_INTERVAL_FAST 100
