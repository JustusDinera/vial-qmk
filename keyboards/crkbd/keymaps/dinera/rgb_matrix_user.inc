RGB_MATRIX_EFFECT(twoColors)

RGB_MATRIX_EFFECT(piano)

#define STATUS_LED_MIN 19
#define STATUS_LED_MAX 21

#define W_KEY 1
#define B_KEY 0
#define O_KEY 2

#define LED_OFFSET 27 // LEDs per side

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
//static enum {NO_ALERT, ALERT_1, ALERT_2, ALERT_3, ALERT_4} STATUS;

static uint8_t underglow[] = {0, 0xff, 0};
static uint8_t mainKeys[] = {0xff, 0, 0xff};
static uint8_t ctrlKeys[] = {0xff, 0xff, 0};

static uint8_t pianoKeys[] = {
    W_KEY, W_KEY, W_KEY, W_KEY, W_KEY, W_KEY, // underglow
    O_KEY,
    W_KEY, W_KEY, W_KEY, // F
    W_KEY, W_KEY, W_KEY, // E
    O_KEY, O_KEY,
    W_KEY, B_KEY, B_KEY, // D#
    W_KEY, W_KEY, W_KEY, // D
    W_KEY, B_KEY, B_KEY, // C#
    W_KEY, W_KEY, W_KEY, // C
    W_KEY, W_KEY, W_KEY, W_KEY, W_KEY, W_KEY, // underglow
    O_KEY,
    W_KEY, B_KEY, B_KEY, // F#
    W_KEY, W_KEY, W_KEY, // G
    O_KEY, O_KEY,
    W_KEY, B_KEY, B_KEY, // G#
    W_KEY, W_KEY, W_KEY, // A
    W_KEY, B_KEY, B_KEY, // A#
    W_KEY, W_KEY, W_KEY  // H
};

static bool isThumbLED(uint8_t ledNum){
    for (uint8_t i = 0; i < 2; i++)
    {
        if (
            (ledNum - i*LED_OFFSET == 6) ||
            (ledNum - i*LED_OFFSET == 13) ||
            (ledNum - i*LED_OFFSET == 14)
        )
        {
            return true;
        }
    }
    return false;
}

static bool isPinkyLED(uint8_t ledNum){
    for (uint8_t i = 0; i < 2; i++)
    {
        if (
            (ledNum - i*LED_OFFSET <= 26) &&
            (ledNum - i*LED_OFFSET >= 24)
        )
        {
            return true;
        }
    }
    return false;
}

static bool isUnderLED(uint8_t ledNum){
    for (uint8_t i = 0; i < 2; i++)
    {
        if (
            (ledNum - i*LED_OFFSET < 6) &&
            (ledNum - i*LED_OFFSET >= 0)
        )
        {
            return true;
        }
    }
    return false;
}


static bool twoColors(effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (isThumbLED(i) || isPinkyLED(i)){
            rgb_matrix_set_color(i, ctrlKeys[0], ctrlKeys[1], ctrlKeys[2]);
        }
        else if (isUnderLED(i))
        {
            rgb_matrix_set_color(i, underglow[0], underglow[1], underglow[2]);
        }

        else{
            rgb_matrix_set_color(i, mainKeys[0], mainKeys[1], mainKeys[2]);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool piano(effect_params_t* params){
    HSV hsv;
    RGB rgb;
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = 0; i < 54; i++)
    {
        switch (pianoKeys[i])
        {
        case W_KEY:
            rgb_matrix_set_color(i, RGB_WHITE);
            break;
        case B_KEY:
            rgb_matrix_set_color(i, 0, 0, 0);
            break;
        default:
            hsv = rgb_matrix_get_hsv();
            rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS
