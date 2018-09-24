/*******************************************************************************
 * MainWindow.hpp
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
#ifndef SRC_GUI_MAINWINDOW_HPP_
#define SRC_GUI_MAINWINDOW_HPP_

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/entry.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include <string>

class MainWindow: public Gtk::Window {
	public:
		MainWindow();
		virtual ~MainWindow();
	protected:
		/*Main title window*/
		std::string _title;

		/*Container Widgets*/
		Gtk::Grid grid;

		/*Widgets*/
		Gtk::Button button_0;
		Gtk::Button button_1;

		Gtk::ComboBoxText sensor;
		Gtk::Label sensor_label;

		Gtk::ComboBoxText lens_type;
		Gtk::Label lens_type_label;

		Gtk::Entry focal_length;
		Gtk::Label focal_length_label;

		Gtk::Entry pano_width;
		Gtk::Label pano_width_label;

		Gtk::Entry pano_height;
		Gtk::Label pano_height_label;
};

#endif /* SRC_GUI_MAINWINDOW_HPP_ */
