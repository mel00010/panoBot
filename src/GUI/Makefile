SOURCES = $(wildcard *.cpp) $(wildcard *.hpp)
CXX = g++
CFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

%.o : %.cpp %.hpp
	$(CXX) -c $(CFLAGS) $< 

# Add any additional targets you may have here 
test.exe: main.o
	$(CXX) -o $@ $^
# Link with external main (on ix-dev only)

clean:
	$(RM) test.exe $(OBJECTS)
