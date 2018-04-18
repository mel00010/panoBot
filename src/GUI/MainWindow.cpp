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

#include <iostream>

MainWindow::MainWindow() {

	set_border_width(100);

	m_button_0.add_label("Button 0");
	m_button_1.add_label("Button 1");

	/*when button receives click signal, calls
	 this function*/
	m_button_0.signal_clicked().connect([this] {
		std::cout << "m_button_0 pressed " << std::endl;
	});
	m_button_1.signal_clicked().connect([this] {
		std::cout << "m_button_1 pressed" << std::endl;
	});

	m_grid.add(m_button_0);
	m_grid.add(m_button_1);

	m_grid.show_all();
	add(m_grid);

}

MainWindow::~MainWindow() {

}
