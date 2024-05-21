#ifndef INCLUDE_WIDGETS_H
#define INCLUDE_WIDGETS_H
#include <string>
#include <vector>
#include <unordered_map>

//Forward declarations
struct ImFont;

struct FontData {
	std::string id;
	unsigned char* data;
	size_t size;
	int fontsize;
};

//@TODO: not final
namespace Loaders {
	void BeforeNewFrame();
	void* LoadImageFromMemory(std::string id, unsigned char* data, size_t size); // returns nullptr if it fails
	void* LoadFontFromMemory(std::string id, unsigned char* data, size_t size, int fontsize = 16); // returns nullptr if it fails
	void* LoadFontFromMemoryRuntime(std::string id, unsigned char* data, size_t size, int fontsize = 16); // returns nullptr if it fails

	inline std::unordered_map<std::string, void*> image_storage = {};
	inline std::unordered_map<std::string, ImFont*> font_storage = {};
	inline std::vector<FontData> requested_fonts = {};
}

namespace Widgets {
	bool Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height = 70.f);
	inline bool navbar_initialized = false;
}
#endif