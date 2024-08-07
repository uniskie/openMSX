#ifndef OSDIMAGEBASEDWIDGET_HH
#define OSDIMAGEBASEDWIDGET_HH

#include "OSDWidget.hh"
#include "stl.hh"
#include <array>
#include <cstdint>
#include <optional>
#include <span>

namespace openmsx {

class GLImage;
class Display;

class OSDImageBasedWidget : public OSDWidget
{
protected:
	static constexpr auto imageBasedProperties = [] {
		using namespace std::literals;
		return concatArray(
			widgetProperties,
			std::array{
				"-rgba"sv, "-rgb"sv, "-alpha"sv,
				"-fadePeriod"sv, "-fadeTarget"sv,
				"-fadeCurrent"sv,
				"-scrollSpeed"sv,
				"-scrollPauseLeft"sv,
				"-scrollPauseRight"sv,
				"-query-size"sv,
			});
	}();

public:
	[[nodiscard]] gl::vec2 getPos() const override;
	[[nodiscard]] uint32_t getRGBA(uint32_t corner) const { return rgba[corner]; }
	[[nodiscard]] std::span<const uint32_t, 4> getRGBA4() const { return rgba; }

	[[nodiscard]] virtual uint8_t getFadedAlpha() const = 0;

	[[nodiscard]] std::span<const std::string_view> getProperties() const override {
		return imageBasedProperties;
	}
	void setProperty(Interpreter& interp,
	                 std::string_view name, const TclObject& value) override;
	void getProperty(std::string_view name, TclObject& result) const override;
	[[nodiscard]] float getRecursiveFadeValue() const override;
	[[nodiscard]] bool isVisible() const override;
	[[nodiscard]] bool isRecursiveFading() const override;

protected:
	OSDImageBasedWidget(Display& display, const TclObject& name);
	~OSDImageBasedWidget() override;
	[[nodiscard]] bool hasConstantAlpha() const;
	void createImage(OutputSurface& output);
	void invalidateLocal() override;
	void paint(OutputSurface& output) override;
	[[nodiscard]] virtual std::unique_ptr<GLImage> create(OutputSurface& output) = 0;
	[[nodiscard]] gl::vec2 getRenderedSize() const;

	void setError(std::string message);
	[[nodiscard]] bool hasError() const { return error; }

	std::unique_ptr<GLImage> image;

private:
	void setRGBA(std::span<const uint32_t, 4> newRGBA);
	[[nodiscard]] bool isFading() const;
	[[nodiscard]] float getCurrentFadeValue() const;
	[[nodiscard]] float getCurrentFadeValue(uint64_t now) const;
	[[nodiscard]] bool isAnimating() const;
	[[nodiscard]] std::optional<float> getScrollWidth() const;
	void updateCurrentFadeValue();

	[[nodiscard]] gl::vec2 getTransformedPos(const OutputSurface& output) const;

private:
	uint64_t startFadeTime = 0;
	float fadePeriod = 0.0f;
	float fadeTarget = 1.0f;
	mutable float startFadeValue = 1.0f;
	float scrollSpeed = 0.0f; // 0 means disabled
	float scrollPauseLeft = 0.0f;
	float scrollPauseRight = 0.0f;
	uint64_t startScrollTime = 0;
	std::array<uint32_t, 4> rgba;
	bool error = false;
};

} // namespace openmsx

#endif
