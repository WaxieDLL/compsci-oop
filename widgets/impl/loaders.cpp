#include "../widgets.hpp"
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_opengl3.h>
#include <gl/GL.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../../dependencies/stb_image.h"
#include <imgui.h>

void Loaders::BeforeNewFrame() {
	if (!requested_fonts.empty())
	{

		for (auto it = requested_fonts.begin(); it != requested_fonts.end(); it++)
		{
			ImFontConfig cfg;
			cfg.FontDataOwnedByAtlas = false;
			ImFont* temp = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(it->data, it->size, it->fontsize, &cfg);
			Loaders::font_storage[it->id] = temp;
		}

		ImGui::GetIO().Fonts->Build();
		ImGui_ImplOpenGL3_CreateFontsTexture();
		requested_fonts.clear();
	}
}

void* Loaders::LoadImageFromMemory(std::string id, unsigned char* data, size_t size) {
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load_from_memory(data, size, &image_width, &image_height, NULL, STBI_rgb_alpha);
	if (image_data == NULL)
		return nullptr;
	GLuint image_texture;
	glGenTextures(1, &image_texture);
	glBindTexture(GL_TEXTURE_2D, image_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

	image_storage[id] = reinterpret_cast<void*>(image_texture);
	return image_storage[id];
}

void* Loaders::LoadFontFromMemoryRuntime(std::string id, unsigned char* data, size_t size, int fontsize) {

	FontData font_data;
	font_data.id = id;
	font_data.data = data;
	font_data.size = size;
	font_data.fontsize = fontsize;
	requested_fonts.push_back(font_data);

	return nullptr;
}