#ifndef HD44780_H
#define HD44780_H

enum class command_4bit_e
{
    _4bit_interface = 0b0010,
    function_set    = 0b0011,
};

//TODO check risk of doing this
template<typename T, typename P>
inline T operator|(T a, P b)
{
    return static_cast<T>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

template<typename T, typename P>
inline T operator&(T a, P b)
{
    return static_cast<T>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

template<typename T>
inline T operator~(T a)
{
    return ~static_cast<T>(static_cast<uint8_t>(a));
}

class Hd44780 : public iLcdHw
{
private:
    iParallel4bit * parallel4bit;
    bool initialized;
    e_display_control display_control;
    e_entry_mode entry_mode;
    
public:
    Hd44780(iParallel4bit * Parallel4bit);
    void init();
    void write_data(uint8_t data);
    void set_entry_mode(bool set, e_entry_mode command);
    void set_display_control(bool set, e_display_control command);
    void set_command(e_command_mask command);
    void gotoXY(uint8_t x, uint8_t y);

private:
    void write_command(e_command_mask cmd);
    void write_command(command_4bit_e cmd);
};

#endif