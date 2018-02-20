#include <gtkmm.h>
#include "MainWindow.h"

#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 300

int main(int argc , char* argv[]){

	auto app = Gtk::Application::create(argc, argv, "Test window");

	MainWindow window;

	return app->run(window);
}


/*gtk::application stored in smartpointer,
checks args passed, standard options such ass 
--display*/