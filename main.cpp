#define IMGUI_DEFINE_MATH_OPERATORS
#include "app.hpp"
#include "gui/window.hpp"
#include "widgets/widgets.hpp"
#include "dependencies/json.hpp"
#include <fstream>
#include <iostream>
#include "backend/classes/ccallmanager.hpp"
#include "backend/interfaces/iemergencycall.hpp"

extern void HomeContent(CAppManager* app);
extern void DispatcherContent(CAppManager* app);

static void ExampleJsonParsing(CCallManager* pCallManager);

int main()
{
	const std::unique_ptr<CCallManager> pCallManager(new CCallManager);

	ExampleJsonParsing(pCallManager.get());

	CAppManager app;
	if (!app.IsValid())
		return -1;

	const auto pHomeWindow = app.AddWindow("Home Window"); //it will be default window since we added it first
	if (pHomeWindow.has_value())
		pHomeWindow.value()->SetCallback([&] {HomeContent(&app); });

	const auto pDispatchWindow = app.AddWindow("Dispatch Window");
	if (pDispatchWindow.has_value())
		pDispatchWindow.value()->SetCallback([&] {DispatcherContent(&app); });

	/* Ways of changing active window
	* 
	*	app.SetActiveWindow("Home Window");
	*
	*	// This also works!
	*
	*	if(pHomeWindow.has_value())
	*		app.SetActiveWindow(pHomeWindow.value());
	*/

	app.MainLoop();
	return 0;
}

static void DrawNavbar(CAppManager* app) {
	static std::string selected = "Home";
	if (Widgets::Navbar("Police Station", { "Home", "Dispatch", "Officers", "Search" }, &selected))
	{
		if (selected == "Home")
		{
			app->SetActiveWindow("Home Window");
		}
		else if (selected == "Dispatch")
		{
			app->SetActiveWindow("Dispatch Window");
		}
		else if (selected == "Officers")
		{
			app->SetActiveWindow("Home Window");
		}
		else if (selected == "Search")
		{
			app->SetActiveWindow("Home Window");
		}
	}
}

static void ContentWrapper(std::function<void()> callback, ImVec2 start_pos) {
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(ImColor(16, 16, 16)));
	ImGui::SetCursorPos(start_pos);
	ImGui::BeginChild("Content", ImGui::GetWindowSize() - start_pos);
	if (callback)
		callback();
	ImGui::EndChild();
	ImGui::PopStyleColor();
}

void HomeContent(CAppManager* app)
{
	if (!app)
		return;

	DrawNavbar(app);
	ContentWrapper([] {
		ImGui::TextUnformatted("Home Window");
		}, {0, 70});
}
void DispatcherContent(CAppManager* app)
{
	if (!app)
		return;

	DrawNavbar(app);
	ContentWrapper([] {
		ImGui::TextUnformatted("Dispatch Window");
		}, { 0, 70 });
}

void ExampleJsonParsing(CCallManager* pCallManager)
{

	std::ifstream ifs("sample.json");
	nlohmann::json sample = nlohmann::json::parse(ifs);

	for (const auto& obj : sample.items())
	{
		const auto data = obj.value();
		if (!data.contains("caller") || !data.contains("incident") || !data.contains("location") || !data.contains("details"))
			continue;

		std::string caller = data["caller"];
		std::string incident = data["incident"];
		std::string location = data["location"];
		std::string details = data["details"];

		auto emergency_call = pCallManager->CreateEmergencyCall(incident);
		emergency_call->SetCallerName(caller);
		emergency_call->SetDetails(details);
		emergency_call->SetLocation(location);
	}
}
