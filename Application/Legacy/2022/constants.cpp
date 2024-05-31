
using namespace std;

class Constants
{
public:
    const char TAB = '\t';
    const char LINE_BREAK = '\n';
    const char STRING_BREAK = '\0';
    const char NUMBER_SIGN = '@';
    const char DOT = '.';
    const char SPACE = ' ';
    const char FILE_DATA_VALUE_BREAK = '|';

    const int SHORT_LOG_DELAY = 10;
    const int LONG_LOG_DELAY = 100;
    const int DEFAULT_LOG_DELAY = 0;

    const int BOLD_FONT_STYLE = 1;
    const int TRANSLUSENT_FONT_STYLE = 2;
    const int ITALIC_FONT_STYLE = 3;
    const int DEFAULT_FONT_STYLE = 0;

    const int GREY_FONT_COLOR = 30;
    const int RED_FONT_COLOR = 31;
    const int GREEN_FONT_COLOR = 32;
    const int YELLOW_FONT_COLOR = 33;
    const int BLUE_FONT_COLOR = 34;
    const int MAGENTA_FONT_COLOR = 35;
    const int CYAN_FONT_COLOR = 36;
    const int WHITE_FONT_COLOR = 37;
    const int BRIGHT_GREY_FONT_COLOR = 90;
    const int BRIGHT_RED_FONT_COLOR = 91;
    const int BRIGHT_GREEN_FONT_COLOR = 92;
    const int BRIGHT_YELLOW_FONT_COLOR = 93;
    const int BRIGHT_BLUE_FONT_COLOR = 94;
    const int BRIGHT_MAGENTA_FONT_COLOR = 95;
    const int BRIGHT_CYAN_FONT_COLOR = 96;
    const int BRIGHT_WHITE_FONT_COLOR = 97;
    const int DEFAULT_FONT_COLOR = 10;

    const int GREY_BACKGROUND_COLOR = 40;
    const int RED_BACKGROUND_COLOR = 41;
    const int GREEN_BACKGROUND_COLOR = 42;
    const int YELLOW_BACKGROUND_COLOR = 43;
    const int BLUE_BACKGROUND_COLOR = 44;
    const int MAGENTA_BACKGROUND_COLOR = 45;
    const int CYAN_BACKGROUND_COLOR = 46;
    const int WHITE_BACKGROUND_COLOR = 47;
    const int BRIGHT_GREY_BACKGROUND_COLOR = 100;
    const int BRIGHT_RED_BACKGROUND_COLOR = 101;
    const int BRIGHT_GREEN_BACKGROUND_COLOR = 102;
    const int BRIGHT_YELLOW_BACKGROUND_COLOR = 103;
    const int BRIGHT_BLUE_BACKGROUND_COLOR = 104;
    const int BRIGHT_MAGENTA_BACKGROUND_COLOR = 105;
    const int BRIGHT_CYAN_BACKGROUND_COLOR = 106;
    const int BRIGHT_WHITE_BACKGROUND_COLOR = 107;
    const int DEFAULT_BACKGROUND_COLOR = 10;

    const string CLEAR_CONSOLE = "cls";
    const string STYLING_BREAK = ";";
    const string BEGINNING_PRE_STYLING = "\x1b[";
    const string END_PRE_STYLING = "m";
    const string BEGINNING_POST_STYLING = "\033[0m";
};

Constants constants;
