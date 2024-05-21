#ifndef INCLUDE_WIDGETS_H
#define INCLUDE_WIDGETS_H
#include <string>
#include <vector>
#include <unordered_map>


//@TODO: not final
namespace Loaders {
	void* LoadImageFromMemory(std::string id, unsigned char* data, size_t size); // returns nullptr if it fails

	inline std::unordered_map<std::string, void*> image_storage = {};
}

namespace Widgets {
	void Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height = 70.f);
}
#endif