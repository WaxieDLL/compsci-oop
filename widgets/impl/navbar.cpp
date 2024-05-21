#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "../widgets.hpp"
#include "../../memassets/logo.hpp"
#include "../../memassets/fonts.hpp"

static void DrawLogo(const std::string& title) {

	if (Loaders::image_storage.contains("ul_logo"))
	{
		ImGui::SetCursorPosX(15);
		ImGui::SetCursorPosY(ImGui::GetWindowSize().y / 2 - 48 / 2); // compiler will optimize it
		ImGui::Image(Loaders::image_storage.at("ul_logo"), { 48,48 });
		ImGui::SameLine(0, 15.f);
	}
	ImGui::PushFont(Loaders::font_storage.at("semibold_24"));
	{
		ImVec2 text_size = ImGui::CalcTextSize(title.c_str());
		ImGui::SetCursorPosY(ImGui::GetWindowSize().y / 2 - text_size.y / 2);
		ImGui::TextUnformatted(title.c_str());
	}
	ImGui::PopFont();

	//extra details

	ImGui::SameLine();
	const ImVec2 scr_pos = ImGui::GetCursorScreenPos();
	ImGui::SetCursorPosY(0);
	ImGui::Dummy({32, ImGui::GetWindowSize().y});
	ImVec2 line_pos = {
		scr_pos.x + 32 / 2,
		12
	};
	ImGui::GetWindowDrawList()->AddLine(line_pos, line_pos + ImVec2(0, ImGui::GetWindowSize().y - line_pos.y * 2), ImColor(255,255,255,20));
}

//Returns true if tab clicked
static bool DrawTabButton(const std::string& name, bool selected = false) {

	constexpr float padding_h = 10.f;

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));

	const ImVec2 text_size = ImGui::CalcTextSize(name.c_str());
	const ImVec2 button_size = ImVec2(text_size.x + padding_h * 2, ImGui::GetWindowSize().y);

	ImGui::SetCursorPosY(0);
	const ImVec2 scr_pos = ImGui::GetCursorScreenPos();


	const bool clicked = ImGui::Button(name.c_str(), button_size);


	if(selected)
		ImGui::GetWindowDrawList()->AddLine(scr_pos + ImVec2(0, button_size.y - 1), scr_pos + button_size - ImVec2(0, 1), ImColor(0, 117, 255));

	ImGui::PopStyleColor(3);

	return clicked;
}

bool Widgets::Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height)
{
	bool data_changed = false;
	if (!navbar_initialized)
	{
		Loaders::LoadImageFromMemory("ul_logo", logoMemory, sizeof logoMemory);
		Loaders::LoadFontFromMemoryRuntime("regular_18", interRegularMemory, sizeof interRegularMemory, 18);
		Loaders::LoadFontFromMemoryRuntime("semibold_24", interSemiboldMemory, sizeof interSemiboldMemory, 24);
		navbar_initialized = true;
	}

	if (!Loaders::font_storage.contains("regular_18"))
		return false;
	if (!Loaders::font_storage.contains("semibold_24"))
		return false;

	ImGui::PushFont(Loaders::font_storage.at("regular_18"));
	ImGui::SetCursorPos({ 0,0 });
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(ImColor(6, 6, 6)));
	ImGui::BeginChild(title.c_str(), ImVec2(ImGui::GetWindowSize().x, height));
	{
		ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(0, height - 1),
			ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, height - 1), ImColor(255, 255, 255, 20));

		DrawLogo(title);

		for (const auto& item : items)
		{
			ImGui::SameLine();
			bool selected = item == *selected_item;
			if (DrawTabButton(item, selected))
			{
				*selected_item = item;
				data_changed = true;
			}
		}
	}
	ImGui::EndChild();
	ImGui::PopStyleColor();
	ImGui::PopFont();


	return data_changed;
}