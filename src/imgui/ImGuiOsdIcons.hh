#ifndef IMGUI_OSD_ICONS_HH
#define IMGUI_OSD_ICONS_HH

#include "ImGuiAdjust.hh"
#include "ImGuiPart.hh"

#include "GLUtil.hh"
#include "TclObject.hh"
#include "gl_vec.hh"

#include <vector>

namespace openmsx {

class ImGuiOsdIcons final : public ImGuiPart
{
public:
	explicit ImGuiOsdIcons(ImGuiManager& manager_);

	[[nodiscard]] zstring_view iniName() const override { return "OSD icons"; }
	void save(ImGuiTextBuffer& buf) override;
	void loadStart() override;
	void loadLine(std::string_view name, zstring_view value) override;
	void loadEnd() override;
	void paint(MSXMotherBoard* motherBoard) override;

private:
	void setDefaultIcons();
	void loadIcons();
	void paintConfigureIcons();

public:
	bool showIcons = true;
	bool showConfigureIcons = false;

private:
	bool iconsHideTitle = true;
	bool iconsAllowMove = false;
	int iconsHorizontal = 1; // 0=vertical, 1=horizontal
	float iconsFadeDuration = 5.0f;
	float iconsFadeDelay = 5.0f;

	struct IconInfo {
		IconInfo() = default;
		IconInfo(TclObject expr_, std::string on_, std::string off_, bool fade_)
			: expr(expr_), on(std::move(on_)), off(std::move(off_)), fade(fade_) {}
		struct Icon {
			Icon() = default;
			explicit Icon(std::string filename_) : filename(std::move(filename_)) {}
			std::string filename;
			gl::Texture tex{gl::Null{}};
			gl::ivec2 size;
		};
		TclObject expr;
		Icon on, off;
		float time = 0.0f;
		bool lastState = true;
		bool enable = true;
		bool fade = false;
	};
	std::vector<IconInfo> iconInfo;
	gl::ivec2 iconsTotalSize;
	gl::ivec2 iconsMaxSize;
	int iconsNumEnabled = 0;
	bool iconInfoDirty = true;

	AdjustWindowInMainViewPort adjust;

	static constexpr auto persistentElements = std::tuple{
		PersistentElement{"show",         &ImGuiOsdIcons::showIcons},
		PersistentElement{"hideTitle",    &ImGuiOsdIcons::iconsHideTitle},
		PersistentElement{"allowMove",    &ImGuiOsdIcons::iconsAllowMove},
		PersistentElementMax{"layout",    &ImGuiOsdIcons::iconsHorizontal, 2},
		PersistentElement{"fadeDuration", &ImGuiOsdIcons::iconsFadeDuration},
		PersistentElement{"fadeDelay",    &ImGuiOsdIcons::iconsFadeDelay},
		PersistentElement{"showConfig",   &ImGuiOsdIcons::showConfigureIcons}
		// manually handle "icon.xxx", "adjust"
	};
};

} // namespace openmsx

#endif
