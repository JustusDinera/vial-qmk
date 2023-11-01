RGB_MATRIX_EFFECT(twoColors)
RGB_MATRIX_EFFECT(piano)
RGB_MATRIX_EFFECT(gameLayer)
RGB_MATRIX_EFFECT(obsLayer)
RGB_MATRIX_EFFECT(funcLayer)

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


/*
static uint8_t pianoKeys[] = {
    O_KEY, O_KEY, O_KEY, O_KEY, O_KEY, O_KEY, // underglow
    O_KEY,
    W_KEY, W_KEY, W_KEY, // F
    W_KEY, W_KEY, W_KEY, // E
    O_KEY, O_KEY,
    W_KEY, B_KEY, B_KEY, // D#
    W_KEY, W_KEY, W_KEY, // D
    W_KEY, B_KEY, B_KEY, // C#
    W_KEY, W_KEY, W_KEY, // C
    O_KEY, O_KEY, O_KEY, O_KEY, O_KEY, O_KEY, // underglow
    O_KEY,
    W_KEY, B_KEY, B_KEY, // F#
    W_KEY, W_KEY, W_KEY, // G
    O_KEY, O_KEY,
    W_KEY, B_KEY, B_KEY, // G#
    W_KEY, W_KEY, W_KEY, // A
    W_KEY, B_KEY, B_KEY, // A#
    W_KEY, W_KEY, W_KEY  // H
};
*/


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

static bool setThumbLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isThumbLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
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

static bool setPinkyLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isPinkyLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
}

static bool isCtrlLED(uint8_t ledNum){
    return (isPinkyLED(ledNum) || isThumbLED(ledNum));
}

static bool setCtrlLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isCtrlLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
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

static bool setUnderLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isUnderLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
}

static bool isWasdLED(uint8_t ledNum){

    if (
        (ledNum == 11) ||
        (ledNum == 16) ||
        (ledNum == 17) ||
        (ledNum == 19) ||
        (
            (ledNum <= 23) &&
            (ledNum >= 21)
        )
    )
    {
        return true;
    }
    return false;
}

static bool setWasdLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isWasdLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
}

static bool isFuncLED(uint8_t ledNum){
    for (uint8_t i = 0; i < 2; i++)
    {
        if (
            (ledNum - i*LED_OFFSET == 9) ||
            (ledNum - i*LED_OFFSET == 10) ||
            (ledNum - i*LED_OFFSET == 17) ||
            (ledNum - i*LED_OFFSET == 18) ||
            (ledNum - i*LED_OFFSET == 23) ||
            (ledNum - i*LED_OFFSET == 24)
        )
        {
            return true;
        }
    }
    return false;
}

static bool setFuncLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isFuncLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
}

// TODO set OBS keys
static bool isObsLED(uint8_t ledNum){
    for (uint8_t i = 0; i < 2; i++)
    {
        if (
            (ledNum - i*LED_OFFSET == 9) ||
            (ledNum - i*LED_OFFSET == 10) ||
            (ledNum - i*LED_OFFSET == 17) ||
            (ledNum - i*LED_OFFSET == 18) ||
            (ledNum - i*LED_OFFSET == 23) ||
            (ledNum - i*LED_OFFSET == 24)
        )
        {
            return true;
        }
    }
    return false;
}

static bool setObsLED(uint8_t ledNum, uint8_t r, uint8_t g, uint8_t b){
    bool result = isObsLED(ledNum);
    if (result)
    {
        rgb_matrix_set_color(ledNum, r, g, b);
    }
    return result;
}

// deprecated
static bool twoColors(effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (!(
            setCtrlLED(i, ctrlKeys[0], ctrlKeys[1], ctrlKeys[2]) ||
            setUnderLED(i, underglow[0], underglow[1], underglow[2])
        ))
        {
            rgb_matrix_set_color(i, mainKeys[0], mainKeys[1], mainKeys[2]);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool isWhiteKey(uint8_t col, uint8_t row){
    if (row < MATRIX_ROWS/2 - 1) // left side
    {
        if (
            col % 2 == 0 ||
            col == 5
        )
        {
            return true;
        }
    }
    else if (row >= MATRIX_ROWS/2 && row < MATRIX_ROWS - 1) // right side
    {
        if (col % 2 == 0)
        {
            return true;
        }
    }
    return false;
}

// shows a piano keyboard
static bool piano(effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv;
    RGB rgb;

    hsv = rgb_matrix_get_hsv();
    rgb = hsv_to_rgb(hsv);

    //for (uint8_t i = led_min; i < led_max; i++)
    for (uint8_t row = 0; row < 12; row++)
     {
        //switch (pianoKeys[i]
        for(int col = 0; col < 4; col++)
        {
            if (isWhiteKey(col, row))
                rgb_matrix_set_color(g_led_config.matrix_co[row][col], 100, 100, 100);
            else
                rgb_matrix_set_color(g_led_config.matrix_co[row][col], rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
    //return rgb_matrix_check_finished_leds(led_max);
}

static bool gameLayer(effect_params_t * params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = rgb_matrix_get_hsv();
    RGB normKey = hsv_to_rgb(hsv);
    RGB specialKey;

    hsv.h += rgb_matrix_config.speed;
    specialKey = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++)
    {
        if (!(
            setWasdLED(i, specialKey.r, specialKey.g, specialKey.b) ||
            //setPinkyLED(i, specialKey.r, specialKey.g, specialKey.b) ||
            setThumbLED(i, specialKey.r, specialKey.g, specialKey.b)
            ))
            rgb_matrix_set_color(i, normKey.r, normKey.g, normKey.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool obsLayer(effect_params_t * params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = rgb_matrix_get_hsv();
    RGB normKey = hsv_to_rgb(hsv);
    RGB specialKey;

    hsv.h += rgb_matrix_config.speed;
    specialKey = hsv_to_rgb(hsv);


    for (uint8_t i = led_min; i < led_max; i++)
    {
        if (!(setObsLED(i, specialKey.r, specialKey.g, specialKey.b) ||
            setFuncLED(i, specialKey.r, specialKey.g, specialKey.b) ||
            setWasdLED(i, specialKey.r, specialKey.g, specialKey.b)
        ))
            rgb_matrix_set_color(i, normKey.r, normKey.g, normKey.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool funcLayer(effect_params_t * params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = rgb_matrix_get_hsv();
    RGB normKey = hsv_to_rgb(hsv);
    RGB specialKey;

    hsv.h += rgb_matrix_config.speed;
    specialKey = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++)
    {
        if (!(
            setFuncLED(i, specialKey.r, specialKey.g, specialKey.b) ||
            setPinkyLED(i, specialKey.r, specialKey.g, specialKey.b)
        ))
            rgb_matrix_set_color(i, normKey.r, normKey.g, normKey.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS
