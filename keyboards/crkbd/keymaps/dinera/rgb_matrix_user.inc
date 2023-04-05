RGB_MATRIX_EFFECT(my_cool_effect)

//RGB_MATRIX_EFFECT(my_cool_effect2)

#define STATUS_LED_MIN 19
#define STATUS_LED_MAX 21

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static enum {NO_ALERT, ALERT_1, ALERT_2, ALERT_3, ALERT_4} STATUS;

static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    if (((i < STATUS_LED_MAX) && (i > STATUS_LED_MIN)) /*|| ((i < STATUS_LED_MAX-(led_max/2)) && (i > STATUS_LED_MIN-(led_max/2)))*/){
        // Code of status LEDs
        switch (STATUS)
        {
        case ALERT_1:
            rgb_matrix_set_color(i, RGB_PINK);
            break;
        case ALERT_2:
            rgb_matrix_set_color(i, RGB_BLUE);
            break;
        case ALERT_3:
            rgb_matrix_set_color(i, RGB_WHITE);
            break;
        case ALERT_4:
            rgb_matrix_set_color(i, RGB_YELLOW);
            break;
        default:
            rgb_matrix_set_color(i, RGB_GREEN);
            break;
        }
    }
    else{
        rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}
#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS
