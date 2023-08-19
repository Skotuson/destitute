#ifndef DRAW_H
#define DRAW_H

using Color = std::string;

class Draw {
    public:
        inline static const std::string RETURN_CURSOR   = "\033[H",
                                        CLEAR_SCREEN    = "\033[2J",
                                        SHOW_CURSOR     = "\033[?25h",
                                        HIDE_CURSOR     = "\033[?25l",
                                        COLOR_DEFAULT   = "\033[0m",
                                        COLOR_BLACK     = "\033[0;30m",
                                        COLOR_RED       = "\033[0;31m",
                                        COLOR_GREEN     = "\033[0;32m",
                                        COLOR_YELLOW    = "\033[0;33m",
                                        COLOR_BLUE      = "\033[0;34m",
                                        COLOR_MAGENTA   = "\033[0;35m",
                                        COLOR_CYAN      = "\033[0;36m",
                                        COLOR_WHITE     = "\033[0;37m",
                                        COLOR_B_GREEN   = "\033[0;92m",
                                        COLOR_B_YELLOW  = "\033[0;93m",
                                        COLOR_B_BLUE    = "\033[0;94m",
                                        COLOR_B_MAGENTA = "\033[0;95m",
                                        COLOR_B_CYAN    = "\033[0;96m",
                                        //8-bit
                                        COLOR_BROWN   = "\033[38;5;130m";
};

#endif