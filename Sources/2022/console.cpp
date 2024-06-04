
using namespace std;

class Console
{
private:
    int font_style = constants.DEFAULT_FONT_STYLE;
    int background_color = constants.DEFAULT_BACKGROUND_COLOR;
    int font_color = constants.DEFAULT_FONT_COLOR;
    int log_delay = constants.SHORT_LOG_DELAY;
    bool is_reset_text_properties_allowed = true;

    void handle_pre_text_properties()
    {
        cout << constants.BEGINNING_PRE_STYLING;
        cout << Console::font_style;
        cout << constants.STYLING_BREAK;
        cout << Console::background_color;
        cout << constants.STYLING_BREAK;
        cout << Console::font_color;
        cout << constants.END_PRE_STYLING;
    }

    void handle_reset_text_properties()
    {
        if (Console::is_reset_text_properties_allowed)
        {
            Console::reset_text_properties();
        }
    }

    void handle_log_iteration(string text)
    {
        int index = 0;
        while (text[index] != constants.STRING_BREAK)
        {
            Console::log_character_with_delay(text[index]);
            index += 1;
        }
    }

    void log_character_with_delay(char character)
    {
        // ISSUE: REFACTOR LINE 45 AND 47 INTO A NEW CLASS
        auto delay = chrono::steady_clock::now() + chrono::milliseconds(Console::log_delay);
        cout << character;
        this_thread::sleep_until(delay);
    }

    void handle_post_text_properties()
    {
        cout << constants.BEGINNING_POST_STYLING;
        Console::handle_reset_text_properties();
    }

public:
    int get_font_style()
    {
        return Console::font_style;
    }

    int get_background_color()
    {
        return Console::background_color;
    }

    int get_font_color()
    {
        return Console::font_color;
    }

    int get_log_delay()
    {
        return Console::log_delay;
    }

    int get_is_reset_text_properties_allowed()
    {
        return Console::is_reset_text_properties_allowed;
    }

    void reset_text_properties()
    {
        set_log_delay_to_short();
        set_font_style_to_default();
        set_font_color_to_default();
        set_background_color_to_default();
    }

    void log(string text)
    {
        Console::handle_pre_text_properties();
        Console::handle_log_iteration(text);
        Console::handle_post_text_properties();
    }

    void set_font_style_to_bold()
    {
        Console::font_style = constants.BOLD_FONT_STYLE;
    }

    void set_font_style_to_translusent()
    {
        Console::font_style = constants.TRANSLUSENT_FONT_STYLE;
    }

    void set_font_style_to_italic()
    {
        Console::font_style = constants.ITALIC_FONT_STYLE;
    }

    void set_font_style_to_default()
    {
        Console::font_style = constants.DEFAULT_FONT_STYLE;
    }

    void set_font_color_to_grey()
    {
        Console::font_color = constants.GREY_FONT_COLOR;
    }

    void set_font_color_to_red()
    {
        Console::font_color = constants.RED_FONT_COLOR;
    }

    void set_font_color_to_green()
    {
        Console::font_color = constants.GREEN_FONT_COLOR;
    }

    void set_font_color_to_yellow()
    {
        Console::font_color = constants.YELLOW_FONT_COLOR;
    }

    void set_font_color_to_blue()
    {
        Console::font_color = constants.BLUE_FONT_COLOR;
    }

    void set_font_color_to_magenta()
    {
        Console::font_color = constants.MAGENTA_FONT_COLOR;
    }

    void set_font_color_to_cyan()
    {
        Console::font_color = constants.CYAN_FONT_COLOR;
    }

    void set_font_color_to_white()
    {
        Console::font_color = constants.WHITE_FONT_COLOR;
    }

    void set_font_color_to_bright_grey()
    {
        Console::font_color = constants.BRIGHT_GREY_FONT_COLOR;
    }

    void set_font_color_to_bright_red()
    {
        Console::font_color = constants.BRIGHT_RED_FONT_COLOR;
    }

    void set_font_color_to_bright_green()
    {
        Console::font_color = constants.BRIGHT_GREEN_FONT_COLOR;
    }

    void set_font_color_to_bright_yellow()
    {
        Console::font_color = constants.BRIGHT_YELLOW_FONT_COLOR;
    }

    void set_font_color_to_bright_blue()
    {
        Console::font_color = constants.BRIGHT_BLUE_FONT_COLOR;
    }

    void set_font_color_to_bright_magenta()
    {
        Console::font_color = constants.BRIGHT_MAGENTA_FONT_COLOR;
    }

    void set_font_color_to_bright_cyan()
    {
        Console::font_color = constants.BRIGHT_CYAN_FONT_COLOR;
    }

    void set_font_color_to_bright_white()
    {
        Console::font_color = constants.BRIGHT_WHITE_FONT_COLOR;
    }

    void set_font_color_to_default()
    {
        Console::font_color = constants.DEFAULT_FONT_COLOR;
    }

    void set_background_color_to_grey()
    {
        Console::background_color = constants.GREY_BACKGROUND_COLOR;
    }

    void set_background_color_to_red()
    {
        Console::background_color = constants.RED_BACKGROUND_COLOR;
    }

    void set_background_color_to_green()
    {
        Console::background_color = constants.GREEN_BACKGROUND_COLOR;
    }

    void set_background_color_to_yellow()
    {
        Console::background_color = constants.YELLOW_BACKGROUND_COLOR;
    }

    void set_background_color_to_blue()
    {
        Console::background_color = constants.BLUE_BACKGROUND_COLOR;
    }

    void set_background_color_to_magenta()
    {
        Console::background_color = constants.MAGENTA_BACKGROUND_COLOR;
    }

    void set_background_color_to_cyan()
    {
        Console::background_color = constants.CYAN_BACKGROUND_COLOR;
    }

    void set_background_color_to_white()
    {
        Console::background_color = constants.WHITE_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_grey()
    {
        Console::background_color = constants.BRIGHT_GREY_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_red()
    {
        Console::background_color = constants.BRIGHT_RED_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_green()
    {
        Console::background_color = constants.BRIGHT_GREEN_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_yellow()
    {
        Console::background_color = constants.BRIGHT_YELLOW_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_blue()
    {
        Console::background_color = constants.BRIGHT_BLUE_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_magenta()
    {
        Console::background_color = constants.BRIGHT_MAGENTA_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_cyan()
    {
        Console::background_color = constants.BRIGHT_CYAN_BACKGROUND_COLOR;
    }

    void set_background_color_to_bright_white()
    {
        Console::background_color = constants.BRIGHT_WHITE_BACKGROUND_COLOR;
    }

    void set_background_color_to_default()
    {
        Console::background_color = constants.DEFAULT_BACKGROUND_COLOR;
    }

    void set_log_delay_to_short()
    {
        Console::log_delay = constants.SHORT_LOG_DELAY;
    }

    void set_log_delay_to_long()
    {
        Console::log_delay = constants.LONG_LOG_DELAY;
    }

    void set_log_delay_to_default()
    {
        Console::log_delay = constants.DEFAULT_LOG_DELAY;
    }

    void allow_reset_text_properties()
    {
        Console::is_reset_text_properties_allowed = true;
    }

    void avoid_reset_text_properties()
    {
        Console::is_reset_text_properties_allowed = false;
    }

    void log_line_break()
    {
        cout << constants.LINE_BREAK;
    }

    void log_tab()
    {
        cout << constants.TAB;
    }

    void clear()
    {
        system("cls");
    }
};

Console console;
