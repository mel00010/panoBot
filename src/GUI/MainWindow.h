#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <string>

class MainWindow : public Gtk::Window{

	public:
		MainWindow();

	protected:
		/*Main title window*/
		std::string _title;

		/*Event handlers*/
		void OnButtonClick();

		/*Container Widgets*/
		Gtk::Grid m_grid;

		/*Widgets*/
		Gtk::Button m_button;
		Gtk::Button m_button1;

};