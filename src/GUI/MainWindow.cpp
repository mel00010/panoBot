#include "MainWindow.h"
#include <iostream>


MainWindow::MainWindow(){

	set_border_width(10);

	m_button.add_label("Button 0");
	m_button1.add_label("Button 1");

	/*when button recieves click signal, calls
	this function*/
	m_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnButtonClick));
	m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnButtonClick));
	
	m_grid.add(m_button);
	m_grid.add(m_button1);


	m_grid.show_all();
	add(m_grid);	

}


void MainWindow::OnButtonClick(){
	std::cout << "Test " << std::endl; 
}