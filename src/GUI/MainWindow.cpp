/*******************************************************************************
 * MainWindow.cpp
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

#include <glibmm/i18n.h>
#include <functional>
#include <iostream>

MainWindow::MainWindow() {
	set_size_request(200, 100);
	set_title("PanoBot");

	add(grid);

	sensor_label.set_text(_("Sensor Type   "));
	sensor.append(_("EF"));
	sensor.append(_("EF-S"));

	lens_type_label.set_text(_("Lens Type"));
	lens_type.append(_("EF"));
	lens_type.append(_("EF-S"));


	focal_length.set_max_length(50);
	focal_length_label.set_text(_("Focal length"));

	pano_width.set_max_length(50);
	pano_width_label.set_text(_("Panorama width"));

	pano_height.set_max_length(50);
	pano_height_label.set_text(_("Panorama height"));

	button_0.add_label(_("Button 0"));
	button_0.signal_clicked().connect([this] {
		std::cout << _("Button 0 pressed ") << std::endl;
		std::cout << sensor.get_active_text() << std::endl;
	});

	button_1.add_label(_("Button 1"));
	button_1.signal_clicked().connect([this] {
		std::cout << _("Button 1 pressed") << std::endl;
	});
	grid.set_row_spacing(20);
	grid.set_column_spacing(1);
	grid.attach(sensor_label, 0, 0, 1, 1);
	grid.attach(sensor, 1, 0, 1, 1);
	grid.attach(lens_type_label, 0, 1, 1, 1);
	grid.attach(lens_type, 1, 1, 1, 1);
	grid.attach(focal_length_label, 0, 2, 1, 1);
	grid.attach(focal_length, 1, 2, 1, 1);
	grid.attach(pano_width_label, 0, 3, 1, 1);
	grid.attach(pano_width, 1, 3, 1, 1);
	grid.attach(pano_height_label, 0, 4, 1, 1);
	grid.attach(pano_height, 1, 4, 1, 1);
	grid.attach(button_0, 0, 5, 1, 1);
	grid.attach(button_1, 0, 6, 1, 1);

	show_all_children();
}

MainWindow::~MainWindow() {

}
