/*******************************************************************************
 * main.cpp
 * Copyright (C) 2018 Mel McCalla <melmccalla@gmail.com>
 *
 * This file is part of panoBot.
 *
 * panoBot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * panoBot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with panoBot.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

#include "MainWindow.hpp"

#include <gtkmm/application.h>
#include <glibmm/i18n.h>

int main(int argc, char* argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain(GETTEXT_PACKAGE, PROGRAMNAME_LOCALEDIR);
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	auto app = Gtk::Application::create(argc, argv, "com.github.panoBot-GUI");

	MainWindow window;

	return app->run(window);
}

/*gtk::application stored in smartpointer,
 checks args passed, standard options such ass
 --display*/
