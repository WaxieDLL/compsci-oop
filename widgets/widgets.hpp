#ifndef INCLUDE_WIDGETS_H
#define INCLUDE_WIDGETS_H
#include <string>
#include <vector>
namespace Widgets {
	void Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height = 70.f);
}
#endif