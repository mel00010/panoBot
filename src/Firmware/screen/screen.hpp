
#include <string>






class Screen{
public:
	Screen();
	~Screen();
	//erases entire screen
	void eraseScreen();
	//writes a string to screen 
	void write(const std::string  &input);
	//position to write to in "screen"
	void moveCursor(const size_t &x, const size_t y);
	//gets current cursor position
	std::pair<size_t, size_t> getCursorPosition();
	//overwriting in a certain position
	void update(const std::string &input, const size_t x, const size_t y);
	//erases at a certain position rather than the entire screen
	void erasePosition(const size_t x, const size_t y);
	//for sending command?
	void command(char i);
	void data(char i);

};



