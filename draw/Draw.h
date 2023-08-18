#ifndef DRAW_H
#define DRAW_H



class Draw {
    public:
        inline static const std::string RETURN_CURSOR = "\033[H",
                                        CLEAR_SCREEN  = "\033[2J",
                                        SHOW_CURSOR   = "\033[?25h",
                                        HIDE_CURSOR   = "\033[?25l";
};

#endif